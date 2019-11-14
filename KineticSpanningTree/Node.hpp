//
//  Node.hpp
//  KineticSpanningTree
//
//  Created by Erik A. Kvam Garí on 7/11/19.
//  Copyright © 2019 Universitat Politècnica de Catalunya. All rights reserved.
//

#include <string>
using namespace std;

#ifndef Node_hpp
#define Node_hpp

class Node {
private:
    string label;
    
public:
    Node(string label){
        this->label = label;
    }
};
#endif /* Node_hpp */
