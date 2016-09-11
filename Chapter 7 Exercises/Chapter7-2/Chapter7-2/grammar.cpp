//
//  grammar.cpp
//  Chapter7-2
//
//  Created by Andrew Meyers on 9/10/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "grammar.h"
#include <istream>
#include <string>
#include "string_util.h"
#include <vector>
#include <map>

using namespace std;

Grammar read_grammar(istream& in){
    Grammar ret;
    string line;
    
    while(getline(in, line)){
        vector<string> entry = split(line);
        
        if(!entry.empty()){
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    
    return ret;
}