#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


void mergeAlgo(vector<int> &arr,int i,int mid,int j) {
    int l=i;
    int h=mid+1;
    vector<int> b;
    while (l <= mid && h <= j) {
        if (arr[l] < arr[h]) {
            b.push_back(arr[l]);
            l++;
        } else {
            b.push_back(arr[h]);
            h++;
        }
    }
    
    if (l > mid) {
        for (int x=h;x<=j;x++) {
            b.push_back(arr[x]);
        }
    } else {
        for (int x=l;x<=mid;x++) {
            b.push_back(arr[x]);
        }
    }

    int z = 0;
    for(int x = i; x<=j;x++) {
        arr[x] = b[z];
        z++;
    }
}

void mergeSort(vector<int> &arr,int low,int high) {
    if (low == high) {
        return;
    } else {
        int mid = (low + high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        mergeAlgo(arr,low,mid,high);
    }
}

void pushElements(vector<int> &arr,int sz) {
    for (int i=0;i<sz;i++) {
        int el;
        cin >> el;
        arr.push_back(el);
    }
}

int main() {
    int arr_sz;
    vector<int> arr;
    cin >> arr_sz;

    pushElements(arr,arr_sz);

    mergeSort(arr,0,arr_sz-1);

    for(int i=0;i<=arr_sz-1;i++) {
        cout << arr[i] << " ";
    }
}

