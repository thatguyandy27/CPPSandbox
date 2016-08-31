//
//  main.cpp
//  Chapter2-5
//
//  Created by Andrew Meyers on 8/31/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int squareSize;
    
    cout<< "Please enter a square size: ";
    cin>> squareSize;
    
    for(int h=0; h < squareSize; h++){
        cout<<string(squareSize, '*') <<endl;
    }
    
    int triangleSize;
    cout<<endl<<"Please enter a triangle size: ";
    cin>> triangleSize;
    
    for(int h = 0; h < triangleSize; h++){
        cout<<string(h, '*')<<endl;
    }

    
    
    
    return 0;
}
