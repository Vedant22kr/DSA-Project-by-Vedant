•	Algorithm

1.	Start the program.
2.	Read the number of junctions (n) and roads (m). Validate the values.
3.	Create an adjacency list with n + 1 entries, using junction numbers from 1 to n.
4.	Read each road as (u, v, w). Add the road in both directions because roads are bidirectional. Reject invalid junction numbers or negative distances.
5.	Read the source junction and initialize every distance to infinity and every parent to -1. Set the source distance to 0.
6.	Insert (0, source) into a min-priority queue.
7.	While the priority queue is not empty, remove the junction u with the smallest tentative distance.
8.	Skip the entry if it contains an outdated distance. Otherwise, examine every adjacent junction v.
9.	Calculate newDist = dist[u] + weight. If newDist is smaller than dist[v], update dist[v] and parent[v], then insert the new pair into the priority queue.
10.	Collect all reachable junctions and sort them by distance. Display each junction and its shortest distance.
11.	Read the destination junction. If its distance is infinity, display that no path exists.
12.	Otherwise, follow the parent array from the destination back to the source, reverse the sequence, and display the shortest path and total distance.
13.	Stop the program.

 
