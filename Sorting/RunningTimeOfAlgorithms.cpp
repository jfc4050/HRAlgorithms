//
// Created by Justin Chiu on 9/13/17.
//

#include <vector>
#include <iostream>
using namespace std;

vector<int> createVector() {
    int size; cin >> size;
    vector<int> vec;
    while (size--) {
        int element; cin >> element;
        vec.push_back(element);
    }
    return vec;
}

void printVector(vector<int> vec) {
    for (int element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vect = createVector(); // generate vector from user input
    //for each field in vector (besides first):
    unsigned int shifts = 0;
    for (auto iter = (vect.begin() + 1) ; iter != vect.end() ; ++iter) {
        auto temp = iter;
        // while temp iterator not at beginning and current number less than number before temp
        while (temp > vect.begin() and *iter < *(temp - 1)) {
            temp--;
            shifts++;
        }
        if (temp != iter) {  // if needed, swap elements
            int val = *iter;
            vect.erase(iter);
            vect.insert(temp, val);
        }
    }
    cout << shifts << endl;
    return 0;
}