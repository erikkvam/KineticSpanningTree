//
//  Graph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Graph.hpp"
#include <iterator>
Graph::Graph(){
    V.clear();
    Ew.clear();
}

bool Graph::add(const int& u, const int& v, const int& a, const int& b){
    if (inV(u) and inV(v) and not inE(u,v)) {
        Ew[u][v] = pair<int,int>(a,b);
        Ew[v][u] = pair<int,int>(a,b);
        return true;
    } else {
        return false;
    }
}

bool Graph::del(const int& u, const int& v){
    if (inV(u) and inV(v) and inE(u,v)){
        Ew[u].erase(v);
        Ew[v].erase(u);
        return true;
    } else {
        return false;
    }
}


bool Graph::inV(const int& v){
    return V.count(v) > 0;
}

bool Graph::inE(const int& u, const int& v){
    return Ew[u].count(v);
}

pair<int, int> Graph::getCostFunction(const int&u, const int& v){
    return Ew[u][v];
}
