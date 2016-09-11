//
//  main.cpp
//  Chapter7-2
//
//  Created by Andrew Meyers on 9/10/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "sentence.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    vector<string> sentence = gen_sentence(read_grammar(cin));
    
    vector<string>::const_iterator it = sentence.begin();
    
    if(!sentence.empty()){
        cout << *it;
        it++;
    }
    
    while(it != sentence.end()){
        cout << " " << *it;
        it++;
    }
    
    cout << endl;
    
    
    return 0;
}
