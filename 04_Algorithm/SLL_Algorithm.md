Algorithm 1: Add Coach
1.	Start.
2.	Create a new coach node.
3.	Enter coach number and coach type.
4.	Set next = NULL.
5.	If head == NULL, make the new node head.
6.	Otherwise, traverse to the last node and link the new node.
7.	Display “Coach added successfully”.
8.	Stop.

Algorithm 2: Remove Coach
1.	Start.
2.	If head == NULL, display “No coaches available” and stop.
3.	Enter the coach number to remove.
4.	If the first node matches, update head and delete the node.
5.	Otherwise, search for the required coach.
6.	If found, change the links and delete the node.
7.	If not found, display “Coach not found”.
8.	Stop.

Algorithm 3: Display Coaches
1.	Start.
2.	If head == NULL, display “No coaches available” and stop.
3.	Set temp = head.
4.	Traverse the linked list.
5.	Display coach number and coach type of each node.
6.	Stop.

Algorithm 4: Search Coach
1.	Start.
2.	If head == NULL, display “No coaches available” and stop.
3.	Enter the coach number to search.
4.	Set temp = head.
5.	Compare the coach number with each node.
6.	If found, display coach details.
7.	If temp == NULL, display “Coach not found”.
8.	Stop.

Algorithm 5: Main Program
1.	Start.
2.	Initialize head = NULL.
3.	Display the menu.
4.	Read the user's choice.
5.	Perform Add, Remove, Display, or Search operation.
6.	If choice is 5, exit the program.
7.	Otherwise, return to the menu.
8.	Stop.
