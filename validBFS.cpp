/*

//*******************************************************Boredom.***********************************************************
https://codeforces.com/problemset/problem/1037/D




// Time Complexity:O(n).                                                     // n- #nodes in the tree.                                                                                                                                                                  
// Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                     // n- #nodes in the tree.                                                                                                                                                                  
// Space Complexity:O(n).                                                 
// This is BFS+Array based solution. 







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






bool validateBFSArray(vector<int>&v, vector<vector<int>>&graph, vector<int>&parent) {
    if(v[0]!=1) return false;
    int i=0, j=1;
    for(int i=0;i<v.size() && j<v.size();i++) {
        int child=graph[v[i]].size()-1;
        if(i==0) child++;
        while(child>0) {
            // cout<<"child: "<<v[j]<<" and par : "<<v[i]<<endl;
            if(parent[v[j]]!=v[i]) return false;
            child--;
            j++;
        }
    }
    return true;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // ifstream cin;
    // cin.open("D:\\Masters\\Coding_Practice\\CPP\\CodeForces\\testFile.txt");

    int nodes, node1, node2;
    cin>>nodes;
    // cout<<"nums: "<<nums<<" and target: "<<target<<endl;
    vector<vector<int>>graph(nodes+1);
    bool found=false;
    for(int i=0;i<nodes-1;i++) {
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    vector<int>bfsArray(nodes,-1);
    for(int i=0;i<nodes;i++) cin>>bfsArray[i];
    vector<int>parent(nodes+1, -1);
    queue<int>q;
    q.push(1);
    parent[1]=0;// To prevent revisit during BFS.

    while(!q.empty()) {
        int curr=q.front();
        q.pop();
        for(int adj: graph[curr]) {
            if(parent[adj]==-1) {
                parent[adj]=curr;
                q.push(adj);
            }
        }
    }

    validateBFSArray(bfsArray, graph, parent)?
    cout<<"Yes"<<endl:
    cout<<"No"<<endl;
    return 0;
}








//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(m*n).                                                     // n- length of the array, m- target val.                                                                                                                                                                    
// Space Complexity:O(m+n).                                                 
// This is BFS+Array based solution. 







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






bool validateBFSArray(vector<int>&v, vector<vector<int>>&graph, vector<int>&parent) {
    if(v[0]!=1) return false;
    int i=0, j=1;
    for(int i=0;i<v.size() && j<v.size();i++) {
        int child=graph[v[i]].size()-1;
        if(i==0) child++;
        while(child>0) {
            // cout<<"child: "<<v[j]<<" and par : "<<v[i]<<endl;
            if(parent[v[j]]!=v[i]) return false;
            child--;
            j++;
        }
    }
    return true;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // ifstream cin;
    // cin.open("D:\\Masters\\Coding_Practice\\CPP\\CodeForces\\testFile.txt");

    int nodes, node1, node2;
    cin>>nodes;
    // cout<<"nums: "<<nums<<" and target: "<<target<<endl;
    vector<vector<int>>graph(nodes+1);
    bool found=false;
    for(int i=0;i<nodes-1;i++) {
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    vector<int>bfsArray(nodes,-1), order(nodes+1, -1);
    for(int i=0;i<nodes;i++) {
        cin>>bfsArray[i];
        order[bfsArray[i]]=i;
    }

    for(int i=1;i<=nodes;i++) {
        sort(graph[i].begin(), graph[i].end(),[&order](int lt, int rt){
            return order[lt]<order[rt];
        });
    }

    queue<int>q;
    q.push(1);
    vector<bool>visited(nodes+1, false);
    int index=1;
    bool notBFS=false;
    while(!q.empty()) {
        int curr=q.front();
        visited[curr]=true;
        q.pop();
        for(int adj: graph[curr]) {
            if(visited[adj]==false) {
                if(bfsArray[index++]!=adj) {
                    notBFS=true;
                    break;
                }
                q.push(adj);
            }
        }
        if(notBFS) break;
    }

    (notBFS)?
    cout<<"No"<<endl:
    cout<<"Yes"<<endl;
    return 0;
}


