/*
 * Feature.h
 *
 *  Created on: Nov 16, 2015
 *      Author: florian
 *  Last modified: Nov 16, 2015 
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>
#include <tuple>
#include <map>
#include <iostream>

template<typename... T> struct Feature {
  virtual ~Feature(void) {}
};

template<typename T> struct Feature<T> : Feature<>{
public:
  Feature(void);
  Feature(const unsigned int & dim, const unsigned int & n);
  Feature(const std::vector<T> & x, const unsigned int & dim);
  virtual ~Feature(void);
  
  inline T & operator[](unsigned int i);
  inline const T & operator[](unsigned int i) const;
  
  inline std::vector<T> & Entry(void);
  inline const std::vector<T> & Entry(void) const;
  inline unsigned int Dim(void) const;
  inline unsigned int Len(void) const;
  inline unsigned int Size(void) const;
  
private:
  std::vector<T> entry_;
  unsigned int mDim_;
  unsigned int mLen_;

};

#include "Feature-inl.h"

#endif // FEATURE_H_