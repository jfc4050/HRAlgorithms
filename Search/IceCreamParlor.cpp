//
// Created by Justin Chiu on 9/13/17.
//

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class IceCream {
public:
    int cost;
    int index;

    IceCream(const int& costIn, const int& indexIn) {
        cost = costIn;
        index = indexIn;
    }
};

bool compareByCost(const IceCream& i1, const IceCream& i2) {
    return i1.cost < i2.cost;
}

int binarySearch(int first, int last, const vector<IceCream>& vect, const int& search) {
    int mid = (first + last) / 2;

    if (vect[mid].cost == search) {
        return vect[mid].index;
    } else if (search < vect[mid].cost) {
        return binarySearch(first, mid - 1, vect, search);
    } else if (search > vect[mid].cost) {
        return binarySearch(mid + 1, last, vect, search);
    }
    return -1;
}

int main() {
    int trips;
    cin >> trips;

    while (trips--) {
        int money, flavors;
        cin >> money
            >> flavors;

        vector<IceCream> flavorList;

        for (int i = 0; i < flavors; ++i) {
            int cost; cin >> cost;
            flavorList.emplace_back(IceCream(cost, i + 1));
        }
        sort(flavorList.begin(), flavorList.end(), compareByCost);

        int i = 0;
        for (IceCream flavor : flavorList) {
            if (money > flavor.cost) {
                int remaining = money - flavor.cost;
                int index = binarySearch(i + 1, flavors - 1, flavorList, remaining);
                if (index != -1) {
                    cout << min(flavor.index, index) << " " << max(flavor.index, index) << endl;
                    break;
                }
            }
        }
    }
}



