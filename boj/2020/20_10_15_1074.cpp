#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N, C, r, c;
bool check = false;

void recur(int& firstr, int& firstc,int& secondr, int& secondc) {
	if (r >= firstr && r < secondr && c >= firstc && c < secondc) {
		if (firstr + 1 == secondr && firstc + 1 == secondc) {
		
			if (firstr == r && firstc == c) {
				cout << C  << endl;
			}
			return;
		}
		if (check) return;
		int newr = (firstr + secondr) / 2;
		int newc = (firstc + secondc) / 2;

		recur(firstr, firstc, newr, newc);
		recur(firstr, newc, newr, secondc);
		recur(newr, firstc, secondr, newc);
		recur(newr, newc, secondr, secondc);
		return;
	}
	C += (secondr - firstr)*(secondc - firstc);
}
int main() {
	cin >> N >> r >> c;

	int size = pow(2, N);
	int start = 0;

	recur( start,start , size , size );

}