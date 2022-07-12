// Solution here: https://www.youtube.com/watch?v=9DckVBRzuQU&ab_channel=CodeLibrary-byYogesh%26Shailesh

#include<bits/stdc++.h>
using namespace :: std;

bool comp(int a, int b){
    return a>b;
}

int main(){
    int t = 0;
    cin>>t;
    while(t--){
        int n = 0, m = 0;
        cin>>n>>m;
        vector<int> r(n-1, 0), c(m-1, 0);
        for(int i=1; i<n; i++){
            cin>>r[i-1];
        }

        for(int i=1; i<m; i++){
            cin>>c[i-1];
        }

        sort(r.begin(), r.end(), comp);
        sort(c.begin(), c.end(), comp);

        int rows = 1, cols = 1;

        int i=0, j=0;
        int ans = 0;
        while(i<(n-1) && j<(m-1)){
            if(r[i]>c[j]){
                ans+=r[i]*cols;
                rows++;
                i++;
            }
            else if(r[i]<c[j]){
                ans+=c[j]*rows;
                cols++;
                j++;
            }
            else{
                if(rows>cols){
                    ans+=r[i]*cols;
                    rows++;
                    i++;
                }
                else{
                    ans+=c[j]*rows;
                    cols++;
                    j++;
                }
            }
        }
        while(i<(n-1)){
            ans+=r[i]*cols;
            rows++;
            i++;
        }
        while(j<(m-1)){
            ans+=c[j]*rows;
            cols++;
            j++;
        }

        cout<<ans<<"\n";
    }
    return 0;
}