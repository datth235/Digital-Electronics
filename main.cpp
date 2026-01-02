#include"gen_state_table.h"
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> w = {"0111"};
    node_moore x = gen_moore(w);
    print_moore_state_table(x);
    return 0;
}