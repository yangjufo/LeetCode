/*
 * // Definition for a Node. class Node { public int val; public Node next; public Node random;
 * 
 * public Node() {}
 * 
 * public Node(int _val,Node _next,Node _random) { val = _val; next = _next; random = _random; } };
 */
class Solution {
    Map<Node, Node> visited = new HashMap<>();

    private Node getNode(Node node) {
        if (node != null) {
            if (!visited.containsKey(node))
                visited.put(node, new Node(node.val, null, null));
            return visited.get(node);
        }
        return null;
    }

    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        Node oldNode = head, newNode = new Node(oldNode.val, null, null);
        visited.put(oldNode, newNode);

        while (oldNode != null) {
            newNode.random = getNode(oldNode.random);
            newNode.next = getNode(oldNode.next);
            oldNode = oldNode.next;
            newNode = newNode.next;
        }
        return visited.get(head);
    }
}
