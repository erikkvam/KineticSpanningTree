//
//  Graph.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include "Event.cpp"
#include "Certificate.cpp"
#include <map>
#include <queue>
#include <string>
#include <list>
using namespace std;

class Graph {
protected:
    vector<string> nodes = vector<string>();
    map<string, list<pair<string, double>>> adjacencies = map<string, list<pair<string, double>>>();
    map<string, list<pair<string, double>>> MSTadjacencies = map<string, list<pair<string, double>>>();
    
    
    typedef pair<double,string> weightedVertex;
    typedef priority_queue<weightedVertex> priorityVertexQueue;
    
public:
    Graph();
    void calculateMST();
    void add(string label, list<pair<string,double>> adjacencies);
    double cost(string v, string w);
    list<pair<string, double>> adjacent(string);
    void print();
    void addVertex(string v);
    void addEdge(string v, string w, double weight);
};
#endif /* Graph_hpp */
