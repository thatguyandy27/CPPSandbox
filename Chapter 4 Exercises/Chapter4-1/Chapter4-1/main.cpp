//
//  main.cpp
//  Chapter4-1
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <iomanip>

int getMaxDisplayWidth(int maxNum){
    int displayWidth = 0;
    
    while (maxNum > 0){
        maxNum /= 10;
        displayWidth++;
    }
    
    return displayWidth;
}

int main(int argc, const char * argv[]) {
    
    const int MAX_NUM = 100;
    const int display_width = getMaxDisplayWidth(MAX_NUM);
    const int display_answer = getMaxDisplayWidth(MAX_NUM * MAX_NUM) + 1;
    
    for (int i = 0; i <= MAX_NUM; i++) {
        std::cout<< std::setw(display_width) << i << std::setw(display_answer) << i * i << std::endl;
    }
    
    return 0;
}

