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
    Graph MST;
    KineticGraph kineticGraph;

    KineticSpanningTree();
    
protected:
    float t;
    
public:
    KineticSpanningTree(string name);
    void print();
};
#endif /* KineticSpanningTree_hpp */
