# 12891 - Longest Row Vector

---


### Description
**Matrix** : A sequence of row vectors.
**Length of vector** : <img src="https://render.githubusercontent.com/render/math?math=|v|=\sqrt\sumv_i^2"> 
**Switch (i, j)** : swap i-row and j-row, denoted by 0 in inputs.
**Add (i, j)** : Add j-row to $i$-row, which means only $i$-row changes, denoted by 1 in inputs.

----

#### Input

Three numbers m, n, k in first line, means that there are m rows of vectors which size are n.
And in next m lines  is the matrix.
Then in next k lines means the operation of above(switch, add).

----

#### Output

Output the longest vector of matrix, if there are over one vectors have the same longest length, then output one with smallest index.(with '\n').

----

### Thoughts & Implementation

Use double array (or vector) to store the input, and then in next $k$ lines just implement `switch(i, j)` & `add(i, j)`.
**switch** :
```c++
if(operation == 0) {    //switch.
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++) 
                swap(matrix[a][i], matrix[b][i]);
        }
```
**Add** :
```c++
if(operation == 1) {    //add.
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++) 
                matrix[a][i] += matrix[b][i];
        }
```
After $k$ operations then we have to count the length and find the index of the longest vector, so we have the function `ansidx` to find the idx.
```c++
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
```
Then we can output what we need in the end.

---

### Code
```c++
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
```
