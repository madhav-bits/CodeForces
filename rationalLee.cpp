/*

//*******************************************************RationalLee.***********************************************************
hthttps://codeforces.com/problemset/problem/1369/C




// Time Complexity:O(nlogn+mlogm).											// n- #integers, m-#friends                                                  
// Space Complexity:O(1).                                                 

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn+mlogm).											// n- #integers, m-#friends                                                  
// Space Complexity:O(1).                                                   
// This is Greedy based solution. Here, top K great elements are assigned to all friends, later small nums are distributed to 
// friends whom you give greater num of chocolates, as a result many small nums get pushed into few friends, as a result greater
// value nums are disitrubuted among most of the friends, which contirbute more to the total happiness of all the friends.







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

    int tests, n, k;
    cin>>tests;

    for(int a=0;a<tests;a++){
    	cin>>n>>k;
    	vector<int>nums(n,-1);
    	vector<int>allowed(k,-1);
    	for(int i=0;i<n;i++)
    		cin>>nums[i];
    	for(int i=0;i<k;i++)
    		cin>>allowed[i];

    	sort(nums.begin(), nums.end(), greater<int>());
    	sort(allowed.begin(), allowed.end());
    	long long int res=0;
    	for(int i=0;i<k;i++) 
    		res+=nums[i];
    	int i=k-1, j=n-1;
    	while(i>=0){
    		// cout<<"i: "<<allowed[i]<<" j: "<<j<<" and res: "<<res<<endl;
    		if(allowed[i]==1) res+=nums[i];
    		else{
    			res+=nums[j];
    			j-=allowed[i]-1;
    			
    		}
    		i--;
    	}

    	cout<<res<<endl;
    }

    return 0;
}
