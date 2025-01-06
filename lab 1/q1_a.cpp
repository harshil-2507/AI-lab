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

    vector<vector<int>> adjMatrix = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0}
    };

    int numNodes = adjMatrix.size();
    vector<bool> visited(numNodes, false); 

    cout << "DFS Traversal: ";

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i, adjMatrix, visited);
        }
    }

    return 0;
}
