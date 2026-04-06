#ifndef FSM_GRAPHVIZ_H
#define FSM_GRAPHVIZ_H

#include <string>
#include"gen_state_table.h"
using namespace std;

void exportMooreFSM(node_moore start, string filename);
void exportMealyFSM(node_mealy start, string filename);

#endif