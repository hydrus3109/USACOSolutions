#include <fstream>
#include <algorithm>

#define MAX 2000

using namespace std;

int n,c,x[MAX],y[MAX],dist[MAX];

int main()
{
	ifstream fin("irrigation.in");
	fin >> n >> c;
	for (int i=0; i<n; i++) fin >> x[i] >> y[i];
	fin.close();

	int k=0,l=0;			// start from vertex 0
					// initial length of MST is 0
	fill(dist,dist+n,1000000000);

	for (int i=0; i<n-1; i++)
	{
		dist[k]=-1;		// mark used vertices

		// explore vertices and update edges in the queue
		for (int j=0; j<n; j++)
		{
			int d=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
						// if (x,j) edge is long enough
			if (d>=c && d<dist[j]) dist[j]=d;
		}

		// choose the unused edge with minimum length in the queue
		k=-1;
		for (int j=0; j<n; j++)
			if (dist[j]!=-1 && dist[j]!=1000000000)
				if (k==-1 || dist[k]>dist[j]) k=j;

		if (k==-1) break;	// if graph is not connected
		l+=dist[k];		// update total cost of mst
	}
	if (k==-1) l=-1;

	ofstream fout("irrigation.out");
	fout << l << endl;
	fout.close();
			

}
