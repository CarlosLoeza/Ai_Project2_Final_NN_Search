//
//  Classifier.cpp
//  Project2_Final_NN_Search
//
//  Created by Carlos Loeza on 6/1/21.
//



#include "Classifier.hpp"


// Train() places our data in vectors (ex: column1, column2, etc.)

void Classifier::Train(vector<double> train_set){

//    // temp variables for each column(feature column) so we can push it to the desired vector
//    // ex: t_feature1 will be pushed to feature1
//    double t_classification, t_feature1, t_feature2, t_feature3, t_feature4, t_feature5, t_feature6, t_feature7, t_feature8, t_feature9, t_feature10;
//
//
//    // Read the contents of our file
//    ifstream inFile;
//    inFile.open(data_path);
//    // Read data until we reach the end
//    while (inFile) {
//        // assing values to our temp variables
//        inFile >> t_classification >> t_feature1 >> t_feature2 >> t_feature3 >> t_feature4 >> t_feature5 >> t_feature6 >> t_feature7 >> t_feature8 >> t_feature9 >> t_feature10;
//        // push temp values to the desired vector
//        classification.push_back(t_classification);
//        feature1.push_back(t_feature1);
//        feature2.push_back(t_feature2);
//        feature3.push_back(t_feature3);
//        feature4.push_back(t_feature4);
//        feature5.push_back(t_feature5);
//        feature6.push_back(t_feature6);
//        feature7.push_back(t_feature7);
//        feature8.push_back(t_feature8);
//        feature9.push_back(t_feature9);
//        feature10.push_back(t_feature10);
//    }
//    // done reading .txt file
//    inFile.close();
//
//    set.push_back(classification);
//    set.push_back(feature1);
//    set.push_back(feature2);
//    set.push_back(feature3);
//    set.push_back(feature4);
//    set.push_back(feature5);
//    set.push_back(feature6);
//    set.push_back(feature7);
//    set.push_back(feature8);
//    set.push_back(feature9);
//    set.push_back(feature10);

}


vector<vector<double>> Classifier::Normalize(vector<vector<double>> set){
    
    // sum of the values squared. We will get the square root of the sum later in order to normalize vector
    double sum_of_values = 0;
    // holds the result once we square sum_of_sqr_values
    double squared_sum_result;
    // holds current feature aka column
    vector<double> curr_feat;
    // hold mean
    double mean;
    // (value-mean)^2
    double val_mean_sqr=0;
    double sqr_val;
    double std;
    
    double min = 2;
    double max = -1;
    
    
    for(int i = 1; i < set.size(); i++){
        // current feature column
        curr_feat = set[i];
        

        for(int j = 0; j < curr_feat.size()-1; j++){
            val_mean_sqr += curr_feat[j] * curr_feat[j];
        }

        sqr_val = sqrt(val_mean_sqr);
        
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
    return set;
}


double Classifier::Test(int j){
    
    
    return 0;
}
