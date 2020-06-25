/*

//*******************************************************Mixing Water.***********************************************************
https://codeforces.com/problemset/problem/1359/C




// Time Complexity:O(logn).          										// n- #upper limit of Binary Search.                                        
// Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).          										// n- #upper limit of Binary Search.                                        
// Space Complexity:O(1).                                                   
// This is Binary Search based solution. Here, we are using hot and cold water cups in turns. As a result, avg. of all even #cups
// poured into barrel would always be mean of two temps. We also can't get temperature(avg) less then mean of two temps, so the 
// closest we can achieve is mean. So, we return mean for target<=mean. If target==hot, we return 1, we can get it after 1 cup. 
// The varying avg temps are over odd numbered cup fillings, and the avg is decreasing for every turn. So, we perform Binary 
// Search over odd turns to find closest temps. to target temp. After finding the turn which is closest lesser value to target
// temp, we will also look at curr. result-1 to get avg. > target. These two avgs are on two sides of target temp., we have to 
// find the closest avg by comparing and return it's corresponding turn(cup filling) number.
// I had took a huge number for Binary Search upper limit, as there was no logical way to come up with one.






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

    int tests, hot=0, cold=0, target=0;
    cin>>tests;
    for(int a=0;a<tests;a++){
    	cin>>hot>>cold>>target;
    	double median=(0.0+hot+cold)/2.0;
    	if(target==hot){
    		cout<<1<<endl;
    		continue;
    	}
    	if(target<=median){
    		cout<<2<<endl;
    		continue;
    	}

    	long long int low=1, high=(1LL<<40), res=0;

    	while(low<high){
    		long long int mid=(low+high)/2;
    		long long int total=0ll+(mid*hot)+((mid-1)*cold);
    		double avg= total/(2.0*mid-1.0);
    		if(avg<=target) high=mid;
    		else low=mid+1;
    	}
    	long long int diff=0ll+(low*hot)+((low-1)*cold);					// Turn whose avg is closest < target temp.
    	double avg=diff/(2.0*low-1.0);
    	// cout<<"low: "<<low<<" and diff: "<<avg<<endl;
    	low--;
    	diff=0ll+(low*hot)+((low-1)*cold);									// Turn whose avg. is closest > target temp.
    	double newAvg=diff/(2.0*low-1.0);
    	if(target-avg<newAvg-target) res=low+1;
    	else res=low;
    	cout<<2ll*res-1<<endl;												// Converting bin. search notation to odd #turns.
    }

    return 0;
}
