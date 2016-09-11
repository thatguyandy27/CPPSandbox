//
//  nrand.cpp
//  Chapter7-2
//
//  Created by Andrew Meyers on 9/10/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "nrand.h"
#include <cstdlib>
#include <stdexcept>

using namespace std;

int nrand(int n){
    
    if( n <= 0 || n > RAND_MAX){
        throw domain_error("Argument to nrand is out of range");
    }
    const int bucket_size =  RAND_MAX / n;
    
    int r;
    
    do r = rand() / bucket_size;
    while ( r >= n);
    
    return r;
}