
#include <iostream>
#include "mdp/state.hpp"
#include "mdp/action.hpp"

int main(int argc, char* argv[])
{
  mdp::State state0("state0");
  mdp::State state1("state1");
  mdp::Action action0("action0");
  
  action0.addEdge(state1, 1.0, 0);
  
  state0.addAction(action0);
  
  return 0;
}
