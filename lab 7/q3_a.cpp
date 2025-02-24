#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maze = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

pair<int, int> goal = {4, 4};

int heuristic(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void bestFirstSearchMaze(pair<int, int> start) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

    pq.push({heuristic(start, goal), start});
    visited[start.first][start.second] = true;

    while (!pq.empty()) {
        auto current = pq.top().second;
        pq.pop();

        cout << "Visiting: (" << current.first << ", " << current.second << ")" << endl;

        if (current == goal) {
            cout << "Goal reached!" << endl;
            return;
        }

        // Explore neighbors
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int x = current.first + dir.first;
            int y = current.second + dir.second;

            if (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0 && !visited[x][y]) {
                visited[x][y] = true;
                pq.push({heuristic({x, y}, goal), {x, y}});
            }
        }
    }

    cout << "Goal not reachable!" << endl;
}

int main() {
    pair<int, int> start = {0, 0};
    cout << "Starting Best First Search for Maze..." << endl;
    bestFirstSearchMaze(start);
    return 0;
}