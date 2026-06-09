/*  Seating Arrangement


Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.

Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:

Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.
Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.
Input: k = 0, seats[] = [0, 0, 0, 1, 1]
Output: false
Explanation: The seating arrangement already contains two adjacent occupied seats at indices 3 and 4.
Constraints:
0 ≤ k ≤ 105
1 ≤ seats.size() ≤ 105
seats[i] == 0 or seats[i] == 1 */

class Solution {
public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();

        // Check if current arrangement is already invalid
        for (int i = 0; i < n - 1; i++) {
            if (seats[i] == 1 && seats[i + 1] == 1)
                return false;
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (seats[i] == 0) {
                bool leftEmpty = (i == 0 || seats[i - 1] == 0);
                bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    seats[i] = 1;
                    k--;
                }
            }
        }

        return k == 0;
    }
};
