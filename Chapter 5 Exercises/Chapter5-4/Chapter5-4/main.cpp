//
//  main.cpp
//  Chapter5-4
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include "permuted_index.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> lines;
    lines.push_back("the quick brown fox");
    lines.push_back("jumped over the fence");

    vector<string> str = get_permuted_index(lines);
    
    for (vector<string>::size_type i = 0; i < str.size(); i++) {
        cout<< str[i] << endl;
    }
    
    return 0;
}
