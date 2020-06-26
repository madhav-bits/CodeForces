/*

//*******************************************************Make Good.***********************************************************
https://codeforces.com/problemset/problem/1270/C




// Time Complexity:O(k).													// k- constant value.                                                  
// Space Complexity:O(1).                                                       

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(k).													// k- constant value.                                                  
// Space Complexity:O(1).                                                   
// This is Bitmask and observation based solution. I had learnt the solution from fellow coders. Here, we add two nums to achieve 
// our target. First one is to add xorSum on both sides and total xor to be =0, later we add numTotal+xorSum on both sides, on the 
// left side, it is 2*(numTotal+xorSum), on the right side xor would be (0^(numTotal+xorSum))=(numTotal+xorSum). As we multiply
// right side with 2, we get both sides to be equal.




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

    
    int tests, nums, num;
    cin>>tests;
    for(int a=0;a<tests;a++){
    	cin>>nums;
    	long long int total=0, xNums=0;
    	for(int i=0;i<nums;i++){
    		cin>>num;
    		total+=num;
    		xNums^=num;
    	}
    	cout<<2<<endl;
    	cout<<xNums<<" "<<total+xNums<<endl;
    }
    return 0;
}
