//
//  main.cpp
//  Chapter10-4
//
//  Created by Andrew Meyers on 9/29/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    int fail_count = 0;
    
    for(int i = 1; i < argc; i++){
        ifstream in(argv[i]);
        
        if(in){
            string line;
            
            while(getline(in, line)){
                cout << line <<endl;
            }
        }
        else {
            cerr << "Could not read file: " << argv[i] << endl;
            fail_count++;
        }
    }

    return fail_count;
}
