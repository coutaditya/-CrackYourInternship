// Since the constraints allow O(n^3) solution, we will use the floyd-warshall algo to store the all-pair-shortest-paths
// TC: O(n^3)  SC: O(n^2) 

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dist(n, vector<int>(n, 10001));
        
        for(auto i:edges){
            dist[i[0]][i[1]] = dist[i[1]][i[0]] = i[2];
        }
        
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        int res = 0, sum = INT_MAX;
        for(int i=0; i<n; i++){
            int c = 0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    c++;
                }
            }
            if(c<=sum){
                sum = c;
                res = i;
            }
        }
        
        
        return res;
    }
};