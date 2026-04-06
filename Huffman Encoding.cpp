/* Huffman Encoding

Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency. You need to build the Huffman tree and return all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Examples:

Input: s = "abcdef", f[] = {5, 9, 12, 13, 16, 45}
Output: [0, 100, 101, 1100, 1101, 111]
Explanation:

HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Constraints:
1 ≤ s.size() = f.size() ≤ 26   */



struct MinHeapNode
{
    char data;
    unsigned freq;
    int idx;
    MinHeapNode *left, *right;

    MinHeapNode(char data , unsigned freq, int idx)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
        this->idx = idx;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l , MinHeapNode* r)
    {
        if (l->freq == r->freq)
            return l->idx > r->idx;
        return l->freq > r->freq;
    }
};

class Solution
{
	public:
	    void getCodes(MinHeapNode* root , string str , vector<string> &res)
        {
            if(!root) return;
                
            if(root->data != '$')
            {
                if(str == "") str = "0";
                res.push_back(str);
            }
            
            getCodes(root->left, str + "0", res);
            getCodes(root->right, str + "1", res);
        }
    
		vector<string> huffmanCodes(string S , vector<int> f)
		{
		    int N = S.size();

		    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
            
            for(int i = 0; i < N; ++i)
                minHeap.push(new MinHeapNode(S[i], f[i], i));
                
            while(minHeap.size() > 1)
            {
                MinHeapNode* left = minHeap.top(); minHeap.pop();
                MinHeapNode* right = minHeap.top(); minHeap.pop();
        
                int newIdx = min(left->idx, right->idx);
                
                MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq, newIdx);
                
                top->left = left;
                top->right = right;
                
                minHeap.push(top);
            }
            
            vector<string> res;
            getCodes(minHeap.top(), "", res);
            
            return res;
		}
};
