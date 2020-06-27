/*

//*******************************************************Flowers.***********************************************************
https://codeforces.com/problemset/problem/474/D




// Time Complexity:O(n).       												// n- max. flowers he can eat.                                           
// Space Complexity:O(n).                                                          

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).       												// n- max. flowers he can eat.                                           
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, #combinations of flowers depend on prev. step and i-k step, as we can add
// new white flowers set of size k, to the (i-k) length combinations. So, we add dp[i]=dp[i-1]+dp[i-k].Since, for all these queries, 
// all combinations used will be the same, after filling dp array till the maxm. length allowed string. We form a prefix sum array 
// of dp array, as a result we can answer the queries easily: dp[high]-dp[low-1].

// I missed out on few observation while solving, I sought help from solutions posted online.





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

    int tests, grp=0, md=1000000007, low=0, high=0;
    cin>>tests>>grp;
    long long int dp[100003];
	memset(dp,0, sizeof(dp));
	dp[0]=1;
	long long res=0;
	for(int i=1;i<100003;i++){
		dp[i]=dp[i-1];
		if(i-grp>=0) dp[i]=(dp[i]+dp[i-grp])%md;
		if(i>=low && i<=high) res=(res+dp[i])%md;
	}
	dp[0]=0;
	for(int i=1;i<100003;i++){
		dp[i]=(dp[i]+dp[i-1])%md;
	}
    for(int a=0;a<tests;a++){
    	cin>>low>>high;
    	cout<<(dp[high]-dp[low-1]+md)%md<<endl;
    }

    return 0;
}
