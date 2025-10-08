#include <bits/stdc++.h>
#define INF 999
using namespace std;
// this is a change occured on Github website
int n; 
int w[100][100]; 
int pre[100];

void tracePath(int i) {
    if (pre[i] != i) tracePath(pre[i]);
    cout << " -> " << i;
}

void dijkstra(int source) {
    int L[100]; 
    vector<int> T; 
    
    for (int i = 0; i < n; i++) {
        L[i] = INF;
        pre[i] = i;
        T.push_back(i);
    }
    L[source] = 0;

    while (!T.empty()) {
        
        int v = T[0], id = 0;
        for (int i = 0; i < T.size()-1; i++) {
            if (L[T[i]] < L[v]) {
                v = T[i];
                id = i;
            }
        }

        T.erase(T.begin() + id);

        for (int x : T) {
            if (w[v][x] != INF) { 
                int oldDist = L[x];
                L[x] = min(L[x], L[v] + w[v][x]);
                if (L[x] != oldDist) pre[x] = v;
            }
        }
    }

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << L[i] << "\n";
    }

    cout << "\nPaths:\n";
    for (int i = 0; i < n; i++) {
        cout << "Path from " << source << " to " << i << ": ";
        if (L[i] == INF) {
            cout << "No path";
        } else {
            cout << source;
            tracePath(i);
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    int source;   
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(source);

    return 0;
}

