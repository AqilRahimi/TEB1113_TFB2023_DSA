/* Graph with BFS
Name: Muhammad Aqil Rahimi bin Mohamad Rasidi
id: 22011363
Lab G2
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Graph {
private:
    unordered_map<char, vector<char>> adj;

public:
    // Add edge (undirected)
    void addEdge(char u, char v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS Traversal
    void BFS(char start) {
        set<char> visited;
        queue<char> q;

        visited.insert(start);
        q.push(start);

        cout << "BFS starting from " << start << ": ";

        while (!q.empty()) {
            char vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (char neighbor : adj[vertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g;

    g.addEdge('A', 'B');
    g.addEdge('B', 'E');
    g.addEdge('A', 'D');
    g.addEdge('A', 'C');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.addEdge('B', 'D');

    g.BFS('A');

    return 0;
}
