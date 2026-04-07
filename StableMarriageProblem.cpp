/*  Stable Marriage Problem
You are given two arrays men[] and women[], each of length n, where:

men[i] represents the preference list of the i-th man, ranking all women in order of preference.
women[i] represents the preference list of the i-th woman, ranking all men in order of preference.
The task is to form n pairs (marriages) such that:

Each man is matched with exactly one woman, and each woman is matched with exactly one man.
The matching is stable, meaning there is no pair (man, woman) who both prefer each other over their current partners.
It is guaranteed that a stable matching always exists. Return the stable matching from the men’s perspective, i.e., the one where men are considered for the final output.
Return an array result[] of size n, where result[i] denotes the index (0-based) of the woman matched with the i-th man.

Examples: 

Input: n = 2, men[] = [[0, 1], [0, 1], women[] = [[0, 1], [0, 1]]
Output: [0, 1]
Explanation:
Man 0 is married to Woman 0 (his first choice and her first choice).
Man 1 is married to Woman 1 (his second choice and her second choice).
Input: n = 3, men[] = [[0, 1, 2], [0, 1, 2], [0, 1, 2]], women[] = [[2, 1, 0], [2, 1, 0], [2, 1, 0]]
Output: [2, 1, 0]
Explanation:
Man 0 is married to Woman 2 (his third choice and her third choice).
Man 1 is married to Woman 1 (his second choice and her second choice).
Man 2 is married to Woman 0 (his first choice and her first choice).
Constraints: 
2 ≤ n ≤ 103
0 ≤ men[i] ≤ n - 1
0 ≤ women[i] ≤ n - 1   */

class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        
        int n = men.size();
        
        vector<int> womanPartner(n, -1);   // which man is engaged to woman
        vector<int> manPartner(n, -1);     // which woman is engaged to man
        vector<int> next(n, 0);            // next woman each man will propose
        
        // ranking[w][m] = preference rank of man m for woman w
        vector<vector<int>> ranking(n, vector<int>(n));
        
        for(int w = 0; w < n; w++){
            for(int i = 0; i < n; i++){
                ranking[w][women[w][i]] = i;
            }
        }
        
        queue<int> freeMen;
        for(int i = 0; i < n; i++){
            freeMen.push(i);
        }
        
        while(!freeMen.empty()){
            int m = freeMen.front();
            freeMen.pop();
            
            int w = men[m][next[m]++];  // woman to propose
            
            if(womanPartner[w] == -1){
                womanPartner[w] = m;
                manPartner[m] = w;
            }
            else{
                int current = womanPartner[w];
                
                if(ranking[w][m] < ranking[w][current]){
                    womanPartner[w] = m;
                    manPartner[m] = w;
                    manPartner[current] = -1;
                    freeMen.push(current);
                }
                else{
                    freeMen.push(m);
                }
            }
        }
        
        return manPartner;
    }
};


 
