/* Mirror Swap
You have an array 
A
A of size 
2
⋅
N
2⋅N.

You can perform the following operation as many times as you want:

Swap 

​
  with 
A

2N+1−i
​
  (i.e. it's mirror element).
For example, we can swap 
A
1
A 
1
​
  with 

2N

​
  with 
 
2N−1
​
  and so on.


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, G;
    cin >> N >> G;

    if (N >= G)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
