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
        vertices.clear();
        edges.clear();
        MSTedges.clear();
        clusters.clear();
    }
    else {
        t = 0;
        vertices.clear();
        edges.clear();
        MSTedges.clear();
        clusters.clear();
    }
    transformGraph();
    recalculateIntra();
    recalculateInter();
    recalculateDual();
    
    
}

void KineticSpanningTree::print(){
    cout << "Printing a Kinetic Spanning Tree" << endl;
    
    cout << "At time " << t << ", the tree looks like:" << endl;
    //kineticGraph.print();
    
    cout << endl << endl;
    
    cout << "At time " << t << ", the MST looks like:" << endl;
    //MST.print();
}

void KineticSpanningTree::advanceTimeUntil(float timeLimit){
    while (t < timeLimit) {
        event x = events.top();
        events.pop();
        t = x.time;
        
        switch (x.type) {
            case EdgeAddition:
                addEdge(x.v, x.w, x.a, x.b);
//                findAndPerformNonPositiveSwaps();
                break;
                
            case VertexAddition:
                addVertex(x.v, x.w);
                break;
                
            case EdgeDeletion:
                deleteEdge(x.v, x.w);
//                if (inTheMST(x.v, x.w)) {
//                    edge bestEdge;
//                    for (vector<vector<int>> connectionsOfACluster : edgesBetweenClusters) {
//                        for (vector<int> connectionsBetweenTwoClusters : connectionsOfACluster) {
//                            edge bestOfCluster = findBestReplacementEdgeFor(x.v, x.w, connectionsBetweenTwoClusters);
//                            if ((bestOfCluster.a+bestOfCluster.b*t) > (bestEdge.a+bestEdge.b*t)) {
//                                bestEdge = bestOfCluster;
//                            }
//                        }
//                    }
//                    performSwap(x.v, x.w, bestEdge);
//                }
                break;
                
            case VertexDeletion:
                for (edge e : findEdgesThatComeFrom(x.v, x.w)) {
                    deleteEdge(e);
                }
                deleteVertex(x.v, x.w);
                break;
                
            case EdgeWeightUpdate:
                deleteEdge(x.v, x.w);
                addEdge(x.v, x.w, x.a, x.b);
                break;
                
            case MSTSwap:
                if (sameSwap(nextInter, x)) {
                    recalculateInter();
                }
                else if (sameSwap(nextIntra, x)) {
                    recalculateIntra();
                }
                else if (sameSwap(nextDual, x)) {
                    recalculateDual();
                }
                performSwap(x);
                break;
            
            default:
                break;
        }
    }
}
    
