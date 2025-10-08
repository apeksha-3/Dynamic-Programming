#include <iostream>
#include <vector>
using namespace std;


double OBST(vector<int>& keys, vector<double>& p, vector<double>& q, int n) {
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0)); 
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0)); 
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0)); 

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

     
    for (int l = 1; l <= n; l++) { 
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = 99;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    return e[1][n]; 
}

int main() {
    int n;
    cout << "Enter number of book IDs: ";
    cin >> n;

    vector<int> keys(n);
    cout << "Enter sorted book IDs: ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    vector<double> p(n), q(n + 1);
    cout << "Enter  (p[i]): ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter (q[i]): ";
    for (int i = 0; i <= n; i++)
        cin >> q[i];

    double result = OBST(keys, p, q, n);
    cout << "\nMinimum Expected Search Cost: " << result << endl;

    return 0;
}