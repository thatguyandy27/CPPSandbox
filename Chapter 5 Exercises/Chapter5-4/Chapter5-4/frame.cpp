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
#include "string_util.h"

using namespace std;

vector<string> create_frame(const vector<string>& strings){
    vector<string> frame;
    string::size_type max_w = max_width(strings);
    string border(max_w + 4, '*');
    
    frame.push_back(border);
    
    for (vector<double>::size_type i = 0; i < strings.size(); i++) {
        frame.push_back("* " + strings[i] + string(max_w - strings[i].size(), ' ') + " *");
        
    }
    
    frame.push_back(border);
    
    return frame;
}

