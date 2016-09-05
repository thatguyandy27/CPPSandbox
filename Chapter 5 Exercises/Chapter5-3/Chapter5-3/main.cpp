//
//  main.cpp
//  Chapter5-3
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "frame.h"

using namespace std;

int main(int argc, const char * argv[]) {

    string s;
    vector<string> words;
    while(getline(cin, s)){
        words.push_back(s);
    }
    
    vector<string> frame = create_frame(words);
    
    for(vector<string>::size_type i = 0; i < frame.size(); i++){
        cout<<frame[i]<<endl;
    }
    
    return 0;
}
