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
	State* target_;
	double probability_;
	int reward_;
	
	Edge(State* target,
		 double probability,
		 int reward);
	
	Edge();
  };

  class Action{
  private:
	std::string name_;
	std::vector<Edge> edges_;

	double probabilitySum_;
	
  public:
	Action(const std::string name);
	
	~Action();

	void addEdge(State& target,
				 double probability,
				 int reward);

	std::string getName();
  };	
}

