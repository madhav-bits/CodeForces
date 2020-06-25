/*

//*******************************************************Hamburgers.***********************************************************
https://codeforces.com/problemset/problem/371/C




Time Complexity:O(logn).													// n-#rubles available for shopping.                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(lognn).                                                // n-#rubles available for shopping. 
// Space Complexity:O(1).                                                   
// This is Binary Search based solution. Here, we pick the low, high values of #hamburgers that can be made with the money we have.
// At every step, we calc. how many of three ingredients we would need, we subtract #three ingredients which are already present,
// we then calculate the #each of those ingredients needed. We calc. cost for it, if it is<money, this #burgers could be a answer,
// we make res=mid, low=mid+1, if cost>money, this #burgers is not possble, we make high=mid-1. If we get the cost==money, we 
// directly return the #burgers, if not we will return the res at the end of the loop.







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



int currB=0, currS=0, currC=0, costB=0, costS=0, costC=0, numB=0, numS=0, numC=0;


long long int getCost(long long int burgers){
	long long int extraB=max(0ll, burgers*numB-currB);
	long long int extraS=max(0ll, burgers*numS-currS);
	long long int extraC=max(0ll, burgers*numC-currC);
	return extraB*costB+extraS*costS+extraC*costC;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    string s="";
    long long int money=0;
    
    cin>>s;
    cin>>currB>>currS>>currC;
    cin>>costB>>costS>>costC;
    cin>>money;
    for(auto ch:s){
    	if(ch=='B') numB++;
    	else if(ch=='S') numS++;
    	else numC++;
    }
    long long int low=0, high=money+110;
    long long int res=0;
    while(low<=high){
    	long long int mid=(low+high)/2;
    	long long int currCost=getCost(mid);
    	if(currCost==money){
    		cout<<mid<<endl;
    		return 0;
    	}
    	if(currCost<money){
    		res=mid;
    		low=mid+1;
    	}else high=mid-1;
    }
    cout<<res<<endl;
    return 0;
}
