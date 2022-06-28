// TC: O(n^3) SC: O(n^2)

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1) matrix[i][j] = 100001;
	        }
	    }
	    
	    for(int k = 0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(matrix[i][k]!=-1 && matrix[k][j]!=-1) matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==100001) matrix[i][j] = -1;
	        }
	    }
	}
};