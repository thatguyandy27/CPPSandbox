//
//  main.cpp
//  Chapter10-1
//
//  Created by Andrew Meyers on 9/27/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
using namespace std;

int next(int n){
    return n + 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int (*fp)(int) = &next;
    
    cout << "Using function pointer: " << fp(10) << endl;
    
    return 0;
}
