#pragma once

#include <vector>
#include "mdp/state.hpp"
#include "mdp/action.hpp"

namespace mdp{

  // Stores one State and a reference to the Action that's the best policy in this state
  struct PolicyElement{
	std::string stateName_;
	Action& action;
  };
  
  class Policy{
  private:
	
  public:
	Policy(int horizon, 
		   std::vector<State> stateSpace);

	~Policy();
  };
}
