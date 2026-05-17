#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int>&arr,int z) {
    for (int i = 1;i<z;i++) {
        int key = arr[i];
        int j = i-1;
        while (j!=-1 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
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
    insert_sort(arr,z);
    for (int i=0;i<z;i++) {
        cout<<arr[i]<< " ";
    }
    return 0;
}