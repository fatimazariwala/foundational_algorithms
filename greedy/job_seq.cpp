#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

struct job {
    int id;
    int deadline;
    int profit;
    bool alloted;
};

int job_schedule(vector<job>& xp,int sz,int d_max,vector<int>& sol) {
    int profit = 0;

    for (int i=0;i<sz;i++) {
        for(int z= (xp[i].deadline)-1;z!=-1;z--) {
            if (sol[z] == -1) {
                sol[z] = xp[i].id;
                xp[i].alloted = true;
                break;
            }
        }
    }

    for(int i=0;i<sz;i++) {
        if (xp[i].alloted != false) {
            profit += xp[i].profit;
        }
    }
    return profit;
}

int main() {
    // Input format: N - number of jobs
    // Job1 -> deadline profit
    // Job2 -> deadline profit
    // ....
    int no_jobs; cin >> no_jobs;
    vector<job> jp;
    int d_max = 0;
    for (int i=0;i<no_jobs;i++) {
        int d; cin >> d;
        int p; cin >> p;
        if (d > d_max) d_max = d;
        jp.push_back({i,d,p,false});  // Job id starts from Job-0,Job-1,Job-2 ...
    }

    vector<int> sol (d_max,-1);
    sort(jp.begin(),jp.end(),[](const job &a,const job &b){
        return a.profit > b.profit;
    });

    int max_profit = job_schedule(jp,no_jobs,d_max,sol);
    cout << "Following jobs will be completed at given deadlines with max possible profit => " << max_profit <<endl;
    for (int i=0;i<d_max;i++) {
        cout << "D: " << i+1 << " Job: " << sol[i] <<endl;
    }
}

