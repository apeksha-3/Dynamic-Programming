#include <iostream>
using namespace std;

struct cost {
    int val;
    char dir;
};

void LCS(string str1, string str2, int size1, int size2, cost **c) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (i == 0 || j == 0) {
                c[i][j].val = 0;
                c[i][j].dir = 'H';
            } else {
                if (str1[i - 1] == str2[j - 1]) {  
                    c[i][j].val = c[i - 1][j - 1].val + 1;
                    c[i][j].dir = 'D';
                } else {
                    c[i][j].val = max(c[i - 1][j].val, c[i][j - 1].val);
                    if (c[i - 1][j].val >= c[i][j - 1].val)
                        c[i][j].dir = 'U';
                    else
                        c[i][j].dir = 'S';
                }
            }
        }
    }
    cout << "Length of LCS: " << c[size1 - 1][size2 - 1].val << endl;
}

void print(string str1, cost **c, int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (c[i][j].dir == 'D') {
        print(str1, c, i - 1, j - 1);
        cout << str1[i - 1] << " ";  
    } else {
        if (c[i][j].dir == 'U')
            print(str1, c, i - 1, j);
        else
            print(str1, c, i, j - 1);
    }
}

int main() {
    string str1, str2;
    cout << "Enter Str1: ";
    cin >> str1;
    cout << "Enter Str2: ";
    cin >> str2;

    int m = str1.length() + 1;
    int n = str2.length() + 1;

    cost **c = new cost *[m];
    for (int i = 0; i < m; ++i) {
        c[i] = new cost[n];
    }

    LCS(str1, str2, m, n, c);

    cout << "LCS: ";
    print(str1, c, m - 1, n - 1);
    cout << endl;

    return 0;
}