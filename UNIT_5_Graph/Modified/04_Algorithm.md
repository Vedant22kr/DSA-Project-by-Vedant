•	Algorithm

1.	Start the program.
2.	Read the number of junctions n and the number of roads m.
3.	Create an adjacency list to represent the road network.
4.	Read each road as (from junction, to junction, distance). Add the road in both directions because roads are bidirectional.
5.	Read the source junction and the destination junction.
6.	Initialize all distances to infinity, set the source distance to zero, and set all parent values to -1.
7.	Insert the source junction into a minimum-priority queue.
8.	While the priority queue is not empty, remove the junction with the smallest known distance.
9.	For each neighboring junction, check whether travelling through the current junction gives a shorter distance.
10.	If a shorter path is found, update the distance and parent, then insert the updated distance into the priority queue.
11.	When the queue becomes empty, display the shortest distances and mark unreachable junctions.
12.	Use the parent values to reconstruct and display the shortest path to the destination and its total distance. If no route exists, display a no-path message.
13.	Stop the program.

 
