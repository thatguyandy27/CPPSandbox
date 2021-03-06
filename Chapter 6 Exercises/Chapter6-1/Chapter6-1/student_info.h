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

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};
bool compare_student(const Student_info& s1, const Student_info& s2);
std::istream& read(std::istream& in, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& values);
#endif /* student_info_h */
