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
        pair<int,int> ab = pair<int,int>(a,b);
        
        list<list<pair<int,pair<int,int>>>>::iterator uPos = next(Ew.begin(),u);
        (*uPos).push_back(pair<int, pair<int,int>>(v,ab));
        
        list<list<pair<int,pair<int,int>>>>::iterator vPos = next(Ew.begin(),v);
        (*vPos).push_back(pair<int, pair<int,int>>(u,ab));
        
        return true;
    } else {
        return false;
    }
}

bool Graph::del(const int& u, const int& v){
    if (inV(u) and inV(v) and inE(u,v)){
        list<list<pair<int,pair<int,int>>>>::iterator uPos = next(Ew.begin(),u);
        list<pair<int,pair<int,int>>>::iterator vPos = next((*uPos).begin(),v);
        (*uPos).erase(vPos);
        
        return true;
    } else {
        return false;
    }
}


bool Graph::inV(const int& v){
    return V.count(v) > 0;
}

bool Graph::inE(const int& u, const int& v){
    list<list<pair<int,pair<int,int>>>>::iterator uPos = next(Ew.begin(),u);
    for (pair<int,pair<int,int>> vertex : (*uPos)) {
        if (vertex.first == v) return true;
    }
    return false;
}

pair<int, int> Graph::getCostFunction(const int&u, const int& v){
    list<list<pair<int,pair<int,int>>>>::iterator uPos = next(Ew.begin(),u);
    list<pair<int,pair<int,int>>>::iterator vPos = next((*uPos).begin(),v);
    pair<int,int> toReturn;
    toReturn.first = (*vPos).second.first;
    toReturn.second = (*vPos).second.second;
    return toReturn;
}
