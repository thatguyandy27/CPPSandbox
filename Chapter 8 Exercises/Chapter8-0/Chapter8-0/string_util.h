//
//  string_util.h
//  Chapter5-2
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef string_util_h
#define string_util_h

#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

template <class Out>
void split(const std::string& str, Out os){
    
    typedef std::string::const_iterator iter;
    
    iter i = str.begin();
    while (i != str.end()){
        
        i = find_if(i, str.end(), not_space);
        
        iter j = find_if(i, str.end(), space);
        
        if(i != str.end()){
            *os++ = std::string(i, j);
        }
        
        i = j;
        
    }
    
}


#endif /* string_util_hpp */