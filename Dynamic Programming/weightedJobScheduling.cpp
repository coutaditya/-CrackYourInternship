// Greedy works when all jobs require 1 unit time to complete

bool comp(Job a, Job b){
    return a.profit>b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int md = 0;
        for(int i=0; i<n; i++){
            md = max(md, arr[i].dead);
        }
        
        vector<bool> avail(md+1, true);
        
        sort(arr, arr+n, comp);
        
        int pr = 0, jb = 0;
        for(int i=0; i<n; i++){
            int d = arr[i].dead;
            while(d>0 && avail[d]==false){
                d--;
            }
            if(d!=0){
                pr+=arr[i].profit;
                jb++;
                avail[d] = false;
            }
        }
        
        return {jb, pr};
    } 
};


// We need to use Dynamic Programming when each job has a different duration
// Read this article: https://www.geeksforgeeks.org/weighted-job-scheduling/