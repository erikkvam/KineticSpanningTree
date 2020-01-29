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
class Graph {
private:
    set<int> V;
    list<list<int>> E;
    
    int w[][];
    
    bool add(const int& u, const int& v, const int& a, const int& b);
    bool del(const int& u, const int& v);
    bool modify(const int& u, const int& v, const int& a, const int& b);
}
#endif /* Graph_hpp */
