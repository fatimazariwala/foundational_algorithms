#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int pivot(vector<int> &arr,int low,int high) {
    int key = arr[low]; // Pivot element is the first element
    int m = low;
    int i = m+1;
    int j = high;

    while(i<j) {
        while(i!=high+1 && arr[i]<key) {
            i++;
        }
        while(arr[j]>key) {
            j--;
        }
        if(i<j) {
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    swap(arr[m],arr[j]);
    return j; 
}

void QuickSort(vector<int> &arr,int low,int high) {
    if (low > high) return;

    int p_ind = pivot(arr,low,high);

    QuickSort(arr,low,p_ind-1);
    QuickSort(arr,p_ind+1,high);
}

int main() {
    int sz; cin >> sz;
    vector<int> arr;
    for(int i=0;i<sz;i++) {
        int el; cin >> el; arr.push_back(el);
    }
    QuickSort(arr,0,sz-1);
    for (int i=0;i<sz;i++) {
        cout << arr[i] <<" ";
    }
}
