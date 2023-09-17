#include <bits/stdc++.h>
using namespace std; 

int dp[3] = {0,0,0};


/*
int DP(const vector<int>& v, int  N){
	if( N == v.at(0) && N == v.at(1) && N == v.at(2) ){return 1;}

	if(N == 0){
		return 0;
	}else{
		if(	(N-v.at(0)) >= v.at(0) || (N-v.at(0)) >= v.at(1) || (N-v.at(0)) >= v.at(2) ){dp[0] += 1 + DP(v,(N-v.at(0)));}else{return 0;}
		if(	(N-v.at(1)) >= v.at(0) || (N-v.at(1)) >= v.at(1) || (N-v.at(1)) >= v.at(2) ){dp[1] += 1 + DP(v,(N-v.at(1)));}else{return 0;}
		if(	(N-v.at(2)) >= v.at(0) || (N-v.at(2)) >= v.at(1) || (N-v.at(2)) >= v.at(2) ){dp[2] += 1 + DP(v,(N-v.at(2)));}else{return 0;}
	}
	return max_element(dp,dp+3);
}
*/

int DP(const vector<int>& v, int N) {
    if (N == v[0] && N == v[1] && N == v[2]) { return 1; }

    if (N <= 0) {
        return 0;
    } else {
        int max_cuts = 0;
        if ((N - v[0]) >= v[0] || (N - v[0]) >= v[1] || (N - v[0]) >= v[2]) {
        	dp[0] = 1 + DP(v, N - v[0]);
        	max_cuts = max(max_cuts, dp[0]);
        }
        if ((N - v[1]) >= v[0] || (N - v[1]) >= v[1] || (N - v[1]) >= v[2]) {
        	dp[1] = 1 + DP(v, N - v[1]);
        	max_cuts = max(max_cuts, dp[1]);
        }
        if ((N - v[2]) >= v[0] || (N - v[2]) >= v[1] || (N - v[2]) >= v[2]) {
        	dp[2] = 1 + DP(v, N - v[2]);
        	max_cuts = max(max_cuts, dp[2]);
        }
        return max_cuts;
    }
}


int main()
{	
	// longitud de la cinta 
	int N; cin >> N; 
	/* 
		N = 5
	*/
	
	// longitud de cortes
	int a,b,c; cin >> a >> b >> c; 

	vector<int> dp = {a, b, c};	// INDICES   → 	 0  1  2  
								// VECTOR dp →	[a][b][c]

	/*
		a = 5
		b = 3
		c = 2
	*/

	int cont = DP(dp,N); cout << cont;


	/*
	
	  [][][][][]	→	 longitud 5


	  	|	PRIMERA RAMA (c)	|	SEGUNDA RAMA (b)	|	TERCERA RAMA (a)	|
	  	|	[][]	[][][]		|	[][][]	[][]		|	   [][][][][]		|	PRIMER CORTE
	  	|	 	      ↓			|			  ↓			|      CORTE = 1     	|


	*/

	return 0;
}