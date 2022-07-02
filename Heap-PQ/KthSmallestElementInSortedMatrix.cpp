// READ THE EXPLANATION: https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

// Priority_queue based solution (not that great)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        
        for(auto i:matrix){
            for(auto j:i){
                q.push(j);
                if(q.size()>k) q.pop();
            }
        }
        
        return q.top();
    }
};


// Binary Search Solution
class Solution {
public:
    int elementsGreater(vector<vector<int> > &matrix, int n, int num){
        int ans = 0;
        for(int i=0; i<n; i++){
            if(matrix[i][0]>num){
                return ans;
            }

            if(matrix[i][n-1]<=num){
                ans+=n;
                continue;
            }


            int greaterThan = 0;
            for (int jump = n / 2; jump >= 1; jump /= 2) {
                while (greaterThan + jump < n && matrix[i][greaterThan + jump] <= num) {
                    greaterThan += jump;
                }
            }

            ans += greaterThan + 1;
        }
        
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(k==1) return matrix[0][0];
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        
        while(l<=r){
            int mid1 = l+(r-l)/2;
            
            if(elementsGreater(matrix, n, mid1)>=k) r=mid1-1;
            else l = mid1+1;
            
        }
        
        return l;
    }
};