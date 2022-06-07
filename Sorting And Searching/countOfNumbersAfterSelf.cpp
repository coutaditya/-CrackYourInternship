// This problem requires to calculate the inversion count for each index in the array
// I used fenwick trees to calculate that because it is much easier that way
// Merge sort se total inversion count is fine (didnot get how to cal for each index-do it later)


// fenwick tree for range sum and point update (change accordingly)
struct fenwick{
	vector<int> fn;
	int n;

	void init(int n){
		this->n=n+1;
		fn.resize(n+1, 0);
	}

	void add(int x, int y){
		x++;  // 1 based indexing
		while(x<n){
			fn[x]+=y;
			x+=(x&(-x));  // add the lsb
		}
	}

	int sum(int x){
		x++;
		int ans=0;
		while(x>0){
			ans+=fn[x];
			x-=(x&(-x));
		}
		return ans;
	}

	int sum(int l, int r){
		return sum(r)-sum(l-1);
	}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        fenwick tree;
        tree.init(n);
        vector<pair<int, int> > v;
        
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++){
            tree.add(v[i].second,1);
            ans[v[i].second] = tree.sum(v[i].second+1, n-1);
        }
        
        return ans;
    }
};