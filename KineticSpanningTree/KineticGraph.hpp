//
//  KineticGraph.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef KineticGraph_hpp
#define KineticGraph_hpp
#include "Graph.hpp"
#include <limits>
#include <queue>

class KineticGraph: public Graph {
private:
    list<list<pair<double, double>>> adjacencyParameters;
    priority_queue<Event> events;
        
public:
    KineticGraph();
    KineticGraph(float t);
    KineticGraph(string name);
};

#endif /* KineticGraph_hpp */
