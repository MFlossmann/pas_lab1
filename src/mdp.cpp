#include "mdp/mdp.hpp"

namespace mdp{
  void utilityIteration(std::vector<State>& stateList){
	int foo = 20;

	while(foo--){
	  cout << "Iteration " << foo << ":" << endl;
	  for (int i=0; i<stateList.size(); i++){
		std::vector<Action> actions =  stateList[i].getActions(); // Get the reference to the actions of the current state
		cout << "\tState: " << stateList[i].getName() << endl;

		for (int a=0; a<actions.size();a++){               // sum through utilities of actions
		  std::vector<Edge> edges = actions[a].getEdges(); // get the reference to the edges of the current Action
		  double utility, max_utility = 0;
		  for (int j=0; j<edges.size(); j++){
			utility = edges[j].target_->utility * edges[j].probability_; // sum(p*U(target))
			utility += actions[a].getReward()*edges[j].probability_;
			utility += stateList[i].utility;
			if (utility > max_utility)
			  max_utility = utility;
			//edges[j].target_->utility = utility; // assign the new utility value to the stateList
		  } // end edge iteration
		  cout << "\t\tAction: " << actions[a].getName() \
			   << "\tutility: " << utility << endl;
		  //stateList[i]->utility = utility; // assign the new utility value to the stateList
		} // end action iteration
	  } // end state iteration
	} // end while
  } // end utilityIteration
} // end namespace
