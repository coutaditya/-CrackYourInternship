// Memoized solution:

class Solution {
public:
    int solve(vector<pair<int, int> > &v, int i, int m, int n, vector<vector<vector<int> > > &t){
        if(i==-1 || (m==0 && n==0)){
            return 0;
        }
        
        if(t[i][m][n]!=-1) return t[i][m][n];
        
        int z = v[i].first;
        int o = v[i].second;
        
        if(z<=m && o<=n){
            t[i][m][n] = max(solve(v, i-1, m-z, n-o, t)+1, solve(v, i-1, m, n, t));
            // cout<<i<<" "<<m<<" "<<n<<": "<<t[i][m][n]<<"\n";
            return t[i][m][n];
        }
        else{
            t[i][m][n] = solve(v, i-1, m, n, t);
            // cout<<i<<" "<<m<<" "<<n<<": "<<t[i][m][n]<<"\n";
            return t[i][m][n];
        } 
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int> > v;
        for(auto i:strs){
            int z = 0;
            for(int j=0; j<i.length(); j++){
                if(i[j]=='0') z++;
            }
            
            v.push_back({z, i.length()-z});
        }
        
        
        vector<vector<vector<int> > > t(v.size(), vector<vector<int> >(m+1, vector<int>(n+1, -1)));
        
        return solve(v, v.size()-1, m, n, t);
    }
};

// Tabulation Solution:

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int> > v;
        for(auto i:strs){
            int z = 0;
            for(int j=0; j<i.length(); j++){
                if(i[j]=='0') z++;
            }
            
            v.push_back({z, i.length()-z});
        }
        
        
        vector<vector<vector<int> > > t(v.size()+1, vector<vector<int> >(m+1, vector<int>(n+1, 0)));
        
        for(int i=0; i<v.size()+1; i++){
            t[i][0][0] = 0;
        }
        
        for(int i=1; i<=v.size(); i++){
            for(int j=0; j<m+1; j++){
                for(int k=0; k<n+1; k++){
                    if(j==k && j==0){
                        continue;
                    }
                    
                    if(j>=v[i-1].first && k>=v[i-1].second){
                        t[i][j][k] = max(t[i-1][j-v[i-1].first][k-v[i-1].second]+1,t[i-1][j][k]); 
                    }
                    else{
                        t[i][j][k] = t[i-1][j][k];
                    }
                }
            }
        }
        
        return t[v.size()][m][n];
    }
};