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
    
    // vector to hold each column in our .txt file
    vector<double> classification, feature1, feature2, feature3, feature4, feature5, feature6, feature7, feature8, feature9, feature10;
    // vector containing our columns
    vector<vector<double>> set;
    
    // Train(): places the column features in vectors
    // data_path: path to our .txt file in our computer
    void Train(vector<double> train_set);
    
    vector<vector<double>> Normalize(vector<vector<double>> set);
    
    double Test(int i);
    
    
};

#endif /* Classifier_hpp */
