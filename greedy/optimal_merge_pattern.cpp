#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> optimal_merge(priority_queue<int,vector<int>,greater<int>>  &a,int sz) {
    int rec = 0;
    int comp;
    while (a.size() > 1) {
        int z = a.top();
        a.pop();
        int x = a.top();
        a.pop();
        rec += z + x;
        a.push(rec);
    }
    comp = rec - (sz-1);
    return {rec,comp};
} 

int main() {
    int no_files; cin >> no_files;
    vector<int> files;
    priority_queue <int,vector<int>,greater<int>> minheap;
    for (int i=0;i<no_files;i++) {
        int sz_file; cin >> sz_file;
        files.push_back(sz_file);
    }
    for(int i=0;i<no_files;i++) {
        minheap.push(files[i]);
    }
    pair <int,int> rec_comp = optimal_merge(minheap,no_files);
    cout << "No. of Recording Movement to merge the Files: " << rec_comp.first<< endl;
    cout << "No. of comparisions required to merge the Files: " << rec_comp.second << endl;
}