// Read the explanation here: https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/662812/C%2B%2B-BFS-or-Bellman-Ford-Algo-or-Dijkstra-Algo

// CODE USING BELLMAN-FORD ALGO

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i<k+1; i++){
            vector<int> t(dist);
            for(auto i:flights){
                if(dist[i[0]]!=INT_MAX && t[i[1]]>dist[i[0]]+i[2]){
                    t[i[1]] = dist[i[0]]+i[2];
                }
            }
            dist = t;
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};

// Write Code using dijkstras after watching an explanation