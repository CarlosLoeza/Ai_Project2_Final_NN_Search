//
//  Validator.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza 
//

#include "Validator.hpp"
#include "Classifier.hpp"

    
double Validator::Leave_One_Out(vector<int> subset, vector<vector<double>> set){
    
    // correct class
    int orig_cls;
    // predicted class
    int predicted_class;
    // total correct predictions
    double correct_predictions = 0; // total # of predicted class == actual class
    // clock timer
    time_t clock_timer;
    // loov allows us to run Test from Class Classifier
    Classifier loov;
   
    // Start timer
    clock_timer = clock();

    // Loop through each train instance
    for(int j = 0; j<set[0].size()-1; j++){
        //cout << "Row: " << j << endl;
        predicted_class = loov.Test(j, set, subset);
        
        orig_cls = set[0][j];
        
        if(orig_cls == predicted_class){
            correct_predictions++;
        }
    }
    // Stop timer
    clock_timer = clock() - clock_timer;
   
    cout << "Total time: " <<  ((float)clock_timer)/CLOCKS_PER_SEC << " seconds" << endl;
    return correct_predictions;
}

