//
//  student_info.h
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef student_info_h
#define student_info_h

#include <vector>
#include <string>
#include <iostream>
#include "grade.h"

struct Student_info {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
    
    std::istream& read(std::istream&);
    double grade() const;
};
bool compare_student(const Student_info& s1, const Student_info& s2);
std::istream& read_hw(std::istream& in, std::vector<double>& values);
#endif /* student_info_h */
