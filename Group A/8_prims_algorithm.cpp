#include <iostream>
using namespace std;

int main() {
    int n;
    int cost[20][20];
    int selected[20] = {0};

    cout << "Enter number of departments: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 if no link):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    selected[0] = 1;
    int edges = 0;
    int total = 0;

    cout << "Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = 9999, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << min << endl;
        total += min;
        selected[y] = 1;
        edges++;
    }

    cout << "Total distance: " << total << endl;
    return 0;
}
