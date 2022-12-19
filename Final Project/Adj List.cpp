#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int v;
        string nama[100];
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;
    public:
        Graph(int v) {
            this->v = v;
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
        }
        void nameVertex(int i, string nama){
	    this->nama[i]=nama;
	    vector<int>arr;
	    arr.push_back(i);
	    sort(arr.begin(), arr.end());
	}
	void tampilList(){
	    cout << "=== Adjacency List ===" << endl<<endl;
            list<int>::iterator it;
            for(int i=1; i < v; i++){
                cout << nama[i] << "(V"<< i <<")";
                for(it=adj[i].begin(); it != adj[i].end(); ++it){
                    cout << " -> " << nama[*it] << "(V"<< *it <<")" <<"[" <<  weight[make_pair(i, *it)]<<"]";
                }                                                                 
                cout << endl;
            }
            cout << endl;        	
	}
		
        void BFS(int start, int end){
            cout << endl;
            cout << "=== BFS ===" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty())
            {
                int curr = q.front();
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {

                    if(weight[make_pair(curr, *it)] + dist[curr] < dist[*it]){
                        dist[*it] = weight[make_pair(curr, *it)] + dist[curr];
                        domain[*it] = curr;
                        q.push(*it);
                    }
                }
                q.pop();
            }

            vector<int> result;
            int i = end;
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << nama[result[i]] <<"(V" <<  result[i] << ")"<< ", ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
        }
        
        void DFS(int start, int end){
            cout << endl;
            cout << "=== DFS === " << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << nama[dfsResult[i]] <<"(V" <<  dfsResult[i] << ")"<< ", ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 1; i <= v; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        void dijkstra(int start, int end){
            cout << endl << "=== Dijkstra ===" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);

            dist[start] = 0;

            for (int itv = 1; itv <= v ; itv++)
            {
                int min = minDist(dist, vis);
                vis[min] = true;
                list<int>::iterator it;
                for(it = adj[min].begin(); it != adj[min].end(); ++it){
                    if (
                        weight[make_pair(min, *it)] &&
                        !vis[*it] && 
                        dist[min] + weight[make_pair(min, *it)]  < dist[*it]
                    )
                    {
                        dist[*it] = dist[min] + weight[make_pair(min, *it)]; 
                        res[*it] = min;
                    }
                }
            }

            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true)
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }

            reverse(r.begin(), r.end());

            for (int i = 0; i <  r.size(); i++)
            {
                cout << nama[r[i]] <<"(V" <<  r[i] << ")"<< ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }

};

int main(){
    Graph g(20);
    g.nameVertex(1, "Rumah"); 				g.nameVertex(11, "Alfamidi");
    g.nameVertex(2, "Makam Sisingamangaraja XXI");      g.nameVertex(12, "SMP BDB Balige");
    g.nameVertex(3, "Toko Bangunan");  			g.nameVertex(13, "Resto");
    g.nameVertex(4, "Toba Futsal"); 			g.nameVertex(14, "Cafe");
    g.nameVertex(5, "Kantor Bupati"); 			g.nameVertex(15, "Hotel");
    g.nameVertex(6, "Museum TB Silalahi"); 		g.nameVertex(16, "Gereja");
    g.nameVertex(7, "Kolam Renang"); 			g.nameVertex(17, "SPBU");
    g.nameVertex(8, "Bengkel"); 			g.nameVertex(18, "Taman");
    g.nameVertex(9, "Kantin"); 				g.nameVertex(19, "Bank Mandiri");
    g.nameVertex(10, "SMAN 2 Balige"); 			g.nameVertex(20, "Pasar");

    g.addEdge(1,2,4);		g.addEdge(2,1,4);
    g.addEdge(1,3,2);		g.addEdge(3,1,2);
    g.addEdge(1,9,8);		g.addEdge(9,1,8);
    g.addEdge(2,4,1);		g.addEdge(4,2,1);
    g.addEdge(2,9,8); 		g.addEdge(9,2,8);
    g.addEdge(3,5,4);		g.addEdge(5,3,4);
    g.addEdge(3,8,5);		g.addEdge(8,3,5);
    g.addEdge(4,6,4);		g.addEdge(6,4,4);
    g.addEdge(5,8,6); 		g.addEdge(8,5,6);
    g.addEdge(6,7,4); 		g.addEdge(7,6,4);
    g.addEdge(8,13,19);		g.addEdge(13,8,19);
    g.addEdge(8,15,7);		g.addEdge(15,8,7);
    g.addEdge(8,17,14);		g.addEdge(17,8,14);
    g.addEdge(9,10,4);		g.addEdge(10,9,4);
    g.addEdge(9,11,4);		g.addEdge(11,9,4);
    g.addEdge(11,12,1);		g.addEdge(12,11,1);
    g.addEdge(12,13,10);	g.addEdge(13,12,10);
    g.addEdge(13,17,15);	g.addEdge(17,13,15);
    g.addEdge(14,15,2);		g.addEdge(15,14,2);
    g.addEdge(15,16,6);		g.addEdge(16,15,6);
    g.addEdge(15,17,12);	g.addEdge(17,15,12);
    g.addEdge(16,17,5);		g.addEdge(17,16,5);
    g.addEdge(16,18,8);		g.addEdge(18,16,8);
    g.addEdge(17,18,8);		g.addEdge(18,17,8);
    g.addEdge(17,19,10);	g.addEdge(19,17,10);
    g.addEdge(18,19,4);		g.addEdge(19,18,4);
    g.addEdge(18,20,7);		g.addEdge(19,20,10);
    g.addEdge(20,18,4);		g.addEdge(20,19,4);
  
    g.tampilList();
    int start, end;
    cout << "start : ";
    cin >> start;
    cout << "end : ";
    cin >> end;
    g.BFS(start, end);
    g.DFS(start, end);
    g.dijkstra(start, end);
    return 0;    
}
