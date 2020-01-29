////
////  KineticSpanningTree.cpp
////  KineticSpanningTree
////
////  Created by Erik A. Kvam Garí on 7/11/19.
////  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
////
//
//#include "KineticSpanningTree.hpp"
//#include <string>
//#include <iostream>
//using namespace std;
//
//KineticSpanningTree::KineticSpanningTree(string name){
//    if (name == "example") {
//        t = 0;
//        vertices.clear();
//        edges.clear();
//        MSTedges.clear();
//        clusters.clear();
//    }
//    else {
//        t = 0;
//        vertices.clear();
//        edges.clear();
//        MSTedges.clear();
//        clusters.clear();
//    }
//    transformGraph();
//    recalculateIntra();
//    recalculateInter();
//    recalculateDual();
//}
//
//void KineticSpanningTree::print(){
//    cout << "Printing a Kinetic Spanning Tree" << endl;
//    
//    cout << "At time " << t << ", the tree looks like:" << endl;
//    //kineticGraph.print();
//    
//    cout << endl << endl;
//    
//    cout << "At time " << t << ", the MST looks like:" << endl;
//    //MST.print();
//}
//
//void KineticSpanningTree::advanceTimeUntil(float timeLimit){
//    while (t < timeLimit) {
//        event x = events.top();
//        events.pop();
//        t = x.time;
//        
//        switch (x.type) {
//            case EdgeAddition:
//                addEdge(x.v, x.w, x.a, x.b);
////                findAndPerformNonPositiveSwaps();
//                break;
//                
//            case VertexAddition:
//                addVertex(x.v);
//                break;
//                
//            case EdgeDeletion:
//                deleteEdge(x.v, x.w);
////                if (inTheMST(x.v, x.w)) {
////                    edge bestEdge;
////                    for (vector<vector<int>> connectionsOfACluster : edgesBetweenClusters) {
////                        for (vector<int> connectionsBetweenTwoClusters : connectionsOfACluster) {
////                            edge bestOfCluster = findBestReplacementEdgeFor(x.v, x.w, connectionsBetweenTwoClusters);
////                            if ((bestOfCluster.a+bestOfCluster.b*t) > (bestEdge.a+bestEdge.b*t)) {
////                                bestEdge = bestOfCluster;
////                            }
////                        }
////                    }
////                    performSwap(x.v, x.w, bestEdge);
////                }
//                break;
//                
//            case VertexDeletion:
//                for (edge e : findEdgesThatComeFrom(x.v)) {
//                    deleteEdge(e);
//                }
//                deleteVertex(x.v);
//                break;
//                
//            case EdgeWeightUpdate:
//                deleteEdge(x.v, x.w);
//                addEdge(x.v, x.w, x.a, x.b);
//                break;
//                
//            case MSTSwap:
//                if (sameSwap(nextInter, x)) {
//                    recalculateInter();
//                }
//                else if (sameSwap(nextIntra, x)) {
//                    recalculateIntra();
//                }
//                else if (sameSwap(nextDual, x)) {
//                    recalculateDual();
//                }
//                performSwap(x);
//                break;
//            
//            default:
//                break;
//        }
//    }
//}
//    
//const bool KineticSpanningTree::sameSwap(const swap& s, const event& e){
//    return e.type == MSTSwap and e.v == s.v and e.w == s.w and e.a == s.x and e.b == s.y;
//}
//
//void KineticSpanningTree::deleteEdge(const edge &e){
//    //Delete From MST
//    //Delete from graph
//}
//
//void KineticSpanningTree::deleteEdge(const int &v, const int &w){
//    edge e;
//    e.v = v;
//    e.w = w;
//    
//    deleteEdge(e);
//}
//
//void KineticSpanningTree::performSwap(const swap &s){
//    //perform the swap
//}
//
//void KineticSpanningTree::performSwap(const event &e){
//    swap s;
//    s.v = e.v;
//    s.w = e.w;
//    s.x = e.a;
//    s.y = e.b;
//    
//    
//    for (edge f : edges) {
//        if (f.v == e.v and f.w == e.w) {
//            s.a = f.a;
//            s.b = f.b;
//        }
//    }
//    
//    performSwap(s);
//}
//
//void KineticSpanningTree::deleteVertex(const int &id){
//    for (edge e : edges) {
//        if(e.v == id or e.w == id) deleteEdge(e);
//    }
//    //recalculate all needed structures
//    vertex v;
//    v.id = id;
//    vector<vertex>::iterator it = vertices.begin();
//    for (int i = 0; i < id; i++) it++;
//    vertices.erase(it);
//}
//
//vector<KineticSpanningTree::edge> KineticSpanningTree::findEdgesThatComeFrom(const int &v){
//    vector<edge> adjacent = vector<edge>(0);
//    for(edge e : edges){
//        if(e.v == v || e.w == v) adjacent.push_back(e);
//    }
//    return adjacent;
//}
