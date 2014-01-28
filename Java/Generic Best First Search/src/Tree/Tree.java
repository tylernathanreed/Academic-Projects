//* Description *//
// Title: Tree
// Author: Tyler Reed
// Defines a Tree Class with variable Degree

//* Package *//
package Tree;

//* Libraries *//
import java.util.List;

//* Tree Class *//
public class Tree<T>
{
	//* Class Variables *//
	private TreeNode<T> root;

	//* Constructor *//
	// Creates the Tree Class
	public Tree(T data)
	{
		root = new TreeNode<T>(data);
	}

	//* Root Methods *//
	// Returns the Root Node
	public TreeNode<T> getRoot()
	{
		return root;
	}

	// Returns the Tree Node Data
	public T getRootData()
	{
		return root.getData();
	}

	//* Child Methods *//
	// Returns the specified Child of the specified Node
	public TreeNode<T> getChild(TreeNode<T> node, int index)
	{
		return node.getChild(index);
	}

	// Returns the specified Child Data from the specified Node
	public T getChildData(TreeNode<T> node, int index)
	{
		return node.getChild(index).getData();
	}

	// Sets the specified Child Data from the specified Node
	public T setChildData(TreeNode<T> node, int index, T data)
	{
		return node.setChildData(index, data);
	}

	//* Container Methods *//
	// Returns the Number of Children the specified Node has
	public int getDegree(TreeNode<T> node)
	{
		return node.getDegree();
	}

	// Returns whether or not the specified Node has Children
	public boolean isLeaf(TreeNode<T> node)
	{
		return node.isLeaf();
	}

	// Returns the List of Children of the specified Child
	public List<TreeNode<T>> getChildren(TreeNode<T> node)
	{
		return node.getChildren();
	}
}
