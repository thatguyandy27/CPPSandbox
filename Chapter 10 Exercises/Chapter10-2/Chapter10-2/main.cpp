//
//  main.cpp
//  Chapter10-2
//
//  Created by Andrew Meyers on 9/27/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include "letter_grade.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    double grade;

    std::cout << "Enter your numeric grade: ";
    
    std::cin >> grade;
    
    std::cout << "Your letter grade is : " << letter_grade(grade) << std::endl;
    
    return 0;
}
