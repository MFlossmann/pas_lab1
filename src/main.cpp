
#include <iostream>
#include <stdlib.h>
#include "mdp/mdp.hpp"
#include "mdp/state.hpp"
#include "mdp/action.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  std::vector<mdp::State> stateList;
  stateList.push_back(mdp::State("born",0.0));
  stateList.push_back(mdp::State("init",0.0));
  stateList.push_back(mdp::State("Level 1",0.0));
  stateList.push_back(mdp::State("Level 2",0.0));
  mdp::Action growUp("grow up",0.0);
  growUp.addEdge("normal",stateList[1],0.95); // Normal kid
  growUp.addEdge("talented",stateList[2],0.04); // Talented
  growUp.addEdge("genious",stateList[3],0.01); // Genious
  stateList[0].addAction(growUp);
  
  // from init human
  mdp::Action workHard("work hard",-2000.0);
  workHard.addEdge("success",stateList[3],0.7);
  workHard.addEdge("neutral",stateList[2],0.2);
  workHard.addEdge("failed", stateList[1],0.1);
  stateList[1].addAction(workHard);
  mdp::Action playHard("play hard",-5.);
  playHard.addEdge("success",stateList[2],0.7);
  playHard.addEdge("failed",stateList[1],0.3);
  stateList[1].addAction(playHard);
  mdp::Action slackOff("slack off",1.);
  slackOff.addEdge("...zzz...",stateList[1],1.);
  stateList[1].addAction(slackOff);

  // from Level 1 human
  workHard = mdp::Action("work hard", -2000.0);
  workHard.addEdge("success",stateList[3],0.7);
  workHard.addEdge("failed",stateList[2],0.3);
  stateList[2].addAction(workHard);
  playHard = mdp::Action("play hard", 2.);
  playHard.addEdge("success",stateList[2],0.8);
  playHard.addEdge("failed",stateList[1],0.2);
  stateList[2].addAction(playHard);

  // from Level 2 human
  slackOff = mdp::Action("slack off", 4.);
  slackOff.addEdge("...zzz...",stateList[3],.2);
  slackOff.addEdge("overslept",stateList[2],.8);
  stateList[3].addAction(slackOff);

  int horizon = 20;
  if (argc >=2)
	horizon = atoi(argv[1]);
  mdp::Policy policy = mdp::utilityIteration(stateList, horizon);

  policy.print();

  return 0;
}
