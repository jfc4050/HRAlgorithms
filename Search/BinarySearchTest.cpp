//
// Created by Justin Chiu on 9/13/17.
//

#include <vector>
#include <iostream>
using namespace std;

int binarySearch(int first, int last, vector<int> arr, int search) {
    int mid = (first + last) / 2;
    if (arr[mid] == search) {
        return mid;
    } else {
        if (arr[mid] > search) {
            return binarySearch(first, mid - 1, arr, search);
        } else if (arr[mid] < search) {
            return binarySearch(mid + 1, last, arr, search);
        }
    }
    return -1;
}

int main() {
    vector<int> vect = {1, 2, 3, 4, 5};
    int first = 0;
    int last = 4;
    int search = 4;
    cout << binarySearch(first, last, vect, search);
}