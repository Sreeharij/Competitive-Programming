//O(k*E solution) using normal queue
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto coord : flights) {
            graph[coord[0]].push_back({coord[1], coord[2]});
        }

        queue<vector<int>> q;
        //distance, stops, node
        q.push({0,0,src});
        vector<int> shortest_paths(n,INT_MAX);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it[0];
            int stops = it[1];
            int node = it[2];
            if(stops > k)continue;
            for(auto neighbour: graph[node]){   
                int next_node = neighbour.first;
                int weight = neighbour.second;

                if(distance + weight < shortest_paths[next_node]){
                    shortest_paths[next_node] = distance + weight;
                    q.push({distance + weight,stops+1,next_node});
                }
            }
        }
        return shortest_paths[dst] == INT_MAX ? -1 : shortest_paths[dst];
    }
};

//O(k*E) using bellman ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        for(int i=0;i<k+1;i++){
            vector<int> temp_distance(distance.begin(),distance.end());

            for(auto coord: flights){
                int u = coord[0];
                int v = coord[1];
                int weight = coord[2];
                if(distance[u] == INT_MAX)continue;
                if(distance[u] + weight < temp_distance[v]){
                    temp_distance[v] = distance[u] + weight;
                }
            }
            distance = temp_distance;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};