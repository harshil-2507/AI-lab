#include <iostream>
#include <vector>
using namespace std;


void dfs(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adjMatrix[node].size(); i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            dfs(i, adjMatrix, visited);
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
    cout << "DFS Traversal: ";
    dfs(startNode, adjMatrix, visited);
    cout << endl;

    return 0;
}
