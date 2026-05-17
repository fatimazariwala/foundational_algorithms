#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void swap_el(int &a,int &b) {
    int z = a;
    a = b;
    b = z;
}

void selection_boy(vector<int>& arr,int z) {
    int min_ind = 0;
    for (int i=0;i<(z-1);i++){
        min_ind = i;
        for(int j=i+1;j<z;j++) {
            if (arr[min_ind] > arr[j]) {
                min_ind = j;
            }
        }
        swap_el(arr[i],arr[min_ind]);
    }
}

int main() {
    int z;
    cin >> z;
    vector<int> immaSelect;
    for (int i=0;i<z;i++) {
        int el;
        cin >> el;
        immaSelect.push_back(el);
    }
    selection_boy(immaSelect,z);
    for (int i=0;i<z;i++) {
        cout<<immaSelect[i];
    }
    return 0;
}