//
// Created by Justin Chiu on 9/12/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int targetVal, size;
    cin >> targetVal >> size;
    int val;
    int index = 0;
    while (cin >> val and val != targetVal) {
        index++;
    }
    cout << index;
    return 0;
}