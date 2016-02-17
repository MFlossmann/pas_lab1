#include "mdp/action.hpp"

namespace mdp {

  Edge::Edge(State* target,
			 double probability,
			 int reward){
	target_ = target;
	probability_ = probability;
	reward_ = reward;
  }
  
  Edge::Edge(){

  }

  Action::Action(const std::string name){
	name_ = name;

#ifdef _VERBOSE_MODE_
	cout << "Created new action with name " << name_ << "." << endl;
#endif
  }
  
  Action::~Action(){
	
  }

  void Action::addEdge(State& target,
					   double probability,
					   int reward){
	
	Edge new_edge(&target, probability, reward);
	edges_.push_back(new_edge);
	probabilitySum_ += probability;
	
	cout << "Added edge " << target.getName() << "\t"	  \
		 << probability << "\t"							  \
		 << reward << "\tto action " << name_ << "." << endl;
  }

  std::string Action::getName(){
	return name_;
  }

}
