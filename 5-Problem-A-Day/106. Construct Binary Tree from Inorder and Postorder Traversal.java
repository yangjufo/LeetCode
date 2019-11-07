/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    int postIdx;
    Map<Integer, Integer> inMap;

    private TreeNode build(int[] postorder, int inLeft, int inRight) {
        if (inLeft > inRight)
            return null;
        TreeNode root = new TreeNode(postorder[postIdx]);
        int inIdx = inMap.get(postorder[postIdx]);
        postIdx -= 1;
        root.right = build(postorder, inIdx + 1, inRight);
        root.left = build(postorder, inLeft, inIdx - 1);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIdx = postorder.length - 1;
        inMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inMap.put(inorder[i], i);
        }
        return build(postorder, 0, inorder.length - 1);
    }
}
