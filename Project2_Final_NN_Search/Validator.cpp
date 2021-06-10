//
//  Validator.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza 
//

#include "Validator.hpp"
#include "Classifier.hpp"

    
double Validator::Leave_One_Out(vector<int> subset, vector<vector<double>> set){
    
        
    double min_dist =2;
    double temp_dist;
    int orig_cls;
    int cls;
    double correct =0; // if correct == 1 match found
    double total_correct = 0; // total # of predicted class == actual class
    double cur_dist = 0;
        


    for(int j = 0; j<set[3].size()-1; j++){
        cout << "Row: " << j << endl;
        orig_cls = set[0][j]; // orig index class
        for(int k = 0; k<set[3].size()-1; k++){
            if(j != k){

                for(int l = 0; l < subset.size(); l++){

                    int feat = subset[l];

                    // feat3
                    temp_dist = set[feat][j] - set[feat][k];
                    temp_dist = (temp_dist*temp_dist);
                    cur_dist += temp_dist;
                }
                cur_dist = sqrt(cur_dist);
                if(cur_dist < min_dist){
                    cls = set[0][k];
                    min_dist = cur_dist;
                }
                cur_dist = 0; // reset for next iteration
            }
        }


        if(orig_cls == cls){
            correct++;
        }


        cout << "Actual class: " << orig_cls << endl;
        cout << "Predicted class: " << cls << endl;

        if(correct == 1)
            total_correct++;

        // reset for next iteration
        min_dist = 2;
        correct =0;
        cout << "-------------------" << endl;
    }
   
    return total_correct;
}

