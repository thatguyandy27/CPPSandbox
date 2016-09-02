//
//  main.cpp
//  Chapter4-2
//
//  Created by Andrew Meyers on 9/1/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ios>
#include <stdexcept>

using namespace std;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

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

double median(vector<double> vec){
    
    typedef vector<double>::size_type vec_size;
    const vec_size size = vec.size();
    const vec_size half = size / 2;
    
    
    if(size == 0){
        throw domain_error("Median of empty vector");
    }
    
    sort(vec.begin(), vec.end());
    
    return size % 2 == 0 ? (vec[half] + vec[half - 1]) / 2 : vec[half];
    
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

bool compare_student(const Student_info& s1, const Student_info& s2){
    return s1.name < s2.name;
}

int main(int argc, const char * argv[]) {
    
    vector<Student_info> students;
    Student_info student;
    string::size_type max_length = 0;
    
    while(read(cin, student)){
        students.push_back(student);
        max_length = max(max_length, student.name.size());
    }
    
    sort(students.begin(), students.end(), compare_student);
    
    cout << endl;
    for(vector<Student_info>::size_type i = 0; i < students.size(); i++){
        try{
            
            double final_grade = grade(students[i]);
            streamsize size = cout.precision();
            cout << students[i].name << string(max_length + 1 - students[i].name.size(), ' ')
                <<  setprecision(3) << final_grade << setprecision(size);
        }
        catch(domain_error e){
            cout<< e.what();
        }
        
        cout<< endl;
    }
    
    return 0;
}

