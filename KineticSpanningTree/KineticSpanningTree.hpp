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
    struct vertexLess{
        const bool operator()(const vertex& a, const vertex& b){
            return a.id < b.id;
        }
    };
    struct edge {
        int id;
        int v, w; //vertex IDs
        double a, b; //cost = a+bt
    };
    void addEdge(const int& v, const int& w, const float& a, const float& b);
    void deleteEdge(const edge& e);
    void deleteEdge(const int& v, const int& w);
    void addVertex(const int& v);
    void deleteVertex(const int& v);
    vector<edge> findEdgesThatComeFrom(const int& v);
    void transformGraph();
    
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
    const bool sameSwap(const swap& s, const event& e);
    void recalculateIntra();
    void recalculateInter();
    void recalculateDual();
    void performSwap(const swap& s);
    void performSwap(const event& e); //e should be an MSTswap
    
protected:
    float t;
    
public:
    KineticSpanningTree(string name);
    void print();
    void advanceTimeUntil(float t);
};
#endif /* KineticSpanningTree_hpp */
