#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr, int n) {
    int swap = 0;
    for (int i=0;i<(n-1);i++) {
        swap = 0;
        for(int j=0;j<(n-1)-i;j++) {
            if (arr[j]>arr[j+1]) {
                int x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
                swap = 1;
            }
        }
        if (swap == 0) {
            break;
        }
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int el;
        cin >> el;
        arr.push_back(el);
    }
    bubble_sort(arr,n);
    for (int i=0;i<n;i++) {
        cout << arr[i];
    }
}