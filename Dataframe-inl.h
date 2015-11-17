/*
 * Dataframe.h
 *
 *  Created on: Nov 16, 2015
 *      Author: florian
 *  Last modified: Nov 16, 2015 
 */

#ifndef DATAFRAME_INL_H_
#define DATAFRAME_INL_H_

#include "Dataframe.h"

template< typename T, typename... Ts>
Record<T, Ts...>::Record(T t, Ts... ts) : Record<Ts...>(ts...), entry_(t) {}

template< typename T, typename... Ts>
template< typename... T2s > Record<T, Ts...>::Record(const Record< T2s... > & src) : Record<Ts...>(src.Tail()), entry_(src.Head()) {}  
/*
template< typename T, typename... Ts>
template< typename... T2s > Record<T, Ts...> & Record<T, Ts...>::operator=(const Record<T2s...> & src) {
  if ( this != &src ) {
    entry_ = src.Head();
    *this = src.Tail();
  }
}
*/
template< typename T, typename... Ts>
Record<T, Ts...> & Record<T, Ts...>::operator=(const Record<T, Ts...> & src) {
  if ( this != &src ) {
    entry_ = src.Head();
    *this = src.Tail();
  }
  return *this;
}

template< typename T, typename... Ts>
const T& Record<T, Ts...>::Head(void) const {
  return entry_;
}

template< typename T, typename... Ts>
T & Record<T, Ts...>::Head(void) {
  return entry_;
}

template< typename T, typename... Ts>
const Record<Ts...> & Record<T, Ts...>::Tail(void) const { 
  return *this; 
}

template< typename T, typename... Ts>
Record<Ts...> & Record<T, Ts...>::Tail(void) { 
  return *this; 
}


template< typename T, typename... Ts>
Record<T, Ts...>::~Record(void) {}

#endif // DATAFRAME_INL_H_