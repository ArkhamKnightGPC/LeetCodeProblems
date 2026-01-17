/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {

    def solve(curNode: TreeNode, curSum: Int, targetSum: Int): Boolean = {
        if(curNode == null)return false

        val newSum = curSum + curNode.value
        val nodeLeft = curNode.left
        val nodeRight = curNode.right
        if(nodeLeft == null & nodeRight == null) return (newSum == targetSum)

        val solveLeft = solve(nodeLeft, newSum, targetSum)
        if(!solveLeft)return solve(nodeRight, newSum, targetSum)
        return solveLeft
    }

    def hasPathSum(root: TreeNode, targetSum: Int): Boolean = {
        return solve(root, 0, targetSum)
    }
}