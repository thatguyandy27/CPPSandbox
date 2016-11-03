//
//  Str.cpp
//  Chapter12-0
//
//  Created by Andrew Meyers on 10/7/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "Str.h"
#include <iostream>
#include <cctype>

using namespace std;


istream& operator >>(istream& in, Str& s){
    s.data.clear();
    
    char c;
    while (in.get(c) && isspace(c));
    
    if(in){
        do {
            s.data.push_back(c);
        } while(in.get(c) && !isspace(c));
        
        if(in){
            in.unget();
        }
    }
    
    return in;
        
    
}
ostream& operator <<(ostream& out, const Str& s){
    for (Str::size_type i = 0; i != s.size(); i++){
        out << s[i];
    }
    return out;
}
