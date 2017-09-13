//
// Created by Justin Chiu on 9/12/17.
//

#include <iostream>
using namespace std;


int main() {
    int size;
    cin >> size;
    int sum = 0;
    while (size--) {
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum;

    return 0;
}

