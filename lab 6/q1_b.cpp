#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

const int N = 3;
vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

struct Node {
    vector<vector<int>> state;
    int x, y, cost, depth;
    Node* parent;
    
    Node(vector<vector<int>> s, int x, int y, int depth, Node* p) : state(s), x(x), y(y), depth(depth), parent(p) {
        cost = depth + heuristic();
    }

    int heuristic() {
        int h = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (state[i][j] != 0) {
                    int val = state[i][j] - 1;
                    int targetX = val / N;
                    int targetY = val % N;
                    h += abs(i - targetX) + abs(j - targetY);
                }
            }
        }
        return h;
    }
};

bool isGoal(const vector<vector<int>>& state) {
    return state == goal;
}

vector<Node*> getNeighbors(Node* node) {
    vector<Node*> neighbors;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++) {
        int nx = node->x + dx[i];
        int ny = node->y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            vector<vector<int>> newState = node->state;
            swap(newState[node->x][node->y], newState[nx][ny]);
            neighbors.push_back(new Node(newState, nx, ny, node->depth + 1, node));
        }
    }
    return neighbors;
}

int getSolutionDepth(Node* node) {
    int moves = 0;
    while (node->parent) {
        moves++;
        node = node->parent;
    }
    return moves;
}

void bfs(vector<vector<int>> start, int x, int y) {
    queue<Node*> q;
    set<vector<vector<int>>> visited;
    q.push(new Node(start, x, y, 0, nullptr));
    
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (isGoal(node->state)) {
            cout << "BFS Solution found in " << getSolutionDepth(node) << " moves." << endl;
            return;
        }
        visited.insert(node->state);
        for (Node* neighbor : getNeighbors(node)) {
            if (visited.find(neighbor->state) == visited.end()) {
                q.push(neighbor);
            }
        }
    }
}

void dfs(vector<vector<int>> start, int x, int y, int maxDepth = 20) {
    stack<Node*> s;
    set<vector<vector<int>>> visited;
    s.push(new Node(start, x, y, 0, nullptr));
    
    while (!s.empty()) {
        Node* node = s.top(); s.pop();
        if (isGoal(node->state)) {
            cout << "DFS Solution found in " << getSolutionDepth(node) << " moves." << endl;
            return;
        }
        if (node->depth >= maxDepth) continue;
        visited.insert(node->state);
        for (Node* neighbor : getNeighbors(node)) {
            if (visited.find(neighbor->state) == visited.end()) {
                s.push(neighbor);
            }
        }
    }
    cout << "DFS did not find a solution within depth limit." << endl;
}

void aStar(vector<vector<int>> start, int x, int y) {
    auto cmp = [](Node* a, Node* b) { return a->cost > b->cost; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    set<vector<vector<int>>> visited;
    pq.push(new Node(start, x, y, 0, nullptr));
    
    while (!pq.empty()) {
        Node* node = pq.top(); pq.pop();
        if (isGoal(node->state)) {
            cout << "A* Search Solution found in " << getSolutionDepth(node) << " moves." << endl;
            return;
        }
        visited.insert(node->state);
        for (Node* neighbor : getNeighbors(node)) {
            if (visited.find(neighbor->state) == visited.end()) {
                pq.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> start = {{1, 2, 3}, {4, 0, 6}, {7, 5, 8}};
    int x = 1, y = 1;
    
    bfs(start, x, y);
    dfs(start, x, y);
    aStar(start, x, y);
    
    return 0;
}