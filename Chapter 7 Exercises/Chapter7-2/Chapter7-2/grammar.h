//
//  grammar.h
//  Chapter7-2
//
//  Created by Andrew Meyers on 9/10/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef grammar_h
#define grammar_h

#include <vector>
#include <string>
#include <map>
#include <istream>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
#endif /* grammer_hpp */
