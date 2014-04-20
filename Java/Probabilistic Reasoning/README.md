Probabilistic Reasoning
========================

**Compile:**<br>
No compiling is necessary. Download the contents in the *exe* folder. Should you really wish to compile this project yourself, import the project into the Eclipse IDE and export it into a Runnable Jar.

**Execution:**<br>
Run the `ProbabilisticReasoning.jar` File with the following command:<br>
`java -jar <Jar File> <Bayes Net File> <enum | elim> <Query>`

**Flags:**<br>
The following Flags serve the specified Purpose:
 - `-jar <Jar File>` : Tells Java to run the specified Jar File *(Probabilistic Reasoning.jar)*
 - `<Bayes Net File>` : Tells which Bayes Net to Use *(./example1.bn)*
 - `<enum | elim>` : Tells the Program which Calculation Method to Use
    - `enum` : Calculates by Enumeration
    - `elim` : Calculates by Elimination *(NYI)*
 - `<Query>` : Tells the Program which Query to Use *("P(B|J=t,M=t)")*
    - Queries should not contain spaces, and should be wrapped in Quotations

Note that you may carefully reorder these arguments. The Program searches for a file with a `.bn` extension, the word `enum` or `elim`, and an argument beginning with `P(`.

**Example:**<br>
`java -jar ProbabilisticReasoning.jar example1.bn enum P(B|J=t,M=t)` *(Runs the Program using the Bayes Net in the Example 1 File and calculates the Probability of `B` given `J` and `M` are true using the Enumeration Algorithm)*

**Output:**<br>
The Program will Output the Enumeration at each Step displaying its Values for the given Entry.

The Final Output will be the Value of the Query and its Inverse.

**Bayes Net File:**<br>
A Bayes Net File has a Formal Definition of:

  <file> ::= <var-prob> (<newline> <newline> <var-prob>)*
  <var-prob> ::= <prior-prob> | <prob-table>
  <prior-prob> ::= "P(" <var> ") = " <decimal>
  <prob-table> ::= <header> <newline> <horiz-sep> <newline>
  <entry-list>
  <header> ::= <var> (" " <var>)* " | " <var>
  <horiz-sep> ::= "-"+ "|" "-"+
  <entry-list> ::= <table-entry> (<newline> <table-entry>)+
  <table-entry> ::= <truth-symb> (" " <truth-symbol>)* " | "
  <decimal>
  <truth-symbol> ::= "t" | "f"
  <decimal> ::= "0" | "0"? "." <digit>+
  <digit> ::= "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"
  <var> ::= "A"|"B"|"C"|"D"|"E"|"F"|"G"|"H"|"I"|"J"|"K"|"L"|"M"|"N"|"O"|"P"|"Q"|"R"|"S"|"T"|"U"|"V"|"W"|"X"|"Y"|"Z"
  <newline> ::= "\n"

If you don't understand what that means, look at the formatting of the Examples. If you format a File incorrectly, the Program will be sure to tell you what you did wrong.

**Probabilistic Reasoning:**<br>
The purpose of this Program is to determine the Probability of a certain Variable given certain known Conditions. The Bayes Net used in the Program helps specify how Variables are related to each other *(i.e. Whether or not it Rains might help you conclude whether or not the Ground is Wet)*.

This is calcuated by using three Probability Rules:
 - Total Probability: `P(A) = P(A,B=t) + P(A,B=f)`
 - Chain Rule: `P(A,B) = P(A|B)*P(B)`
 - Bayes Rule: `P(A|B) = P(B|A) * [P(A)/P(B)]`

When used together an Enumeration Algorithm can be formed. See the `parseQuery` and `enumerateAll` methods in the `BayesNet` Class to see how this is done.

**File Descriptions:**<br>
 - Assignment: Contains Implementation Specific Classes
    - `Input.java`: Defines the *Input* Class, which is responsible for being able to read a Bayes Net File
    - `Main.java`: Defines the *Main* Class, which runs the Program and interprets the Command Line
    - `FileFormatException.java`: Defines the *FileFormatException* Class, which is thrown when a File is found to be Formatted Incorrectly
 - Knowledge: Contains General Computational Classes
    - `BayesNet.java`: Defines the *BayesNet* Class, which represents the relationship between Probabilities, and is responsible for parsing Queries
    - `Probability.java`: Defines the *Probability* Class, which represents a Probability
    - `Query.java`: Defines the *Query* Class, which represents a Query and is responsible for being able to interpret a Query String
