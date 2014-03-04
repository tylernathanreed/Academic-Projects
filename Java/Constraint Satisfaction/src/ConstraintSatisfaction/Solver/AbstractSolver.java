//* Description *//
// Title: Abstract Solver
// Author: Tyler Reed
// Creates an Abstract Constraint Satisfaction Solver

//* Package *//
package ConstraintSatisfaction.Solver;

//* Libraries *//
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.DomainValue;
import ConstraintSatisfaction.Ordering.ValueOrderingFactory;
import ConstraintSatisfaction.Ordering.VariableOrdering;

//* Class *//
public abstract class AbstractSolver
{
	//* Class Variables *//
	private List<List<ConstrainedVariable>> badVariableConfigurations;
	private List<List<DomainValue>> badValueConfigurations;
	private List<ConstrainedVariable> goodVariableConfiguration;
	private List<DomainValue> goodValueConfiguration;
	protected VariableOrdering variableOrder;
	protected ValueOrderingFactory valueFactory;
	protected List<Constraint> constraints;
	protected List<ConstrainedVariable> activeVariables;
	protected int attempts;
	protected int maxAttempts;

	//* Constructor *//
	// Creates the Abstract Solver Class
	public AbstractSolver(VariableOrdering variableOrder, ValueOrderingFactory valueFactory, List<Constraint> constraints)
	{
		this.variableOrder = variableOrder;
		this.valueFactory = valueFactory;
		this.constraints = constraints;

		badVariableConfigurations = new ArrayList<List<ConstrainedVariable>>();
		badValueConfigurations = new ArrayList<List<DomainValue>>();
		goodVariableConfiguration = null;
		goodValueConfiguration = null;

		activeVariables = new Vector<ConstrainedVariable>(variableOrder.getVariables().size());

		maxAttempts = 30;
	}

	//* Abstract Methods *//
	// Solves the Constraint Satisifaction
	public abstract boolean solve();

	//* Constraint Methods *//
	// Returns whether or not the Current State is the Goal State
	protected boolean isSatisfied()
	{
		for(Constraint constraint : constraints)
			if(!constraint.isEnforced())
				return false;

		return true;
	}

	//* Tracking Methods *//
	// Stores the Active Variables as Good Variables
	protected void storeSuccess()
	{
		goodVariableConfiguration = new ArrayList<ConstrainedVariable>();
		goodValueConfiguration = new ArrayList<DomainValue>();

		// Store the Active Variables and their Values
		for(ConstrainedVariable variable : activeVariables)
		{
			// Make sure the Variable is Assigned
			if(!variable.isAssigned())
				throw new IllegalStateException("Variables without Values cannot be Stored");

			goodVariableConfiguration.add(variable);
			goodValueConfiguration.add(variable.getAssignedValue());
		}
	}

	// Stores the Active Variables as Bad Variables
	protected void storeFailure()
	{
		List<ConstrainedVariable> badVariables = new ArrayList<ConstrainedVariable>();
		List<DomainValue> badValues = new ArrayList<DomainValue>();

		// Store the Active Variables and their Values
		for(ConstrainedVariable variable : activeVariables)
		{
			// Make sure the Variable is Assigned
			if(variable.isAssigned())
			{
				badVariables.add(variable);
				badValues.add(variable.getAssignedValue());
			}
		}
	
		this.badVariableConfigurations.add(badVariables);
		this.badValueConfigurations.add(badValues);
	}

	//* Conversion Methods *//
	// Returns a String of Formatted Results
	public String getSolutionPath()
	{
		String path = "";

		// Append all of the Bad Results
		for(int i = 0; i < badVariableConfigurations.size(); i++)
		{
			// Append the Bad Configuration Step
			path += (i + 1) + ") "; // (1-Based Indexing)
	
			// Determine the Current Bad Variable and Value Configuration
			List<ConstrainedVariable> badVariables = badVariableConfigurations.get(i);
			List<DomainValue> badValues = badValueConfigurations.get(i);

			// Cycle through the Bad Configuration in Reverse (As it was Solved Forwards)
			for(int j = badVariables.size() - 1; j >= 0; j--)
			{
				// Determine the Current Variable and Value
				ConstrainedVariable variable = badVariables.get(j);
				DomainValue value = badValues.get(j);

				// Append the Variable with its Bad Value
				path += variable + " = " + value;

				// Delimit the Assignments
				if(j > 0)
					path += ", ";
				else // Append as Failure
					path += " Failure\n";
			}
		}

		// Check if there was a Good Configuration
		if(goodVariableConfiguration != null)
		{
			// Append the Good Configuration Step
			path += (badVariableConfigurations.size() + 1) + ") "; // (1-Based Indexing)
	
			// Cycle through the Good Configuration in Reverse (As it was Solved Forwards)
			for(int i = 0; i < goodVariableConfiguration.size(); i++)
			{
				// Determine the Current Variable and Value
				ConstrainedVariable variable = goodVariableConfiguration.get(i);
				DomainValue value = goodValueConfiguration.get(i);

				// Append the Variable with its Good Value
				path += variable + " = " + value;

				// Delimit the Assignments
				if(i < goodVariableConfiguration.size() - 1)
					path += ", ";
				else // Append as Success
					path += " Success\n";
			}
		}

		return path;
	}
}
