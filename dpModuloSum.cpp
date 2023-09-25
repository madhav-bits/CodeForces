/*

//*******************************************************Boredom.***********************************************************
https://codeforces.com/problemset/problem/577/B




Time Complexity:O(m*n).                             						// n- length of the array, m- target val.                                                                                                                                                                    
Space Complexity:O(m+n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                     // n- length of the array, m- target val.                                                                                                                                                                    
// Space Complexity:O(m+n).                                                 
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
#include<cstring>




using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // ifstream cin;
    // cin.open("D:\\Masters\\Coding_Practice\\CPP\\CodeForces\\testFile.txt");

    int nums, target;
    cin>>nums>>target;
    // cout<<"nums: "<<nums<<" and target: "<<target<<endl;
    int arr[nums];
    memset(arr, 0, sizeof(arr));
    bool found=false;
    for(int i=0;i<nums;i++) {
        cin>>arr[i];
        arr[i]%=target;
        if(arr[i]==0) {
            found=true;
            break;
        }
    }
    if(found) {
        cout<<"YES"<<endl;
        return 0;
    }

    bool dp[2][target];
    memset(dp, false, sizeof(dp));
    dp[1][0]=true;
    for(int i=0;i<nums;i++) {
        int num=arr[i];
        for(int j=0;j<target;j++) {
            if(j==0 && dp[(i+1)%2][(j-num+target)%target]) {
                found=true;
                break;
            }
            dp[i%2][j]=dp[(i+1)%2][j] || dp[(i+1)%2][(j-num+target)%target];
        }
        if(found) break;
    }
    (found)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}
