//
//  KineticSpanningTree.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticSpanningTree.hpp"
#include <string>

KineticSpanningTree::KineticSpanningTree(){}

KineticSpanningTree::KineticSpanningTree(string name){
    if (name == "example") {
        t = 0;
        kineticGraph = KineticGraph("example");
        kineticGraph.calculateMST();
    }
}
