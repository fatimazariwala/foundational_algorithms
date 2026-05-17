#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(int key,vector<int>&arr,int i,int j) {
    if (i==j && key != arr[i]) return -1;
    int mid = (i+j)/2;
    if (arr[mid] == key) {
        cout << "Imma here";
        return mid;
    } else if(arr[mid] > key) {
        return binary_search(key,arr,i,mid-1);
    } else {
        return binary_search(key,arr,mid+1,j);
    }
}
int main() {
    int z,key;
    cout << "Enter array Size: " << endl;
    cin >> z;
    cout << "Enter array elements: " << endl;
    vector<int> arr;
    for (int i=0;i<z;i++) {
        int el;
        cin >> el;
        arr.push_back(el);
    }
    sort(arr.begin(),arr.end());
    for (int i: arr) {
        cout << i;
    }
    cout << "Enter key: ";
    cin >> key;
    int key_ind = binary_search(key,arr,0,z-1);
    cout << "Found elemnet at: "<< key_ind <<endl;
    return 0;
}
