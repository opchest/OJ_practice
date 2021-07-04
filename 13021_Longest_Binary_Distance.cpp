#include <iostream>

using namespace std;
int maxlength, num_of_one;
void find_len(long long num) {
    int length = 0;
    bool is_one_appear = false;
    while(num > 0) {
        if(num % 2 == 1) {
            is_one_appear = true;
            num_of_one++;
            length = 0;
        }
        else if(num % 2 == 0 && is_one_appear) {
            length++;
            maxlength = max(length, maxlength);
        }
        num = num / 2;
    }
}
int main() {
    int q;
    cin >> q;
    while(q--) {
        long long input;
        cin >> input;
        maxlength = num_of_one = 0;
        find_len(input);
        if(num_of_one < 2) {
            cout << -1 << endl;
        }
        else 
            cout << maxlength << endl;
    }
    return 0;
}
