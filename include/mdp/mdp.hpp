#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "mdp/state.hpp"
#include "mdp/policy.hpp"

#define EPSILON 1e-4
#define LAMBDA 0.8

#ifndef INFINITY
#define INFINITY -1
#endif

namespace mdp{
  
  void utilityIteration(std::vector<State>& state,
						int horizon);

  double rootMeanSquareError(std::vector<State> stateList,
							 std::vector<State> stateListPrime);
}
