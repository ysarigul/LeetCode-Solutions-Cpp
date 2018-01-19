/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        for (ListNode *x = root; x; ++len, x = x->next);

        int n = len / k, r = len % k;
        vector<ListNode*> ret(k);
        for (int i = 0; i < k && root; ++i) {
            ret[i] = root;
            for (int j = 1; j < n + (i < r); ++j)
                root = root->next;
            ListNode *next = root->next;
            root->next = nullptr;
            root = next;
        }
        return ret;
    }
};