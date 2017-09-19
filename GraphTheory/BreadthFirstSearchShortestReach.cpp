//
// Created by Justin Chiu on 9/19/17.
//

#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int val;
    std::vector<Node*> links {};

    explicit Node(int nodeNum) {
        val = nodeNum;
    }
};

class Graph {
public:
    std::vector<Node*> nodePtrs {};

    //Add nodes to graph
    void addNode(int newNode){
        auto* newPtr = new Node(newNode);   //create new pointer and add to vector of pointers
        nodePtrs.push_back(newPtr);
    }
};

void populateGraph(Graph& grph){
    int nodes, edges; std::cin >> nodes >> edges;  //get nodes and edges from user input

    grph.nodePtrs.push_back(nullptr);
    //populate graph with nodes, starting at index 1
    for (int nodeInd = 1 ; nodeInd <= nodes ; ++nodeInd) {
        grph.addNode(nodeInd);
    }

    //specify edges connecting nodes
    while (edges--) {
        unsigned long nodeNum1, nodeNum2;
        std::cin >> nodeNum1 >> nodeNum2;
        Node* node1Ptr = grph.nodePtrs.at(nodeNum1);               //create pointers to nodes
        Node* node2Ptr = grph.nodePtrs.at(nodeNum2);
        node1Ptr->links.push_back(node2Ptr);   //add pointer to Node at NodeNum1
        node2Ptr->links.push_back(node1Ptr);   //add pointer to Node at NodeNum2
    }
}

class BFStracking {
public:
    int dist = 6;
    std::vector<int> explored {};
    std::queue<Node*> que {};

    void increment(int amt=6){
        dist += amt;
    }
    void addToExplored(Node* exploredNodePtr){
        explored.push_back(exploredNodePtr->val);
    }
    void enQue(Node* nodePtr){
        que.push(nodePtr);
    } Node* deQue(){
        Node* temp = que.front();
        que.pop();
        return temp;
    }
};

int breadthFirstSearch(int search, BFStracking& track, Node* startPtr = nullptr) {
    if (startPtr == nullptr) {
        startPtr = track.deQue();
    }
    track.addToExplored(startPtr);
    for (Node* pntr : startPtr->links) {
        if (pntr->val == search) {
            return track.dist;
        } else if (std::find(track.explored.begin(), track.explored.end(), pntr->val) == track.explored.end()) {
            track.enQue(pntr);
        }
    }
    track.increment();
    if (!track.que.empty()) {
        return breadthFirstSearch(search, track);
    }
    else {
        return -1;
    }

}

int main() {
    int queries; std::cin >> queries;       //get number of queries from user input

    //for each query:
    while (queries--) {
        Graph grph;                 //create new graph object
        populateGraph(grph);        //populate Graph
        unsigned long start; std::cin >> start;
        Node* startPtr = grph.nodePtrs.at(start);
        for (Node* nodePtr : grph.nodePtrs) {
            if (nodePtr == nullptr or nodePtr->val == start) { ; }
            else {
                BFStracking tracker;
                std::cout << breadthFirstSearch(nodePtr->val, tracker, startPtr) << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}