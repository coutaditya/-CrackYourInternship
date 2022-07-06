vector<vector<vector<long long> > > t(4, vector<vector<long long> >(3, vector<long long>(26, -1)));

class Solution{
    
    vector<vector<int> > v = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    
    
    int dx[5] = {1,-1,0,0,0};
    int dy[5] = {0,0,1,-1,0};

	public:
	long long solve(int i, int j, int n){
	    if(n==1) return 1;
	    
	    if(t[i][j][n]!=-1) return t[i][j][n];
	    
	    long long ans = 0; 
	    
	    for(int x = 0; x<5; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            
            if(xx<4 && xx>=0 && yy<3 && yy>=0 && v[xx][yy]!=-1){
                ans+=solve(xx, yy, n-1);
            }
    }
	    
	    return t[i][j][n] = ans;
	    
	}
	
	long long getCount(int N){
		long long ans = 0;
		
		for(int i=0; i<4; i++){
		    for(int j=0; j<3; j++){
		        if(v[i][j]!=-1){
		            ans+=solve(i, j, N);
		        }
		    }
		}
		
		return ans;
	}


};