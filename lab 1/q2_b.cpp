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

    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int numNodes = adjMatrix.size();
    vector<bool> visited(numNodes, false);

    cout << "BFS Traversal: ";
   
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            bfs(i, adjMatrix, visited);
        }
    }

    return 0;
}
