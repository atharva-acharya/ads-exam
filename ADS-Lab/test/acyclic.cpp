#include <bits/stdc++.h>
using namespace std;

int totalNodes(vector<int> adjac[], int n, int x, int y)
{
	bool visited[n+1] = {0};
	int p[n] ;
	queue<int> q;
	q.push(x);
	visited[x] = true;
	int m;
	while (!q.empty())
	{
		m = q.front() ;
		q.pop();
		for (int i=0; i<adjac[m].size(); ++i)
		{
			int h = adjac[m][i];
			if (!visited[h])
			{
				visited[h] = true;

				p[h] = m ;
				q.push(h);
			}
		}
	}
	int count = 0;
	int i = p[y];
	while (i != x)
	{
		count++;
		i = p[i];
	}
	return count ;
}

int main()
{
	vector < int > adjac[7];

	adjac[1].push_back(4);
	adjac[4].push_back(1);
	adjac[5].push_back(4);
	adjac[4].push_back(5);
	adjac[4].push_back(2);
	adjac[2].push_back(4);
	adjac[2].push_back(6);
	adjac[6].push_back(2);
	adjac[6].push_back(3);
	adjac[3].push_back(6);

	cout << totalNodes(adjac, 7, 1, 3);

	return 0;
}
