#include <bits/stdc++.h>
using namespace std;

int main(){
	int T; cin >> T;

	for (int i = 0; i < T; ++i){
		int w, h; cin >> w >> h;
		
		if(w == h){ cout << "Square" << endl; }
		else{ cout << "Rectangle" << endl; }
	}

	return 0;
}