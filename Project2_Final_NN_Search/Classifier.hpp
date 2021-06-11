//
//  Classifier.hpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza on 6/1/21.
//

#ifndef Classifier_hpp
#define Classifier_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>        // std::abs


using namespace std;


class Classifier{
 
public:
    // Train() places our data in vectors (ex: column1, column2, etc.)
    // set: vector containing all of our features
    vector<vector<double>> Normalize(vector<vector<double>> set);
    
    // Train(): places the column features in vectors
    // data_path: path to our .txt file in our computer
    void Train(vector<double> train_set);
    
    // Test: predicts what class instance i belongs to
    // int i: test instance
    // set: vector containing all of our features
    // subset: subset containing features we will use in our test
    double Test(int i, vector<vector<double>> set, vector<int> subset);
    
    
};

#endif /* Classifier_hpp */
