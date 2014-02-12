//* Description *//
// Title: Constrained Variable
// Author: Tyler Reed
// Defines an Abstract Constrained Variable with a Domain of Values

//* Package *//
package ConstraintSatisfaction;

//* Libraries *//
import java.util.List;

//* Abstract Class *//
public abstract class ConstrainedVariable implements Comparable<ConstrainedVariable>
{
	//* Class Variables *//
	protected List<DomainValue> values;
	protected List<ConstrainedVariable> constraints;
	protected DomainValue assignment;

	//* Constraint Methods *//
	// Applies the Contraints to the Constrained Variables
	protected abstract void applyConstraints();

	// Returns whether or not this Variable is Constraining another Variable
	public boolean isConstraining(ConstrainedVariable variable)
	{
		return constraints.contains(variable);
	}

	// Returns the Number of Constrained Variables
	public int getConstraintCount()
	{
		return constraints.size();
	}

	//* Assigned Methods *//
	// Returns the Assigned Value
	public DomainValue getAssignedValue()
	{
		return assignment;
	}

	// Sets the Assigned Value
	public DomainValue setAssignedValue(DomainValue assignment)
	{
		// Store the old Assignment
		DomainValue old = this.assignment;
		this.assignment = assignment;

		// Update the Available Values
		values.clear();
		values.add(assignment);

		// Apply Constraints
		applyConstraints();

		return old;
	}

	// Returns whether or not the Variable has a Assigned Value
	public boolean isAssigned()
	{
		return assignment != null;
	}
	
	//* Value Methods *//
	// Returns the Number of Remaining Values
	public int getValueCount()
	{
		return values.size();
	}

	// Returns the specified Value
	public DomainValue getValue(int index)
	{
		return values.get(index);
	}

	// Adds the specified Value to the Domain
	public boolean addValue(DomainValue value)
	{
		// Ignore Duplicates
		if(values.contains(value))
			return false;

		return values.add(value);
	}

	// Removes the specified Domain Value
	public boolean removeValue(DomainValue value)
	{
		return values.remove(value);
	}
}
