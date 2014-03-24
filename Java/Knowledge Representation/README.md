Knowledge Representation
========================

**Compile:**<br>
No compiling is necessary. Download the contents in the *exe* folder. Should you really wish to compile this project yourself, import the project into the Eclipse IDE and export it into a Runnable Jar.

**Execution:**<br>
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

**Knowledge Reasoning:**<br>
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

**Implementation:**<br>
Given the large state space that is quickly derived from the initial Clauses, this Program has been Multi-Threaded, and thus will not yield the same result each time. The Program will always accurately tell you whether or not a Contradiction exists within the Knowledge Base, but the exact route to get there, as well as additional derived information, may vary per execution.

Similarly, to help increase readibility of the Output, if a Contradiction is detected, only the Clauses that participated in the derivation will be included.

**File Descriptions:**<br>
 - Assignment: Contains Implementation Specific Classes
    - `Input.java`: Defines the *Input* Class, which is responsible for being able to read a Clause Definition File
    - `Main.java`: Defines the *Main* Class, which runs the Program and interprets the Command Line
    - `Output.java`: Defines the *Output* Class, which is responsible for being able to write to an Output File
 - Knowledge: Contains Abstract Computational Classes
    - `Clause.java`: Defines the *Clause* Class, which represents a set of Literals in Disjunction
    - `ContradictionException.java`: Defines the *ContradictionException* Class, which is to be thrown when a Logical Contradiction is detected
    - `KnowledgeBase.java`: Defines the *KnowledgeBase* Class, which represents a set of Clauses in Conjunction and is capable of deriving new Clauses using the Resolution Rule
    - `Literal.java`: Defines the *Literal* Class, which represents a Variable that is either Positive or Negative *(Negated)*
    - `Resolution.java`: Defines the *Resolution* Class, which is a Threaded implementation of the Resolution Rule that is responsible for deriving new Clauses given a hook Variable *(L[k])*
    - `Variable.java`: Defines the *Variable* Class, which represents an assignable Variable that uses a String to represent its Name
