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

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    
    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const {return n; }
    bool valid() const { return !homework.empty();}
    bool did_all_hw() const;
    bool is_failing() const;
    
private:
    std::string n;
    double midterm;
    double final;
    std::vector<double> homework;
};


bool compare_student(const Student_info& s1, const Student_info& s2);
//std::istream& read_hw(std::istream& in, std::vector<double>& values);
#endif /* student_info_h */
