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
        Node dummy = new Node(), p = dummy, head = root;
        while (head != null) {
            Node node = head;
            while (node != null) {
                if (node.left != null) {
                    p.next = node.left;
                    p = p.next;
                }
                if (node.right != null) {
                    p.next = node.right;
                    p = p.next;
                }
                node = node.next;
            }
            head = dummy.next;
            dummy.next = null;
            p = dummy;
        }
        return root;
    }
}
