//
//  KineticGraph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticGraph.hpp"

KineticGraph::KineticGraph(){
    adjacencies = adjacency_weights(0);
}

list<list<float>> KineticGraph::adjacency_weights(float t){
    return list<list<float>>(0);
}
