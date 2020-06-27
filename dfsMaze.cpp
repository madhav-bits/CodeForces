/*

//*******************************************************Maze.***********************************************************
https://codeforces.com/problemset/problem/377/A




// Time Complexity:O(n*m).													// n- #strings, m-length of the string.                                                  
// Space Complexity:O(n*m).                                                  

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).													// n- #strings, m-length of the string.                                                  
// Space Complexity:O(n*m).                                                   
// This is DFS based solution. Here, since we have to add additional k walls while making sure rest of empty spaces are still
// connected. We first iterate over a connected init. empty-k spaces and start marking empty spaces with walls afterwards. Thus, 
// we maintained connectivity among remaining empty spaces and added k walls.







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




vector<int>dirs({-1,0,1,0,-1});



void dfsArray(vector<string>&v, int row, int col, int &escape, vector<vector<bool>>&visited){
	if(escape<=0)
		v[row][col]='X';
	escape--;
	visited[row][col]=true;
	for(int i=0;i<4;i++){
		int dx=dirs[i], dy=dirs[i+1];
		if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].length() || visited[row+dx][col+dy]==true || v[row+dx][col+dy]!='.') continue;
		dfsArray(v, row+dx, col+dy, escape, visited);
	}
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols, newWalls, emptySpaces=0;
    int startRow=-1, startCol=-1;
    cin>>rows>>cols>>newWalls;
    vector<string>v(rows);
    string s;
    for(int a=0;a<rows;a++){
    	cin>>v[a];
    	// cout<<v[a]<<endl;
    	for(int b=0;b<cols;b++){
    		if(v[a][b]=='.') emptySpaces++;
    		if(v[a][b]=='.' && startRow==-1){
    			startRow=a;
    			startCol=b;
    		}
    	}
    }
    int escape=emptySpaces-newWalls;
    // cout<<"emptySpaces: "<<escape<<endl;
    vector<vector<bool>>visited(rows, vector<bool>(cols, false));
    dfsArray(v, startRow, startCol, escape, visited);

    for(int i=0;i<rows;i++)
    	cout<<v[i]<<endl;
    return 0;
}
