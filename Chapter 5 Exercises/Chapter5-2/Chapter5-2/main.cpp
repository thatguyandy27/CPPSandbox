//
//  main.cpp
//  Chapter5-2
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include "string_util.h"
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    string s;
    
    while(getline(cin, s)){
        vector<string> v = split(s);
        
        for(vector<string>::size_type i = 0; i != v.size(); i++){
            cout << v[i] << endl;
        }
    }
    
    return 0;
}
