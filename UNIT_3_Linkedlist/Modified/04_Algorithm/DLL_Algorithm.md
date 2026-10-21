Algorithm for DLL

1.	Start the program and initialize head and tail to NULL.

2.	Display the menu containing Add, Delete, Search, Display Forward, Display Backward, Count, and Exit.

3.	Read the user's choice.

4.	If the choice is Add, create a new coach node and read its coach number.

5.	Check the list for a duplicate coach number. If it exists, delete the unused node and return to the menu.

6.	Read the coach type. Set the new node's prev and next pointers to NULL.

7.	If the list is empty, set both head and tail to the new node. Otherwise, link the current tail to the new node and update tail.

8.	If the choice is Delete, search for the requested coach number. If found, reconnect its previous and next nodes, update head or tail when required, and delete the node.

9.	If the choice is Search, traverse from head and compare each coach number with the requested number. Display the result.

10.	If Display Forward is selected, traverse from head to NULL and print every coach.

11.	If Display Backward is selected, traverse from tail to NULL using prev pointers and print every coach.

12.	If Count is selected, traverse from head to NULL and increment a counter for each node.

13.	Repeat the menu until the user selects Exit.

14.	On Exit, delete all remaining nodes to free memory, then stop.
