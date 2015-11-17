#include "Dataframe.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>



bool compare(Record<const float*, const float &, const int &> a, Record<const float*, const float &, const int &> b ) {
  return get<1>(a) < get<1>(b);
}

/*
bool compare(const Record<const float*, const float &, const int &> & a, const Record<const float*, const float &, const int &> & b ) {
  //std::cout << get<1>(a) << " " << get<1>(b) << std::endl;
  return get<1>(a) < get<1>(b);
}
*/
struct myss {
  bool operator()(Record<const float*, const float &, const int &> & a, Record<const float*, const float &, const int &> & b) {
    return get<1>(a) < get<1>(b);;
  }
};
/*
template< typename... Ts>
inline bool operator==(const Record<Ts...>&, const Record<Ts...>&) { return true; }
*/
/*
inline bool operator==(const Record<>&, const Record<>&) { return true; }

template< typename T1, typename... T1s, typename T2, typename... T2s > 
inline bool operator==(const Record<T1, T1s...> & a, const Record<T2, T2s...> & b) {
  return a.Head() == b.Head() && a.Tail() == b.Tail();
}


inline bool operator<(const Record<>&, const Record<>&) { return true; }

template< typename T1, typename... T1s, typename T2, typename... T2s > 
inline bool operator<(const Record<T1, T1s...> & a, const Record<T2, T2s...> & b) {
  return a.Head() < b.Head() && a.Tail() < b.Tail();
}
*/

//inline bool compare(const Record<>&, const Record<>&) { return true; }
/*
template< typename T1, typename... T1s, typename T2, typename... T2s > 
inline bool compare(const Record<T1, T1s...> & a, const Record<T2, T2s...> & b) {
  return true;
}
*/

int main(void){
  
  std::map<std::string, std::vector<float> * > test;
  
  std::vector< float > x1 = {4,3,3,6,8};
  std::vector< int > x2 = {1,1,1,0,0};
  float* x3 = (float*)malloc(5*3*sizeof(float));
  
  for( int i= 0; i < 5*3;++i) x3[i] = i;
  
  //test["x"] = &x;
  //test["y"] = &y;
  
  std::map<std::string, float> t;
  std::map<std::string, int> tt;
  t["2"] = 2.0;
  tt["asdf"] = 2;
  
  
  //Feature<std::vector<float>> f1("feature1", x1);
  //Feature<std::vector<int>> f2("ids", x2);
  
  //Record< std::map<std::string, float>, std::map<std::string, int> > rec(t, tt);
  //Record< Feature<std::vector<float>> & , Feature<std::vector<int>> & > rec(f1, f2);
  Record< std::map<std::string, float> & , std::map<std::string, int> & > rec2(t, tt);

  //std::sort(test, test["x"]);
  
  Record<std::string, std::string, std::string> Header("Acts", "meta", "id");
  
  std::vector< Record<const float*, const float &, const int &> > data;
  for ( unsigned int i = 0; i < 5; ++i ) {
    data.push_back(Record<const float*, const float &, const int &>(&x3[i*3], x1[i], x2[i]));
    std::cout << x3[i*3] << " " << x1[i] <<  " " << x2[i] << std::endl;    
  }
  
  auto x = get<0>(Header);
  std::cout << get<0>(Header) << " " << get<1>(Header) << " " << get<2>(Header) << " " << std::endl;
  for ( auto & i : data ) {
    std::cout << get<0>(Header) << "; " << *get<0>(i) << ", " <<
    get<1>(Header) << ": " << get<1>(i) <<  ", " <<
    get<2>(Header) << ": " << get<2>(i) << std::endl;
  }
  

  //myss sorter;
  
  //std::sort(x2.begin(), x2.end(), tester);
  
  //std::sort(data.begin(), data.end());
  std::sort(data.begin(), data.end(), compare);
  //std::sort(data.begin(), data.end(), static_cast<bool (*comparer_t)(const T*, const T*)>(&compare));
  
  
  std::cout << "here" << std::endl;
  //std::cout << (data[0] == data[2]) << " " << compare(data[0], data[0]) << " " << compare(data[0], data[1]) << std::endl;
  
  
  Record<const float*, const float &, const int &> s(data[0]);
  std::cout << get<0>(s) << " " << get<1>(s) << " " << get<2>(s) << std::endl;
  std::cout << get<0>(data[0]) << " " << get<1>(data[0]) << " " << get<2>(data[0]) << std::endl;

  
  free(x3);
  printf("Exit Success!\n");
  return 0;
}

