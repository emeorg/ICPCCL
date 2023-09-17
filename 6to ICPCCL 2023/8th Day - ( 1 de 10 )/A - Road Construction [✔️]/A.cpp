#include<bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> parent, rank, size;
    priority_queue<int> pq;

    Dsu(int N) {
        parent.resize(N);
        rank.resize(N);
        size.resize(N, 1);
        for (int i = 0; i < N; i++){
            parent[i] = i;
        }
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    int findSet(int i) { 
        if(parent[i] == i){
            return i;
        }else{
            return parent[i] = findSet(parent[i]);
        } 
    }
    void unionSet(int i, int j){
        int x = findSet(i);
        int y = findSet(j);
        if (x != y){
            if (rank[x] > rank[y]){
                parent[y] = x;
                size[x] += size[y]; pq.push(size[x]);
            }else if(rank[x] < rank[y]){
                parent[x] = y;
                size[y] += size[x]; pq.push(size[y]);
            }else{
                parent[x] = y;
                size[y] += size[x]; pq.push(size[y]);
                rank[y]++;
            }
        }
    }

    int getSize(int i){
        return size[findSet(i)];
    }
};

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges, edges_mst;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.push_back({1, a, b});
    }

    // Ordeno las aristas por peso 
    // (es importante que el peso sea el primer elemento de cada arista) 
    //sort(edges.begin(), edges.end());

    Dsu dsu(n);

    // Kruskal
    int grupos=n;
    for(int i = 0; i < m; i++){ // cada dia se agrega una
        int w = edges[i][0];
        int a = edges[i][1];
        int b = edges[i][2];

        if(!dsu.isSameSet(a, b)){   // Si a y b no son del mismo grupo
            grupos=grupos-1;  // 

        }
        dsu.unionSet(a, b);
        edges_mst.push_back({w, a, b});

        cout<<grupos<<" "<< dsu.pq.top() <<'\n';
    }

    return 0;
}