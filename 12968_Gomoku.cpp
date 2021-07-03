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