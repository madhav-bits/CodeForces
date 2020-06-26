/*

//*******************************************************Domino.***********************************************************
https://codeforces.com/problemset/problem/353/A




Time Complexity:O(n).                                                    	// n- #rows of dominoes.                                                                                                                                           
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).         											// n- #rows of dominoes.                                         
// Space Complexity:O(1).                                                   
// This is Observation based solution. Here, we keep track of #odd nums on the left, right. If we have odd number of odd nums on 
// only one side then we can't get our desired psn. We cnt #dominoes with odd, even nums on it. They will be used to balance the
// #odds in the solution. We balance them if we have odd #odds and modify the values accordingly. If we dont' have even #odds on 
// both sides at the end, we return -1 else we return #moves.







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

    int rows=0, lt=0, rt=0;
    int leftOdd=0, rightOdd=0, totalLeftOdd=0, totalRightOdd=0;
    cin>>rows;
    for(int i=0;i<rows;i++){
    	cin>>lt>>rt;
    	if(lt%2==1) totalLeftOdd++;
    	if(rt%2==1) totalRightOdd++;

    	if(lt%2==1 && rt%2==0) leftOdd++;
    	if(rt%2==1 && lt%2==0) rightOdd++;
    }
    if(totalLeftOdd%2==1 ^ totalRightOdd%2==1){
    	cout<<-1<<endl;
    	return 0;
    }
    int res=0;
	if(totalLeftOdd%2==1 && rightOdd!=0){
		res++;
		totalRightOdd--;
		rightOdd--;
		leftOdd++;
		totalLeftOdd++;
	}

	if(totalRightOdd%2==1 && leftOdd!=0){
		res++;
		totalRightOdd++;
		rightOdd++;
		leftOdd--;
		totalLeftOdd--;
	}
	if(totalLeftOdd%2==1 || totalRightOdd%2==1) cout<<-1<<endl;
	else cout<<res<<endl;

    return 0;
}
