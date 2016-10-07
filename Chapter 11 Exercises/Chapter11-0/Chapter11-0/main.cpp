//
//  main.cpp
//  Chapter11-0
//
//  Created by Andrew Meyers on 9/29/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include "vec.h"

int main(int argc, const char * argv[]) {
    
    Vec<double> vec;
    
    for(double i = 0; i < 1000; i++){
        vec.push_back(i);
    }
    
    for (Vec<double>::size_type size = 0; size < vec.size(); size++){
        std::cout<< vec[size] << std::endl;
    }
    
    
    Vec<double>::const_iterator it = vec.begin();
    
    std::cout<<"-----------using iterator----------" <<std::endl;
    
    while(it != vec.end()){
        std::cout<< *it << std::endl;
        it++;
    }
    
    return 0;
}
