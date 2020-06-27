/*

//*******************************************************Convert to Ones.***********************************************************
https://codeforces.com/problemset/problem/997/A




Time Complexity:O(n).                                                       // n- length of the array.                                                                                                                           
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  	// n- length of the array.
// Space Complexity:O(1).                                                   
// This is Observation based solution. Here, there are two ways to do it. Since, #moves in these are almost same, another scenario
// to achieve the target doesn't arise. One is we reverse the substrings to get all zeroes to one place and invert them to one. 
// Other way is to invert all subarrays of zeroes. We return the minm. value of both of these ways.







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

    
    int len, rev=0, invert=0;
    cin>>len>>rev>>invert;
    string s="";
    cin>>s;
    int grp1=0, grp2=0;
    bool first=false, last=false;
    for(int i=0;i<s.length();i++){
    	if(i==0 && s[i]=='0'){
    		grp1++; grp2++;
    	} 
    	if(i>0 && s[i]=='0' && s[i-1]=='1'){
    		grp1++; grp2++;
    	} 
    }
    if(grp1==0){
    	cout<<0<<endl;
    	return 0;
    }
    grp1--;
    // cout<<"grp1: "<<grp1<<" grp2: "<<grp2<<endl;
    long long int res1=1ll*grp1*rev+1ll*invert;
    long long int res2=1ll*grp2*invert;
    // cout<<"res1: "<<res1<<" and res2: "<<res2<<endl;
    cout<<min(res1, res2)<<endl;
    return 0;
}
