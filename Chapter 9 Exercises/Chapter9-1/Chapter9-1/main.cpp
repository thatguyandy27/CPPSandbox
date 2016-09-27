//
//  main.cpp
//  Chapter9-1
//
//  Created by Andrew Meyers on 9/26/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include "student_info.h"
#include "grade.h"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    sort(students.begin(), students.end(), compare_student);
    
    for(vector<Student_info>::size_type i = 0; i < students.size(); i++){
        cout << students[i].name() << string(maxlen + 1  - students[i].name().size(), ' ');
        
        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
            
        }
        catch(domain_error e){
            cout << e.what() << endl;
        }
    }
    
    return 0;
}
