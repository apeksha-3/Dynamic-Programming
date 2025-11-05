#include<iostream>
using namespace std ;
#define MAX 20 
void printval(int* x , int size){
    for (int i = 0 ; i < size ; i++){
        cout << "Color of vertex "  << i << " ->" << x[i] << endl;
    }
    cout << "-----------------------------------------------" << endl ;
}
void nextValue(int G[MAX][MAX], int* x,  int k ,int n , int color){
     while (true) {
        x[k] = (x[k] + 1) % (color + 1); 
        if (x[k] == 0) return; 

        int j;
        for (j = 0; j < n; j++) {
            if (G[k][j] && x[k] == x[j])
                break; 
        }
        if (j == n) return;
    }

}
void mColor(int G[MAX][MAX], int k , int* x, int n , int color){

    while(true){
        nextValue(G, x, k, n, color);
        if (x[k] == 0)
            return;
        if (k == n - 1)
            printval(x, n);
        else
            mColor(G, k + 1, x, n, color);
    }
}

int main () {
    int n = 4 ;

    int G[MAX][MAX] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int* x = new int[n];
    for (int i = 0; i < n; i++) x[i] = 0;

    int color;
    cout << "Enter the number of colors: ";
    cin >> color;

    mColor(G, 0, x, n, color);
}