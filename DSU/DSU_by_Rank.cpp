#include<iostream>
#include<list>
using namespace std;

//Cycle Detection in a undirected graph using DSU

class Graph{
    int V;
    list<pair<int,int> > l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    int addEdge(int u,int v)
    {
        l.push_back(make_pair(u,v));
    }
    
    // Find
    int findSet(int i,int parent[]){
        //base case
        if(parent[i]==-1)
        {
            return i;
        }
        return findSet(parent[i],parent);
    }

    //Union 
    void union_set(int x,int y,int parent[], int rank[]){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);

        if(s1!=s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;  // s2 become parent
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;  // s1 become parent
                rank[s1] += rank[s2];
            }
        }
    }

    bool contains_cycle(){
        //DSU Logic to check if graph contains cycle or not
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i=0;i<V;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        //iterate over the edge list
        for(auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i,parent);
            int s2 = findSet(j,parent);

            if(s1!=s2){
                union_set(s1, s2, parent, rank);
            }
            else{
                // cout<<"Same parents"<<s1<<" and "<<s2<<endl;
                return true;
            }
        }
    delete [] parent;
    return false;
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.contains_cycle()<<endl;
}





// LC


class DSU {
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int Find(int x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }
    
    bool Union(int x, int y){
        int xset = Find(x), yset = Find(y);
        if(xset != yset){
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};
