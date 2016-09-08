//
//  median.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "median.h"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>

using namespace std;

double median(vector<double> vec){
    
    typedef vector<double>::size_type vec_size;
    const vec_size size = vec.size();
    const vec_size half = size / 2;
    
    
    if(size == 0){
        throw domain_error("Median of empty vector");
    }
    
    sort(vec.begin(), vec.end());
    
    return size % 2 == 0 ? (vec[half] + vec[half - 1]) / 2 : vec[half];
    
}

double average(vector<double> vec){
    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}