//
//  Graph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Graph.hpp"
#include <iterator>
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

bool Graph::inV (const int& v){
    return V.count(v) > 0;
}
