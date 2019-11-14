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

class KineticGraph: public Graph {
private:
    int size;
    list<list<pair<float, float>>> adjacencyParameters;
    
    float SELF = -1;
    float UNCONNECTED = -2;
    
public:
    KineticGraph();
    KineticGraph(float t);
    KineticGraph(string name);
};

#endif /* KineticGraph_hpp */
