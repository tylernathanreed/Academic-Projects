Internet Simulation
===================

##Project Description:
Simulate a simple Network by having a Process correspond to a Node in the Network, and Files correspond to Channels in the Network. The Network supports up to 10 Nodes.

###Channel and Output Files:
Nodes will Read and Write to Files in the Channels Folder *(you must create the Directory yourself)*. Each File will be named `from[X]to[Y].txt` where `X` is the Source Node and `Y` is the Destination Node. Readers will access the `from[X]to[ID].txt` Files, where Writers will access `from[ID]to[Y].txt` Files.

After Termination, Nodes will Output all received Messages into a File in the Output Folder *(you must create the Directory yourself*). Each file will be named `node[X]received.txt` where `X` is the Node that received the Messages.

Files are not cleared after Termination so that you may see what the Nodes wrote to them. It is recommended that you clear these files by either using the `make clear` command specified in the `makefile` or manually by using the `rm ./Output/* & rm ./Channels/*` command.

###Overview of each Layer:
The Node is split into 3 Layers: Data Link, Network, and Transport.

Each Layer has its respective Packaging and Unpackaging Methods to deal with communication between the same Layers of other Nodes.

A full Message in a Channel may appear as `SZZ[DST[DSTQQ[M...M]]CC` *(Brackets not included)*

####Data Link Layer:
The Data Link Layer is responsible for Channel I/O and will Read and Write from/to Channels.

A Data Link Package is of the form `SZZM...MCC` where:
  - `S` is the Type Byte
  - `ZZ` is the Size of the Message *(This includes the entire Message, from `S` to `CC`)*
  - `M...M` is the Message *(This is likely a Package for the Network Layer)*
  - `CC` is the Check Sum *(Modulo 100)*, which takes the sum of the ASCII values of the Package

####Network Layer:
The Network Layer is responsible for Message Routing and delivering Messages to the Transport Layer once they have reached their Destination. If the Network Layer receives a Message for another Node, it is passed towards the Destination *(Going back down to the Data Link Layer)*.

The Network Layer will periodically Broadcast Configuration Messages to establish the Routing Table and discover new Nodes, as well as determine when Nodes have died.

A Network Routing Package is of the form `DSTM...M` where:
 - `D` is the Type Byte
 - `S` is the Source ID
 - `T` is the Destination ID
 - `M...M` is the Message *(This is likely a Package for the Transport Layer)*

A Network Configuration Package is of the form `CRSTHH` where:
 - `C` is the Type Byte
 - `R` is the Root ID
 - `S` is the Source ID
 - `T` is the Destination ID
 - `HH` is the Hop Count *(Distance)* from the Root ID

####Transport Layer:
The Transport Layer is responsible for End-to-End Messaging, and will split up Messages into smaller portions if they are too large. Negative Acknowledgements will be sent to the Source Node when it recognizes that a Message failed to be received.

A Transport Partial Message Package is of the form `DSTQQM...M` where:
 - `D` is the Type Byte
 - `S` is the Source ID
 - `T` is the Destination ID
 - `QQ` is the Sequence ID *(Used for determining the order of Partial Messages)*
 - `M...M` is the Partial Message *(Has fixed Maximum Length, default 5)*

A Transport Negative Acknowledgement Package is of the form `NSTQQ` where:
 - `N` is the Type Byte
 - `S` is the Source ID
 - `T` is the Destination ID
 - `QQ` is the Sequence ID


When all layers are chained together, their activity may appear as such:
<img src="https://dl.dropboxusercontent.com/u/22054931/Photo%20Dump/Git%20Hub/Internet%20Simulation/Layer%20Design.png" alt="Node Layer Design">

##Compile:
There are three ways to compile this project:
1) Download the contents of the *exe* folder, everything is already done for you.
2) Download the contents of the *src* folder, run the ***make*** command *(Specified in the makefile)*
3) Download the contents of the *src* folder, compile manually with `g++ ./Main.cpp ./DataLink.cpp ./Network.cpp ./Transport.cpp -o Node`

###Execution:
The Program itself acts as a single Node within a Network. To properly run the Simulation, you will need to run multiple instances of the Program. You may do this in Bash with the `&` Operator, or specify a Test Case Scenario in a Shell Script.

A single instance of the Node may be executed as such:
`Node -i <id> -l <lifetime> -n <count> <neighbors> [-m <message> -d <destination>] [-D <debug level>]`

Example:
`Node -i 0 -l 60 -m "This is a Message" -d 1 -n 1 1 -D 2`

When run together, a Test Case Scenario may appear as such:

    Node -i 0 -l 60 -m "This is a Message" -d 1 -n 1 1 -D 2 &
    Node -i 1 -l 60 -n 1 0 -D 2

This will prompt Node 0 to send "This is a Message" to Node 1.

###Flags:
The Following Flags serve the specified Purpose:
 - `-i <id>` : Specifies the ID of the Node
 - `-l <lifetime>` : Specifies the Lifetime of the Node *(In Seconds)*
 - `-m <message>` : Specifies the Message to be Sent *[Optional; Must be in Quotes]*
 - `-d <destination>` : Specifies the Destination of the Message *[Only Required when Message is specified]*
 - `-n <count> <neighbors>` : Specifies the Number of Neighbors, and then a Space-Delimited List of Neighbors
 - `-D <debug level>` : Speicies the Debug Level of the Node *[Optional; Provides Runtime Output]*
    - Debug Levels vary from 0 to 4, where 0 is Off, and 4 is Maximum. It is recommended that you use values 1 - 3.

###Debugging:
Running a Node without the Debug Parameter will cause the Console to lock up for however long the Node is set to live. Given the boring nature of this Output, as well as no knowledge of how Nodes go about their business, it is recommended that you use the Debug Feature. Different Nodes can have different Debug Levels. I personally recommend having Source and Destination Nodes on Debug Level 3, Intermediate Nodes on Debug Level 1 or 2, and all other Nodes on Debug Level 1. You should need to use Debug Level 4 unless you're actually trying to fix something.

Example Output for the following Test Case:

    Node -i 0 -l 20 -m "This is a Message" -d 1 -n 1 1 -D 2 &
    Node -i 1 -l 20 -n 1 0 -D 2

<img src="https://dl.dropboxusercontent.com/u/22054931/Photo%20Dump/Git%20Hub/Internet%20Simulation/Sample%20Output.png" alt="Sample Output">

This may seem like a lot of information, but to fully understand what everything is doing, having this feature is extremely useful.
