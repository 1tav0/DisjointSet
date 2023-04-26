#include <bits10_1.h>/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
public: 
    DisjointSet(int n){
        rank.resize(n + 1, 0); //to work with 0 and 1 based indexes
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ul_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same component" << endl;
    }else{
        cout << "Not the same component" << endl;
    }

    ds.unionByRank(3, 7);
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same component" << endl;
    }else{
        cout << "Not the same component" << endl;
    }
    return 0;
}