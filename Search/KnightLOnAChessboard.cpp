//
// Created by Justin on 9/26/17.
//

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

#include <iostream>
#include <utility>
#include <queue>
#include <functional>
#include <vector>

class Knight {
private:
    std::pair<int, int> location;
    std::queue<std::pair<int, int> > que;
    std::vector<std::pair<int, int> > visitedPairs;
    std::vector<std::pair<int, int> > currentLevel;
    int aRange;
    int bRange;
    int bound;

    std::pair<int, int> upRight(const std::pair<int, int> &start) {
        int y = start.second + aRange;
        int x = start.first + bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> upLeft(const std::pair<int, int> &start) {
        int y = start.second + aRange;
        int x = start.first - bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> downRight(const std::pair<int, int> &start) {
        int y = start.second - aRange;
        int x = start.first + bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> downLeft(const std::pair<int, int> &start) {
        int y = start.second - aRange;
        int x = start.first - bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> rightUp(const std::pair<int, int> &start) {
        int x = start.first + aRange;
        int y = start.second + bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> rightDown(const std::pair<int, int> &start) {
        int x = start.first + aRange;
        int y = start.second - bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> leftUp(const std::pair<int, int> &start) {
        int x = start.first - aRange;
        int y = start.second + bRange;
        return std::make_pair(x, y);
    }

    std::pair<int, int> leftDown(const std::pair<int, int> &start) {
        int x = start.first - aRange;
        int y = start.second - bRange;
        return std::make_pair(x, y);
    }

    bool visited(std::pair<int, int> curPair) {
        for (std::pair<int, int> visitedPair : visitedPairs) {
            if (curPair == visitedPair) {
                return true;
            }
        }
        return false;
    }

    void printVisited() {
        for (std::pair<int, int> coord : visitedPairs) {
            printPair(coord);
        }
        std::cout << "\n";
    }

    void printPair(std::pair<int, int> coord) {
        std::cout << "(" << coord.first << "," << coord.second << ")" << " ";
    }

public:
    Knight() {
        location = std::make_pair(0, 0);
        que.push(location);
        visitedPairs.push_back(location);
        aRange = 0;
        bRange = 0;
    }

    Knight(int aIn = 1, int bIn = 3, int boundIn = 5) {
        location = std::make_pair(0, 0);
        bound = boundIn;
        que.push(location);
        visitedPairs.push_back(location);
        aRange = aIn;
        bRange = bIn;
    }

    int breadthFirstSearch() {
        typedef std::pair<int, int> (Knight::* funcPtr)(const std::pair<int, int> &start);

        funcPtr funcArr[]{
                &Knight::upRight,
                &Knight::upLeft,
                &Knight::downRight,
                &Knight::downLeft,
                &Knight::rightUp,
                &Knight::rightDown,
                &Knight::leftUp,
                &Knight::leftDown
        };

        std::pair<int, int> target = std::make_pair(bound - 1, bound - 1);
        int moves = 0;

        while (!que.empty()) {
            while (!que.empty()) {
                std::pair<int, int> &current = que.front();
                que.pop();
                if (current == target) {
                    return moves;
                } else {
                    currentLevel.push_back(current);
                }
            }
            moves++;
            for (std::pair<int, int> curPair : currentLevel) {
                for (funcPtr movement : funcArr) {
//                    std::pair<int, int> result = std::invoke(movement, *this, curPair);
                    std::pair<int,int> result = CALL_MEMBER_FN(*this, movement)(curPair);

                    if (result == target)
                        return moves;

                    if (result.first >= 0 and result.first < bound and result.second >= 0 and result.second < bound and
                        not visited(result)) {
                        que.push(result);
                        visitedPairs.push_back(result);
                    }
                }
            }
            currentLevel.clear();
        }
        return -1;
    }
};

int main() {
    int bound;
    std::cin >> bound;
//    bound = 5;

    for (int i = 1 ; i < bound ; ++i) {
        for (int j = 1 ; j < bound ; ++j) {
            auto* myKnight = new Knight(i, j, bound);
            std::cout << myKnight->breadthFirstSearch() << " ";
            delete myKnight;
        }
        std::cout << "\n";
    }

    return 0;
}