# IDEA
1. 先對輸入的字串依照題目的 char 排序規則由小到大排序
2. 利用呼叫遞迴的方式，每一次將字串調整為 "比目前字串大之最小字串"，若以調整到只剩最後一個 char，則輸出字串。
　　須注意的是，每次呼叫遞迴前須先確認，調整後的字串和調整前的字串是否相同，若不同才呼叫遞迴，否則不呼叫。

---

可用 c++ STL 之 next_permutatoin()，替代遞迴呼叫，以更簡單的程式碼達成尋找 "比目前字串大之最小字串"

```cpp
#include <iostream>
#include <string>
#include <cctype>		// tolower
#include <algorithm>	// next_permutaion

using namespace std;

bool compare(char, char);

int main() {
    string input = "aAbB";
    next_permutation(input.begin(), input.end(), compare);

    return 0;
}

bool compare(char a, char b){
    char lower_a = tolower(a), lower_b = tolower(b);
    if( lower_a == lower_b ){
        return a < b;
    }
    else 
        return lower_a < lower_b; 
}
```