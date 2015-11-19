#include "Dataframe.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <tuple>

int main(void){
  
  std::vector<Feature<> * > data;
  std::vector<float> ma = {1,2,3,4,4};
  
  float* a = (float*) malloc(sizeof(float) * 20);
  
  
  data.push_back(new Feature<float>(2,10));
  data.push_back(new Feature<float>(ma, 1));
  
  std::cout << dynamic_cast<Feature<float>*>(data[0])->Size() << " " << dynamic_cast<Feature<float>*>(data[0])->Len() << " " << dynamic_cast<Feature<float>*>(data[0])->Dim() << std::endl;
  std::cout << dynamic_cast<Feature<float>*>(data[1])->Size() << " " << dynamic_cast<Feature<float>*>(data[1])->Len() << " " << dynamic_cast<Feature<float>*>(data[1])->Dim() << std::endl;

  
  //std::cout << static_cast<Feature<float>>(data2[0]).Size() << " " << static_cast<Feature<float>>(data2[0]).Len() << " " << static_cast<Feature<float>>(data2[0]).Dim() << std::endl;

  
  
  /*
  
  data.push_back(new Feature<int>(8,1,1));
  data.push_back(new Feature<std::string>("test",1,1));
  data.push_back(new Feature<float*>(a,2,10));
  data.push_back(new Feature<std::vector<float>&>(ma,1,5));
  
  for ( int i = 0; i< 20; i++) a[i] = i;
  
  
  std::cout << dynamic_cast<Feature<int>*>(data[0])->get() << std::endl;
  std::cout << dynamic_cast<Feature<std::string>*>(data[1])->get() << std::endl;
  for ( int i = 0; i< 20; i++) { 
    std::cout << "i " << i << " " << dynamic_cast<Feature<float*>*>(data[2])->get()[0] << std::endl;
  }
  
  std::tuple<float, float, std::string> test(1.0,2.0,"arsch");
  std::cout << std::get<0>(test) << " " << std::get<2>(test) <<std::endl;
*/
  printf("Exit Success!\n");
  return 0;
}

