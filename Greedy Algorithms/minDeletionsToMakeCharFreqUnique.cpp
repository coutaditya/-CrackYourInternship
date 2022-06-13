// Inefficient Solution

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        for(auto c:s){
            m[c]++;
        }
        
        int ans = 0;
        bool freq[(int)1e5+1] = {false};
        for(auto i:m){
            if(!freq[i.second]){
                freq[i.second]=true;
            }
            else{
                int t = i.second-1;
                while(t>0 && freq[t]){
                    t--;
                }
                freq[t]=true;
                ans+=(i.second-t);
            }
        }
        
        return ans;
    }
};


// Efficient Solution
// First of all let us understand, what the question is telling. 
// We have to** delete** the character such that frequency of every character becomes unique. 
// So, a simple greedy approach will that, we store the frequencies of every char in a array, 
// And then, we will sort it in reverse order. Let us take a example,
// s = " abbcbcca "
// cnt[a] = 2, cnt[ b ]=3 & cnt [ c ] = 3.
// After sorting our frequency array will look like [ 3, 3, 2 ], 
// Now, to make every char unique we will start from index 1 and if the value is greater than or equal to its previous value, 
// we will change it to a value 1 less than the previous value and we will find count of number we removed. 
// The array becomes, [3, 2, 1] after doing all the operations.

bool comp(int a, int b){
    return a>b;
}

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(auto c:s){
            freq[c-'a']++;
        }
        
        int ans = 0;
        sort(freq, freq+26, comp);
        for(int i=0; i<25; i++){
            if(freq[i]!=0 && freq[i+1]>=freq[i]){
                ans+=(freq[i+1]-freq[i]+1);
                freq[i+1]=(freq[i]-1);
            }
            else if(freq[i]==0){
                ans+=freq[i+1];
                freq[i+1] = 0;
            }
        }
        
        return ans;
    }
};