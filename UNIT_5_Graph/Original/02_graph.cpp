#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

const long long INF = 4000000000000000000LL;

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
    pq.push(make_pair(0LL, source));

    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist != dist[u])
            continue;

        vector<pair<int, long long> >::const_iterator it;

        for (it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = it->first;
            long long weight = it->second;

            if (currentDist > INF - weight)
                continue;

            long long newDist = currentDist + weight;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                parent[v] = u;
                pq.push(make_pair(newDist, v));
            }
        }
    }
}

int main() {
    int n, m;

    cout << "Enter number of junctions: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of junctions.\n";
        return 1;
    }

    cout << "Enter number of roads: ";
    if (!(cin >> m) || m < 0) {
        cout << "Invalid number of roads.\n";
        return 1;
    }

    vector<vector<pair<int, long long> > > graph(n + 1);

    cout << "\nEnter roads as: junction1 junction2 distance\n";
    cout << "Roads are bidirectional.\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        cout << "Road " << i + 1 << ": ";

        if (!(cin >> u >> v >> w) ||
            u < 1 || u > n ||
            v < 1 || v > n ||
            w < 0 || w >= INF) {
            cout << "Invalid road details.\n";
            return 1;
        }

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int source, destination;

    cout << "\nEnter source junction: ";
    if (!(cin >> source) || source < 1 || source > n) {
        cout << "Invalid source junction.\n";
        return 1;
    }

    vector<long long> dist;
    vector<int> parent;

    dijkstra(graph, source, dist, parent);

    vector<pair<long long, int> > reachable;

    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF) {
            reachable.push_back(make_pair(dist[i], i));
        }
    }

    sort(reachable.begin(), reachable.end());

    cout << "\nShortest distances from junction "
         << source << ":\n";

    cout << "Junction\tDistance\n";

    for (int i = 0; i < (int)reachable.size(); i++) {
        cout << reachable[i].second << "\t\t"
             << reachable[i].first << "\n";
    }

    cout << "\nEnter destination junction: ";
    if (!(cin >> destination) ||
        destination < 1 || destination > n) {
        cout << "Invalid destination junction.\n";
        return 1;
    }

    if (dist[destination] == INF) {
        cout << "No path exists between the selected junctions.\n";
        return 0;
    }

    vector<int> path;

    int v = destination;

    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest path: ";

    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];

        if (i < (int)path.size() - 1)
            cout << " -> ";
    }

    cout << "\nTotal distance: " << dist[destination] << "\n";

    return 0;
}
