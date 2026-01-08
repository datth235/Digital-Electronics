#include"gen_state_table.h"
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cout << "Nhap so chuoi w muon phat hien: ";
    cin >> n;
    vector<string> w;
    string s;
    cout << "Nhap chuoi muon phat hien: \n";
    for(int i = 0; i < n; i++){
        cout << i + 1 << ": ";
        cin >> s;
        w.push_back(s);
    }
    cout << "Mo hinh muon su dung\n";
    cout << "1. Moore\n";
    cout << "2. Mealy\n";
    cout << "Nhap lua chon: ";
    cin >> n;
    if(n == 1){
        node_moore moore = gen_moore(w);
        print_moore_state_table(moore);
        cout << "Bang ma hoa: \n";
        map<node_moore, string> mp = encode_moore_state_table(moore);
    }
    else if(n == 2){
        node_mealy mealy = gen_mealy(w);
        print_mealy_state_table(mealy);
        cout << "Bang ma hoa: \n";
        map<node_mealy, string> mp = encode_mealy_state_table(mealy);
    }
    else{
        cout << "ERROR\n";
    }
    return 0;
}