#pragma once

#include <vector>
#include <stdlib.h>
#include "mdp/state.hpp"
#include "mdp/action.hpp"

namespace mdp{

  // Stores one State and a reference to the Action that's the best policy in this state
  struct PolicyRow{
	std::vector<State*> stateSpace_;
	std::vector<int> actionIndices_;

	//	PolicyRow(std::vector<State&> stateSpace);

	PolicyRow(std::vector<State>& stateSpace);

	PolicyRow(const PolicyRow& policyRow);

	PolicyRow();
  };
  
  class Policy{
  private:
	std::vector<std::vector<int> > policyMatrix_;
	std::vector<State> stateSpace_;
	bool infiniteHorizon_;
	int horizon_;
		
	
  public:
	Policy(std::vector<State>& stateSpace,
		   int horizon);

	Policy(const Policy& policy);
	
	~Policy();

	void calculate(std::vector<State> stateSpace,
				   int step);

	void calculate(std::vector<State> stateSpace);

	void print();

	void printMatrix();
  };
}
