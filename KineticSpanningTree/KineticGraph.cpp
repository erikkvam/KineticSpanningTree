//
//  KineticGraph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticGraph.hpp"
#include <string>
#include <iterator>
#include <list>

KineticGraph::KineticGraph(){
    adjacencyParameters = list<list<pair<float, float>>>(0);
}

//KineticGraph::KineticGraph(float t){
//    adjacencyParameters = list<list<pair<float, float>>>(adjacencies.size());
//    list<list<pair<float, float>>> parameters = adjacencyParameters;
//    list<list<pair<float, float>>>::iterator it = parameters.begin();
//    for (list<float> adjacencyRow : adjacencies) {
//        list<pair<float, float>> parameterRow = *it;
//        list<pair<float, float>>::iterator jt = parameterRow.begin();
//        for (float n : adjacencyRow) {
//            n = (*jt).first*t+(*jt).second;
//            jt++;
//        }
//        it++;
//    }
//}

KineticGraph::KineticGraph(string name){
    if (name == "example") {
        nodes.push_back("a");
        nodes.push_back("b");
        nodes.push_back("c");
        
        adjacencies["a"].push_back(pair<string, double>("b",2));
        adjacencies["b"].push_back(pair<string, double>("a",2));
    }
    else KineticGraph();
}
