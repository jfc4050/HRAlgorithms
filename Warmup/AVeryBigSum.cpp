//
// Created by Justin Chiu on 9/12/17.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numbers;
    cin >> numbers;
    long sum = 0;
    while (numbers--) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}

