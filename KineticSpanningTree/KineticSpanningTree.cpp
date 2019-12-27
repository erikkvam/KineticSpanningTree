//
//  KineticSpanningTree.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticSpanningTree.hpp"
#include <string>
#include <iostream>
using namespace std;


KineticSpanningTree::KineticSpanningTree(string name){
    if (name == "example") {
        t = 0;
        vertices = vector<vertex>(0);
        edges = vector<edge>(0);
        MSTedges = vector<int>(0);
        clusters = vector<cluster>(0);
    }
}

void KineticSpanningTree::print(){
    cout << "Printing a Kinetic Spanning Tree" << endl;
    
    cout << "At time " << t << ", the tree looks like:" << endl;
    //kineticGraph.print();
    
    cout << endl << endl;
    
    cout << "At time " << t << ", the MST looks like:" << endl;
    //MST.print();
}
    
