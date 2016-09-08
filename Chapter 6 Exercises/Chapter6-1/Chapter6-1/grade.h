//
//  grade.h
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef grade_h
#define grade_h

#include <vector>
#include <list>
#include "student_info.h"

bool did_all_hw(const Student_info& student);
double grade(double midterm, double final, double hw_median);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& student);
bool is_failing(const Student_info& student);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
double median_analysis(const std::vector<Student_info>& students);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median_analysis(const std::vector<Student_info>& students);


#endif /* grade_hpp */
