//
//  Certificate.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 29/01/20.
//  Copyright © 2020 Universitat Politècnica de Catalunya. All rights reserved.
//

#ifndef Certificate_hpp
#define Certificate_hpp

#include <stdio.h>
class Certificate {
public:
    int u, v, x, y; //The swap (u,v)<->(x,y) is positive, with (u,v) in the MST and (x,y) not in the MST
    //bool?
    
    Certificate(int uu, int vv, int xx, int yy);
};

#endif /* Certificate_hpp */
