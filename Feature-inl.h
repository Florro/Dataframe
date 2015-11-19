/*
 * Feature-inl.h
 *
 *  Created on: Nov 19, 2015
 *      Author: florian
 *  Last modified: Nov 19, 2015 
 */

#ifndef FEATRUE_INL_H_
#define FEATRUE_INL_H_

#include "Feature.h"

template<typename T>
Feature<T>::Feature(void) : mDim_(0), mLen_(0) {}
  
template<typename T>
Feature<T>::Feature(const unsigned int & dim, const unsigned int & n) : mDim_(dim), mLen_(n) {
  entry_.resize(dim * n);
}

template<typename T>
Feature<T>::Feature(const std::vector<T> & x, const unsigned int & dim) : mDim_(dim) {
  entry_ = x;
  mLen_ = x.size() / dim;
}

template<typename T>
Feature<T>::~Feature(void) {}

template<typename T>
inline T & Feature<T>::operator[](unsigned int i) { 
  return entry_[i * mDim_]; 
}

template<typename T>
inline const T & Feature<T>::operator[](unsigned int i) const { return entry_[i * mDim_]; }

template<typename T>
inline std::vector<T> & Feature<T>::Entry(void) { return entry_; }

template<typename T>
inline const std::vector<T> & Feature<T>::Entry(void) const { return entry_; }

template<typename T>
inline unsigned int Feature<T>::Dim(void) const { return mDim_; }

template<typename T>
inline unsigned int Feature<T>::Len(void) const { return mLen_; }

template<typename T>
inline unsigned int Feature<T>::Size(void) const { return entry_.size(); }


#endif // FEATRUE_INL_H_
