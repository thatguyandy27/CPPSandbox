//
//  string_util.h
//  Chapter5-2
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef string_util_h
#define string_util_h

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str);
std::string::size_type max_width(const std::vector<std::string>& v);
#endif /* string_util_hpp */