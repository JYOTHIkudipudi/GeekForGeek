/*   Display longest name

Given an array arr[] containing strings of names. Your task is to return the longest string. If there are multiple names of the longest size,
return the first occurring name.

Examples :
Input: arr[] = ["Geek", "Geeks", "Geeksfor", "GeeksforGeek", "GeeksforGeeks"]
Output: "GeeksforGeeks"
Explanation: name "GeeksforGeeks" has maximum length among all names. 
Input: arr[] = ["Apple", "Mango", "Orange", "Banana"]
Output: "Orange"
Explanation: names "Orange" and "Banana" both have maximum length among all names but Orange comes first so answer will be "Orange".

Constraints:
1 <= arr.size()<= 1000
1 <= arr[i] <= 1000
arr[i] has only lowercase and uppercase letters  */


class Solution {
  public:
    string longest(vector<string>& arr) {
        string longestName = "";
        int maxLength = 0;

        for (string name : arr) {
            if (name.length() > maxLength) {
                maxLength = name.length();
                longestName = name;
            }
        }

        return longestName;
    }
};
