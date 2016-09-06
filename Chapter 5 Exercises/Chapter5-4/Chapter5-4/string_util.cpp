//
//  string_util.cpp
//  Chapter5-2
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "string_util.h"
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> split(const string& str){
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0, str_len = str.size();
    
    while (i != str_len){
        
        while(i != str_len && isspace(str[i])){
            i++;
        }
        
        string_size end_index = i;
        
        while(end_index != str_len && !isspace(str[end_index])){
            end_index++;
        }
        
        if(end_index != i){
            ret.push_back(str.substr(i, end_index - i));
            i = end_index;
        }
    }
    
    
    return ret;
}

string::size_type max_width(const vector<string>& v){
    string::size_type max_size = 0;
    
    for (vector<string>::size_type i = 0; i < v.size(); i++) {
        max_size = max(max_size, v[i].size());
    }
    
    return max_size;
}
