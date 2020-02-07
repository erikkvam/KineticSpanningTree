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
            updateStructuresOnDeletion(event);
            if (MST.inE(event.parameters[0],event.parameters[1])) {
                replaceWithBest(event.parameters[0],event.parameters[1]);
            }
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
        G.performSwap(bestSwap);
    }
}
