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
    
    vector<vertex> vertices;
    vector<edge> edges;
    vector<int> MSTedges;
    
    priority_queue<event, vector<event>, lessEvent> events; //should act as a priority queue
    
    typedef vector<vertex> cluster;
    vector<cluster> clusters;
    vector<vector<vector<int>>> edgesBetweenClusters;
    
    struct swap {
        int v, w, x, y, a, b; //delete v-w and add x-y (weight a+bt)
    };
    swap nextIntra, nextInter, nextDual;

    
    
protected:
    float t;
    
public:
    KineticSpanningTree(string name);
    void print();
    void advanceTimeUntil(float t);
};
#endif /* KineticSpanningTree_hpp */
