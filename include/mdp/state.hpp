#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "mdp/action.hpp"

using std::cout;
using std::endl;
//using std::string;

namespace mdp 
{
  class Action;

  class State
  {
  private:
	std::string name_;
	std::vector<Action> actions_;
	std::double reward_;
	
  public:
    State(const std::string& name,
		  double reward);
	~State();

	void addAction(Action action);

	std::string getName();
};
	
}

