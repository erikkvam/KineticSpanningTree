//
//  Graph.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Graph.hpp"
#include <limits>
#include <queue>
#include <map>

Graph::Graph(){}

void Graph::calculateMST(){
    /*
     @misc{ wiki:xxx,
       author = "{Wikipedia contributors}",
       title = "Prim's algorithm --- {Wikipedia}{,} The Free Encyclopedia",
       year = "2019",
       howpublished = "\url{https://en.wikipedia.org/w/index.php?title=Prim%27s_algorithm&oldid=923305218}",
       note = "[Online; accessed 14-November-2019]"
     }
    */
    //Associate with each vertex v of the graph a number C[v] (the cheapest cost of a connection to v) and an edge E[v] (the edge providing that cheapest connection). To initialize these values, set all values of C[v] to +∞ (or to any number larger than the maximum edge weight) and set each E[v] to a special flag value indicating that there is no edge connecting v to earlier vertices.
    map<string, string> E;
    map<string, double> C;
    for (string node : nodes) {
        E[node] = "";
        C[node] = numeric_limits<double>::infinity();
    }
    //Initialize an empty forest F and a set Q of vertices that have not yet been included in F (initially, all vertices).
    Graph F = Graph();
    priorityVertexQueue Q = priorityVertexQueue();
    for (string node : nodes){
        Q.push(weightedVertex(C[node],node));
    }
    //Repeat the following steps until Q is empty:
    while (not Q.empty()) {
        //Find and remove a vertex v from Q having the minimum possible value of C[v]
        weightedVertex v = Q.top();
        Q.pop();
        string label = v.second;
        //Add v to F and, if E[v] is not the special flag value, also add E[v] to F
        F.add(label, adjacent(label));
        if (E[label] != "") {
            F.add(E[label], adjacent(E[label]));
        };
        //Loop over the edges vw connecting v to other vertices w.
        for (pair<string, double> edge : adjacent(label)) {
            //For each such edge, if w still belongs to Q and vw has smaller weight than C[w], perform the following steps:
            if (edge.second < C[edge.first]) {
                //Set C[w] to the cost of edge vw
                C[edge.first] = cost(label, edge.first);
                //Set E[w] to point to edge vw.
                E[edge.first] = label;
            }
        }
        
    }
}


//Graph add(string label, list<pair<string,double>> adjacencies);
void Graph::add(string node, list<pair<string,double>> adjacent_to){
    nodes.push_back(node);
    for (pair<string, double> adjacency : adjacent_to){
        adjacencies[node].push_back(adjacency);
        adjacencies[adjacency.first].push_back(pair<string, double>(node,adjacency.second));
    };
}

double Graph::cost(string v, string w){
    for (pair<string, double> adjacency : adjacencies[v]) {
        if (adjacency.first == w) {
            return adjacency.second;
        }
    }
    return numeric_limits<double>::infinity();
}

list<pair<string, double>> Graph::adjacent(string v){
    return adjacencies[v];
}

