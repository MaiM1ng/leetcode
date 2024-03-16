/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root) {
        if (root == NULL) {
            return;
        }
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<Node*> v;
            for (int i = 0; i < n; i++) {
                Node* cur = q.front();
                q.pop();
                v.push_back(cur);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            for (int i = n - 2; i >= 0; i--) {
                v[i]->next = v[i + 1];
            }
        }
    }

    Node* connect(Node* root) {
        bfs(root);

        return root;
    }
};
