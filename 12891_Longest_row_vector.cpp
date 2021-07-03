#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int matrix[1010][1010];

int ansidx(const int& m, const int& n) {
    int maxlen = INT16_MIN, idx;
    for(int i = 0; i < m; i++) {
        int length = 0;
        for(int j = 0; j < n; j++)
            length += pow(matrix[i][j], 2);
        if(length > maxlen) {
            maxlen = length;
            idx = i;
        }
    }
    return idx;
}
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) 
            cin >> matrix[i][j];
    }
    while(k--) {
        int operation;
        cin >> operation;
        if(operation == 0) {    //switch.
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++) 
                swap(matrix[a][i], matrix[b][i]);
        }
        if(operation == 1) {    //add.
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++) 
                matrix[a][i] += matrix[b][i];
        }
    }
    int idx = ansidx(m, n);
    for(int i = 0; i < n - 1; i++) 
        cout << matrix[idx][i] << " ";
    cout << matrix[idx][n - 1] << endl;
}