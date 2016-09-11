//
//  sentence.cpp
//  Chapter7-2
//
//  Created by Andrew Meyers on 9/10/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "sentence.h"
#include "grammar.h"
#include "nrand.h"
#include <vector>
#include <string>

using namespace std;

bool is_braketed(const string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret){
    if(!is_braketed(word)){
        ret.push_back(word);
    }
    else{
        
        Grammar::const_iterator it = g.find(word);
        if(it == g.end()){
            throw logic_error("empty rule");
        }
        
        const Rule_collection& c = it -> second;
        
        const Rule& r = c[nrand(c.size())];
        
        for (Rule::const_iterator i = r.begin(); i != r.end(); i++){
            gen_aux(g, *i, ret);
        }
    }
}


vector<string> gen_sentence(const Grammar& g){
    vector<string> ret;
    
    gen_aux(g, "<sentence>", ret);
    
    return ret;
}

