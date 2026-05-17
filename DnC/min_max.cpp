#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> mini_maxi(vector<int> &arr,int start,int end) {
    int mini,maxi;
    mini = maxi = 0;
    if (start==end) {
        mini = maxi = arr[0];
        return {mini,maxi};
    } else if (start == end-1) {
        if(arr[start] > arr[end]) {
            maxi=arr[start];
            mini=arr[end];
        } else {
            maxi=arr[end];
            mini=arr[start];
        }
        return {mini,maxi};
    } else {
        int mid = (start + end)/2;
        int min1,min2,max1,max2;
        pair<int,int> p0 = mini_maxi(arr,start,mid);
        pair<int,int> p1 = mini_maxi(arr,mid+1,end);
        if (p0.first < p1.first) {
            mini = p0.first;
        }else {
            mini = p1.first;
        }
        if (p0.second > p1.second) {
            maxi = p0.second;
        }else {
            maxi = p1.second;
        }
    }
    return {mini,maxi};
}
int main() {
    int z;
    cin >> z;
    vector<int> arr;
    for (int i=0;i<z;i++) {
        int el;
        cin >> el;
        arr.push_back(el);
    }
    pair<int,int> p = mini_maxi(arr,0,z-1);
    cout << "Min: " << p.first << " Max: " << p.second;
    return 0;
}