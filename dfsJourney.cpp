/*

//*******************************************************Journey.***********************************************************
https://codeforces.com/problemset/problem/839/C




// Time Complexity:O(n).													// n- #nodes in the graph.                                                  
// Space Complexity:O(n).                                                         

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).													// n- #nodes in the graph.                                                  
// Space Complexity:O(n).                                                   
// This is DFS based solution. Here, as we are calc. Expected distance, we have to multiply probs with dist. As the horeses travels 
// until it reaches the leaf nodes, we pass the dist and prob. for horse to be in a node in the dfs call. We add the product of these 
// two vars at all leaf nodes and return it with 7 decimal point precision.







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
#include<iomanip>



using namespace std;




void iterateGraph(vector<vector<int>>&graph, int node, int par, double prob, int dist, double&res){
	if(graph[node].size()==1 && graph[node][0]==par){
		// cout<<"node: "<<node<<" and prob: "<<prob<<" and dist: "<<dist<<endl;
		res+=prob*dist;
		return ;
	}

	int len=(int)graph[node].size()-1;
	if(par==-1) len++;
	for(int i=0;i<graph[node].size();i++){
		int adj=graph[node][i];
		// cout<<"node: "<<node<<" and adj: "<<len<<endl;
		if(adj==par) continue;
		iterateGraph(graph, adj, node, prob/len, dist+1, res);
	}
	return ;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    vector<vector<int>>graph(100001);
    int nodes, node1, node2;
    cin>>nodes;
    if(nodes==1){
    	cout<<0.0<<endl;// Don't know why.
    	return 0;
    }
    for(int i=1;i<nodes;i++){
    	cin>>node1>>node2;
    	graph[node1].push_back(node2);
    	graph[node2].push_back(node1);
    }

    double res=0;
    iterateGraph(graph, 1, -1, 1.0, 0, res);
    cout<<fixed<<setprecision(7)<<res<<endl;
    return 0;
}
