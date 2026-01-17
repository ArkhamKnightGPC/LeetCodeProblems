/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
import scala.collection.mutable

object Solution {

    val memo = mutable.Map[TreeNode, Int]()

    def depth(curNode: TreeNode): Int = {
        if(curNode == null)return 0
        if(memo.contains(curNode))return memo(curNode)
        val nodeLeft = curNode.left
        val nodeRight = curNode.right

        val depthLeft = 1 + depth(nodeLeft)
        val depthRight = 1 + depth(nodeRight)
        val depthCur = math.max(depthLeft, depthRight)
        memo(curNode) = depthCur
        return depthCur
    }

    def isBalanced(root: TreeNode): Boolean = {
        if(root == null)return true
        val nodeLeft = root.left
        val nodeRight = root.right

        val depthLeft = depth(nodeLeft)
        val depthRight = depth(nodeRight)
        return isBalanced(nodeLeft) & isBalanced(nodeRight) & math.abs(depthLeft - depthRight)<=1
    }
}