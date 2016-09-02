//
//  main.cpp
//  Chapter4-3
//
//  Created by Andrew Meyers on 9/2/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//


#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ios>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"

using namespace std;

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
