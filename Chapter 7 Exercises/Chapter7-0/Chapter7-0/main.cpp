//
//  main.cpp
//  Chapter7-0
//
//  Created by Andrew Meyers on 9/9/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    map<string, int> counters;
    
    while(cin>> s){
        counters[s]++;
    }
    
    for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++){
        cout<< it ->first << " was used " << it-> second << " times." <<endl;
    }
    
    return 0;
}
