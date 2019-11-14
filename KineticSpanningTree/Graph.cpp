//
//  Graph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Graph.hpp"
Graph::Graph(){
    nodes = list<Node>();
    adjacencies = list<list<float>>(1, list<float>(1, 0));
}

Graph Graph::calculateMST(){
    return *this;
}
