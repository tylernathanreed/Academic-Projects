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
	protected Object variable;
	protected List<DomainValue> domain;
	protected List<ConstrainedVariable> constraints;
	protected DomainValue assignment;

	//* Constructor *//
	// Creates the Extendable Constrained Variable Class
	public ConstrainedVariable(Object variable, List<DomainValue> domain)
	{
		this.variable = variable;
		this.domain = domain;
	}

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
		domain.clear();
		domain.add(assignment);

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
		return domain.size();
	}

	// Returns the specified Value
	public DomainValue getValue(int index)
	{
		return domain.get(index);
	}

	// Adds the specified Value to the Domain
	public boolean addValue(DomainValue value)
	{
		// Ignore Duplicates
		if(domain.contains(value))
			return false;

		return domain.add(value);
	}

	// Removes the specified Domain Value
	public boolean removeValue(DomainValue value)
	{
		return domain.remove(value);
	}
}
