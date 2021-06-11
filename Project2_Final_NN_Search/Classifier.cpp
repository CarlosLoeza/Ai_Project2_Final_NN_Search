//
//  Classifier.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza on 6/1/21.
//



#include "Classifier.hpp"


// Train() places our data in vectors (ex: column1, column2, etc.)

void Classifier::Train(vector<double> train_set){
}


vector<vector<double>> Classifier::Normalize(vector<vector<double>> set){
    
    // sum of the values squared. We will get the square root of the sum later in order to normalize vector
    double sum_of_values = 0;
    // holds current feature aka column
    vector<double> curr_feat;
    // (value-mean)^2
    double val_mean_sqr=0;
    double sqr_val;
    

    // Loop through each feature column
    for(int i = 1; i < set.size(); i++){
        // current feature column
        curr_feat = set[i];
        // compute value^2
        for(int j = 0; j < curr_feat.size()-1; j++){
            val_mean_sqr += curr_feat[j] * curr_feat[j];
        }
        // square (value^2)
        sqr_val = sqrt(val_mean_sqr);
        
        // replace old value with normalized value
        for(int j =0; j<curr_feat.size()-1; j++){
            curr_feat[j] = curr_feat[j]/sqr_val;
        }
        // replace original feature column with normalized version
        set[i] = curr_feat;
        // reset variables in order to reuse
        sum_of_values =0;
        val_mean_sqr = 0;
        curr_feat = {};
    }
    // return normalized feature set
    return set;
}


double Classifier::Test(int j, vector<vector<double>> set, vector<int> subset){
    
    // minimum distance between
    double min_dist =2;
    // holds the modified distance
    double temp_dist;
    // current distance
    double cur_dist = 0;
    // correct class
    int orig_cls;
    // predicted class
    int predicted_class;
    // feature we want to use (ex: feature = 1, implies use feature 1)
    int feature;
    
    // get correct class
    orig_cls = set[0][j];
    // cycle through each item in feature set
    for(int k = 0; k<set[0].size()-1; k++){
        // make sure test instance != train instance
        if(j != k){
            // get the subset
            for(int l = 0; l < subset.size(); l++){
                feature = subset[l];
                temp_dist = set[feature][j] - set[feature][k];
                temp_dist = (temp_dist*temp_dist);
                cur_dist += temp_dist;
            }
            cur_dist = sqrt(cur_dist);
            if(cur_dist < min_dist){
                predicted_class = set[0][k];
                min_dist = cur_dist;
            }
            cur_dist = 0; // reset for next iteration
        }
    }
    return predicted_class;
}
