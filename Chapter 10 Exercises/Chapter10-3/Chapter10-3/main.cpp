//
//  main.cpp
//  Chapter10-3
//
//  Created by Andrew Meyers on 9/29/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream infile("in");
    ofstream outfile("out");
    
    string s;
    
    while (getline(infile, s)){
        outfile << s <<endl;
    }

    
    return 0;
}
