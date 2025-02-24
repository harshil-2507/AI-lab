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

bool iterativeDeepeningSearchMaze(vector<vector<int>>& maze, int startX, int startY, vector<pair<int, int>>& path) {
    int limit = 0;
    while (true) {
        vector<vector<int>> mazeCopy = maze;
        path.clear();
        if (depthLimitedSearchMaze(mazeCopy, startX, startY, 0, limit, path)) return true;
        limit++;
    }
}

bool iterativeDeepeningSearchPuzzle(vector<vector<int>>& puzzle, int startX, int startY, vector<vector<vector<int>>>& path) {
    int limit = 0;
    while (true) {
        vector<vector<int>> puzzleCopy = puzzle;
        path.clear();
        if (depthLimitedSearchPuzzle(puzzleCopy, 0, limit, startX, startY, path)) return true;
        limit++;
    }
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
    vector<pair<int, int>> mazePath;
    if (iterativeDeepeningSearchMaze(maze, 0, 0, mazePath)) {
        cout << "Maze IDS: Found" << endl;
        printMazePath(mazePath);
    } else {
        cout << "Maze IDS: Not Found" << endl;
    }

    vector<vector<int>> puzzle = {
        {1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}
    };
    vector<vector<vector<int>>> puzzlePath;
    if (iterativeDeepeningSearchPuzzle(puzzle, 2, 0, puzzlePath)) {
        cout << "8-Puzzle IDS: Found" << endl;
        printPuzzlePath(puzzlePath);
    } else {
        cout << "8-Puzzle IDS: Not Found" << endl;
    }

    return 0;
}
