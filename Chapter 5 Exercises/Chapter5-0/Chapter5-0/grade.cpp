//
//  grade.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "student_info.h"
#include "median.h"

using namespace std;

double grade(double midterm, double final, double hw_median){
    return midterm * .2 + final * .4 + hw_median * .4;
}

double grade(double midterm, double final, const vector<double>& hw){
    if(hw.size() == 0){
        throw domain_error("NO HW Assignments");
    }
    
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& student){
    return grade(student.midterm, student.final, student.homework);
}

bool is_failing(const Student_info& student){
    return grade(student) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    while( i < students.size()){
        if(is_failing(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else {
            i++;
        }
    }
    
    return fail;
}