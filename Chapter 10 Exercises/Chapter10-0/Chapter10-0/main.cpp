//
//  main.cpp
//  Chapter10-0
//
//  Created by Andrew Meyers on 9/27/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int x = 5;
    int *p = &x;
    
    std::cout << "x = " << x << std::endl;
    
    *p = 10;
    
    std::cout << "x = " << x << std::endl;
    

    return 0;
}
