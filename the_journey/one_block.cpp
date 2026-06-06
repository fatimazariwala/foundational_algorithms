#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long f(int S, int N, vector<int>&Arr, int index) {
    if (index >= N) {
        if (S==-501) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int add =0;
        if (S==-501) {
            add = Arr[index];
        } else {
            add = S + Arr[index];
        }
        long long ret=0;
        if (add == 1) {
            ret += f(-501,N,Arr, index+1);
        }
        ret += f(add,N, Arr, index+1);
        return ret;
    }
}

long long OneBlock (int N, vector<int> Arr) {
    long long final = f(-501,N, Arr, 0);
    if (final == 0) final = -1; 
    return final;
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> Arr(N);
    for(int i_Arr = 0; i_Arr < N; i_Arr++)
        cin >> Arr[i_Arr];
    long long out_;
    out_ = OneBlock(N, Arr);
    cout << out_;
}