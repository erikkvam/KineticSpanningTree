////
////  KineticSpanningTree.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef KineticSpanningTree_hpp
#define KineticSpanningTree_hpp
#include "Event.cpp"
#include "Graph.cpp"
using namespace std;

class KineticSpanningTree {
private:
    void evaluate(const Event& event);
public:
    float t;
    Graph G;
    Graph MST;
    
    void addEdge(const int& u, const int& v, const int& a, const int& b);
    void deleteEdge(const int& u, const int& v);
    void modifyEdge(const int& u, const int& v, const int& a, const int& b);
};
#endif /* KineticSpanningTree_hpp */
