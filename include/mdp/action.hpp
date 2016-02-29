#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "mdp/state.hpp"

using std::cout;
using std::endl;
//using std::string;

namespace mdp 
{
  class State;

  struct Edge {
	std::string name_;
	State* target_;
	double probability_;
	
	Edge(std::string name,
		 State* target,
		 double probability);
	
	Edge();
  };

  class Action{
  private:
	std::string name_;
	std::vector<Edge> edges_;
	double reward_;
	
  public:
	Action(const std::string name);

	Action(const std::string name,
		   double reward);

	Action(const Action& action);

	Action();
	
	~Action();

	void addEdge(std::string name,
				 State& target,
				 double probability);

	std::vector<Edge>& getEdges();

	std::string getName() const;

	double getReward() const;
  };	
}

