//
//  KineticSpanningTree.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef KineticSpanningTree_hpp
#define KineticSpanningTree_hpp

#include "Graph.hpp"
#include "KineticGraph.hpp"

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
    struct Event {
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
    }
    
    vector<vertex> vertices;
    vector<edge> edges;
    vector<int> MSTedges;
    
    vector<Event>; //should act as a priority queue
    
    typedef vector<vertex> cluster;
    vector<cluster> clusters;
    
    struct swap {
        int v, w, x, y; //delete v-w and add x-y
    }
    swap nextIntra, nextInter, nextDual;

    

    KineticSpanningTree();
    
protected:
    float t;
    
public:
    KineticSpanningTree(string name);
    void print();
    void advanceTimeUntil(float t);
};
#endif /* KineticSpanningTree_hpp */
