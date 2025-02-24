#include <bits/stdc++.h>
using namespace std;

struct Node {
    int vertex;
    int cost;
    Node(int v, int c) : vertex(v), cost(c) {}
};

struct Compare {
    bool operator()(Node const& a, Node const& b) {
        return a.cost > b.cost;
    }
};

vector<int> bestFirstSearch(int start, int goal, unordered_map<int, vector<Node>>& graph) {
    priority_queue<Node, vector<Node>, Compare> pq;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    vector<int> path;

    pq.push(Node(start, 0));
    visited[start] = true;
    parent[start] = -1;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.vertex == goal) {
            int temp = goal;
            while (temp != -1) {
                path.push_back(temp);
                temp = parent[temp];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto& neighbor : graph[current.vertex]) {
            if (!visited[neighbor.vertex]) {
                pq.push(neighbor);
                visited[neighbor.vertex] = true;
                parent[neighbor.vertex] = current.vertex;
            }
        }
    }
    return {}; 
}

int main() {
    unordered_map<int, vector<Node>> graph;

    graph[0] = {{1, 3}, {2, 6}, {3, 5}};
    graph[1] = {{4, 9}, {5, 8}};
    graph[2] = {{5, 12}, {6, 14}};
    graph[3] = {{6, 7}};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {{7, 5}, {8, 6}};
    graph[7] = {{9, 1}, {10, 10}};
    graph[8] = {{11, 2}, {12, 6}};
    graph[9] = {};
    graph[10] = {};
    graph[11] = {};
    graph[12] = {};

    int start = 0; 
    int goal1 = 9; 
    int goal2 = 8; 

    vector<int> pathToGoal1 = bestFirstSearch(start, goal1, graph);
    vector<int> pathToGoal2 = bestFirstSearch(start, goal2, graph);

    cout << "Path to node I: ";
    for (int node : pathToGoal1) cout << node << " ";
    cout << endl;

    cout << "Path to node J: ";
    for (int node : pathToGoal2) cout << node << " ";
    cout << endl;

    return 0;
}