/*

//*******************************************************Barcode.***********************************************************
https://codeforces.com/problemset/problem/225/C




// Time Complexity:O(m*n).                									// n- #cols, m-diff b/w low and high.                                  
// Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                									// n- #cols, m-diff b/w low and high.                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, since we can form pathches of width [low, high]. For every column we iter. over [i-high, i-low]
// range of cols and make the in between columns of white/black colors and calc. the least #moves for curr. column to have each of white, black colors.
// We return min(dp[cols][white], dp[cols][black]), which shows min cost to properly set colors to all cols until last column.






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
    
    // ifstream cin;
    // cin.open("D:\\Masters\\Coding_Practice\\CPP\\CodeForces\\testFile.txt");

    int rows, cols, low, high;
    cin>>rows>>cols>>low>>high;
    vector<string>v(rows);
	vector<vector<int>>dp(cols+1, vector<int>(2,INT_MAX));
	vector<int>prefixWhiteMoves(cols+1, 0), prefixBlackMoves(cols+1, 0);
	for(int i=0;i<rows;i++) {
		cin>>v[i];
	}
	for(int j=0;j<cols;j++) {
		int whiteSteps=0;
		for(int i=0;i<rows;i++) {
			if(v[i][j]=='#') whiteSteps++;
		}
		prefixWhiteMoves[j+1]=prefixWhiteMoves[j]+whiteSteps;
		prefixBlackMoves[j+1]=prefixBlackMoves[j]+(rows-whiteSteps);
		// cout<<"j: "<<j<<" and whiteMoves: "<<prefixWhiteMoves[j+1]<<" and blackMoves: "<<prefixBlackMoves[j+1]<<endl;
		// if(j>0) {
			// prefixWhiteMoves[j]+=prefixWhiteMoves[j-1];
			// prefixBlackMoves[j]+=prefixBlackMoves[j-1];
		// }		
	}
	
	int steps=high-low+1;
	dp[0][0]=0;
	dp[0][1]=0;
	for(int j=low-1;j<cols;j++) {
		for(int prev=j-low;prev>=j-high && prev+1>=0;prev--) {
			// cout<<"prev: "<<prev<<endl;
			if(dp[prev+1][1]!=INT_MAX)
				dp[j+1][0]=min(dp[j+1][0], dp[prev+1][1]+(prefixWhiteMoves[j+1]-prefixWhiteMoves[prev+1]));
			if(dp[prev+1][0]!=INT_MAX)
				dp[j+1][1]=min(dp[j+1][1], dp[prev+1][0]+(prefixBlackMoves[j+1]-prefixBlackMoves[prev+1]));
		}
		// cout<<"j: "<<j<<" and whiteMoves: "<<dp[j+1][0]<<" and blackMoves: "<<dp[j+1][1]<<endl;
	}
	cout<<min(dp[cols][0], dp[cols][1])<<endl;
    return 0;
}
