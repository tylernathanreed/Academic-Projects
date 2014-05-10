Executables
===========

This folder contains a pre-compiled version of the Project ready for you to use. Be sure to look at the Root Directory for all of the required Flags to run the Program properly.

Provided for you are three test cases that you may run youself using the `sh <shell script>` command.

**Test 1:**

    Node -i 0 -l 20 -m "This is a Message" -d 1 -n 1 1 -D 3 &
    Node -i 1 -l 20 -n 1 0 -D 3

This is the Control Case for the Program. It is simply a Network of two Nodes directly connected to each other.

**Test 2:**

    Node -i 0 -l 120 -m "Message Sent Over" -d 5 -n 2 1 2 -D 1 &
    Node -i 1 -l 120 -n 2 0 2 -D 1 &
    Node -i 2 -l 120 -n 4 0 1 2 4 -D 1 &
    Node -i 3 -l 120 -n 3 2 4 6 -D 1 &
    Node -i 4 -l 120 -n 2 3 5 -D 1 &
    Node -i 6 -l 120 -n 2 3 5 -D 1 &

This Test Case is meant to try out the Network Configuration. You may notice that Node 5 is not defined in this Test Case. That is because Node 5 should be run after the Programs are running.

To do this, use the command `Node -i 5 -l 60 -n 2 4 6 -D 3` once the Nodes have reached Lifetime 60.

**Test 3:**

    Node -D 3 -i 0 -l 20 -n 4 1 2 3 4 &
    Node -D 3 -i 1 -l 20 -m "11111" -d 4 -n 1 0 &
    Node -D 0 -i 2 -l 20 -m "22222" -d 4 -n 1 0 &
    Node -D 0 -i 3 -l 20 -m "33333" -d 4 -n 1 0 &
    Node -D 3 -i 4 -l 20 -n 1 0

This Test Case is meant to try out the Routing Protocol. Three Nodes are trying to send a Message to Node 4 simulatenously. It is up to the Network Layer and Transport Layer to be able to send the Messages across Node 0 and keep the Partial Messages in order.
