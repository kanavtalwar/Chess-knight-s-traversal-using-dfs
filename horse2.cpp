#include<iostream>

#include<cstdlib>

#include <list>

using namespace std;

int previ[64];
		class Graph
		{
			int V;
			 
			list<int> *adj;
			 
			public:
				
			Graph(int V); 

			void addEdge(int v, int w); 

			void BFS(int s); 
		};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	list<int> queue;

	visited[s] = true;
	
	queue.push_back(s);
	
	list<int>::iterator i;

	while(!queue.empty())
	{
	        
		s = queue.front();
			
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				int t; 
				
				t=*i;
				
				visited[*i] = true;
				
				previ[t]=s;
	
				queue.push_back(*i);
			}
		}
	
	}
}
	void printboard(int board[8][8]) 
	{
		cout<<"    1";
		
		for (int i = 2; i < 9; i++) 
		{
			cout<<"    "<< i;
		}
		
		cout<<endl;
		cout<<"  ";
		for (int i = 0; i < 8; i++) 
		{
			cout<<" ----";
		}
		cout<<endl;

		for (int j = 0; j < 8; j++)
		{
			cout<<" "<<j+1 ;
		
			for (int i = 0; i < 8; i++)
			 {
				cout<<"| ";
				if (board[i][j] == 0) 
				{
					cout<<"   ";
				}
				else
				{
					cout<<"X"<<board[i][j]<<" ";
				}
			}
			cout<<"|";
			cout<<endl;
			cout<<"  ";
			for (int i = 0; i < 8; i++)
			{
				cout<<" ----";
			}
			cout<<endl;

		}

	}

int main()
{
int o = 1;
while(o==1)
{	
	Graph g(64);
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i-1>=0&&i-1<8&&j-2>=0&&j-2<8)
				g.addEdge((8*i+j),(8*i+j-10));
				
			if(i+1>=0&&i+1<8&&j-2>=0&&j-2<8)
				g.addEdge((8*i+j),(8*i+j+6));
			
			if(i+2>=0&&i+2<8&&j+1>=0&&j+1<8)
				g.addEdge((8*i+j),(8*i+j+17));
			
			if(i+2>=0&&i+2<8&&j-1>=0&&j-1<8)
				g.addEdge((8*i+j),(8*i+j+15));
			
			if(i-2>=0&&i-2<8&&j-1>=0&&j-1<8)
				g.addEdge((8*i+j),(8*i+j-17));
			
			if(i-2>=0&&i-2<8&&j+1>=0&&j+1<8)
				g.addEdge((8*i+j),(8*i+j-15));
			
			if(i+1>=0&&i+1<8&&j+2>=0&&j+2<8)
				g.addEdge((8*i+j),(8*i+j+10));
			
			if(i-1>=0&&i-1<8&&j+2>=0&&j+2<8)
				g.addEdge((8*i+j),(8*i+j-6));
		}
	}
	 
    int a,b,c,d; 
    cout<<"enter the x co-ordinate of the starting node"<<endl ;
    cin>>a;
    if(a > 8||a < 1)
    {
    	cout<<" Wrong input ";
    	return 0;
	}
    cout<<"enter the y co-ordinate of the starting node"<<endl;
	cin>>b;
	if( b > 8 || b < 1)
	{
		cout<<" Wrong input ";
		return 0;
	}
	cout<<"enter the x co-ordinate of the ending node"<<endl;
	cin>>c;
	if(c > 8 || c < 1)
	{
		cout<<" Wrong input ";
		return 0;
	}
	cout<<"enter the y co-ordinate of the ending node"<<endl;
	cin>>d;
	if( d > 8|| d < 1)
	{
		cout<<" wrong input";
		return 0;
	}
	if(a==c && b==d)
	{
		cout<<"Same position, number of moves is zero";
		return 0;
	}
	cout<<endl;
	int x=8*(a-1)+(b-1);
	int y=8*(c-1)+(d-1);
	g.BFS(x);
	
	int i=y;
	int moves=0;
	cout<<c<<","<<d<<endl;
	int board[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	board[i][j]=0;
	int k=-2;

	while(previ[i]!=x)
	{
		int b=previ[i]%8;
		int a=previ[i]/8;
		moves++;
		i=previ[i];
	}
	
	i=y;
	while(previ[i]!=x)
	{
		int b=previ[i]%8;
		int a=previ[i]/8;
		
		cout<<a+1<<","<<b+1<<endl;
		i=previ[i];
		k++;
		board[a][b]=moves-k;
	}
	board[a-1][b-1]=1;
	board[c-1][d-1]=moves+2;
	cout<<a<<","<<b<<endl;
	cout<<endl;
	cout<<"it takes "<<moves+1<<" moves to reach the end point"<<endl<<endl;
	printboard(board);
	cout<<endl;
	cout<<"Press '1' if you want to run the program again"<<endl;
	cin>>o;
}	
	return 0;	
}
