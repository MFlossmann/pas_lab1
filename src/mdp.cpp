#include "mdp/mdp.hpp"

namespace mdp{
  void utilityIteration(std::vector<State>& stateList,
						int horizon){
	int iterator = 0;
	double lambda, rms;
	if (horizon == INFINITY)
	  lambda = LAMBDA;
	else if (horizon == 0){
	  cout << "Error! Horizon should be >0 or -1 (infinite)!" << endl;
	}
	else
	  lambda = 1;
	  
    do { // iterate to horizon or until convergence
	  std::vector<State> tempList = stateList; // temporary list
	  cout << "Iteration " << iterator << ":" << endl;
	  for (int i=0; i<stateList.size(); i++){
		std::vector<Action> actions =  stateList[i].getActions(); // Get the reference to the actions of the current state

		cout << "\tState: " << stateList[i].getName()			\
			 << "\tutility: " << stateList[i].utility << endl;

		double max_utility = 0;                            // initialize for finding the maximum
		for (int a=0; a<actions.size();a++){               // sum through utilities of actions
		  std::vector<Edge> edges = actions[a].getEdges(); // get the reference to the edges of the current Action
		  double utility = actions[a].getReward() + stateList[i].getReward();

		  // sum through all the edges
		  for (int j=0; j<edges.size(); j++){
			utility += pow(lambda,(double)iterator) *      // recession factor for infinite horizon
			           edges[j].target_->utility * edges[j].probability_; // sum(p*U(target))
		  } // end edge iteration

		  //cout << "\t\tAction: " << actions[a].getName()	\
		  //	   << "\tutility: " << utility << endl;
		  if (utility > max_utility)
			max_utility = utility;
		} // end action iteration
		tempList[i].utility = max_utility; // assign the new utility value to the stateList
	  } // end state iteration

	  if (horizon == INFINITY){
		rms = rootMeanSquareError(stateList, tempList);
		cout << "\t\tRMS= " << rms << endl;
	  }
	  State::updateUtility(stateList, tempList);
	}while(++iterator < horizon ||
		   (horizon == INFINITY && rms > EPSILON)); // end while
  } // end utilityIteration

  double rootMeanSquareError(std::vector<State> stateList,
							 std::vector<State> stateListPrime){
	if (stateList.size() != stateListPrime.size()){
	  cout << "Fatal error in rms: old and new vector aren't the same length!";
	  return -1.0;
	}
	double sum = 0.0;
	int numberOfStates = stateList.size();
	for (int i=0;i<numberOfStates;i++){
	  sum += pow(stateList[i].utility - stateListPrime[i].utility,2); // sum = (U-U')^2
	}
	sum = sqrt(sum)/ (double) numberOfStates;
	
  }
} // end namespace
