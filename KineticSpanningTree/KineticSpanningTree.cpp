//
//  KineticSpanningTree.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "KineticSpanningTree.hpp"

void KineticSpanningTree::addEdge(const int& u, const int& v, const int& a, const int& b){
    evaluate(Event::createAddition(t, u, v, a, b));
}

void KineticSpanningTree::deleteEdge(const int& u, const int& v){
    evaluate(Event::createDeletion(t, u, v));
}
void KineticSpanningTree::modifyEdge(const int& u, const int& v, const int& a, const int& b){
    evaluate(Event::createDeletion(t, u, v));
    evaluate(Event::createAddition(t, u, v, a, b));
}

void KineticSpanningTree::evaluate(const Event& event){
    switch (event.type) {
        case Event::Addition:
            updateStructuresOnAddition(event);
            break;
            
        case Event::Deletion:
            if (MST.inE(event.parameters[0],event.parameters[1])) {
                replaceWithBest(event.parameters[0],event.parameters[1]);
            }
            updateStructuresOnDeletion(event);
            break;
        
        case Event::CertificateFailure:
            updateStructuresOnFailure(event);
            break;


        default:
            break;
    }
}

void KineticSpanningTree::updateStructuresOnAddition(Event event){
    int u = event.parameters[0];
    int v = event.parameters[1];
    int a = event.parameters[2];
    int b = event.parameters[3];
    
    //Update the structures
    G.add(u, v, a, b);
    
    //Find and execute non-positive swaps
    Graph::swap bestSwap = G.findBestSwap();
    if (bestSwap.cost < 0) {
        performSwap(bestSwap);
    }
}

void KineticSpanningTree::updateStructuresOnDeletion(Event event){
    G.del(event.parameters[0], event.parameters[1]);
}

void KineticSpanningTree::updateStructuresOnFailure(Event event){
    Graph::swap s;
    s.u = event.parameters[0];
    s.v = event.parameters[1];
    s.x = event.parameters[2];
    s.y = event.parameters[3];
    
    s.cost = 0;
    
    performSwap(s);
}

void KineticSpanningTree::performSwap(Graph::swap s){
    pair<int,int> cost = G.getCostFunction(s.x,s.y);
    
    MST.del(s.u, s.v);
    MST.add(s.x, s.y, cost.first, cost.second);
}
