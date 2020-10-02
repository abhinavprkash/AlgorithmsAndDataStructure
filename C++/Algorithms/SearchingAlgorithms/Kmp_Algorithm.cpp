
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int lps[M];
	computeLPSArray(pat, M, lps);

	int i = 0;
	int j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;

	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	char txt[n] ;
	char pat[m] ;
	for (int i = 0; i < n; ++i)
	{
		cin>>txt[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>pat[i];
	}
	KMPSearch(pat, txt);
	return 0;
}