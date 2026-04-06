#include "fsm_graphviz.h"
#include <fstream>
#include <set>
#include <cstdlib>

using namespace std;

void dfs_moore(node_moore node, ofstream &f, set<string> &visited){

    if(node == NULL || visited.count(node->state)) return;

    visited.insert(node->state);

    f << node->state << " [label=\""
      << node->state << "/" << node->output << "\"];\n";

    if(node->left){
        f << node->state << " -> " << node->left->state
          << " [label=\"0\"];\n";
        dfs_moore(node->left,f,visited);
    }

    if(node->right){
        f << node->state << " -> " << node->right->state
          << " [label=\"1\"];\n";
        dfs_moore(node->right,f,visited);
    }
}

void dfs_mealy(node_mealy node, ofstream &f, set<string> &visited){

    if(node == NULL || visited.count(node->state)) return;

    visited.insert(node->state);

    f << node->state << " [label=\"" << node->state << "\"];\n";

    if(node->left){
        f << node->state << " -> " << node->left->state
          << " [label=\"0/" << node->output_0 << "\"];\n";
        dfs_mealy(node->left,f,visited);
    }

    if(node->right){
        f << node->state << " -> " << node->right->state
          << " [label=\"1/" << node->output_1 << "\"];\n";
        dfs_mealy(node->right,f,visited);
    }
}

void exportMooreFSM(node_moore start, string filename){

    string dotfile = filename + ".dot";
    string pngfile = filename + ".png";

    ofstream f(dotfile);

    f << "digraph FSM {\n";
    f << "rankdir=LR;\n";

    set<string> visited;
    dfs_moore(start,f,visited);

    f << "}\n";
    f.close();

    string cmd = "dot -Tpng " + dotfile + " -o " + pngfile;
    system(cmd.c_str());
}

void exportMealyFSM(node_mealy start, string filename){

    string dotfile = filename + ".dot";
    string pngfile = filename + ".png";

    ofstream f(dotfile);

    f << "digraph FSM {\n";
    f << "rankdir=LR;\n";

    set<string> visited;
    dfs_mealy(start,f,visited);

    f << "}\n";
    f.close();

    string cmd = "dot -Tpng " + dotfile + " -o " + pngfile;
    system(cmd.c_str());
}