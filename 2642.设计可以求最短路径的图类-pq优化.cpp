class Graph {
public:
    vector<vector<int> > graph[100];
    int max_n;

    Graph(int n, vector<vector<int>>& edges) {
        max_n = n;

        for (vector<int> edge: edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];

            graph[from].push_back({to, cost});
        }
    }  
    
    void addEdge(vector<int> edge) {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];

        graph[from].push_back({to, cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> vistited(max_n, false);
        vector<long long> distance(max_n, INT_MAX);
        distance[node1] = 0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        pq.push({0, node1});

        while (!pq.empty()) {
            int u = pq.top().second;

            if (u == node2) {
                return pq.top().first;
            }

            pq.pop();

            for (vector<int> child: graph[u]) {
                int to = child[0];
                int cost = child[1];

                if (distance[u] + cost < distance[to]) {
                    distance[to] = distance[u] + cost;
                    pq.push({distance[to], to});
                }
            }
        }


        return distance[node2] == INT_MAX ? -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
