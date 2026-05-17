#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct object {
    float w;
    float p;
    float ratio;
    float x;
};

float greedyKnapsack(vector<object>& xp,float m,int objs) {
    int cu = m;
    int i =0;
    float profit;

    for(;i<objs;i++) {
        if (xp[i].w > cu) break;
        cu = cu - xp[i].w;
        xp[i].x = 1;
    }
    if (i!=objs) xp[i].x = cu/xp[i].w;

    int z = 0;
    while(z <= objs && xp[z].x != 0) {
        profit += (xp[z].x)*(xp[z].p);
        z++;
    }
    
    return profit;
}

int main() {
    //input format no_objs maxweight
    // obj1 -> p w
    // obj2 -> p w ..
    int no_obj; cin >> no_obj;
    int max_weight; cin >> max_weight;

    vector<object> px;
    for(int i=0;i<no_obj;i++) {
        float p,w,r,x;
        cin >> p;
        cin >> w;
        px.push_back({w,p,p/w,0});
    }

    sort(px.begin(),px.end(),[](const object&a,const object&b) {
        return a.ratio > b.ratio;
    });

    float final_profit = greedyKnapsack(px,max_weight,no_obj);
    cout << endl;
    cout << final_profit;
}