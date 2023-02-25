#include <bits/stdc++.h>
#include <list>
using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph {
    // All Nodes
    // Hashmap(string, Node*)

    unordered_map<string, Node*> m;
public:
    Graph(vector<string> cities)
    {
        for(auto city : cities)
        {
            m[city] = new Node(city);
        }
    }
    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if(undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdJList() 
    {
        for(auto cityPair : m)
        {
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout << city << "-->";
            for(auto nbr : node->nbrs)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "paris");
    g.addEdge("Paris", "New York");

    g.printAdJList();
    return 0;
}
