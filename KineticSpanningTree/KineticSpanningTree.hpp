//
//  KineticSpanningTree.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef KineticSpanningTree_hpp
#define KineticSpanningTree_hpp
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class KineticSpanningTree {
private:
    struct vertex {
        string label = "";
        int id;
    };
    struct edge {
        int id;
        int v, w; //vertex IDs
        double a, b; //cost = a+bt
    };
    
    enum EventType {VertexDeletion, EdgeDeletion, EdgeWeightUpdate, VertexAddition, EdgeAddition, MSTSwap};
    struct event {
        /*
         VertexDeletion  : delete vertex v
         EdgeDeletion    : delete edge v-w
         EdgeWeightUpdate: set vertex v-w to weight a+bt
         VertexAddition  : add vertex v
         EdgeAddition    : add edge v-w
         MSTSwap         : swap edges v-w and a-b in the MST
         */
        EventType type;
        int time;
        int v, w, a, b;

    };
    struct lessEvent {
        bool operator() (const event& x, const event& y) {
            return x.time < y.time;
        }
    };
    
    set<vertex> vertices;
    set<edge> edges;
    set<int> MSTedges;
    
    priority_queue<event, vector<event>, lessEvent> events;
    
    typedef vector<vertex> cluster;
    set<cluster> clusters;
    vector<vector<set<int>>> edgesBetweenClusters;
    
    struct swap {
        int v, w, x, y, a, b; //delete v-w and add x-y (weight a+bt)
    };
    swap nextIntra, nextInter, nextDual;
    const bool sameSwap(const swap& s, const event& e){
        return e.type == MSTSwap and e.v == s.v and e.w == s.w and e.a == s.x and e.b == s.y;
    }
    
    
protected:
    float t;
    
public:
    KineticSpanningTree(string name);
    void print();
    void advanceTimeUntil(float t);
};
#endif /* KineticSpanningTree_hpp */
