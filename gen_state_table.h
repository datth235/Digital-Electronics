#ifndef GEN_STATE_TABLE_H
#define GEN_STATE_TABLE_H

#include<vector>
#include<string>
#include<map>
using namespace std;
typedef pair<string, string> pss;

struct Node_Moore{ //output only depend on present state
    string state;
    string output;
    string present_w;
    Node_Moore* left; //when input = 0
    Node_Moore* right; //when input = 1
};

typedef Node_Moore* node_moore;

struct Node_Mealy{ //output depend on input and present state
    string state;
    string present_w;
    string output_0;
    string output_1;
    Node_Mealy* left; //when input = 0
    Node_Mealy* right; //when input = 1
};

typedef Node_Mealy* node_mealy;

node_moore gen_moore(vector<string> w, string name = "A");
int count_state(node_moore moore);
map<node_moore, string> encode_moore_state_table(node_moore moore);
void print_moore_state_table(node_moore moore);

node_mealy gen_mealy(vector<string> w, string name = "A");
int count_state(node_mealy mealy);
map<node_mealy, string> encode_mealy_state_table(node_mealy mealy);
void print_mealy_state_table(node_mealy mealy);

#endif  