//
//  Validator.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza 
//

#include "Validator.hpp"
#include "Classifier.hpp"

    
int Validator::Leave_One_Out(vector<int> subset, vector<vector<double>> set){
    
    
    
    double min_dist =2;
    double min_dist5 =2;
    double min_dist7 = 2;
    double max_dist =-1;
    double max_dist5 = -1;
    double max_dist7 = -1;
    int index, index5, index7;
    double value, value5, value7;
    double temp_dist, temp_dist5, temp_dist7;
    int orig_cls;
    int cls, cls5, cls7;
    double correct =0;
    double ncorr = 0;
    

    
    
    //leave_one(use);
    
//    for(int i = 0; i < use.size(); i++){
    for(int j = 0; j<set[3].size()-1; j++){
        cout << "Row: " << j << endl;
        orig_cls = set[0][j]; // orig index class
        for(int k = 0; k<set[3].size()-1; k++){
            if(j != k){
//                // feat3
                temp_dist = set[3][j] - set[3][k];
                temp_dist = (temp_dist*temp_dist);
                // feat 5
                temp_dist5 = set[5][j] - set[5][k];
                temp_dist5 = (temp_dist5*temp_dist5);
                // feat 7
                temp_dist7 = set[7][j] - set[7][k];
                temp_dist7 = (temp_dist7 * temp_dist7);
                
                temp_dist = sqrt(temp_dist + temp_dist5 + temp_dist7);
                
                if(temp_dist < min_dist){
                    cls = set[0][k];
                    min_dist = temp_dist;
                }
//                if(temp_dist < min_dist){
//                    min_dist = temp_dist;
//                    index = k;
//                    value = set[3][k];
//                    cls = set[0][k];
//
//                }
//
//                if(temp_dist5 < min_dist5){
//                    min_dist5 = temp_dist5;
//                    index5 = k;
//                    value5 = set[5][k];
//                    cls5 = set[0][k];
//
//                }
//
//                if(temp_dist7 < min_dist7){
//                    min_dist7 = temp_dist7;
//                    index7 = k;
//                    value7 = set[7][k];
//                    cls7 = set[0][k];
//
//                }
                    
            }
            
        }
        if(orig_cls == cls){
            correct++;
            cout << "yes3" << endl;
        }
        
        

        
        
//        if(orig_cls == cls5){
//            correct++;
//            cout << "yes5" << endl;
//        }
//        if(orig_cls == cls7){
//            correct++;
//            cout << "yes7" << endl;
//        }


        cout << "cls: " << orig_cls << endl;
        cout << "prd cls: " << cls << endl;
        
        if(correct == 1)
            ncorr++;
        
        
        min_dist = 2;
        min_dist5= 2;
        min_dist7 = 2;
        max_dist = -2;
        max_dist5 = -2;
        max_dist7 = -2;
        correct =0;
        cout << "-------------------" << endl;
    }
   
    return ncorr;
    
//        # inputs: 1) feature_subset: this the subset of feature that you are working with, so it can be {3,6,9} meaning you are going to use feature 3, 6 and 9.
//        # outputs: 1) accuracy_score: the accuracy you got by using this feature_subset
//
//        # read all instance_IDs
//        # read all ground_truth_labels (column 1 in the .txt file provided)
//
//        # following would be a possible general structure of the loop to do the LOOV
//        correct_predictions_count = 0
//
   
    
    
    
    
    
    
    
    
    
    
    /*
    Classifier temp;
    double predict_label;
    int correct_predictions = 0;
//        # timer start
//        print("Starting validation...")
//        start = datetime.datetime.now()
//
    double test_instance;
    vector<double> train_instance;
    
    
    int index;
    double value;
    double min_distance = 1; // set min_distance to max. It's 1 since normalized is 0-1.
    double tmp_distance;
    
    vector<double> feature_col;
    
//        for instance_ID in instance_IDs {
    for(int i = 0; i<subset.size(); i++){
        
        train_instance = subset[i];
        for(int j = 0; j<subset[i].size(); j++){
            test_instance = j;
            predict_label = temp.Test(j);
            temp.Train(subset[i]);
//            // if not the same row
//            if(i != j){
//                tmp_distance = test_instance[i] - train_instance[j];
//                if(tmp_distance < min_distance){
//                    min_distance = tmp_distance;
//                    index = j;
//                    value = train_instance[j];
//                }
//            }
        }
        
    }
//            # set test_instance_ID = instance_ID
//            # therefore train_instances = all other instances excluding test_instance
//            # call Classifier.Test() and pass this test_instance_ID to it. It returns predicted_label.
//            # if predicted_label for this test_instance matches ground_truth_label for this instance, correct_predictions_count = correct_predictions_count + 1
//        }
//        # timer stop
//        print("Time taken for validation = {}".format(datetime.datetime.now() - start))
//
//        accuracy_score  = correct_predictions_count / total number of instances
//        print("Using features {}, the accuracy is {}".format(feature_subset, accuracy_score))
//        return accuracy_score
//    }
     
     */
}

