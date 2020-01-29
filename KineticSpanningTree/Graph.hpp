//
//  Graph.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <set>
#include <list>
using namespace std;
class Graph {
private:
    set<int> V;
    list<list<pair<int,pair<int,int>>>> Ew; //Ew[v] = (u,(a,b)) if there exists an edge uv with cost at+b
    
public:
    bool add(const int& u, const int& v, const int& a, const int& b);
    bool del(const int& u, const int& v);
    bool modify(const int& u, const int& v, const int& a, const int& b);
    
    bool inV(const int& v);
    bool inE(const int& u, const int& v);
};
#endif /* Graph_hpp */
