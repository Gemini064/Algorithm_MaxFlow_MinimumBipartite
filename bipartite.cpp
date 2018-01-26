#include <iostream>
#include <string.h>
using namespace std;
 
#define M 46
#define N 5

int prime[46] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,
               103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
 
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++)
	{
		if (bpGraph[u][v] && !seen[v])
		{
            		seen[v] = true;
            		if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            		{
            			matchR[v] = u;
            			return true;
            		}
		}
	}
	return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
	int matchR[N];
	
	memset(matchR, -1, sizeof(matchR));
 
	int result = 0;
	for (int u = 0; u < M; u++)
	{
	bool seen[N];
	memset(seen, 0, sizeof(seen));
 
	if (bpm(bpGraph, u, seen, matchR))
            	result++;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	bool bpGraph[M][N];
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
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

	/*for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << bpGraph[i][j] << " ";
		cout << endl;
	}*/
	
	cout << maxBPM(bpGraph) << endl;
 
	return 0;
}