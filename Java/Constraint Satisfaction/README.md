Constraint Satisfaction
=========================

**Compile:**
No compiling is necessary. Download the contents in the *exe* folder. Should you really wish to compile this project yourself, import the project into the Eclipse IDE and export it into a Runnable Jar.

**Execution:**
Run the `ConstraintSatisfaction.jar` File with the following command:<br>
`java -jar <Jar File> -var <Variable Definition Path> -con <Constraint Definition Path> [-cp <Consistency Procedure>]`

**Flags:**
The following Flags serve the specified Purpose:
 - `-jar <Jar File>` : Tells Java to run the specified Jar File *(ConstraintSatisfaction.jar)*
 - `-var <Variable Definition Path>` : Tells the Program to use the specified Variable Definition File *(./example.var)*
 - `-con <Constraint Definition Path>` : Tells the Program to use the specified Constraint Definition File *(./example.con)*
 - `-cp <Consistency Procedure>` : Tells the Program which Consitency Procedure to Use *[Optional]*
    - `none` : Do not use a Consistency Procedure *(Default)*
    - `fc` : Use the Forward-Checking Consistency Procedure
    - `cp` : Use the Constraint-Propagation Consistency Procedure *(Not Yet Implemented)*
 - `-varh <Heuristic>` : Tells the Program which Variable Selection Heuristic to Use *[Optional]* *(Not Yet Implemented)*
    - `none` : Do not use a Variable Selection Heuristic
    - `alpha` : Use the Alphabetic Variable Selection Heuristic
    - `mcv` : Use the Most-Constrained Variable Selection Heuristic *(Default)*
 - `-valh` : Tells the Program which Value Selection Heuristic to Use *[Optional]* *(Not Yet Implemented)*
    - `none` : Do not use a Value Selection Heuristic
    - `inc` : Use the Increasing Value Selection Heuristic
    - `lcv` : Use the Least-Constraining Value Selection Heuristic *(Default)*
 - `-ma` : Tells the Program the Maximum Number of Attempts it may Use *[Optional]* *(Not Yet Implemented)*
    - Default Value is 30

**Example:**<br>
`java -jar ConstraintSatisfaction.jar -var ./example.var -con ./example.con -cp fc` *(Runs the Program using Forward-Checking Consistency Procedure)*

**Output:**<br>
The Program will Output each Step in the following Format: `#) <Variable> = <Value>, ..., <Variable> = <Value> <Success|Failure>` 

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
