#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex {
    private:
        list<int> adj;
    
    public:
        void addEdge(int v, int w){
            adj.push_back(w);
        }

        void showList(){
            list<int>::iterator i;
                for(i=adj.begin(); i != adj.end(); ++i){
                    cout << "->" << *i;
                }
                cout << endl;
            }
        };


class Graph {
    private:
        int V;
        Vertex adj[5];
        
    public:
        Graph(int V) {
            this->V = V;

        }

        AddEdgeVertex(int v, int w){
            adj[v].addEdge(v,w);
            adj[w].addEdge(w,v);
        }

        showAllVertex(){
            for(int v=0; v < V; v++){
                cout << v;
                adj[v].showList();
            }
            
        }
};



int main(){
    Graph g(5);

    g.AddEdgeVertex( 0, 1);
    g.AddEdgeVertex( 0, 4);
    g.AddEdgeVertex( 1, 2);
    g.AddEdgeVertex( 1, 3);
    g.AddEdgeVertex( 1, 4);
    g.AddEdgeVertex( 2, 3);
    g.AddEdgeVertex( 3, 4);

    g.showAllVertex();
}
