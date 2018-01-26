#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define M 46

int prime[M] = {2,3,5,7,11,13,17,19,23,29,
				31,37,41,43,47,53,59,61,67,71,
				73,79,83,89,97,101,103,107,109,113,
				127,131,137,139,149,151,157,163,167,173,
				179,181,191,193,197,199};

bool bpm (vector<vector<int>> &bpGraph, bool seen[], int matchR[], int N, int u)
{
	for (int i = 0; i < N; i++)
	{
		if (bpGraph[u][i] && !seen[i])
		{
			seen[i] = true;
			if (matchR[i] < 0 || bpm(bpGraph,seen,matchR,N,matchR[i]))
			{
				matchR[i] = u;
				return true;
			}
		}
	}
	return false;
}

int maxBPG (vector<vector<int>> &bpGraph)
{
	int N = bpGraph[0].size();
	int matchR[N];
	memset(matchR,-1,sizeof(matchR));
	int result = 0;
	for (int i = 0; i < M; i++)
	{
		bool seen[N] = {0};
		if (bpm(bpGraph,seen,matchR,N,i))
			result++;
	}
	return result;
}

int main ()
{
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<vector<int>> bpGraph;
	bpGraph.resize(M);
	for (int i = 0; i < M; i++)
		bpGraph[i].resize(N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (prime[i] <= arr[j] && arr[j] % prime[i] == 0)
				bpGraph[i][j] = 1;
			else
				bpGraph[i][j] = 0;
		}
	}

	cout << maxBPG(bpGraph) << endl;
	return 0;
}
