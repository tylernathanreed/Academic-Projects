//* Description *//
// Title: Constrained Variable
// Author: Tyler Reed
// Defines an Abstract Constrained Variable with a Domain of Values

//* Package *//
package ConstraintSatisfaction;

//* Libraries *//
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Vector;

//* Abstract Class *//
public abstract class ConstrainedVariable implements Comparable<ConstrainedVariable>
{
	//* Class Variables *//
	protected Object variable;
	protected Deque<SortedSet<DomainValue>> constrainedDomain;
	protected SortedSet<DomainValue> fullDomain;
	protected List<ConstrainedVariable> constraints;
	protected DomainValue assignment;
	protected boolean assigned;

	//* Constructor *//
	// Creates the Extendable Constrained Variable Class
	public ConstrainedVariable(Object variable, Collection<DomainValue> domain)
	{
		this.variable = variable;
		this.assigned = false;

		// Copy the Domains
		fullDomain = new TreeSet<DomainValue>();
		constrainedDomain = new LinkedList<SortedSet<DomainValue>>();

		fullDomain.addAll(domain);
		constrainedDomain.push(this.fullDomain);
	}

	//* Full Domain Methods *//
	// Returns a Copy of the Full Domain
	public List<DomainValue> getFullDomain()
	{
		List<DomainValue> domain = new Vector<DomainValue>();
		domain.addAll(fullDomain);
		return domain;
	}

	//* Constrained Domain Methods *//
	// Returns a Copy of the Constrained Domain
	public SortedSet<DomainValue> getConstrainedDomain()
	{
		SortedSet<DomainValue> domain = new TreeSet<DomainValue>();
		domain.addAll(constrainedDomain.peek());
		return domain;
	}

	// Adds the List of Domain Values to the Constrained Domain
	public void pushConstrainedDomain(SortedSet<DomainValue> domain)
	{
		// Push a Copy of the Domain
		SortedSet<DomainValue> newDomain = new TreeSet<DomainValue>();
		newDomain.addAll(domain);
		constrainedDomain.push(newDomain);
	}

	// Removes and Returns the Next Constrained Domain
	public SortedSet<DomainValue> popConstrainedDomain()
	{
		if(constrainedDomain.size() == 1)
			throw new IllegalStateException("The Original Domain may not be Removed");
		else
			return constrainedDomain.pop();
	}

	// Clears the Constrained Domain
	public void clearConstrainedDomain()
	{
		// Remove all but the Original Domain
		while(constrainedDomain.size() > 1)
			constrainedDomain.pop();
	}
	
	//* Constraint Methods *//
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

	//* Assignment Methods *//
	// Returns the Assigned Value
	public DomainValue getAssignedValue()
	{
		// Make sure the Variable has been Assigned
		if(!assigned)
			throw new IllegalStateException("Variable has not been Assigned!");

		return assignment;
	}

	// Sets the Assigned Value
	public DomainValue setAssignedValue(DomainValue assignment) throws DomainException
	{
		// Make sure the specified Value is in the Domain
		if(!fullDomain.contains(assignment))
			throw new DomainException();

		// Store the old Assignment
		DomainValue old = this.assignment;
		this.assignment = assignment;

		// Mark the Variable as Assigned
		assigned = true;
		return old;
	}

	// Returns whether or not the Variable has a Assigned Value
	public boolean isAssigned()
	{
		return assignment != null;
	}

	// Unassigns the Variable
	public void unassign()
	{
		assigned = false;
		assignment = null;
	}

	//* Comparable Methods *//
	// Returns whether or not the specified Variable is Equal To this one
	public boolean equals(Object otherVariable)
	{
		if(getClass().equals(otherVariable.getClass()))
			return compareTo((ConstrainedVariable) otherVariable) == 0;
		else
			return super.equals(otherVariable);
	}
}
