#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> a = {{2,3,4},{5,6,7},{8,0,10}};
    cout << "Size of Double" << sizeof(double) <<endl;
    auto m = min_element(a.begin(),a.end(),[](const vector<int> &a,const vector<int> &b) {
        return a[1] < b[1];
    });
    cout << "Found Min: " << (*m)[1] << " " << "Next to it: " << (*m)[0] << endl;
    cout << "ROw at: " << m - a.begin() <<endl;
    return 0;
}

