/*
 * // Definition for a Node. class Node { public int val; public Node left; public Node right;
 * public Node next;
 * 
 * public Node() {}
 * 
 * public Node(int _val,Node _left,Node _right,Node _next) { val = _val; left = _left; right =
 * _right; next = _next; } };
 */
class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        Node pre = root, cur = null;
        while (pre.left != null) {
            cur = pre;
            while (cur != null) {
                cur.left.next = cur.right;
                if (cur.next != null)
                    cur.right.next = cur.next.left;
                cur = cur.next;
            }
            pre = pre.left;
        }
        return root;
    }
}
