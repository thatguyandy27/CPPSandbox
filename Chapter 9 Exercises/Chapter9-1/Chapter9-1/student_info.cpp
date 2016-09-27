//
//  student_info.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "grade.h"
#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

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


Student_info::Student_info(): midterm(0), final(0){}

Student_info::Student_info(istream& in) { read(in);}


bool Student_info::did_all_hw() const
{
    return find(homework.begin(), homework.end(), 0) == homework.end();
}

bool Student_info::is_failing() const {
    return grade() < 60;
}


istream& Student_info::read(istream& in){
    in >> n >> midterm >> final;
    read_hw(in, homework);
    
    return in;
}


double Student_info::grade() const{
    return ::grade(this -> midterm, this -> final, this -> homework);
}

bool compare_student(const Student_info& s1, const Student_info& s2){
    return s1.name() < s2.name();
}