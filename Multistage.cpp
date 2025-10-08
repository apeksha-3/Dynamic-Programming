#include<iostream>
using namespace std;

#define MAX 20 

void MultiStage(int cost[MAX][MAX], int n , int k , int* bcost , int* d , int* p) {
    bcost[1] = 0;
    d[1] = 1;

    for (int i = 2 ; i <= n ; i++) {
        int minCost = 999;
        for (int l = i-1 ; l >= 1 ; l--) {
            if (cost[l][i] != 0 && bcost[l] + cost[l][i] < minCost) {
                minCost = bcost[l] + cost[l][i];
                bcost[i] = minCost;
                d[i] = l;
            }
        }
    }

    p[1] = 1;
    p[k] = n;

    for (int j = k-1 ; j >= 2 ; j--)
        p[j] = d[p[j+1]];
}

int main () {
    int n = 10;
    int cost[MAX][MAX] = {0};

    int temp[MAX][MAX] = {
        {0},
        {0, 0, 6, 9, 4, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 3, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9,11, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} 
    };

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cost[i][j] = temp[i][j];

    int k;
    cout << "Enter the stages: ";
    cin >> k;

    int* bcost = new int[n+1];
    int* d = new int[n+1];
    int* p = new int[k+1];

    MultiStage(cost, n, k, bcost, d, p);

    cout << "Shortest path: ";
    for (int i = 1 ; i <= k ; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}