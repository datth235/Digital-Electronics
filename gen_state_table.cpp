#include"gen_state_table.h"
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<queue>
#include <iomanip>

using namespace std;

node_moore makenode_moore(string state){
    node_moore newnode_moore = new Node_Moore;
    newnode_moore->state = state;
    newnode_moore->output = "";
    newnode_moore->present_w = "";
    newnode_moore->left = NULL;
    newnode_moore->right = NULL;
    return newnode_moore;
}

node_moore findnode_moore(node_moore root, string present_w){ //bfs
    if(root == NULL) return NULL;

    queue<node_moore> q;
    set<node_moore> visited;

    q.push(root);
    visited.insert(root);

    while(!q.empty()){
        node_moore cur = q.front();
        q.pop();

        if(cur->present_w == present_w) return cur;

        if(cur->left && !visited.count(cur->left)){
            visited.insert(cur->left);
            q.push(cur->left);
        }

        if(cur->right && !visited.count(cur->right)){
            visited.insert(cur->right);
            q.push(cur->right);
        }
    }
    return NULL;
}

node_moore gen_moore(vector<string> w, string name){
    int cnt = 0;
    string first_state = name + to_string(cnt++); //State reset
    int size = w.size();
    node_moore moore = makenode_moore(first_state);
    map<string, int> sub_sequence;
    set<string> state; //store the state need to be detected
    for(string s : w) state.insert(s); 
    for(int i = 0; i < size; i++){
        string tmp = "";
        for(int j = 0; j < w[i].size(); j++){
            tmp += w[i][j];
            sub_sequence[tmp]++;
        }
    }
    queue<node_moore> q;
    q.push(moore);
    while(!q.empty()){
        node_moore present = q.front();
        q.pop();
        string present_w = present->present_w;
        if(state.count(present_w) == 0){ //it mean it's not the sequence we are looking for
            present->output = "0"; 
            string next_w_0 = present_w + '0';
            string next_w_1 = present_w + '1';
            if(sub_sequence[next_w_0]){ //it mean it's the new state
                node_moore newnode_moore = makenode_moore(name + to_string(cnt++));
                newnode_moore->present_w = next_w_0;
                present->left = newnode_moore;
                q.push(newnode_moore);
            }
            if(sub_sequence[next_w_1]){ //it mean it's the new state
                node_moore newnode_moore = makenode_moore(name + to_string(cnt++));
                newnode_moore->present_w = next_w_1;
                present->right = newnode_moore;
                q.push(newnode_moore);
            }
            if(!sub_sequence[next_w_0]){
                string res = "";
                string tmp = "";
                for(int i = next_w_0.size() - 1; i >= 0; i--){
                    tmp = next_w_0[i] + tmp;
                    if(sub_sequence[tmp]) res = tmp;
                }
                node_moore find = findnode_moore(moore, res);
                present->left = find;
            }
            if(!sub_sequence[next_w_1]){
                string res = "";
                string tmp = "";
                for(int i = next_w_1.size() - 1; i >= 0; i--){
                    tmp = next_w_1[i] + tmp;
                    if(sub_sequence[tmp]) res = tmp;
                }
                node_moore find = findnode_moore(moore, res);
                present->right = find;
            }
        }
        else{ //it mean it's the sequence we are looking for
            present->output = "1";
            string res = "";
            string tmp = "";
            string next_w_0 = present->present_w + '0';
            string next_w_1 = present->present_w + '1';
            for(int i = next_w_0.size() - 1; i >= 0; i--){
                tmp = next_w_0[i] + tmp;
                if(sub_sequence[tmp]) res = tmp;
            }
            node_moore find = findnode_moore(moore, res);
            present->left = find;
            res = "";
            tmp = "";
            for(int i = next_w_1.size() - 1; i >= 0; i--){
                tmp = next_w_1[i] + tmp;
                if(sub_sequence[tmp]) res = tmp;
            }
            find = findnode_moore(moore, res);
            present->right = find;
        }
    }
    return moore;
}

void print_moore_state_table(node_moore moore){
    if(moore == NULL) return;

    queue<node_moore> q;
    set<node_moore> visited;

    q.push(moore);
    visited.insert(moore);

    cout << "|----------------------------------------------------------|\n"; 
    cout << "|   Present state   |            Next state         |Output|\n";
    cout << "|                   |     w = 0     |     w = 1     |      |\n";
    cout << "|----------------------------------------------------------|\n";

    while(!q.empty()){
        node_moore cur = q.front();
        q.pop();

        cout << "|" << setw(19) << left << cur->state << "|" << setw(15) << left << cur->left->state << "|" << setw(15) << left << cur->right->state << "|" << setw(6)  << left << cur->output << "|\n";

        if(!visited.count(cur->left)){
            visited.insert(cur->left);
            q.push(cur->left);
        }

        if(!visited.count(cur->right)){
            visited.insert(cur->right);
            q.push(cur->right);
        }
    }
    cout << "|----------------------------------------------------------|\n";
}

node_mealy makenode_mealy(string state){
    node_mealy newnode_mealy = new Node_Mealy;
    newnode_mealy->state = state;
    newnode_mealy->present_w = "";
    newnode_mealy->output_0 = "";
    newnode_mealy->output_1 = "";
    newnode_mealy->left = NULL;
    newnode_mealy->right = NULL;
    return newnode_mealy;
}

node_mealy findnode_mealy(node_mealy mealy, string present_w){
    if(mealy == NULL) return NULL;

    queue<node_mealy> q;
    set<node_mealy> visited;

    q.push(mealy);
    visited.insert(mealy);

    while(!q.empty()){
        node_mealy cur = q.front();
        q.pop();

        if(cur->present_w == present_w) return cur;

        if(cur->left && !visited.count(cur->left)){
            visited.insert(cur->left);
            q.push(cur->left);
        }

        if(cur->right && !visited.count(cur->right)){
            visited.insert(cur->right);
            q.push(cur->right);
        }
    }
    return NULL;
}

node_mealy gen_mealy(vector<string> w, string name){
    int cnt = 0;
    string first_state = name + to_string(cnt++); //State reset
    int size = w.size();
    node_mealy mealy = makenode_mealy(first_state);
    map<string, int> sub_sequence;
    set<string> state; //store the state need to be detected
    for(string s : w) state.insert(s); 
    for(int i = 0; i < size; i++){
        string tmp = "";
        for(int j = 0; j < w[i].size() - 1; j++){
            tmp += w[i][j];
            sub_sequence[tmp]++;
        }
    }
    queue<node_mealy> q;
    q.push(mealy);
    while(!q.empty()){
        node_mealy present = q.front();
        q.pop();
        string present_w = present->present_w;
        string next_w_0 = present_w + '0';
        string next_w_1 = present_w + '1';
        if(state.count(next_w_0) == 0){ //it mean it's not sequence we are looking for, with input = 0
            present->output_0 = "0";
            if(sub_sequence[next_w_0]){ //new state
                node_mealy newnode_mealy = makenode_mealy(name + to_string(cnt++));
                newnode_mealy->present_w = next_w_0;
                present->left = newnode_mealy;
                q.push(newnode_mealy);
            }
            else{
                string res = "";
                string tmp = "";
                for(int i = next_w_0.size() - 1; i >= 0; i--){
                    tmp = next_w_0[i] + tmp;
                    if(sub_sequence[tmp]) res = tmp;
                }
                node_mealy find = findnode_mealy(mealy, res);
                present->left = find;
            }
        }
        if(state.count(next_w_1) == 0){ //it mean it's not sequence we are looking for, with input = 1
            present->output_1 = "0";
            if(sub_sequence[next_w_1]){ //new state
                node_mealy newnode_mealy = makenode_mealy(name + to_string(cnt++));
                newnode_mealy->present_w = next_w_1;
                present->right = newnode_mealy;
                q.push(newnode_mealy);
            }
            else{
                string res = "";
                string tmp = "";
                for(int i = next_w_1.size() - 1; i >= 0; i--){
                    tmp = next_w_1[i] + tmp;
                    if(sub_sequence[tmp]) res = tmp;
                }
                node_mealy find = findnode_mealy(mealy, res);
                present->right = find;
            }
        }
        if(state.count(next_w_0)){ //it mean it's sequence we are looking for, with input = 0
            present->output_0 = "1";
            string res = "";
            string tmp = "";
            for(int i = next_w_0.size() - 1; i >= 0; i--){
                tmp = next_w_0[i] + tmp;
                if(sub_sequence[tmp]) res = tmp;
            }
            node_mealy find = findnode_mealy(mealy, res);
            present->left = find;
        }
        if(state.count(next_w_1)){ //it mean it's sequence we are looking for, with input = 0
            present->output_1 = "1";
            string res = "";
            string tmp = "";
            for(int i = next_w_1.size() - 1; i >= 0; i--){
                tmp = next_w_1[i] + tmp;
                if(sub_sequence[tmp]) res = tmp;
            }
            node_mealy find = findnode_mealy(mealy, res);
            present->right = find;
        }
    }
    return mealy;
}

void print_mealy_state_table(node_mealy mealy){
    if(mealy == NULL) return;

    queue<node_mealy> q;
    set<node_mealy> visited;

    q.push(mealy);
    visited.insert(mealy);

    cout << "|-----------------------------------------------------------------------------------|\n"; 
    cout << "|   Present state   |            Next state         |             Output            |\n";
    cout << "|                   |     w = 0     |     w = 1     |     w = 0     |     w = 1     |\n";
    cout << "|-----------------------------------------------------------------------------------|\n";

    while(!q.empty()){
        node_mealy cur = q.front();
        q.pop();

        cout << "|" << setw(19) << left << cur->state << "|" << setw(15) << left << cur->left->state << "|" << setw(15) << left << cur->right->state << "|" << setw(15) << left << cur->output_0 << "|" << setw(15) << left << cur->output_1 << "|\n";

        if(cur->left && !visited.count(cur->left)){
            visited.insert(cur->left);
            q.push(cur->left);
        }

        if(cur->right && !visited.count(cur->right)){
            visited.insert(cur->right);
            q.push(cur->right);
        }
    }
    cout << "|-----------------------------------------------------------------------------------|\n";
}