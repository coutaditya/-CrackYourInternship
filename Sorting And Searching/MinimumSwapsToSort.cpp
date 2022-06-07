// Read: https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/


// APPROACH 1: TC: O(nlog(n))  SC: O(n)
// This can be easily done by visualizing the problem as a graph. 
// We will have n nodes and an edge directed from node i to node j if the element at i’th index must be present at j’th index in the sorted array.

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums){
	    vector<pair<int, int> > t;
	    int n = nums.size();
	    
	    for(int i=0; i<n; i++){
	        t.push_back({nums[i], i});
	    }
	    
	    sort(t.begin(), t.end());
	    
	    vector<bool> vis(n, false);
	    
	    int ans = 0;
	    
	    for(int i=0; i<n; i++){
	        if(!vis[i]){
	            int j = i;
	            int nodes = 0; // nodes in current cycle
	            while(!vis[j]){
	                vis[j] = true;
	                j = t[j].second;
	                nodes++;
	            }
	            
	            if(nodes>0){
	                ans+=(nodes-1);
	            }
	        }
	    }
	    
	    return ans;
	}
};


// APPROACH 2: 
// Make a new array (called temp), which is the sorted form of the input array. 
// We know that we need to transform the input array to the new array (temp) in the minimum number of swaps. 
// Make a map that stores the elements and their corresponding index, of the input array.

// So at each i starting from 0 to N in the given array, where N is the size of the array:
// 		1. If i is not in its correct position according to the sorted array, then
// 		2. We will fill this position with the correct element from the hashmap we built earlier. 
// 		   We know the correct element which should come here is temp[i], so we look up the index of this element from the hashmap. 
// 		3. After swapping the required elements, we update the content of the hashmap accordingly, as temp[i] to the ith position, and arr[i] to where temp[i] was earlier.

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    unordered_map<int, int> m;
	    vector<int> t;
	    
	    for(int i=0; i<n; i++){
	        m[nums[i]] = i;
	        t.push_back(nums[i]);
	    }
	    
	    sort(t.begin(), t.end());
	    int ans = 0;
	    
	    for(int i=0; i<n; i++){
	        if(t[i]!=nums[i]){
	            swap(nums[i], nums[m[t[i]]]);
	            ans++;
	            
	            m[nums[m[t[i]]]] = m[t[i]];
	            m[t[i]] = i;
	        }
	    }
	    
	    return ans;
	}
};
