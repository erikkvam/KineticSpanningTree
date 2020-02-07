//
//  Event.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include "Certificate.cpp"
class Event {
public:
    float time;
    enum EventType {Addition, Deletion, CertificateFailure};
    EventType type;
    
    //If type = Addition, parameters = [u,v,a,b]
    //If type = Deletion, parameters = [u,v]
    //If type = CertFail, parameters = [u,v,x,y] and certificate = Certificate which fails
    Certificate certificate = Certificate(0, 0, 0, 0);
    int parameters[];
    
    static Event createAddition(float t, int u, int v, int a, int b);
    static Event createDeletion(const float t, const int& u, const int& v);
    static Event createCertificateFailure(const float t, const Certificate cert);
};

#endif /* Event_hpp */
