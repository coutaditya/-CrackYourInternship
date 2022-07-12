class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr, arr+n);
        long long n1 = 0;
        long long n2 = 0;
        
        for(int i=0; i<n; i+=2){
            n1*=10;
            n1+=arr[i];
            if(i+1<n){
                n2*=10;
                n2+=arr[i+1];
            }
        }
        
        return n1+n2;
    }
};