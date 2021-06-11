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



//// vector containing our columns
//vector<vector<double>> set;

class Classifier{
 
public:
    // Train() places our data in vectors (ex: column1, column2, etc.)
    

    
    vector<vector<double>> Normalize(vector<vector<double>> set);
    
    // Train(): places the column features in vectors
    // data_path: path to our .txt file in our computer
    void Train(vector<double> train_set);
    
   
    double Test(int i, vector<vector<double>> set, vector<int> subset);
    
    
};

#endif /* Classifier_hpp */
