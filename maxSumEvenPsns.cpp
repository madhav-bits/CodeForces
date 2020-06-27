/*

//*******************************************************Maximum Sum on Even Positions.***********************************************************
https://codeforces.com/problemset/problem/1373/D




// Time Complexity:O(n).        											// n- length of the array.                                          
// Space Complexity:O(n).                                                     

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).        											// n- length of the array.                                          
// Space Complexity:O(n).                                                   
// This is Observation/Greedy based solution. Here, we can reverse single subarray to improve the sum of even indexed values. We 
// try to find one subarray in which odd indexed nums total- even indexed nums is greater. We do this by prefixSum, we maintain
// minm prefix Sum at even/odd index and it's index in two vars. We maintain two vars because, our subarray has to start/end with
// even/odd, odd/even pairs, while calc. max gap we consider whether prefixSum is of even index or odd index. We keep track of
// how much is the diff b/w odd and even indices. We add this diff. to the sum of even indices calc. earlier and return it.







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>
#include<cstring>



using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums, low=-1, high=0;
    long long int res=0, maxDiff=0;
    cin>>tests;
    for(int a=0;a<tests;a++){
    	cin>>nums;
    	long long int v[nums];
    	long long int evenMin=0, oddMin=0, oddMinIndex=-1, evenMinIndex=-1;;
    	low=0; high=0; res=0; maxDiff=0;
    	memset(v, 0, sizeof(v));
    	for(int b=0;b<nums;b++){
    		cin>>v[b];
    		if(b%2==0) res+=v[b];
    	}
    	
    	for(int i=0;i<nums;i++){
    		if(i%2==0) v[i]*=-1;
    		if(i-1>=0) v[i]+=v[i-1];

    		if(i%2==1 && v[i]-oddMin>maxDiff){
    			maxDiff=v[i]-oddMin;
    			low=oddMinIndex+1;
    			high=i;
    		}
    		if(i%2==0 && v[i]-evenMin>maxDiff){
    			maxDiff=v[i]-evenMin;
    			low=evenMinIndex+1;
    			high=i;
    		}

    		if(i%2==0 && v[i]<evenMin){
    			evenMinIndex=i;
    			evenMin=v[i];
    		} 
    		if(i%2==1 && v[i]<oddMin){
    			oddMinIndex=i;
    			oddMin=v[i];
    		} 
    			
    	}
    	// cout<<"low: "<<low<<" and high: "<<high<<" and maxDiff: "<<maxDiff<<endl;
    	if(low!=high) res+=maxDiff;
    	cout<<res<<endl;
    }


    return 0;
}
