# 13021 - Longest Binary Distance

###### tags: `OJ_practice`

---

### Description

Binary distance for an integer is the number of "0" between two adjoining "1"s in the binary representation of an integer. For example, 37 in binary is 100101 so 37 has two binary distance is 2 and 1. If there are not any $0$ between two 1s , the distane would be 0.  
Moreover, if the number of 1 is less than 2, the binary distance is -1.(e.g. 8 in binary is 100, so the distance is -1).

----

#### Input

The first line is an integer q, means that there are q integer to be count.

#### Output

The longest binary distance of every integers.(with endline)

---

### Thoughts 

Since we want to count the binary distance, we need to change decimal into binarry.  
**Note : The 0 at right most can't count since there is no 1 at the right.**
So I use `count` to count the distance, and also count the number of $1$ in case it is less than in the end.  
And *is_one_appear* is to avoid the issue that 0 is at the right most.
(Since the input might over 2^{32} - 1 , *long long* is needed.)
```c++
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
```

---

### Code

```c++
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

```
