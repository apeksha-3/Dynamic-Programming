#include<iostream>
using namespace std;

struct cost {
    int val;
    char dir;
};

void LRS(string str, int n, cost** c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                c[i][j].val = 0;
                c[i][j].dir = 'H';
            } else {
                if (str[i-1] == str[j-1] && i != j) { 
                    c[i][j].val = c[i-1][j-1].val + 1;
                    c[i][j].dir = 'D';
                } else {
                    c[i][j].val = max(c[i-1][j].val, c[i][j-1].val);
                    if (c[i-1][j].val >= c[i][j-1].val)
                        c[i][j].dir = 'U';
                    else
                        c[i][j].dir = 'S';
                }
            }
        }
    }
    cout << "Length of LRS: " << c[n-1][n-1].val << endl;
}

void print(string str, cost** c, int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (c[i][j].dir == 'D') {
        print(str, c, i-1, j-1);
        cout << str[i-1] << " ";  
    } else {
        if (c[i][j].dir == 'U')
            print(str, c, i-1, j);
        else
            print(str, c, i, j-1);
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length() + 1;
    cost** c = new cost*[n];
    for (int i = 0; i < n; ++i) {
        c[i] = new cost[n];
    }

    LRS(str, n, c);

    cout << "Longest Repeating Subsequence: ";
    print(str, c, n-1, n-1);
    cout << endl;

    return 0;
}