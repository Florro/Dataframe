#include "Dataframe.h"

Dataframe::Dataframe(void) {}

Dataframe::~Dataframe(void) {
  for ( auto & i : entries_ ) { delete i; i = nullptr; }
}