/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        LinkedList<Integer> ans = new LinkedList<>();
        collect(root, target, k, ans);
        return ans;
    }

    private void collect(TreeNode root, double target, int k, LinkedList<Integer> ans) {
        if (root == null)
            return;
        collect(root.left, target, k, ans);
        if (ans.size() == k) {
            if (Math.abs(target - root.val) < Math.abs(target - ans.peekFirst()))
                ans.removeFirst();
            else
                return;
        }
        ans.add(root.val);
        collect(root.right, target, k, ans);
    }
}
