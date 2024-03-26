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

   
        for (int i = 0; i < max_n; i++) {
            int u = -1;
            //  每次确定一个最小 找到这个最小
            for (int j = 0; j < max_n; j++) {
                if (!vistited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }
    
            vistited[u] = true;

            for (vector<int> each: graph[u]) {
                int to = each[0];
                int cost = each[1];

                if (distance[u] + cost < distance[to]) {
                    distance[to] = distance[u] + cost;
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
