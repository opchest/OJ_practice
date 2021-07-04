# 12968 - Gomoku

###### tags :`OJ_practice`

---

### Description

We now have board of *gomoku*(五子棋), then we need to decide which one is the winner(black or white), or no one is the winner.
There are few restriction:
- Size of board is 15.
- Black is the first player to place the stone.
- The input must be valid.

----

#### Input

First line is an integer Q, means there are Q boards need to decide.
And then next Q * 15 lines are the each boards, which '.' means empty, 'b' means black stone, 'w' means white stone.

----

#### Output

If the black is the winner output is 'black', likewise ,if white is the winner output is 'white'.
But if there is no winner , output is 'none'.(All with endline).

---

### Thoughts

First read the board in the char double array.
And also record the non-empty place in two sets, black and white.
```c++
for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                cin >> Board[i][j];
                if(Board[i][j] == 'w')
                    white.insert(pair<int, int>(i, j));
                else if(Board[i][j] == 'b')
                    black.insert(pair<int, int>(i, j));
            }
        }
```

Then test the place if there are 5 or more stones in a row by `test_w`
```c++
bool test_w(const int& x, const int& y) {
    for(int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        int count = 0;
        if(new_x >= SIZE || new_x < 0 || new_y >= SIZE || new_y < 0 || Board[new_x][new_y] == '.')    //out of boundary or empty.
            continue;
        while(Board[new_x][new_y] == Board[x][y]) {
            count++;
            if(count >= 4)
                return true;
            new_x += dx[i];
            new_y += dy[i];
            if(new_x >= SIZE || new_x < 0 || new_y >= SIZE || new_y < 0 || Board[new_x][new_y] == '.')
                break;
        }
    }
    return false;
}
```

So we can use the `test_w` function to find the winner.

---

### Code

```c++
#include <iostream>
#include <set>
#define SIZE 15
 
using namespace std;

char Board[SIZE][SIZE];
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool test_w(const int& x, const int& y) {
    for(int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        int count = 0;
        if(new_x >= SIZE || new_x < 0 || new_y >= SIZE || new_y < 0 || Board[new_x][new_y] == '.')    //out of boundary or empty.
            continue;
        while(Board[new_x][new_y] == Board[x][y]) {
            count++;
            if(count >= 4)
                return true;
            new_x += dx[i];
            new_y += dy[i];
            if(new_x >= SIZE || new_x < 0 || new_y >= SIZE || new_y < 0 || Board[new_x][new_y] == '.')
                break;
        }
    }
    return false;
}
int main() {
    int q;
    set<pair<int, int>> white, black;
    cin >> q;
    while(q--) {
        bool is_found = false;
        black.clear();
        white.clear();
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                cin >> Board[i][j];
                if(Board[i][j] == 'w')
                    white.insert(pair<int, int>(i, j));
                else if(Board[i][j] == 'b')
                    black.insert(pair<int, int>(i, j));
            }
        }
        for(auto it : black) {
            if(test_w(it.first, it.second)) {
                cout << "black" << endl;
                is_found = true;
                break;
            }
        }
        for(auto it : white) {
            if(test_w(it.first, it.second)) {
                cout << "white" << endl;
                is_found = true;
                break;
            }
        }
        if(!is_found)
            cout << "none" << endl;
    }
    return 0;
}
```
