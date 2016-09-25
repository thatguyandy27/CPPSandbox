//
//  main.cpp
//  Chapter8-0
//
//  Created by Andrew Meyers on 9/21/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include "median.h"
#include "string_util.h"
#include <sstream>
#include <fstream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    cout<< "Please enter a line to split" << endl;
    
    string s;
    ostream_iterator<string> o = ostream_iterator<string>(cout, "\n");
    
    while (getline(cin, s)){
        split(s, o);
    }
    
    vector<double> list;
    double val;
    
    while(cin >> val){
        list.push_back(val);
    }
    
    cout<< "Enter some numbers" << endl;
    
    
    vector<double>::iterator found = find(list.begin(), list.end(), 10);
    if(found == list.end()){
        cout << "10 not found in list" << endl;
    }
    else {
        cout << "Found the number 10" << endl;
    }
    
    reverse(list.begin(), list.end());
    
    for(vector<double>::iterator i = list.begin(); i < list.end(); i++){
        cout << *i <<endl;
    }

    
    return 0;
}
