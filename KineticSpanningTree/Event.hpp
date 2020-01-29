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
    const float time;
    enum EventType {Addition, Deletion, CertificateFailure};
    const EventType type;
    
    //If type = Addition, parameters = [u,v,a,b]
    //If type = Deletion, parameters = [u,v]
    //If type = CertFail, parameters = [Certificate]
    const int parameters[];
    
    Event createAddition(const float t, const int& u, const int& v, const int& a, const int& b);
    Event createDeletion(const float t, const int& u, const int& v);
    Event createCertificateFailure(const float t, const Certificate cert);
};

#endif /* Event_hpp */
