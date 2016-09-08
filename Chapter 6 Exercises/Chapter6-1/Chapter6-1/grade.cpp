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
#include <algorithm>
#include <numeric>

using namespace std;


bool did_all_hw(const Student_info& student){
    return find(student.homework.begin(), student.homework.end(), 0) == student.homework.end();
}

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

double average_grade(const Student_info& student){
    return grade(student.midterm, student.final, average(student.homework));
}

double grade_aux(const Student_info& student){
    try{
        return grade(student);
    }
    catch(domain_error){
        return grade(student.midterm, student.final, 0);
    }
}

double median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    
    return median(grades);
}


double average_analysis(const vector<Student_info>& students){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    
    return median(grades);
}

double optimistic_median(const Student_info& student){
    vector<double> nonzero;
    
    remove_copy(student.homework.begin(), student.homework.end(), back_inserter(nonzero), 0);
    
    if(nonzero.empty()){
        return grade(student.midterm, student.final, 0);
    }
    else {
        return grade(student.midterm, student.final, median(nonzero));
    }
}

double optimistic_median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    
    return median(grades);
}


