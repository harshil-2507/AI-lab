#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>
#include <algorithm> // Include this header for std::find

using namespace std;

// Heuristic function (Manhattan distance for 8-puzzle)
int heuristic(vector<int>& state, vector<int>& goal) {
    int distance = 0;
    for (int i = 0; i < 9; i++) {
        if (state[i] != 0) {
            int goalPos = find(goal.begin(), goal.end(), state[i]) - goal.begin();
            distance += abs(i / 3 - goalPos / 3) + abs(i % 3 - goalPos % 3);
        }
    }
    return distance;
}

// Best First Search for 8-puzzle
void bestFirstSearch8Puzzle(vector<int>& start, vector<int>& goal) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    unordered_set<string> visited;

    pq.push({heuristic(start, goal), start});
    visited.insert(string(start.begin(), start.end()));

    while (!pq.empty()) {
        auto current = pq.top().second;
        pq.pop();

        cout << "Current state: "<<endl;
        for (int i = 0; i < 9; i++) {
            cout << current[i] << " ";
            if ((i + 1) % 3 == 0) cout << endl;
        }
        cout << endl;

        if (current == goal) {
            cout << "Goal state reached!" << endl;
            return;
        }

        // Find the position of the empty tile (0)
        int zeroPos = find(current.begin(), current.end(), 0) - current.begin();
        int x = zeroPos / 3, y = zeroPos % 3;

        // Explore neighbors
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                vector<int> nextState = current;
                swap(nextState[zeroPos], nextState[nx * 3 + ny]);

                string nextStateStr = string(nextState.begin(), nextState.end());
                if (visited.find(nextStateStr) == visited.end()) {
                    visited.insert(nextStateStr);
                    pq.push({heuristic(nextState, goal), nextState});
                }
            }
        }
    }

    cout << "Goal state not reachable!" << endl;
}

int main() {
    vector<int> start = {1, 2, 3, 0, 4, 6, 7, 5, 8};
    vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    cout << "Starting Best First Search for 8-Puzzle..." << endl;
    bestFirstSearch8Puzzle(start, goal);
    return 0;
}