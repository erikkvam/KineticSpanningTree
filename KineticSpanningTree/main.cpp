//
//  main.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include <string>
#include <iostream>
#include "KineticSpanningTree.cpp"


void testGraph(){
    //create a Graph
    Graph g = Graph();
    cout << "testGraph: Graph created" << endl;
}

void testKineticSpanningTree(){
    KineticSpanningTree KST;
}


int main() {
    cout << "main: Starting tests" << endl;
//    testGraph();
//    testCertificate();
//    testEvent();
    testKineticSpanningTree();
    cout << "main: All tests OK" << endl;
}

