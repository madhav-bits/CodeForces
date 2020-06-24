/*

//*******************************************************Number of Ways.***********************************************************
https://codeforces.com/problemset/problem/466/C




Time Complexity:O(n).														// n- len. of the array.                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                              		// n- len. of the array.    
// Space Complexity:O(1).                                                   
// This is Dynamic Programming based solution. Here, we store #times first third of the three parts had occured, if we had encountered
// end of second part, it can be the second part for all the first parts found before it, so we add ones to second, as the third
// part has to end at last index, we skip iter. last index to avoid corner scenarios for total array sum=0, all seconds would be
// able to form the third part with the rest of the indices. So, we just directly return the #second parts found.







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

    int len;
    long long int total=0;
    cin>>len;
    vector<int>v(len);
    for(int i=0;i<len;i++){
    	cin>>v[i];
    	total+=v[i];
    }
    // cout<<"total: "<<total<<endl;
    if(total%3!=0){
    	cout<<0<<endl;
    	return 0;
    }

    long long int ones=0, seconds=0;
    long long int sum=0;
    for(int i=0;i<len-1;i++){
    	sum+=v[i];
    	// cout<<"sum: "<<sum<<endl;
    	if((total*2)/3==sum) seconds+=ones;
    	if((total/3)==sum) ones++;
    }
    cout<<seconds<<endl;


    return 0;
}
