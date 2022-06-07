// Find number of rotations (index of smallest element)
// then BS the number in [0,rot-1] and [rot, n-1]

// My Ghisa-Pita Solution
class Solution {
public:
    int rotations(vector<int> nums){
        int n = nums.size();
        
        int ans = -1;
        
        int l=0, r=n-1;
        while(l<=r){
            if(nums[l]<nums[r] || l==r){
                return l;
            }
            
            int mid = l+(r-l)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            
            if(nums[mid]<nums[next] && nums[mid]<nums[prev]){
                return mid;
            }
            
            else if(nums[mid]>=nums[l]){
                l=mid+1;
            }
            else if(nums[mid]<=nums[r]){
                r=mid-1;
            }
        }
        return ans;
    }
    
    int bs(vector<int> nums, int s, int e, int key){
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[mid] == key){
                return mid;
            }
            else if(nums[mid]<key){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int rot = rotations(nums);
        cout<<"pivot="<<rot<<endl;
        
        int l = bs(nums, 0, rot-1, target);
        cout<<"l="<<l<<endl;
        if(l!=-1){
            return l;
        }
        
        int r = bs(nums, rot, nums.size()-1, target);
        cout<<"r="<<r<<endl;
        if(r!=-1){
            return r;
        }
        
        return -1;
    }
};


// Better concise solution

class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};