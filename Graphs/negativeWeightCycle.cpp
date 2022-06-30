// Bellman Ford Algorithm to detect negative edge cycle

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INT_MAX);
	    
	    dist[0] = 0;
	    
	    for(int i=0; i<n-1; i++){
	        for(auto i:edges){
	            if(dist[i[0]]!=INT_MAX && dist[i[1]]>(dist[i[0]]+i[2])){
	                dist[i[1]]=dist[i[0]]+i[2];
	            }
	        }
	    }
	    
	    for(auto i:edges){
	        if(dist[i[0]]!=INT_MAX && dist[i[1]]>(dist[i[0]]+i[2])){
                return 1;
            }
	    }
	    
	    return 0;
	}
};