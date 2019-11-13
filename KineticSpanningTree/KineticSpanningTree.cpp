//
//  KineticSpanningTree.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticSpanningTree.hpp"
KineticSpanningTree::KineticSpanningTree(){
    time = 0;
    kineticGraph = KineticGraph();
    MST = kineticGraph.calculateMST();
}
