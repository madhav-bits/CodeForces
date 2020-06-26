/*

//*******************************************************News Distribution.***********************************************************
https://codeforces.com/problemset/problem/1167/C




// Time Complexity:O(m*n*logn).                                             // m-#groups.     
// Space Complexity:O(n).													// n-#nodes in the graph.                                                            

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n*logn).                                             // m-#groups.     
// Space Complexity:O(n).													// n-#nodes in the graph.                                                   
// This is Disjoing Set and Union based solution. Here, we join nodes belonging to a group, we also keep track of #nodes in the group.
// As news would among all members who are conneced through any one group, so we connected through this technique. At the end, 
// we iter. through all nodes, find their parent and #nodes connected to it directly or indirectly and print their count.







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




int getParent(vector<int>&parent, int node){
	if(parent[node]!=node)
		parent[node]=getParent(parent, parent[node]);
	return parent[node];
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nodes, groups, mems, curr, first=-1;
    cin>>nodes>>groups;
    vector<int>parent(nodes+1,0), weight(nodes+1,1);
    for(int i=1;i<=nodes;i++)
    	parent[i]=i;
    for(int a=0;a<groups;a++){
    	cin>>mems;
    	int parA=0;
    	if(mems>0){
    		cin>>first;
    		parA=getParent(parent, first);
    	} 
    	for(int b=1;b<mems;b++){
    		cin>>curr;
    		// cout<<curr<<" ";
			int parB=getParent(parent, curr);
			if(parA==parB) continue;
			parent[parB]=parA;
			weight[parA]+=weight[parB];
    	}
    	// cout<<endl;
    }

    for(int i=1;i<=nodes;i++){
    	int parA=getParent(parent, i);
    	cout<<weight[parA]<<" ";
    }
    cout<<endl;
    return 0;
}
