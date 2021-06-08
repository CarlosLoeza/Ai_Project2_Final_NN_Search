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
    
    
    
    
    
    // place our data in vectors
    //test.Train(data_path);
    // normalize vectors and update our dataset to be normalized
    set = test.Normalize(set);
//    // test: check if normalized
    for (auto it: set[3])
        cout << it << endl;
    // test: subset
//    vector<vector<double>> subset = {test.set[3], test.set[6], test.set[9]};
//
//    val.Leave_One_Out(subset);
    
    double min_dist = 1;
    int index;
    double value;
    double temp_dist;
    int orig_cls;
    int cls;
    int correct =0;
    
    for(int i = 0; i < set[7].size()-1; i++){
        orig_cls = set[0][i];
        for(int j = 0; j < set[7].size()-1; j++){
            if(i != j){
                temp_dist = abs(set[7][i] - set[7][j]);
                if(temp_dist < min_dist){
                    min_dist = temp_dist;
                    index = j;
                    value = set[7][j];
                    cls = set[0][j];
                }
            }
        }
        
        if(orig_cls == cls)
            correct++;
        
        cout << "Orig index: " << i << endl;
        cout << "Orig value: " << set[7][i] << endl;
        cout << "Orig class: " << set[0][i] << endl;
        cout << "Min dist: " << min_dist << endl;
        cout << "Index: " << index << endl;
        cout << "Value: " << value << endl;
        cout << "Predicted class: " << cls << endl;
        cout << "---------------------" << endl;
        
   
        
        min_dist = 1;
        
    }
    
    cout << "Correct: " << correct;
    

    
    
    //vector<double> feat1 = test.feature1;

    
    
    
    //Thus, if feature_1 = [ N1, N2, N3, ..., Nn]
    //normalized_feature_1 = [(N1 - mean(feature_1) / std(feature_1), ..., (Nn - mean(feature_1) / std(feature_1)]

    // sum of the values squared. We will get the square root of the sum later in order to normalize vector
//    double sum_of_sqr_values = 0;
//    // holds the result once we square sum_of_sqr_values
//    double squared_sum_result;
//
//    for(auto it: feat1){
//        cout << it << endl;
//    }
//
//    cout << endl;
//
//    //get sum of square values
//    for (int i = 0; i< feat1.size(); i++){
//        sum_of_sqr_values += feat1[i]*feat1[i];
//    }
//
//    squared_sum_result = sqrt(sum_of_sqr_values);
//
//    // Normalize each value in vector and update
//    for(int i = 0; i < feat1.size(); i++){
//        feat1[i] = feat1[i] / squared_sum_result;
//    }
//
//    for(auto it: feat1){
//        cout << it << endl;
//    }
//
    // ---------------------------------------------
    
    
//    // test: print out features in the specific vector
//    for(auto it: feature1){
//        cout << it << endl;
//    }
    
//    double new_val;
//    double val = 2.61;
//    double euclid_distance =0;
//    double max = 100;
//    double dist = 100;
//    int cl;
//
//    vector<double> c =feature1;
//
//    for (int i = 0; i < c.size(); i++){
//
//        euclid_distance = sqrt(pow((c[i]-val), 2));
//        //cout << "------------------" << endl;
//        //cout << "Curr: " << c[i] << endl;
//        //cout << "Max: " << max << endl;
//        if(euclid_distance < dist){
//            dist = euclid_distance;
//            new_val = feature1[i];
//            cl = i;
//            //cout << "Feature: " << new_val << endl;
//
//        }
//    }
//    cout << "Original value: " << val << endl;
//    cout << "Value found: " << new_val << endl;
//    cout << "Index i: " << cl << endl;
//    cout << "Euclidean Distance: " << dist << endl;
//    cout << "Class: " << classification[cl] << endl;
    
    return 0;
}
