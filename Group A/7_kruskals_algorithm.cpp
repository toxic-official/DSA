#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[50];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, e;
    Edge edges[100];

    cout << "Enter number of departments: ";
    cin >> n;
    cout << "Enter number of links: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter two departments and distance: ";
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + e, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;
    cout << "Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            total += edges[i].w;
            parent[a] = b;
        }
    }

    cout << "Total distance: " << total << endl;
    return 0;
}
