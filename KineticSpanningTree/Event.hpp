//
//  Event.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 28/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp
#include "Certificate.cpp"

class Event {
    enum eventType {swap};
    Certificate c;
    double t;
};
#endif /* Event_hpp */
