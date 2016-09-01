//
//  main.cpp
//  Chapter3-1
//
//  Created by Andrew Meyers on 9/1/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    
    string name;
    double midterm, final, hw, hwMedian;
    vector<double> homeworkList;
    typedef vector<double>::size_type vector_size;

    
    cout << "Please enter your student's name: ";
    cin >> name;
    cout << "Hello " << name << "!" << endl;
    cout << "Please enter your midterm and final grades: ";
    cin >> midterm >> final;
    cout << "Enter all your homework including EOF: ";
    
    while (cin >> hw){
        homeworkList.push_back(hw);
    }
    vector_size size = homeworkList.size();
    
    if (size == 0){
        cout << "No HW entered.  Please try again" << endl;
        return 1;
    }
    sort(homeworkList.begin(), homeworkList.end());
    vector_size mid = size / 2;
    
    hwMedian = size % 2 == 0 ? (homeworkList[mid - 1] + homeworkList[mid]) / 2 : homeworkList[mid];
    
    streamsize prec = cout.precision();
    cout << endl << "Your final grade is: " << setprecision(3)
        << .2 * midterm + .4 * final + .4 * hwMedian
        << setprecision(prec) << endl;
    
    
    return 0;
}
