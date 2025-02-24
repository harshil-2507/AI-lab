#include <bits/stdc++.h>
using namespace std;

// Maze configuration
const int N = 5;
int maze[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};
pair<int, int> start = {0, 0}, goal = {4, 4};

// Possible movements
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Utility function to check if position is valid
bool isValid(int x, int y, vector<vector<bool>> &visited) {
    return x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 0 && !visited[x][y];
}

// Print path
void printPath(vector<pair<int, int>> &path) {
    for (auto &p : path)
        cout << "(" << p.first << ", " << p.second << ") -> ";
    cout << "Goal\n";
}

// **DFS Algorithm**
void dfsUtil(int x, int y, vector<vector<bool>> &visited, vector<pair<int, int>> &path) {
    if (x == goal.first && y == goal.second) {
        printPath(path);
        return;
    }
    
    for (auto &dir : directions) {
        int nx = x + dir.first, ny = y + dir.second;
        if (isValid(nx, ny, visited)) {
            visited[nx][ny] = true;
            path.push_back({nx, ny});
            dfsUtil(nx, ny, visited, path);
            path.pop_back();
            visited[nx][ny] = false;
        }
    }
}

// Wrapper for DFS
void dfs() {
    cout << "DFS Path: ";
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<pair<int, int>> path = {start};
    visited[start.first][start.second] = true;
    dfsUtil(start.first, start.second, visited, path);
}

// **BFS Algorithm**
void bfs() {
    cout << "BFS Path: ";
    queue<vector<pair<int, int>>> q;
    set<pair<int, int>> visited;
    
    q.push({start});
    visited.insert(start);
    
    while (!q.empty()) {
        vector<pair<int, int>> path = q.front();
        q.pop();
        pair<int, int> current = path.back();
        
        if (current == goal) {
            printPath(path);
            return;
        }
        
        for (auto &dir : directions) {
            int nx = current.first + dir.first, ny = current.second + dir.second;
            if (isValid(nx, ny, *new vector<vector<bool>>(N, vector<bool>(N, false))) && visited.find({nx, ny}) == visited.end()) {
                vector<pair<int, int>> newPath = path;
                newPath.push_back({nx, ny});
                q.push(newPath);
                visited.insert({nx, ny});
            }
        }
    }
}

// **A* Search Algorithm**
struct Node {
    int x, y, g, h;
    vector<pair<int, int>> path;
    
    Node(int _x, int _y, int _g, int _h, vector<pair<int, int>> _path) 
        : x(_x), y(_y), g(_g), h(_h), path(_path) {}

    bool operator>(const Node &other) const {
        return (g + h) > (other.g + other.h);
    }
};

// Heuristic function (Manhattan Distance)
int heuristic(int x, int y) {
    return abs(x - goal.first) + abs(y - goal.second);
}

// A* Algorithm
void aStar() {
    cout << "A* Path: ";
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<pair<int, int>> visited;
    
    pq.push(Node(start.first, start.second, 0, heuristic(start.first, start.second), {start}));
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        if (current.x == goal.first && current.y == goal.second) {
            printPath(current.path);
            return;
        }
        
        if (visited.find({current.x, current.y}) != visited.end()) continue;
        visited.insert({current.x, current.y});
        
        for (auto &dir : directions) {
            int nx = current.x + dir.first, ny = current.y + dir.second;
            if (isValid(nx, ny, *new vector<vector<bool>>(N, vector<bool>(N, false))) && visited.find({nx, ny}) == visited.end()) {
                vector<pair<int, int>> newPath = current.path;
                newPath.push_back({nx, ny});
                pq.push(Node(nx, ny, current.g + 1, heuristic(nx, ny), newPath));
            }
        }
    }
}

int main() {
    cout << "Maze Solving Algorithms\n";
    dfs();
    bfs();
    aStar();
    return 0;
}
