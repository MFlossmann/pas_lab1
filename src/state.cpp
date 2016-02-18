#include "mdp/state.hpp"

namespace mdp {
  State::State(const std::string& name,
			   double reward){
	name_ = name;
	reward_ = reward;
	utility = 0;

#ifdef _VERBOSE_MODE_
	cout << "Created a new state with name " << name_ << "." << endl;
#endif
  }
  
  State::~State(){
  
  }

  void State::addAction(Action action){
	actions_.push_back(action);
	cout << "Added action " << action.getName() << " to state " << name_ << endl;
  }

  void State::setReward(double reward){
	reward_ = reward;
  }
  
  std::string State::getName(){
	return name_;
  }

  double State::getReward(){
	return reward_;
  }
  
  std::vector<Action>& State::getActions(){
	return actions_;
  }
}
