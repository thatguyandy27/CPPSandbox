//
//  permuted_index.cpp
//  Chapter5-4
//
//  Created by Andrew Meyers on 9/5/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "permuted_index.h"

#include <vector>
#include <algorithm>
#include <string>
#include "frame.h"

using namespace std;

struct permuted_index{
    vector<string>::size_type word_index;
    vector<string> words;
    string rotated_line;
};

bool sort_permuted_index(const permuted_index& pi1, const permuted_index& pi2){
    return pi1.rotated_line < pi2.rotated_line;
}

vector<permuted_index> get_rotations(const vector<string>& lines){
    
    vector<permuted_index> rotations;
    
    
    for(vector<string>::size_type w = 0; w < lines.size(); w++){
    
        string line = lines[w];
        vector<string> words = split(line);
        
        for(vector<string>::size_type rotation_start = 0; rotation_start < words.size(); rotation_start++){

            string rotated_line = "";
            for (vector<string>::size_type i = rotation_start; i < words.size(); i++) {
                rotated_line += words[i] + " " ;
            }
            for(vector<string>::size_type i = 0; i < rotation_start; i++){
                rotated_line += words[i] + " ";
            }
            
            permuted_index index;
            index.word_index = rotation_start;
            index.words = words;
            index.rotated_line = rotated_line;
            rotations.push_back(index);
        }
    }
    
    sort(rotations.begin(), rotations.end(), sort_permuted_index);
    
    return rotations;
}

vector<string> join_fames(const vector<string>& left, const vector<string>& right){
    
    vector<string> new_frame;
    
    for (vector<string>::size_type i = 0; i < left.size(); i++) {
        new_frame.push_back(left[i] + " " + right[i]);
    }
    
    return new_frame;
}

vector<string> get_permuted_index(const vector<string>& lines){
    
    vector<permuted_index> rotations = get_rotations(lines);
    vector<string> left, right;
    for (vector<permuted_index>::size_type i = 0; i < rotations.size(); i++) {
        vector<string>::size_type left_start = 0;
        string left_word = "", right_word = "";
        permuted_index index = rotations[i];
   
        while(left_start < index.word_index){
            left_word += index.words[left_start] + " ";
            left_start++;
        }
        for (vector<string>::size_type right_start = left_start; right_start < index.words.size(); right_start++) {
            right_word += index.words[right_start] + " ";
        }
        left.push_back(left_word);
        right.push_back(right_word);
    }
    left = create_frame(left);
    right = create_frame(right);
    
    return join_fames(left, right);
}

