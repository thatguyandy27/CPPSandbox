//
//  vec.h
//  Chapter11-0
//
//  Created by Andrew Meyers on 9/29/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef vec_h
#define vec_h

#include <cstddef>
#include <memory>
#include <algorithm>


template<class T>
class Vec{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
 
    // Constructors/destructors
    Vec() { create();};
    explicit Vec(size_type n, const T& val = T()) { create(n, val); };
    Vec(const Vec& v){create(v.begin(), v.end());};
    ~Vec(){ uncreate(); }
    
    // methods
    size_type size() const { return avail - data;}
    void push_back(const T& t){
        if (avail == limit){
            grow();
        }
        unchecked_append(t);
    }
    
    // operators
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    Vec& operator=(const Vec&);
    
    // iterators
    iterator begin() { return data;}
    const_iterator begin() const { return data;}

    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    
private:
    iterator data;
    iterator limit;
    iterator avail;
    
    std::allocator<T> alloc;
    void create(){
        data = limit = avail = 0;
    }
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    
    void uncreate(){
        if(data){
            iterator it = avail;
            
            while (it != data){
                alloc.destroy(--it);
            }
            
            alloc.deallocate(data, limit - data);
        }
        
        data = limit = avail = 0;

    }
    
    void grow();
    void unchecked_append(const T& val){
        alloc.construct(avail++, val);
    }
};


template <class T>
void Vec<T>::grow(){
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    
    uncreate();
    
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}


#endif /* vec_hpp */
