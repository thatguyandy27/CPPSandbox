//
//  frame.cpp
//  Chapter5-3
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "frame.h"

#include <vector>
#include <string>
#include <utility>

using namespace std;

string::size_type width(const vector<string>& v){
    string::size_type max_size = 0;
    
    for (vector<string>::size_type i = 0; i < v.size(); i++) {
        max_size = max(max_size, v[i].size());
    }
    
    return max_size;
}

vector<string> create_frame(const vector<string>& strings){
    vector<string> frame;
    string::size_type max_width = width(strings);
    string border(max_width + 4, '*');
    
    frame.push_back(border);
    
    for (vector<double>::size_type i = 0; i < strings.size(); i++) {
        frame.push_back("* " + strings[i] + string(max_width - strings[i].size(), ' ') + " *");
        
    }
    
    frame.push_back(border);
    
    return frame;
}

