//
//  main.cpp
//  Chapter4-0
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

int main(int argc, const char * argv[]) {
    
    string name;
    double midterm, final;
    vector<double> homeworkList;
    typedef vector<double>::size_type vector_size;
    
    
    cout << "Please enter your student's name: ";
    cin >> name;
    cout << "Hello " << name << "!" << endl;
    cout << "Please enter your midterm and final grades: ";
    cin >> midterm >> final;
    cout << "Enter all your homework including EOF: ";

    read_hw(cin, homeworkList);
    try{
        double final_grade = grade(midterm, final, homeworkList);
        streamsize size = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(size) << endl;
    }
    catch(domain_error){
        cout<< "No HW entered"<< endl;
        
        return 1;
    }
    
    return 0;
}

