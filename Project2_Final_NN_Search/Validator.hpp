//
//  Validator.hpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza on 6/1/21.
//

#ifndef Validator_hpp
#define Validator_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Validator{
public:
    int Leave_One_Out(vector<int> subset, vector<vector<double>> set);
    
    
};
#endif /* Validator_hpp */
