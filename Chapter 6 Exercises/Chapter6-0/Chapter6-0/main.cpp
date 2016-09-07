//
//  main.cpp
//  Chapter6-0
//
//  Created by Andrew Meyers on 9/7/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include "url_util.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Please enter a string to search for urls: ";
    string s;
    getline(cin, s);
    
    vector<string> urls = find_urls(s);
    
    
    if (urls.empty()){
        cout << "No URLs Found"<< endl;
    }
    else {
        vector<string>::const_iterator i = urls.begin();

        while (i != urls.end()){
            cout << *i << endl;
            i++;
        }
        
    }
    
    return 0;
}
