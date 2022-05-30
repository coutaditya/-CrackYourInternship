#include<bits/stdc++.h>
using namespace :: std;

void printDuplicates(string s){
	unordered_map<char, int> m;

	for(int i=0; i<s.length(); i++){
		m[s[i]]++;
	}

	for(auto i:m){
		if(i.second>1){
			cout<<i.first<<" ";
		}
	}
}

int main(){
	string s = "geeksforgeeks";
	printDuplicates(s);
	return 0;
}