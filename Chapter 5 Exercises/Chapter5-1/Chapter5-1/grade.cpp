//
//  grade.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <stdexcept>
#include <vector>
#include <list>
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

list<Student_info> extract_fails(list<Student_info>& students){
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while( iter != students.end()){
        if(is_failing(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            iter++;
        }
    }
    
    return fail;
}