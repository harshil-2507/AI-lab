#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

bool depthLimitedSearchMaze(vector<vector<int>>& maze, int x, int y, int depth, int limit, vector<pair<int, int>>& path) {
    if (depth > limit) return false;
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 1) return false;
    if (maze[x][y] == 9) {
        path.push_back({x, y});
        return true;
    }

    maze[x][y] = 1;
    path.push_back({x, y}); 

    if (depthLimitedSearchMaze(maze, x + 1, y, depth + 1, limit, path)) return true;
    if (depthLimitedSearchMaze(maze, x - 1, y, depth + 1, limit, path)) return true;
    if (depthLimitedSearchMaze(maze, x, y + 1, depth + 1, limit, path)) return true;
    if (depthLimitedSearchMaze(maze, x, y - 1, depth + 1, limit, path)) return true;

    path.pop_back();
    return false;
}

bool depthLimitedSearchPuzzle(vector<vector<int>>& puzzle, int depth, int limit, int x, int y, vector<vector<vector<int>>>& path) {
    if (depth > limit) return false;
    if (puzzle == goal) {
        path.push_back(puzzle);
        return true;
    }

    path.push_back(puzzle);

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            swap(puzzle[x][y], puzzle[nx][ny]);
            if (depthLimitedSearchPuzzle(puzzle, depth + 1, limit, nx, ny, path)) return true;
            swap(puzzle[x][y], puzzle[nx][ny]);
        }
    }

    path.pop_back();
    return false;
}

void printMazePath(const vector<pair<int, int>>& path) {
    cout << "Maze Path: ";
    for (const auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void printPuzzlePath(const vector<vector<vector<int>>>& path) {
    cout << "8-Puzzle Path:" << endl;
    for (const auto& state : path) {
        for (const auto& row : state) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 9, 1}
    };
    int limit = 10;
    vector<pair<int, int>> mazePath;
    if (depthLimitedSearchMaze(maze, 0, 0, 0, limit, mazePath)) {
        cout << "Maze DLS: Found" << endl;
        printMazePath(mazePath);
    } else {
        cout << "Maze DLS: Not Found" << endl;
    }

    vector<vector<int>> puzzle = {
        {1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}
    };
    limit = 15;
    vector<vector<vector<int>>> puzzlePath;
    if (depthLimitedSearchPuzzle(puzzle, 0, limit, 2, 0, puzzlePath)) {
        cout << "8-Puzzle DLS: Found" << endl;
        printPuzzlePath(puzzlePath);
    } else {
        cout << "8-Puzzle DLS: Not Found" << endl;
    }

    return 0;
}