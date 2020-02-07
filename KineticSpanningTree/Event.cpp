//
//  Event.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Event.hpp"

Event Event::createAddition(float t, int u, int v, int a, int b){
    Event returnable;
    returnable.time = t;
    returnable.type = Addition;
    returnable.parameters[0] = u;
    returnable.parameters[1] = v;
    returnable.parameters[2] = a;
    returnable.parameters[3] = b;
    return returnable;
}

Event Event::createDeletion(const float t, const int& u, const int& v){
    Event returnable = Event();
    returnable.time = t;
    returnable.type = Addition;
    returnable.parameters[0] = u;
    returnable.parameters[1] = v;
    return returnable;
}

Event Event::createCertificateFailure(const float t, const Certificate cert){
    Event returnable;
    returnable.time = t;
    returnable.type = Addition;
    returnable.certificate = cert;
    return returnable;
}
