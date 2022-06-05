// TC: O(n) SC: O(n) using unordered_set

bool findPair(int arr[], int size, int n){
    unordered_set<int> s;
    for(int i=0; i<size; i++){
        if(s.count(arr[i]-n) || s.count(n+arr[i])){
            return true;
        }
        s.insert(arr[i]);
    }
    
    return false;
}


// TC: O(nlog(n)) SC: O(1) using sorting

bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    
    if(n<0) n*=-1;
    
    int i=0, j=1;
    while(j<size){
        if(i==j) j++;
        if(arr[j]-arr[i]==n){
            return true;
        }
        else if(arr[j]-arr[i]<n){
            j++;
        }
        else{
            i++;
        }
    }
    return false;
}