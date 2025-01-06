#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(int startNode, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adjMatrix[node].size(); i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int numNodes;


    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;


    vector<vector<int>> adjMatrix(numNodes, vector<int>(numNodes, 0));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<bool> visited(numNodes, false);
    cout << "BFS Traversal: ";
    bfs(startNode, adjMatrix, visited);
    cout << endl;

    return 0;
}
