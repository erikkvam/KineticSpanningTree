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
    int time;
    Graph graph;
    Graph MST;
    KineticGraph kineticGraph;
    
public:
    KineticSpanningTree();
};
#endif /* KineticSpanningTree_hpp */
