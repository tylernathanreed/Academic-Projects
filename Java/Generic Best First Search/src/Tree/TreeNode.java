//* Description *//
// Title: Tree Node
// Author: Tyler Reed
// Defines a Tree Node to be used with the Tree Class

//* Package *//
package Tree;

//* Libraries *//
import java.util.ArrayList;
import java.util.List;

//* Tree Node Class *//
public class TreeNode<T>
{
	//* Class Variables *//
	private T data = null;
	private TreeNode<T> parent = null;
	private List<TreeNode<T>> children = null;

	//* Class Methods *//
	// Data Constructor
	public TreeNode(T data)
	{
		this.data = data;
		children = new ArrayList<TreeNode<T>>();
	}

	// Parent and Data Constructor
	public TreeNode(T data, TreeNode<T> parent)
	{
		this.data = data;
		this.parent = parent;
		children = new ArrayList<TreeNode<T>>();
	}

	//* Data Methods *//
	// Returns the Data of the Node
	public T getData()
	{
		return data;
	}

	// Sets the Data of the Node
	public T setData(T data)
	{
		T old = this.data;
		this.data = data;
		return old;
	}

	//* Parent Methods *//
	// Returns the Parent Node
	public TreeNode<T> getParent()
	{
		return parent;
	}

	// Returns the Parent Node Data
	public T getParentData()
	{
		return parent.getData();
	}

	// Sets the Parent Node Data
	public T setParentData(T data)
	{
		return parent.setData(data);
	}

	// Returns whether or not this Node has a Parent
	public boolean isRoot()
	{
		return parent == null;
	}

	//* Child Methods *//
	// Returns the specified Child Node
	public TreeNode<T> getChild(int index)
	{
		return children.get(index);
	}

	// Returns the specified Child Node Data
	public T getChildData(int index)
	{
		return children.get(index).getData();
	}

	// Sets the specified Child Node Data
	public T setChildData(int index, T data)
	{
		return children.get(index).setData(data);
	}

	//* Container Methods *//
	// Adds the specified Child to this Node
	public int addChild(TreeNode<T> node)
	{
		children.add(node);
		return children.size() - 1;
	}

	// Adds the specified Child Data to this Node
	public int addChildData(T data)
	{
		TreeNode<T> child = new TreeNode<T>(data);
		children.add(child);
		return children.size() - 1;
	}

	// Removes the specified Child from this Node
	public boolean removeChild(TreeNode<T> node)
	{
		return children.remove(node);
	}

	// Removes the specified Index from this Node
	public TreeNode<T> removeChild(int index)
	{
		return children.remove(index);
	}

	// Returns the Number of Children this Node has
	public int getDegree()
	{
		return children.size();
	}

	// Returns whether or not this Node has Children
	public boolean isLeaf()
	{
		return children.size() == 0;
	}

	// Returns the List of Children
	public List<TreeNode<T>> getChildren()
	{
		return children;
	}
}
