//
//  Event.cpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#include "Event.hpp"
class Event {
public: float time;
    enum EventType {Addition, Deletion, CertificateFailure};
    EventType type;
    
    //If type = Addition, parameters = [u,v,a,b]
    //If type = Deletion, parameters = [u,v]
    //If type = CertFail, parameters = [Certificate]
    int parameters[];
    
    Event(EventType eventType, float t);
};
