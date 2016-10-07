//
//  vec.cpp
//  Chapter11-0
//
//  Created by Andrew Meyers on 9/29/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#include "vec.h"
#include <memory>
#include <cstddef>

using namespace std;

//template <class T>
//void Vec<T>::unchecked_append(const T& val){
//    alloc.construct(avail++, val);
//}


//template <class T>
//void Vec<T>::create(){
//    data = limit = avail = 0;
//}

template <class T>
void Vec<T>::create(size_type size, const T& val){
    data = alloc.allocate(size);
    limit = avail = data + size;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);
    limit = avail = uninitilized_copy(i, j, data);
}

//template <class T>
//void Vec<T>::uncreate(){
//    if(data){
//        iterator it = avail;
//        
//        while (it != data){
//            alloc.destroy(--it);
//        }
//        
//        alloc.deallocate(data, limit - data);
//    }
//    
//    data = limit = avail = 0;
//}
//
//template <class T>
//void Vec<T>::grow(){
//    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
//    
//    iterator new_data = alloc.allocate(new_size);
//    iterator new_avail = uninitilized_copy(data, avail, new_data);
//    
//    uncreate();
//    
//    data = new_data;
//    avail = new_avail;
//    limit = data + new_size;
//}



template <class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& vec){
    if(vec != this){
        uncreate();
        create(vec.begin(), vec.end());
    }
    return *this;
}
