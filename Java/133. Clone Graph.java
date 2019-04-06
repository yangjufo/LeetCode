/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    Map<Integer, Node> cloneNodes = new HashMap<>();
    public Node cloneGraph(Node node) {        
        return clone(node);
    }
    
    public Node clone(Node node) {        
        if (node == null)
            return null;
        if (cloneNodes.containsKey(node.val))
            return cloneNodes.get(node.val);
        List<Node> cNeighbors = new ArrayList<>();        
        Node cNode = new Node(node.val, cNeighbors);
        cloneNodes.put(node.val, cNode);        
        for (Node neigh : node.neighbors)
            cNeighbors.add(clone(neigh)); 
        return cNode;
    }
}