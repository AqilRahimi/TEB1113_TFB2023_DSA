/* Graph
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

    // DFS Helper
    void DFSUtil(char vertex, set<char>& visited) {
        cout << vertex << " ";
        visited.insert(vertex);

        for (char neighbor : adj[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS Traversal
    void DFS(char start) {
        set<char> visited;
        cout << "DFS starting from " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
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

    // Add all the edges
    g.addEdge('A', 'B');
    g.addEdge('B', 'E');
    g.addEdge('A', 'D');
    g.addEdge('A', 'C');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.addEdge('B', 'D');

    // Perform DFS and BFS starting from A
    g.DFS('A');
    g.BFS('A');

    return 0;
}
