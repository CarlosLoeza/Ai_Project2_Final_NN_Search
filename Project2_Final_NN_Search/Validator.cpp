//
//  Validator.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza 
//

#include "Validator.hpp"
#include "Classifier.hpp"

    
double Validator::Leave_One_Out(vector<int> subset, vector<vector<double>> set){
    

    int orig_cls;
    int predicted_class;
    double correct =0; // if correct == 1 match found
    double correct_predictions = 0; // total # of predicted class == actual class

    
    Classifier loov;
        
    int clock_start, clock_end;
    
    cout << "Start timer" << endl;
    clock_start = clock();

    for(int j = 0; j<set[0].size()-1; j++){
        //cout << "Row: " << j << endl;
        predicted_class = loov.Test(j, set, subset);
        
        orig_cls = set[0][j];
        if(orig_cls == predicted_class){
            correct++;
        }


//        cout << "Actual class: " << orig_cls << endl;
//        cout << "Predicted class: " << predicted_class << endl;

        if(correct == 1)
            correct_predictions++;


        correct =0;
        //cout << "-------------------" << endl;
    }
   
    cout << "End timer" << endl;
    clock_end = clock();
    
    cout << "Total time: " << clock_end - clock_start << endl; 
    
    return correct_predictions;
}

