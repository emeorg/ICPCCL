#include <bits/stdc++.h>
using namespace std;

int main(){
	int X; cin >> X;

	int count_500 = (X - (X % 500)) / 500;
	int surplus = X - (500 * count_500);
	int count_5 = (surplus - (surplus % 5)) / 5;

	int happiness = (count_500 * 1000) + (count_5 * 5);

	cout << happiness;

	return 0;
}