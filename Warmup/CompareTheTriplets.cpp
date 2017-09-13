//
// Created by Justin Chiu on 9/12/17.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    array<int, 3> alice {}, bob {};

    for (int i = 0 ; i < 3 ; ++i){
        cin >> alice[i];
    }
    for (int i = 0 ; i < 3 ; ++i){
        cin >> bob[i];
    }

    int aliceScore = 0;
    int bobScore = 0;
    for (int i = 0 ; i < 3 ; ++i){
        if (alice[i] > bob[i]) {
            aliceScore++;
        }
        if (bob[i] > alice[i]) {
            bobScore++;
        }
    }
    cout << aliceScore << " " << bobScore;
    return 0;
}

