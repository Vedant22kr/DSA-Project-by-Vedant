Algorithm for Circular Linked List 

1.	Start the program and initialize tail to NULL. The first coach, when present, is tail->next.
2.	Display the menu containing Add, Delete, Search, Display, Count, and Exit.
3.	Read the user's choice.
4.	If the choice is Add, create a new node and read its coach number.
5.	If the list is not empty, traverse the circle from tail->next and reject a duplicate coach number if found.
6.	Read the coach type. If the list is empty, set tail to the new node and make its next pointer point to itself.
7.	Otherwise, link the new node between tail and the first node, then update tail to the new node.
8.	If the choice is Delete, begin at the first node and track the previous node while searching for the requested coach number.
9.	If the matching node is the only node, set tail to NULL. Otherwise, bypass the node; if it is tail, update tail to the previous node. Delete the removed node.
10.	If the choice is Search, traverse the circle and compare coach numbers until the coach is 
11.	found or the pointer returns to the first node.
12.	If Display is selected, print each coach using a do-while loop until traversal returns to the first node.
13.	If Count is selected, traverse the circle once and increment the counter for every node.
14.	Repeat the menu until the user selects Exit.
15.	On Exit, temporarily break the circular link, delete all nodes, and stop.

 
