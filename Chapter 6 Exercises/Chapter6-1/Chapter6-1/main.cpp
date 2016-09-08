//
//  main.cpp
//  Chapter6-1
//
//  Created by Andrew Meyers on 9/7/16.
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

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>& info),
                    const vector<Student_info>& did, const vector<Student_info>& did_not){
    out << name << " : median -> did =  " << analysis(did) << ", median -> didn't = " << analysis(did_not) << endl;
}

int main(int argc, const char * argv[]) {
    
    vector<Student_info> did_hw, no_hw;
    Student_info student;
    
    while(read(cin, student)){
        if (did_all_hw(student)){
            did_hw.push_back(student);
        }
        else{
            no_hw.push_back(student);
        }
    }
    
    if(did_hw.empty()){
        cout<< "NO ONE DID ALL THEIR HW!!!!1"<< endl;
        return 1;
    }
    if(no_hw.empty()){
        cout<< "Everyone did their hw :). " <<endl;
        return 1;
    }
    
    write_analysis(cout, "median", median_analysis, did_hw, no_hw);
    write_analysis(cout, "average", average_analysis, did_hw, no_hw);
    write_analysis(cout, "optimistic median", optimistic_median_analysis, did_hw, no_hw);
    
    return 0;
}


