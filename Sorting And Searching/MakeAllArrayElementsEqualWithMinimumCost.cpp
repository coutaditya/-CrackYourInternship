// Sort the array

// APPROACH 1: 
// This problem can be solved by observing the cost while changing the target equal value, i.e. we will see the change in cost when target equal value is changed. 
// It can be observed that, as we increase the target equal value the total cost decreases up to a limit and then starts increasing i.e. the cost graph with respect to target equal value is of U-shape and 
// as cost graph is in U-shape, the ternary search can be applied to this search space and our goal is to get that bottom most point of the curve which will represent the smallest cost.

// TC: O(n*log3(n)) SC: O(1) 

int computeCost(int arr[], int N, int X)
{
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}

int minCostToMakeElementEqual(int arr[], int N)
{
    int low, high;
    low = high = arr[0];
 
    for (int i = 0; i < N; i++) {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }
 
    while ((high - low) > 2) {

        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
 
        int cost1 = computeCost(arr, N, mid1);
        int cost2 = computeCost(arr, N, mid2);
 
        if (cost1 < cost2)
            high = mid2;
 
        else
            low = mid1;
    }
 
    return computeCost(arr, N, (low + high) / 2);
}


// APPROACH 2:
// Think geometrically. Assume that array elements are co-ordinates on x axis. 
// The problem reduces to finding another co-ordinate such that the sum of distances between this choice and other co-ordinates is minimized. 
// Observe that: If number of coordinates are odd then y = middle element. 
// 				 If even then y is any number in between middle 2 co-ordinates. 
// 				 Say Input = [a, b, c, d]. Output is any number between b and c including both. 
// Hence the cost is sum which can be computed easily now that we have chosen y. sum|(y-ai)| for all i.

// TC: O(n) SC: O(1)

int minCostToMakeElementEqual(int a[], int n){
 
    int y;
    if (n % 2 == 1)
        y = a[n / 2];
 
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
 
    int s = 0;
    for(int i = 0; i < n; i++)
        s += abs(a[i] - y);
         
    return s;
}
