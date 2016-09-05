//
//  main.cpp
//  Chapter5-0
//
//  Created by Andrew Meyers on 9/4/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <ios>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    list<Student_info> students, failing_students;
    Student_info student;
    string::size_type max_length = 0;
    
    while(read(cin, student)){
        students.push_back(student);
        max_length = max(max_length, student.name.size());
    }
    
    students.sort(compare_student);
    
    cout << endl;
    failing_students = extract_fails(students);
    
    cout<< "-----Passing Students-----" << endl;
    
    list<Student_info>::const_iterator iter = students.begin();
    list<Student_info>::const_iterator end = students.end();
    while(iter != end){
        try{
            
            double final_grade = grade(*iter);
            streamsize size = cout.precision();
            cout << iter -> name << string(max_length + 1 - iter -> name.size(), ' ')
            <<  setprecision(3) << final_grade << setprecision(size);
        }
        catch(domain_error e){
            cout<< e.what();
        }
        
        iter++;
        cout<< endl;
    }
    
    cout<< "-----Failing Students-----" << endl;
    
    iter = failing_students.begin();
    end = failing_students.end();

    
    while(iter != end){
        try{
            
            double final_grade = grade(*iter);
            streamsize size = cout.precision();
            cout << iter -> name << string(max_length + 1 - iter -> name.size(), ' ')
            <<  setprecision(3) << final_grade << setprecision(size);
        }
        catch(domain_error e){
            cout<< e.what();
        }
        iter ++;
        cout<< endl;
    }

    
    return 0;
}
