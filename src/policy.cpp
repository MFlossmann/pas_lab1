#include "mdp/policy.hpp"

namespace mdp{

  PolicyRow::PolicyRow(std::vector<State>& stateSpace){
	for (int i=0;i<stateSpace.size();i++){
	  stateSpace_.push_back(&stateSpace[i]);
	  actionIndices_.push_back(-1);	  
	}
  }

  PolicyRow::PolicyRow(const PolicyRow& policyRow){
	stateSpace_ = policyRow.stateSpace_;
	actionIndices_ = policyRow.actionIndices_;
  }

  PolicyRow::PolicyRow(){
	
  }

  // PolicyRow::PolicyRow(std::vector<State&> stateSpace){
  // 	//	stateSpace_= stateSpace;
  // 	for (int i=0;i<stateSpace.size();i++)
  // {
  // 	  stateSpace_.push_back(stateSpace[i]);
  // 	  actionIndices_.push_back(-1);
  // 	}
  // }

  Policy::Policy(std::vector<State>& stateSpace,
				 int horizon){
	PolicyRow tempRow(stateSpace);
	horizon_ = horizon;

	stateSpace_ = stateSpace;

	std::vector<int> dummyRow;
	dummyRow.assign(stateSpace.size(), -1);

	if (horizon <= 0){  // infinite horizon
	  policyMatrix_.push_back(dummyRow);
	  infiniteHorizon_ = true;
	}
	else{
	  //for(int i=0;i<horizon;i++)
	  //policyMatrix_.push_back(dummyRow);
	  policyMatrix_.assign(horizon, dummyRow);
	}
  }

  Policy::Policy(const Policy& policy){
	policyMatrix_ = policy.policyMatrix_;
	infiniteHorizon_ = policy.infiniteHorizon_;
	stateSpace_ = policy.stateSpace_;
	horizon_ = policy.horizon_;
  }

  Policy::~Policy(){

  }

  void Policy::calculate(std::vector<State> stateSpace,
						 int step){
	if (step<0 && !infiniteHorizon_){
	  std::cout << "Error! Step size out of bounds for finite horizon: " \
				<< step << std::endl;
	}
	if (infiniteHorizon_)
	  step = 0;

	std::vector<int> actionIndices;

	for (int i=0;i < stateSpace.size();i++){
	  Action bestAction;
	  double bestActionUtility = 0.0;
	  int bestActionIndex = 0; 
	  std::vector<Action> actions = stateSpace[i].getActions();
	  for (int a=0;a<actions.size();a++){
		double actionUtility = 0.0;
		std::vector<Edge> edges = actions[a].getEdges();
		for (int e=0;e<edges.size();e++){
		  actionUtility += edges[e].probability_ * edges[e].target_->utility;
		} // end going through edges

		if (actionUtility > bestActionUtility){ // found a (currently) best action
		  bestActionUtility = actionUtility;
		  bestAction = actions[a];
		  bestActionIndex = a;
		}
		
// #ifdef _VERBOSE_MODE_
// 		std::cout << "Utility action " << actions[a].getName()\
// 				  << ":\t" << actionUtility
// 				  << " (step " << step << ")" << std::endl;
// #endif
		
	  } // end going through actions

	  actionIndices.push_back(bestActionIndex);
	} // End going through stateSpace
	
	policyMatrix_.push_back(actionIndices);
	policyMatrix_.erase(policyMatrix_.begin());  // for some reason only works this way
  }

  void Policy::calculate(std::vector<State> stateSpace){
	calculate(stateSpace, -1);
  }

  void Policy::print(){
	std::cout << std::endl << std::endl << "Policy:" << std::endl << std::endl;
	for(int step=0; step<abs(horizon_) ;step++){ // abs(horizon_) for infinite horizons
	  std::cout << "⟨";
	  for (int state=0;state<stateSpace_.size();state++){
		std::cout << "( "<< stateSpace_[state].getName() << " , " ;

		//std::cout << "Actionindex: " << policyMatrix_[step][state] << std::endl;

		std::cout << stateSpace_[state].getActions()[policyMatrix_[step][state]].getName() << " ) ";
		  }
	  std::cout	<< "⟩" << std::endl;
	}
  }

  void Policy::printMatrix(){
	int step=0;
	do {
	  for (int state=0;state<stateSpace_.size();state++){
		std::cout << "\t" << policyMatrix_[step][state];
	  }
	  
	  std::cout << std::endl;
	} while (++step < horizon_);
  }

}
