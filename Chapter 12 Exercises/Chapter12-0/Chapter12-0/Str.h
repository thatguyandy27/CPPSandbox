//
//  Str.h
//  Chapter12-0
//
//  Created by Andrew Meyers on 10/7/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef Str_h
#define Str_h
#include "vec.h"
#include <iostream>

class Str {
public:
    friend std::istream& operator>>(std::istream&, Str&);
    typedef Vec<char>::size_type size_type;
    
    Str(){}
    Str(size_type n, char c): data(n, c) {}
    Str(const char* cp){
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    
    template<class In>
    Str(In b, In e){
        std::copy(b,e, std::back_inserter(data));
    }
    
    size_type size() const { return data.size();} 
    
    
    char& operator[](size_type i){return data[i];}
    const char& operator[](size_type i) const {return data[i];}
    
private:
    Vec<char> data;
};

std::istream& operator >>(std::istream&, Str&);
std::ostream& operator <<(std::ostream&, const Str&);

#endif /* Str_hpp */
