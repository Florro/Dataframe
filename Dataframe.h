/*
 * Dataframe.h
 *
 *  Created on: Nov 16, 2015
 *      Author: florian
 *  Last modified: Nov 16, 2015 
 */

#ifndef DATAFRAME_H_
#define DATAFRAME_H_

#include "Feature.h"

struct Dataframe {
public:
  Dataframe(void);
  virtual ~Dataframe(void);
  
private:

  std::vector<Feature<>*> entries_;
  
  
};

#endif // DATAFRAME_H_