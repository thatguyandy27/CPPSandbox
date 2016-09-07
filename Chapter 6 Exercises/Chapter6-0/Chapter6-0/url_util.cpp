//
//  url_util.cpp
//  Chapter6-0
//
//  Created by Andrew Meyers on 9/7/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "url_util.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
typedef string::const_iterator iter;

bool not_url_char(char c){
    static const string url_chars = "~;/?:@=&$-_.+~*'";
    
    return !(isalnum(c) || find(url_chars.begin(), url_chars.end(), c) != url_chars.end());
}


iter url_begin(const iter strB, const iter strE ){
    static const string sep = "://";
    
    iter i = strB;
    
    while((i = search(i, strE, sep.begin(), sep.end())) != strE ){
        if(i != strB && i + sep.size() != strE){
            iter beg = i;
            while (beg != strB && isalnum(beg[-1])){
                beg--;
            }
            
            if(beg != i && !not_url_char(i[sep.size()])){
               return beg;
            }
        }
        
        i += sep.size();
               
    }
    return strE;
}

iter url_end(const iter s_beg, const iter s_end){
    return find_if(s_beg, s_end, not_url_char);
}


vector<string> find_urls(const string& s){
    vector<string> ret;
    iter begin =s.begin(), end = s.end();
    
    while(begin != end){
        begin = url_begin(begin, end);
        
        if(begin != end){
            iter after = url_end(begin, end);
            
            ret.push_back(string(begin, after));
            begin = after;
        }
    }
    
    return ret;
}