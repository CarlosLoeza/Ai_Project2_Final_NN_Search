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
    string data_path = "/Users/carlos/Downloads/cs_170_small80.txt";
    vector<vector<double>> set; // dataset
    
    // temp variables for each column(feature column) so we can push it to the desired vector
    // ex: t_feature1 will be pushed to feature1
    double t_classification, t_feature1, t_feature2, t_feature3, t_feature4, t_feature5, t_feature6, t_feature7, t_feature8, t_feature9, t_feature10;
    
    
    vector<double> classification, feature1, feature2, feature3, feature4, feature5, feature6, feature7, feature8, feature9, feature10;
    
    // Read the contents of our file
    ifstream inFile;
    inFile.open(data_path);
    // Read data until we reach the end
    while (inFile) {
        // assing values to our temp variables
        inFile >> t_classification >> t_feature1 >> t_feature2 >> t_feature3 >> t_feature4 >> t_feature5 >> t_feature6 >> t_feature7 >> t_feature8 >> t_feature9 >> t_feature10;
        // push temp values to the desired vector
        classification.push_back(t_classification);
        feature1.push_back(t_feature1);
        feature2.push_back(t_feature2);
        feature3.push_back(t_feature3);
        feature4.push_back(t_feature4);
        feature5.push_back(t_feature5);
        feature6.push_back(t_feature6);
        feature7.push_back(t_feature7);
        feature8.push_back(t_feature8);
        feature9.push_back(t_feature9);
        feature10.push_back(t_feature10);
    }
    // done reading .txt file
    inFile.close();
    
    set.push_back(classification);
    set.push_back(feature1);
    set.push_back(feature2);
    set.push_back(feature3);
    set.push_back(feature4);
    set.push_back(feature5);
    set.push_back(feature6);
    set.push_back(feature7);
    set.push_back(feature8);
    set.push_back(feature9);
    set.push_back(feature10);
    
    
    for (auto it: set[3])
        cout << it << endl;
    cout << endl;
    

    // place our data in vectors
    //test.Train(data_path);
    // normalize vectors and update our dataset to be normalized
    set = test.Normalize(set);
    // test: check if normalized
    cout << endl;
    
    for (auto it: set[3])
        cout << it << " - " << endl;
    // test: subset
    vector<int> subset = {3, 5, 7};

    double accuracy;
    
    accuracy = val.Leave_One_Out(subset, set);
    
    cout << "accuracy: " << accuracy << endl;

    // ---------------------------------------------
    

    
    return 0;
}
