/*  Geek's Destination with Special Jump

Geek starts at position 0 on the positive X-axis and needs to reach or pass position d on the positive X-axis.

Geek normally follows a repeating movement pattern:

Move forward by a units, taking a seconds.
Move backward by b units, taking b seconds.
Geek also has a special jump that moves him exactly j units forward in 1 second. 
He can use it at any time, even in the middle of a forward or backward movement, and the journey ends immediately after the jump.

Given five integers a, b, d, l, and r. For every integer j in the range [l, r], 
find the minimum time required for Geek to reach or pass position d. He may either use the 
special jump or reach the destination using normal movement alone, whichever takes less time.

Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 109 + 7. 

Note: Each jump length is considered independently.

Examples:

Input: a = 2, b = 1, d = 5, l = 3, r = 4
Output: 5
Explanation: 
For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.
For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.
Total sum for the range [l, r] = 3 + 2 = 5.
Input: a = 4, b = 2, d = 8, l = 2, r = 4
Output: 26
Explanation:
For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to reach the destination. The minimum time required is 11 seconds.
For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach the destination. The minimum time required is 10 seconds.
For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.
Total sum for the range [l, r] = 11 + 10 + 5 = 26.
Constraints:

a ≤ 10
0 < b < a
a < d ≤ 108
0 < l ≤ r
r < d   */

class Solution {
  public:
    typedef long long ll;
    ll A, B, M;

    ll K(ll p) {
        if (p <= A) return 0;
        return (p - A + M - 1) / M;
    }
    ll T(ll p) { return p + 2 * B * K(p); }

    // sum of k(p) for p = 1..n
    ll SK(ll n) {
        if (n <= A) return 0;
        ll N = n - A;
        ll f = N / M, rem = N % M;
        return M * f * (f + 1) / 2 + rem * (f + 1);
    }

    int minTime(int a, int b, int d, int l, int r) {
        const ll MOD = 1e9 + 7;
        A = a; B = b; M = a - b;

        ll pl = d - r, pr = d - l;      // pl >= 1 since r < d
        ll Td = T(d);

        // largest p in [pl, pr] with T(p) + 1 <= Td
        ll lo = pl, hi = pr, best = pl - 1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (T(mid) + 1 <= Td) { best = mid; lo = mid + 1; }
            else hi = mid - 1;
        }

        ll total = 0;
        if (best >= pl) {
            ll cnt = best - pl + 1;
            ll sumP = (pl + best) * cnt / 2;
            ll sumK = SK(best) - SK(pl - 1);
            total += sumP + cnt + 2 * B * sumK;
        }
        if (best < pr) {
            ll cnt = pr - max(best + 1, pl) + 1;
            total += cnt * Td;
        }
        return (int)(total % MOD);
    }
};
