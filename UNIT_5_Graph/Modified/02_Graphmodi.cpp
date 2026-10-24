#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <functional>
using namespace std;
const long long INF = numeric_limits<long long>::max();
void dijkstra(
    const vector<vector<pair<int, long long> > >& graph,
    int source,
    vector<long long>& dist,
    vector<int>& parent
) {
    int n = (int)graph.size() - 1;
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int> >,
        greater<pair<long long, int> >
    > pq;
    dist[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (currentDist != dist[u])
            continue;
        for (int i = 0; i < (int)graph[u].size(); ++i) {
            int v = graph[u][i].first;
            long long weight = graph[u][i].second;
            if (dist[u] != INF &&
                dist[u] <= INF - weight &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
void displayDistances(
    const vector<long long>& dist,
    int source
) {
    vector<pair<long long, int> > reachable;
    int n = (int)dist.size() - 1;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != INF)
            reachable.push_back(make_pair(dist[i], i));
    }
    sort(reachable.begin(), reachable.end());
    cout << "\nShortest distances from Junction "
         << source << ":\n";
    cout << "Junction\tDistance\n";
    for (int i = 0; i < (int)reachable.size(); ++i) {
        cout << reachable[i].second << "\t\t"
             << reachable[i].first << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF)
            cout << i << "\t\tUnreachable\n";
    }
}
void displayPath(
    const vector<long long>& dist,
    const vector<int>& parent,
    int source,
    int destination
) {
    if (dist[destination] == INF) {
        cout << "\nNo path exists between Junction "
             << source << " and Junction "
             << destination << ".\n";
        return;
    }
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << "\nShortest path: ";
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << path[i];
        if (i < (int)path.size() - 1)
            cout << " -> ";
    }
    cout << "\nTotal distance: "
         << dist[destination] << "\n";
}
int main() {
    int n, m;
    cout << "Enter number of junctions: ";
    cin >> n;
    cout << "Enter number of roads: ";
    cin >> m;
    if (n <= 0 || m < 0) {
        cout << "Invalid input.\n";
        return 1;
    }
    vector<vector<pair<int, long long> > > graph(n + 1);
    cout << "Enter each road as: from to distance\n";
    cout << "Roads are bidirectional.\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (u < 1 || u > n ||
            v < 1 || v > n || w < 0) {
            cout << "Invalid road input.\n";
            return 1;
        }
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int source, destination;
    cout << "Enter source junction: ";
    cin >> source;
    cout << "Enter destination junction: ";
    cin >> destination;
    if (source < 1 || source > n ||
        destination < 1 || destination > n) {
        cout << "Invalid source or destination.\n";
        return 1;
    }
    vector<long long> dist;
    vector<int> parent;
    dijkstra(graph, source, dist, parent);
    displayDistances(dist, source);
    displayPath(dist, parent, source, destination);
    return 0;
}
