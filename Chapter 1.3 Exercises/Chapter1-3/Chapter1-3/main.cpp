//
//  main.cpp
//  Chapter1-3
//
//  Created by Andrew Meyers on 8/30/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string name;
    cout<< "Please enter your first name: " ;
    cin >> name;
    
    const string greeting = "Hello " + name + "!";
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";
    const string first(second.size(), '*');
    
    cout<<endl;
    cout<<first<<endl;
    cout<<second<<endl;
    cout<<"* " << greeting << " *" << endl;
    cout<<second<<endl;
    cout<<first<<endl;
    cout<<endl;
    
    
//    return 0;
    
    cout<< "What is your name: ";
    cin>> name;
    cout<< "Hello, " << name << endl<< "and  what is yours? ";
    cin>> name;
    cout<< "Hello, " << name << ".  Nice to meet you too";
    
}
