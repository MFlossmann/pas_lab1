#include "mdp/mdp.hpp"

namespace mdp{
  void utilityIteration(std::vector<State>& stateList){
	int foo = 200;

	while(foo--){
	  cout << "Iteration " << foo << ":" << endl;
	  for (int i=0; i<stateList.size(); i++){
		std::vector<Action> actions =  stateList[i].getActions(); // Get the reference to the actions of the current state
		cout << "\tState: " << stateList[i].getName() << endl;

		double max_utility = 0;
		for (int a=0; a<actions.size();a++){               // sum through utilities of actions
		  std::vector<Edge> edges = actions[a].getEdges(); // get the reference to the edges of the current Action
		  double utility = actions[a].getReward();
		  for (int j=0; j<edges.size(); j++){
			utility += edges[j].target_->utility * edges[j].probability_; // sum(p*U(target))
			if (utility > max_utility)
			  max_utility = utility;
			//edges[j].target_->utility = utility; // assign the new utility value to the stateList
		  } // end edge iteration
		  cout << "\t\tAction: " << actions[a].getName() \
			   << "\tutility: " << utility << endl;
		  if (utility > max_utility)
			max_utility = utility;
		} // end action iteration
		stateList[i].utility = max_utility; // assign the new utility value to the stateList
	  } // end state iteration
	} // end while
  } // end utilityIteration
} // end namespace
