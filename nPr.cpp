/*  nPr
Write a program to calculate nPr . nPr  represents n permutation r and value of nPr  is (n!) / (n-r)!.

Examples:
Input: n = 5, 2 = 1
Output: 2
Explaination: 5!/(5-2)! = 5!/3! = 120/6 = 20.
Input: n = 6, r = 3
Output: 6
Explaination: 6!/(6-3)! = 6!/3! = 720/6 = 120.
Constraints:
1 ≤ n, r ≤ 20    */  

class Solution{
public:
     long long Factorial(int n){
         long fact =1;
         for(int i=1;i<=n;i++){
             fact *= i;
         }
         return fact;
     }
    long long nPr(int n, int r){
        // code here
        long long Fact_n = Factorial(n);
        long long Fact_nmr = Factorial(n-r);
        return Fact_n/Fact_nmr;
    }
};
