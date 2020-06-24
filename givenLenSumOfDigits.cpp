/*

//*******************************************************Given Length and Sum of Digits.***********************************************************
https://codeforces.com/problemset/problem/489/C




// Time Complexity:O(n).													// n-length of the string.                                                  
// Space Complexity:O(1).                                                         

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).													// n-length of the string.                                                  
// Space Complexity:O(1).                                                   
// This is Observation based solution. In case of minm, we will try to fill 0s until we have to fill nums to get the target. In case of 
// maxm we fill up maxm possible nums at the beginning making sure we only fill zeroes in the later indices.







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

    int length, total;
    cin>>length>>total;
    if(total==0 && length==1){
    	cout<<"0 0"<<endl;
    	return 0;
    }
    if(total==0 || (9*length)<total){
    	cout<<"-1 -1"<<endl;
    	return 0;
    } 

    string minm="", maxm="";
    int target=total;
    for(int i=0;i<length;i++){
    	int curr=max(0, target-9*(length-i-1));
    	if(curr==0 && minm.length()==0) curr++;
    	minm+='0'+curr;
    	target-=curr;
    }

    target=total;
    for(int i=0;i<length;i++){
    	int curr=min(9, target);
    	maxm+='0'+curr;
    	target-=curr;
    }
    cout<<minm<<" "<<maxm<<endl;
    return 0;
}
