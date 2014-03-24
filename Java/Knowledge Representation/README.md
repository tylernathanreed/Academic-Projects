Knowledge Representation
========================

**Compile:**
No compiling is necessary. Download the contents in the *exe* folder. Should you really wish to compile this project yourself, import the project into the Eclipse IDE and export it into a Runnable Jar.

**Execution:**
Run the `KnowledgeRepresentation.jar` File with the following command:<br>
`java -jar <Jar File> -i <Input File Path> [-o <Output File Path>]`

**Flags:**
The following Flags serve the specified Purpose:
 - `-jar <Jar File>` : Tells Java to run the specified Jar File *(KnowledgeRepresentation.jar)*
 - `-i <Input File Path>` : Tells the Program to use the specified Clause Definition File *(./input.txt)*
 - `-o <Output File Path>` : Tell the Program to use the specified Output File *(./output.txt)* *[Optional]*
    - Without a specified Output File, the Output will be sent to the System Output *(Console)*

**Example:**<br>
`java -jar KnowledgeRepresentation.jar -i ./input.txt -o ./output.txt` *(Runs the Program using the specified Input and Output Files)*

**Output:**<br>
The Program will Output each Step in the following Format: `#) <Clause> {<Parent A>, <Parent B>}` where the Parents are the Clause Index depicting what two Clauses were used in deriving this information.

Example Output may be:

    1) p q {}
    2) ~p {}
    3) q {1, 2}

Where an Empty Set informs the reader that the Clause was specified in the initial Knowledge Base.

**Clause Definition File:**<br>
This file is used to define the Initial State of the Knowledge Base. Clauses consist of Disjuncted *(OR'ed)* Literals, where each Clause is assumed to be True. Clauses themselves are Conjuncted *(AND'ed)* together to make up the Knowledge Base.

A Clause are defined in the Input File by delimiting Literals with a Space. Literals themselves may be negated by using the '~' Character. An Example Input File may look something like this:

    Sun Mon Tue Wed Thu Fri Sat
    ~Sun ~Mon ~Tue ~Wed ~Thu ~Fri ~Sat
    ~Weekend Sun Sat
    ~Weekday Mon Tue Wed Thu Fri

Here the Clauses may be translated as:
 - 1) Today must be at least one day of the Week
 - 2) Today must be at most one day of the Week
 - 3) A Weekend implies that it is either Sunday or Saturday
 - 4) A Weekday implies that it is either Monday, Tuesday, Wednesday, Thursday, or Friday

Note the use of `var1 var2 var3 ...` and `~var1 ~var2 ~var3 ... `. These define 'At Least' and 'At Most' Contraints. This is not a specific keyword, but rather the natural compilation of logical encoding.

A Clause of the form `var1 implies (->) var2 var3 ...` may be represented as `~var1 var2 var3 ...` as `A -> B` and `~A | B` are equivalent encodings. Given that Clauses require Disjunction, the latter encoding must be used.

**Knowledge Reasoning:**
The purpose of this Program is to be able to derive new information from a predefined set of information. This is done by using the Resolution Rule, which states:

    if (L[1] | L[2] | ... | L[k]) and (~L[k] | L[k+1] | ... | L[m])
        then (L[1] | L[2] | ... | L[k-1] | L[k+1] | ... | L[m]

For example, with the same information above, the following Clauses may be derived:

    ~Weekend ~Mon ~Tue ~Wed ~Thu ~Fri
    ~Weekday ~Sun ~Sat
    ~Weekend ~Weekday

These Clauses may be translated as:
 - 5) A Weekend implies that it is not Monday, Tuesday, Wednesday, Thursday, or Friday
 - 6) A Weekday implies that it is not Sunday or Satuday
 - 7) A Weekend implies that it is not a Weekday *(It cannot be both a Weekend and a Weekday)*

**Implementation:**
Given the large state space that is quickly derived from the initial Clauses, this Program has been Multi-Threaded, and thus will not yield the same result each time. The Program will always accurately tell you whether or not a Contradiction exists within the Knowledge Base, but the exact route to get there, as well as additional derived information, may vary per execution.

Similarly, to help increase readibility of the Output, if a Contradiction is detected, only the Clauses that participated in the derivation will be included.

**File Descriptions:**
 - Assignment: Contains Implementation Specific Classes
    - Constraints: Contains specific Constraint Implementations
       - `EqualsConstraint.java`: Defines the *EqualsConstraint* Class, which is a Specific Implementation of the *Constraint* Class that uses the Relationship `A == B` *(This is defined in the Constraint Definition File as "A = B")*
       - `GreaterThanConstraint.java`: Defines the *GreaterThanConstraint* Class, which is a Specific Implementation of the *Constraint* Class that uses the Relationship `A > B` *(This is defined in the Constraint Definition File as "A > B")*
       - `LessThanConstraint.java`: Defines the *LessThanConstraint* Class, which is a Specific Implementation of the *Constraint* Class that uses the Relationship `A < B` *(This is defined in the Constraint Definition File as "A < B")*
       - `NotEqualsConstraint.java`: Defines the *NotEqualsConstraint* Class, which is a Specific Implementation of the *Constraint* Class that uses the Relationship `A != B` *(This is defined in the Constraint Definition File as "A ! B")*
    - Input: Contains all Classes required to Read Implementation Specific Data
       - `ArgumentException.java`: Defines the *ArgumentException* Class, which is Thrown when an Invalid Argument is provided on the Command Line
       - `ConstraintReader.java`: Defines the *ConstraintReader* Class, which is responsible for being able to read and interpret a Constraint Definition File
       - `FileFormatException.java`: Defines the *FileFormatException* Class, which is Thrown when any specified File in the Program is not formatted correctly
       - `Input.java`: Defines the *Input* Class, which handles all forms of Input from the Command Line
       - `VariableReader.java`: Defines the *VariableReader* Class, which is responsible for being able to read and interpret a Variable Definition File
    - `Letter.java`: Defines the *Letter* Class, which is a Specific Implementation of the *ConstrainedVariable* Class that uses a Single Character to represent a Variable *(This is defined in the Variable Definition File as `A: <Domain>`)*
    - `LetterValue.java`: Defines the *LetterValue* Class, which is a Specific Implementation of the *DomainValue* Class that uses Integers as Domain Values *(This is defined in the Variable Definition File as `<Variable> 1 2 3 4 ...`)*
    - `Main.java`: Defines the *Main* Class, which runs the Program and interprets the Command Line
 - ConstraintSatisfaction: Contains Abstract Computational Classes
    - Ordering: Contains all Abstract Classes that deal with Variable and Value Ordering
       - `LCVOrdering.java`: Defines the *LCVOrdering* Class, which handles the Value Ordering of its Variable by using the Least-Constraining Value Heuristic
       - `LCVOrderingFactory.java`: Defines the *LCVOrderingFactory* Class, which handles the creation of *LCVOrdering* Classes given a specified *ConstrainedVariable* Object
       - `LCVPair.java`: Defines the *LCVPair* Class, which is a Support Class for the *LCVOrdering* Class as it contains the Value and its Restricted Domain Size
       - `MCVOrdering.java`: Defines the *MCVOrdering* Class, which handles the Variable Ordering of all Variables by using the Most-Constrained Variable Heuristic
       - `ValueOrdering.java`: Defines the *ValueOrdering* Class, which is an Abstract Representation of a Value-Ordering Heuristic for a specified Variable
       - `ValueOrderingFactory.java`: Defines the *ValueOrderingFactory* Class, which is an Abstract Representation of a Value-Ordering Factory that handles the creation of *ValueOrdering* Classes given a specified *ConstrainedVariable* Object
       - `VariableOrdering.java`: Defines the *VariableOrdering* Class, which is an Abstract Reprenstation of a Variable-Ordering Heuristic
    - Solver: Contains all Classes that deal with Solving the Abstract Constraint Satisfaction Problem
       - `AbstractSolver.java`: Defines the *AbstractSolver* Class, which is an Abstract Representation of a Constraint Satisfaction Solver
       - `FCSolver.java`: Defines the *FCSolver* Class, which solves Constraint Satisfaction Problems using the Forward-Checking Consistency Procedure
       - `Solver.java`: Defines the *Solver* Class, which solves Constraint Satisfaction Problems without the use of any Consistency Procedures
    - `Configuration.java`: Defines the *Configuration* Class, which holds static Information about the Program's Configuration
    - `ConstrainedVariable.java`: Defines the *ConstrainedVariable* Class, which is an Abstract Representation of a Variable that may have Constraints applied upon it
    - `Constraint.java`: Defines the *Constraint* Class, which is an Abstract Representation of a Constraint that may be placed upon a Variable, and is of the form `<Variable1> <Operator> <Variable2>`
    - `DomainException.java`: Defines the *DomainException* Class, which is Thrown when a Variable is assigned a Value outside of its Domain
    - `DomainValue.java`: Defines the *DomainValue* Class, which is an Abstract Representation of a Value that may be assigned to a Variable
    - `ParticipantException.java`: Defines the *ParticipantException* Class, which is Thrown when a Constraint is prompted for a Variable's Attributes in which the Variable is not a Participant of the Constraint
