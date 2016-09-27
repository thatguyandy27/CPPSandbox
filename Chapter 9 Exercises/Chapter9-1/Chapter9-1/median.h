//
//  median.h
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef median_h
#define median_h

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>


template<class T>
T median(std::vector<T> vec){
    typedef typename std::vector<T>::size_type vec_size;
    const vec_size size = vec.size();
    const vec_size half = size / 2;
    
    
    if(size == 0){
        throw std::domain_error("Median of empty vector");
    }
    
    sort(vec.begin(), vec.end());
    
    return size % 2 == 0 ? (vec[half] + vec[half - 1]) / 2 : vec[half];
    
}

template<class T>
T average(std::vector<T> vec){
    return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

#endif /* median_hpp */
