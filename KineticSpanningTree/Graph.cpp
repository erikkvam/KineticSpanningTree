//
//  Graph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Graph.hpp"
bool Graph::add(const int& u, const int& v, const int& a, const int& b){
    if (inV(u) and inV(v) and not inE(u,v)) {
        pair<int,int> ab = pair<int,int>(a,b);
        
        iterator uPos = Ew.begin() + u;
        *uPos.insert(pair<int, pair<int,int>>(v,ab));
        
        iterator vPos = Ew.begin() + v;
        *vPos.insert(pair<int, pair<int,int>>(u,ab));
        
        return true;
    } else {
        return false;
    }
}
