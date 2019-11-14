//
//  Graph.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include <list>
#include "Node.hpp"
using namespace std;

class Graph {
protected:
    list<Node> nodes;
    list<list<float>> adjacencies;
    
public:
    Graph();
    Graph calculateMST();
};
#endif /* Graph_hpp */
