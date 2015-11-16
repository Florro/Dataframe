/*
 * Dataframe.h
 *
 *  Created on: Nov 16, 2015
 *      Author: florian
 *  Last modified: Nov 16, 2015 
 */

#ifndef DATAFRAME_H_
#define DATAFRAME_H_

#include <type_traits>

template< typename... Ts > struct Record {};

template< typename T, typename... Ts > struct Record<T, Ts...> : Record<Ts...> {

public:
  Record(T t, Ts... ts);
  template< typename... T2s > Record(const Record< T2s... > & src); 
  template< typename... T2s > Record<T, Ts...> & operator=(const Record<T2s...> & src);
  
  const T& Head(void) const;
  T & Head(void);
  
  const Record<Ts...> & Tail(void) const;
  Record<Ts...> & Tail(void);
  
  virtual ~Record(void);

private:
  T entry_;
};

//############################################


template <unsigned int k, typename... Ts> struct elem_type_holder {};
 
template< typename T , typename... Ts > struct elem_type_holder<0, Record<T, Ts...> > {
  typedef T type;
};

template <unsigned int k, typename T, typename... Ts > struct elem_type_holder<k, Record<T, Ts...> > {
  typedef typename elem_type_holder< k - 1, Record<Ts...> >::type type;
};

//#####################################################

template < unsigned int k, typename... Ts >
typename std::enable_if<k == 0, typename elem_type_holder<0, Record<Ts...>>::type&>::type get(Record<Ts...>& t) { return t.Head(); }

template < unsigned int k, typename T, typename... Ts > 
typename std::enable_if<k != 0, typename elem_type_holder<k, Record<T, Ts...>>::type&>::type get(Record<T, Ts...>& t) { 
  Record<Ts...> & base = t;
  return get<k - 1>(base);
}

//template < typename Ts... > typename std::enable_if<k == 0, typename elem_type_holder<0, Record<Ts...>>::type&>::type operator[](unsigned int k){ return t.Entry(); }


/*
template <unsigned int k, class... Ts> struct elem_type_holder {};

template <class T, class... Ts>
struct elem_type_holder<0, Record<T, Ts...>> {
  typedef T type;
};

template <unsigned int k, class T, class... Ts>
struct elem_type_holder<k, Record<T, Ts...>> {
  typedef typename elem_type_holder<k - 1, Record<Ts...>>::type type;
};
*/
#include "Dataframe-inl.h"





/*
#include <map>
#include <string>
template< template < typename T > class... Ts > struct Record {};

template< template < typename T1 > class T, template < typename T2 > class... Ts > struct Record <T, Ts...> : Record<Ts...> {
  
public:
  Record(T t, Ts... ts) : Record<Ts...>(ts...), entry_(t) {}
  
private:
  
  entry_;
  
};
*/
/*
template< typename... Ts > struct Record {};

template< typename T, typename... Ts > struct Record<std::map, T, Ts...> : Record<Ts...> {

public:
  Record(T t, Ts... ts) : Record<Ts...>(ts...), entry_(t) {}
private:
  T entry_;
};

*/
/*
#include <map>

template< template < typename... > class Container, typename ... Ts > struct Record {};

template< typename ... Ts > struct Record < std::map, Ts... > {

public: 
  
};
*/

#endif // DATAFRAME_H_