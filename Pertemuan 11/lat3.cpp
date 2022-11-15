#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph {
    private: 
        int V;
        list<int> *adj;
    public: 
        Graph(int V) {
            this->V = V;
            adj = new list<int>[V];
        };
        void addEdge(int v, int w) {        
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        void tampilList(){
            list<int>::iterator i;
            for(int v=0; v < V; v++){
                cout << v;
                for(i=adj[v].begin(); i != adj[v].end(); ++i){
                    cout << "->" << *i;
                }
                cout << endl;
            }
        }
};


    

int main(int argc, char** argv){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.tampilList();
    return 0;
}
