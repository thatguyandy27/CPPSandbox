//
//  main.cpp
//  Chapter6-2
//
//  Created by Andrew Meyers on 9/9/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "string_util.h"


using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string s, s2;
    getline(cin, s);
    
    cout << "You Entered: " << s << endl;
    vector<string> str = split(s);
    
    cout << "Joined String: " << accumulate(str.begin(), str.end(), string("")) << endl;
    
    
    return 0;
}
