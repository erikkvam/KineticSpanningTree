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

KineticGraph::KineticGraph(float t){
    adjacencyParameters = list<list<pair<float, float>>>(adjacencies.size());
    list<list<pair<float, float>>> parameters = adjacencyParameters;
    list<list<pair<float, float>>>::iterator it = parameters.begin();
    for (list<float> adjacencyRow : adjacencies) {
        list<pair<float, float>> parameterRow = *it;
        list<pair<float, float>>::iterator jt = parameterRow.begin();
        for (float n : adjacencyRow) {
            n = (*jt).first*t+(*jt).second;
            jt++;
        }
        it++;
    }
}

KineticGraph::KineticGraph(string name){
    if (name == "example") {
        nodes = list<Node>();
        nodes.push_back(Node("a"));
        nodes.push_back(Node("b"));
        nodes.push_back(Node("c"));
        
        adjacencies = list<list<float>>();
        
        list<float> aAdjacencies = list<float>();
        aAdjacencies.push_back(SELF);
        aAdjacencies.push_back(UNCONNECTED);
        aAdjacencies.push_back(5);
        adjacencies.push_back(aAdjacencies);
        
        list<float> bAdjacencies = list<float>();
        bAdjacencies.push_back(UNCONNECTED);
        bAdjacencies.push_back(SELF);
        bAdjacencies.push_back(6);
        adjacencies.push_back(bAdjacencies);
        
        list<float> cAdjacencies = list<float>();
        cAdjacencies.push_back(5);
        cAdjacencies.push_back(6);
        cAdjacencies.push_back(SELF);
        adjacencies.push_back(cAdjacencies);
    }
    else KineticGraph();
}
