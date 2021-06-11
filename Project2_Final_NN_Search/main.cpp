#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>        // std::abs
#include <numeric>
#include "Classifier.hpp"
#include "Validator.hpp"

using namespace std;


int main(){
    
    Classifier test;
    Validator val;
    // path to our .txt file
    string data_path = "/Users/carlos/Downloads/Large-test-dataset.txt";
    vector<vector<double>> set; // dataset
    vector<double> temps;
    vector<vector<double>> columns;
    
    // create 41 empty temp variables to hold an instance from a feature column
    for(int i = 0; i < 41; i++){
        temps.push_back(-1);
    }
    // create 41 empty columns to hold each feature column from dataset
    for(int i =0; i<41; i++){
        columns.push_back({});
        
    }
    
    
    // Read the contents of our file
    ifstream inFile;
    inFile.open(data_path);
    // Read data until we reach the end
    while (inFile) {
        // assing feature instance to our temp variables
        for(int j = 0; j<temps.size(); j++){
            inFile >> temps[j];
        }
        // push instances to desired column. (ex: an instance from feature 1 will be pushed to column 1
        for(int j=0; j<temps.size(); j++){
            columns[j].push_back(temps[j]);
        }

    }
    // done reading .txt file
    inFile.close();
    
    // push our columns to our set which holds our the classification and feature vectors
    for(int j = 0; j<columns.size(); j++){
        set.push_back(columns[j]);
    }

    // test print
    for (auto it: set[3])
        cout << it << endl;
    cout << endl;
    

    // place our data in vectors
    //test.Train(data_path);
    // normalize vectors and update our dataset to be normalized
    set = test.Normalize(set);
    // test: check if normalized
    cout << endl;
    
    // test print
    for (auto it: set[3])
        cout << it << " - " << endl;
    // test: subset
    vector<int> subset = {1, 15, 27};

    double accuracy;
    
    accuracy = val.Leave_One_Out(subset, set);
    
    cout << "accuracy: " << accuracy/1000 << endl;

    // ---------------------------------------------
    

    
    return 0;
}
