//
//  main.cpp
//  Chapter3-0
//
//  Created by Andrew Meyers on 9/1/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    
    string name;
    int count = 0;
    double midterm, final, hw, hwTotal = 0;
    
    cout << "Please enter your student's name: ";
    cin >> name;
    cout << "Hello " << name << "!" << endl;
    cout << "Please enter your midterm and final grades: ";
    cin >> midterm >> final;
    cout << "Enter all your homework including EOF: ";
    
    while (cin >> hw){
        count++;
        hwTotal += hw;
    }
    
    streamsize prec = cout.precision();
    cout << endl << "Your final grade is: " << setprecision(3)
        << .2 * midterm + .4 * final + .4 * (hwTotal / count)
        << setprecision(prec) << endl;
    
    
    return 0;
}
