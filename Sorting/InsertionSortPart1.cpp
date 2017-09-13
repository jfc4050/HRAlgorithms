//
// Created by Justin Chiu on 9/13/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> createVector() {
    int size; cin >> size;
    vector<int> vec;
    int input;

    // read up until e;
    while (--size) {
        cin >> input;
        vec.push_back(input);
    }
    // duplicate last element;
//    vec.push_back(input);
    return vec;
}

void printVector(vector<int> vec) {
    for (int element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // create vector from elements up until e
    vector<int> vec = createVector();
    // read e
    int e; cin >> e;

    if (vec.back() < e) { // if e is already in order
        vec.push_back(e);   // add e to end
    }
    else if (vec.back() > e) {

        vec.push_back(vec.back()); // duplicate last element
        auto iter = vec.end() - 2;  // declare iterator, points to last element (not duplicate)
        // while iterator is not past beginning and item to left is greater than e
        while (iter >= vec.begin() and *iter > e) {
            *(iter + 1) = *iter; // copy *iter over to right
            iter--;
            printVector(vec);
        }
        *(iter+1) = e; // insert e
    }
    printVector(vec);
    return 0;
}