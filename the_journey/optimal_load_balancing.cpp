#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct server {
    int id;
    int capacity;
    int alloted;
    bool operator>(const server& other) const {
        return alloted > other.alloted; 
    }
};

server allocate(priority_queue<server,vector<server>,greater<server>> &s) {
    if (s.empty()) {
        return {-1,-1,-1};
    }
    server al = s.top();
    //cout << "Alloted server: " << al.id << " " << al.capacity <<" " << al.alloted << endl;
    s.pop();
    if (al.capacity != al.alloted) {
        al.alloted ++;
        s.push(al);
    } else {
        allocate(s);
    }
    return al;
}

int main() {

    int s; cin >> s;
    priority_queue<server,vector<server>,greater<server>> servers;
    vector<int> task;
    for (int i=0;i<s;i++) {
        int c; cin >> c;
        servers.push({i,c,0});
    }
    int t; cin >> t;
    server max_alloc;
    for (int i=0;i<t;i++) {
        int ta; cin >> ta;
        task.push_back(ta);
    }
    for (int i=0;i<t;i++) {
        for(int j=0;j<task[i];j++) {
            server a = allocate(servers);
            //cout << "After: " << a.id <<" "<< a.capacity << " " << a.alloted << endl ;
            if (a.alloted == -1) {
                std::cout << "No further allocation possible";
                return 0;
            }
            if (i == t-1 && j == task[i]-1) {
                max_alloc = a;
            }
        }
    }
    std::cout << "Min Load Diff: " << max_alloc.alloted - servers.top().alloted;
}