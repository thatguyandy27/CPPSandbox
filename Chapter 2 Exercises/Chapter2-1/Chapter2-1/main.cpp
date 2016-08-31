//
//  main.cpp
//  Chapter2-1
//
//  Created by Andrew Meyers on 8/31/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main(int argc, const char * argv[]) {
    // insert code here...
    string name;
    cout<< "Please enter your name: ";
    cin>>name;

    const int padding = 1;
    const int rows = padding * 2 + 3;
    const string::size_type columns = name.size() + padding * 2 + 2;
    const int maxRow = rows -1;
    const string::size_type maxColumn = columns - 1;
    
    for(int r = 0; r < rows; r++){
        string::size_type c = 0;
        while (c < columns){
            if (r == padding + 1 && c == padding + 1){
                cout << name;
                c += name.size();
            }
            else{
                
                if (r == 0 || r == maxRow ||
                    c == 0 || c == maxColumn){
                    cout << "*";
                }
                else {
                    cout << " ";
                }
                c++;
            }
        }
        cout<< std::endl;
    }
    
    return 0;
}
