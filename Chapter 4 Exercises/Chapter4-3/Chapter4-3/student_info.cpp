//
//  student_info.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

istream& read_hw(istream& in, vector<double>& values){
    
    if (in){
        values.clear();
        double val;
        while(in >> val){
            values.push_back(val);
        }
        in.clear();
        
    }
    
    return in;
}

istream& read(istream& in, Student_info& student){
    in >> student.name >> student.midterm >> student.final;
    read_hw(in, student.homework);
    
    return in;
}

bool compare_student(const Student_info& s1, const Student_info& s2){
    return s1.name < s2.name;
}