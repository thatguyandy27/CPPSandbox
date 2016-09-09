//
//  main.cpp
//  Chapter7-1
//
//  Created by Andrew Meyers on 9/9/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "string_util.h"

using namespace std;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split){
    string line;
    int line_num = 0;
    map<string, vector<int> > ret;
    
    while(getline(in, line)){
        line_num++;
        
        vector<string> words = find_words(line);
        
        for (vector<string>::const_iterator i = words.begin(); i != words.end(); i++) {
            ret[*i].push_back(line_num);
        }
    }
    
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    map<string, vector<int> > result = xref(cin);
    
    
    for(map<string, vector<int> >::const_iterator i = result.begin(); i != result.end(); i++){
        cout << i -> first << " Occurs on the line(s): ";
        
        vector<int>::const_iterator i2 = i -> second.begin();
        
        cout << *i2;
        i2++;
        
        while ( i2 != i -> second.end() ) {
            cout << ", " << *i2;
            i2++;
        }
        
        cout << endl;
    }
    
    
    return 0;
}

