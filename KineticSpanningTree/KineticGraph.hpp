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
    list<list<float>> adjacency_weights (float t);
    
public:
    KineticGraph();
};

#endif /* KineticGraph_hpp */
