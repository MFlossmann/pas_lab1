#include "mdp/action.hpp"

namespace mdp {

  Edge::Edge(std::string name,
			 State* target,
			 double probability){
	name_ = name;
	target_ = target;
	probability_ = probability;
  }
  
  Edge::Edge(){

  }
  
  Action::Action(const std::string name){
  	Action(name, 0.0);
   }
  

  Action::Action(const std::string name,
				 double reward){
	name_ = name;
	reward_ = reward;

#ifdef _VERBOSE_MODE_
	cout << "Created a new action with name " << name_ \
		 << ", reward:\t" << reward_ << endl;
#endif
  }
  
  Action::~Action(){
	
  }

  void Action::addEdge(std::string name,
					   State& target,
					   double probability){
	
	Edge new_edge(name, &target, probability);
	edges_.push_back(new_edge);
	//	probabilitySum_ += probability;
	
	cout << "Added edge " << name						  \
		 <<	"\t->\t" << target.getName() << "\t"		  \
		 << probability \
		 << "\tto action " << this->getName() << "." << endl;
  }

  std::string Action::getName(){
	return name_;
  }

  std::vector<Edge>& Action::getEdges(){
	return edges_;
  }

  double Action::getReward(){
	return reward_;
  }

}
