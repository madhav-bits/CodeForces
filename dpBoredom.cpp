/*

//*******************************************************Boredom.***********************************************************
https://codeforces.com/problemset/problem/455/A




Time Complexity:O(k+n).                             						// n- #integers provided in the question, k- constant val.                                                                                                                                                                    
Space Complexity:O(k).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(k+n).                									// n- #integers provided in the question, k- constant val.                                  
// Space Complexity:O(k).                                                   
// This is Dynamic Programming based solution. Here, we iter. over all possible nums in the array. Instead of storing nums, we stored
// their cnt in cnt array. We iter. over cnt array, at every step, we assume removing curr. num and add curr[i]*i to best possible
// sum of nums from [0,i-2] and we also consider best possible sum of nums from [0, n-1] and assign the greater value of two of 
// them, thus dp[i] stores the best possible sum attainable by nums 0 to i. We need not bother i+1, while deleting i, dp[i] doesn't
// include i+1 in it's representation. Thus, we return the value in dp[100000] to return best possible sum of nums form [0,100000].







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

    int nums, num;
    cin>>nums;
    vector<int>occur(100001,0);
    vector<long long int>dp(100001,0);
    for(int i=0;i<nums;i++){
    	cin>>num;
    	occur[num]++;
    }
    for(int i=1;i<=100000;i++){
    	long long int total=1ll*occur[i]*i;
    	if(i-2>=0) total+=dp[i-2];
    	dp[i]=max(dp[i-1], total);
    	// if(occur[i]!=0) cout<<"i: "<<i<<" and dp: "<<dp[i]<<endl;
    }
    cout<<dp.back()<<endl;
    return 0;
}
