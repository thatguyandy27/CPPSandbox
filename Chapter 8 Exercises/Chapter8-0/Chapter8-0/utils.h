//
//  utils.h
//  Chapter8-0
//
//  Created by Andrew Meyers on 9/23/16.
//  Copyright © 2016 Andrew Meyers. All rights reserved.
//

#ifndef utils_h
#define utils_h

template <class In, class X> In find(In, In, const X&);
template <class In, class Out> Out copy(In, In, Out);
template <class For, class X> void replace(For, For, const X&, const X&);
template <class Bi> void reverse(Bi, Bi);
template <class Ran, class X> bool binary_search(Ran, Ran, const X&);

#endif /* utils_hpp */
