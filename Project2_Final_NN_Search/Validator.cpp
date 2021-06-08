//
//  Validator.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza 
//

#include "Validator.hpp"
#include "Classifier.hpp"

    
void Validator::Leave_One_Out(vector<vector<double>> subset){
    
//        # inputs: 1) feature_subset: this the subset of feature that you are working with, so it can be {3,6,9} meaning you are going to use feature 3, 6 and 9.
//        # outputs: 1) accuracy_score: the accuracy you got by using this feature_subset
//
//        # read all instance_IDs
//        # read all ground_truth_labels (column 1 in the .txt file provided)
//
//        # following would be a possible general structure of the loop to do the LOOV
//        correct_predictions_count = 0
//
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
}

