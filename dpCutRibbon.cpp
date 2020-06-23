/*

//*******************************************************Cut Ribbon.***********************************************************
https://codeforces.com/problemset/problem/189/A




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. 







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




using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int n, a, b, c;
    cin>>n>>a>>b>>c;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
    	if(i-a>=0 && dp[i-a]!=-1) dp[i]=max(dp[i], dp[i-a]+1);
    	if(i-b>=0 && dp[i-b]!=-1) dp[i]=max(dp[i], dp[i-b]+1);
    	if(i-c>=0 && dp[i-c]!=-1) dp[i]=max(dp[i], dp[i-c]+1);
    	// cout<<"i: "<<i<<" and dp[i]: "<<dp[i]<<endl;
    }
    cout<<dp[n];
    return 0;
}
