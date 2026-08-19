/*IOI Gold
Chef recently participated in the IOI competition, and scored 
N
N points out of 
600
600 on the 
2
2 days of competition.

Just now, the gold cutoff was released, which was 
G
G points, meaning everyone with at least 
G
G points gets a gold medal. Chef wants to know if he will get gold or not. Print 
Yes
Yes or 
No
No accordingly.

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
