#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

pair<int,int> get_min_relaxed_edge(vector<vector<double>>&near) {
    auto a = min_element(near.begin(),near.end(),[](const vector<double> rowA,const vector<double> rowB) {
        return rowA[1] < rowB[1];
    });

    int i = a - near.begin();
    int j = (int)(*a)[0];
    return {i,j};
}

int main() {
    double inf = numeric_limits<double>::infinity();
    // Input format
    // No. of vertices
    // No. of edges
    // Cost in format: edge1 edge2 cost
    double mincost;
    int v; cin >> v;
    int e; cin >> e;
    vector<vector<double>> cost (v,vector<double>(v,inf));
    vector<vector<double>> near (v,vector<double>(2,inf));
    vector<vector<int>> t (v-1,vector<int>(2,0));

    double min_cost=inf;
    int edge_mc_1,edge_mc_2;

    for (int i=0;i<v;i++) {
        cost[i][i] = 0.0;
    }

    cout << "Indexing of vertices must start from zero" << endl;


    for (int i=0;i<e;i++) {
        int v1; cin >> v1; // Vertex 1 of edge 1
        int v2; cin >> v2; // vertex 2 of edge 2
        double c; cin >> c; // Cost of (v1,v2)

        cost[v1][v2] = c;
        cost[v2][v1] = c;
        // indexing of vetors with start from zero

        if (c < min_cost) {
            min_cost = c;
            edge_mc_1 = v1;
            edge_mc_2 = v2;
        }
    } 

    near[edge_mc_1][0] = 0.0;
    near[edge_mc_2][0] = 0.0;
    mincost = min_cost;
    
    t[0][0] = edge_mc_1;
    t[0][1] = edge_mc_2;

    for (int i=0;i<v;i++) {
        if(i != edge_mc_1 && i != edge_mc_2) {
            if (cost[i][edge_mc_1] < cost[i][edge_mc_2]) {
                near[i][0] = (double)edge_mc_1;
                near[i][1] = cost[i][edge_mc_1];
            } else {
                near[i][0] = (double)edge_mc_2;
                near[i][1] = cost[i][edge_mc_2];
            }
        } 
    }

    // for (int i=0;i<v;i++) {
    //     cout << near[i][0] << " " << near[i][1]<<endl;
    // }
    
    for (int i=1;i<(v-1);i++) {
        pair<int,int> min_e = get_min_relaxed_edge(near);
       // cout << "Relaxed Edge: " << min_e.second << " " << min_e.first << " Cost: " << near[min_e.first][1] << endl;
        int j = min_e.first;

        mincost += cost[min_e.second][min_e.first];
        t[i][0] = j;
        t[i][1] = min_e.second;
        near[j][0] = 0.0;
        near[j][1] = inf;

        for (int i=0;i<v;i++) {
            if(near[i][0] != 0.0 && near[i][1] > cost[i][j]) {
                near[i][0] = (double)j;
                near[i][1] = cost[i][j]; 
            }
        }
    }

    cout << "Solution matrix" << endl;

    for (int i=0;i<t.size();i++) {
        cout << t[i][0] << " " << t[i][1] << endl;
    }

    cout << "MSCT Cost is: " << mincost;

}