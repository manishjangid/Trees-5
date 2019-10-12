/* Problem Statement:

VERIFIED ON LEETCODE PLATFORM 
116. Populating Next Right Pointers in Each Node
Medium

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example:

Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.

 

Note:

    You may only use constant extra space.
    Recursive approach is fine, implicit stack space does not count as extra space for this problem.


 * Solution 1: scan all the nodes in tree and update the next pointers 
   Time Complexity : O(n)
 * Space complexity :O(1)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
#define FIRST 0
#define LAST 1
class Solution {
public:
    
    void connect_recurse(Node *root) {
        Node *save_my_ptr = NULL;
        if (root == NULL) {
            return;
        }
        /* Draw a diagram to make this condition clear. CHeck for NULL pointers and then update the next pointers */
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;

        /* this is to connect subtrees on different sides */
        if (root->next != NULL && root->right != NULL) {
            root->right->next = root->next->left;
        
        }
        /* Move into both paths of the tree to cover all cases */
        connect_recurse(root->left);
        connect_recurse(root->right);
    }
    
    Node* connect(Node* root) {
        connect_recurse(root);
        return root;
        
    }
};
/* Execute on leetcode platform */


