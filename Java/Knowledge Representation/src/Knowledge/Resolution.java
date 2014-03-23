//* Description *//
// Title: Resolution Thread
// Author: Tyler Reed
// Deduces new Rules given a set of Clauses and a Check Variable

//* Package *//
package Knowledge;

//* Libraries *//
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

//* Class *//
public class Resolution implements Runnable
{
	//* Class Variables *//
	// Static Variables
	private static List<Thread> threads = new ArrayList<Thread>();
	private static volatile List<Clause> clauses = new ArrayList<Clause>();
	private static volatile SortedSet<Clause> deductions = new TreeSet<Clause>();
	private static volatile Map<Clause, SortedSet<Integer>> indeces = new Hashtable<Clause, SortedSet<Integer>>();
	private static volatile boolean terminate = false;
	private static volatile SortedSet<Integer> terminationIndeces;

	// Instance Variables
	private Variable variable;
	private Thread thread;

	//* Constructor *//
	// Creates the Resolution Thread
	public Resolution(Variable variable)
	{
		this.variable = variable;

		// Run the Class on a Thread
		thread = new Thread(this);
		threads.add(thread);
		thread.start();
	}

	//* Thread Methods *//
	// Runs the Thread
	public void run()
	{
		// Track Per-Variable Derivations
		int derivations = 0;

		// Create the Positive and Negative Literals for the Variable
		Literal positiveLiteral = new Literal(variable, false);
		Literal negativeLiteral = new Literal(variable, true);

		// Determine the Initial Set of Positive and Negative Clauses
		SortedSet<Clause> positiveClauses = new TreeSet<Clause>();
		SortedSet<Clause> negativeClauses = new TreeSet<Clause>();

		// Search Clauses for the Positive Literal
		for(Clause clause : clauses)
			if(clause.contains(positiveLiteral))
				positiveClauses.add(clause);
			else if(clause.contains(negativeLiteral))
				negativeClauses.add(clause);

		// Create new Clauses using the Restitution Rule
		for(Clause positiveClause : positiveClauses)
		{
			// Determine the Initial Literals in the Positive Clause
			SortedSet<Literal> positiveLiterals = positiveClause.getCurrentLiterals();

			// Create a New Clause for each Negative Clause
			for(Clause negativeClause : negativeClauses)
			{
				// Determine the Initial Literals in the Negative Clause
				SortedSet<Literal> negativeLiterals = negativeClause.getCurrentLiterals();

				// Join the two Sets for a New Clause
				SortedSet<Literal> newLiterals = new TreeSet<Literal>();
				newLiterals.addAll(positiveLiterals);
				newLiterals.addAll(negativeLiterals);

				// Remove the Positive and Negative Literal Variable
				newLiterals.remove(positiveLiteral);
				newLiterals.remove(negativeLiteral);

				// Track the Clause Indeces
				TreeSet<Integer> indeces = new TreeSet<Integer>();

				// Add the Indeces
				indeces.add(clauses.indexOf(positiveClause) + 1);
				indeces.add(clauses.indexOf(negativeClause) + 1);

				// Check if the new Clause is a Contradiction
				if(newLiterals.isEmpty() && !terminate)
				{
					// Terminate all Threads
					terminate = true;
					terminationIndeces = indeces;
					return;
				}

				// Construct a Clause with the new Literals
				Clause newClause = new Clause(newLiterals);

				// Make sure the Clause is Unique
				if(clauses.contains(newClause) || deductions.contains(newClause))
					continue;

				// Make sure the Clause is Non-Empty
				if(newClause.getCurrentLiteralCount() == 0)
					continue;

				// Make sure that the Threads have not been Terminated
				if(terminate)
					return;

				// Add the Clause to the Derived Set
				addDeduction(newClause, indeces);

				// Map the Indeces with the Clause
				derivations++;
			}
		}
	}

	// Waits for all Threads to Finish
	public static void joinAllThreads()
	{
		for(Thread thread : threads)
			try {thread.join();}
			catch(InterruptedException e){}

		Resolution.threads.clear();
		terminate = false;
	}

	// Returns the Termination Index
	public static SortedSet<Integer> getTerminationIndex()
	{
		return terminationIndeces;
	}

	//* Clause Methods *//
	// Returns the Clause at the specified Index
	public static Clause getClause(int index)
	{
		return clauses.get(index);
	}

	// Sets the List of Clauses
	public static void setClauses(List<Clause> clauses)
	{
		Resolution.clauses = clauses;
	}

	//* Deduction Methods *//
	// Adds the specified Deduction to the List of Deductions
	public static synchronized void addDeduction(Clause deduction, SortedSet<Integer> indeces)
	{
		deductions.add(deduction);
		Resolution.indeces.put(deduction, indeces);
	}

	// Returns the List of Deductions
	public static SortedSet<Clause> getDeductions()
	{
		return deductions;
	}

	// Returns the List of Derivation Indeces
	public static Map<Clause, SortedSet<Integer>> getIndeces()
	{
		return indeces;
	}

	// Clears the List of Deductions
	public static void clearDeductions()
	{
		deductions.clear();
		indeces.clear();
	}
}
