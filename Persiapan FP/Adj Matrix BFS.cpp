#include<bits/stdc++.h>
using namespace std;

class Graph {
   private:
 	vector<vector<int>> adj;
  	int V;
  	string nama[100];

   public:
	Graph(int V) {
	    this->V = V;
	    adj= vector<vector<int>>(V,vector<int>(V,0));
	}
	void nameVertex(int i, string nama){
		this->nama[i]=nama;
		vector<int>arr;
		arr.push_back(i);
		sort(arr.begin(), arr.end());
	}
	void addEdge(int i, int j) {
		adj[i][j] = true;
	    	adj[j][i] = true;
	}
	void tampilList() {
		cout << "=== Nama Vertex ===" << endl;
		for (int i = 1; i < V; i++) 
	      		cout <<  nama[i] << "("<< i <<")" <<", " ;
		cout << endl<<endl;
		cout << "=== Adjacency Matrix ===" << endl;
		cout << "     ";
		for (int i = 1; i < 10; i++) 	
	      		cout <<  i  <<"  ";
		for (int i = 10; i < V; i++) 	
	      		cout <<  i  <<" ";
		cout << endl;
	    	for (int i = 1; i < 10; i++) {
	      		cout << i << "  : ";
	     		for (int j = 1; j < V; j++)
				cout << adj[i][j] << "  ";
	      		cout << "\n";
	   	}
	    	for (int i = 10; i < V; i++) {
	      		cout << i << " : ";
	      		for (int j = 1; j < V; j++)
				cout << adj[i][j] << "  ";
	      		cout << "\n";
	 	}
	  	cout <<endl<<endl;
	}


	void BFS(int s)
	{
		cout << "=== Following is Breadth First Traversal ==="<<endl;
	    	vector<bool> visited(adj.size(), false);
	    	vector<int> queue;
	    	queue.push_back(s);
	    	visited[s] = true;
	    	int vis;
	    	while (!queue.empty()) {
			vis = queue[0];
			cout << nama[vis]<<"("<<"V"<<vis<< ")"  <<", ";
			queue.erase(queue.begin());
			for (int i = 0; i < adj[vis].size(); i++) {
		    		if (adj[vis][i] == 1 && (!visited[i])) {
					queue.push_back(i);
					visited[i] = true;
		    		}
			}
	    	}
	    cout << endl<<endl;
	}
	void BFSWithDestination(int s, int d)
	{
		cout << "=== BFS with destination ===" << endl;
	    	vector<bool> visited(adj.size(), false);
	    	vector<int> queue;
	    	queue.push_back(s);
	    	visited[s] = true;
	    	int vis;
	    	while (!queue.empty()) {
			vis = queue[0];
			cout << nama[vis]<<"("<<"V"<<vis<< ")"  <<", ";
			queue.erase(queue.begin());
			if (vis == d) return;
			for (int i = 0; i < adj[vis].size(); i++) {
		    		if (adj[vis][i] == 1 && (!visited[i])) {
					queue.push_back(i);
					visited[i] = true;
		    		}
			}
	    	}
	}
};

int main()
{
	Graph g(21);
	g.nameVertex(1, "Rumah"); 				g.nameVertex(11, "Alfamidi");
	g.nameVertex(2, "Makam Sisingamangaraja XXI"); 		g.nameVertex(12, "SMP BDB Balige");
	g.nameVertex(3, "Toko Bangunan"); 			g.nameVertex(13, "Resto");
	g.nameVertex(4, "Toba Futsal"); 			g.nameVertex(14, "Cafe");
	g.nameVertex(5, "Kantor Bupati"); 			g.nameVertex(15, "Hotel");
	g.nameVertex(6, "Museum TB Silalahi"); 			g.nameVertex(16, "Gereja");
	g.nameVertex(7, "Kolam Renang"); 			g.nameVertex(17, "SPBU");
	g.nameVertex(8, "Bengkel"); 				g.nameVertex(18, "Taman");
	g.nameVertex(9, "Kantin");				g.nameVertex(19, "Bank Mandiri");
	g.nameVertex(10, "SMAN 2 Balige");			g.nameVertex(20, "Pasar");
	
	g.addEdge(1,2);		g.addEdge(2,1);
   	g.addEdge(1,3);		g.addEdge(3,1);
    	g.addEdge(1,9);		g.addEdge(9,1);
    	g.addEdge(2,4);		g.addEdge(4,2);
    	g.addEdge(2,9); 	g.addEdge(9,2);
    	g.addEdge(3,5);		g.addEdge(5,3);
    	g.addEdge(3,8);		g.addEdge(8,3);
    	g.addEdge(4,6);		g.addEdge(6,4);
    	g.addEdge(5,8); 	g.addEdge(8,5);
    	g.addEdge(6,7); 	g.addEdge(7,6);
    	g.addEdge(8,13);	g.addEdge(13,8);
    	g.addEdge(8,15);	g.addEdge(15,8);
    	g.addEdge(8,17);	g.addEdge(17,8);
    	g.addEdge(9,10);	g.addEdge(10,9);
    	g.addEdge(9,11);	g.addEdge(11,9);
    	g.addEdge(11,12);	g.addEdge(12,11);
    	g.addEdge(12,13);	g.addEdge(13,12);
    	g.addEdge(13,17);	g.addEdge(17,13);
    	g.addEdge(14,15);	g.addEdge(15,14);
    	g.addEdge(15,16);	g.addEdge(16,15);
    	g.addEdge(15,17);	g.addEdge(17,15);
    	g.addEdge(16,17);	g.addEdge(17,16);
    	g.addEdge(16,18);	g.addEdge(18,16);
	g.addEdge(17,18);	g.addEdge(18,17);
    	g.addEdge(17,19);	g.addEdge(19,17);
    	g.addEdge(18,19);	g.addEdge(19,18);
	g.addEdge(18,20);	g.addEdge(19,20);
	g.addEdge(20,18);	g.addEdge(20,19);
	g.tampilList();
	g.BFS(1);
	g.BFSWithDestination(1,10);

	return 0;
}
                        
