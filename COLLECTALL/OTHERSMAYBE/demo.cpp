#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> sum;
	for (int i = 0; i <= 100; i++) {
		sum.push_back(i);
	}
	for (auto x : sum) cout << x << " ";
	cout << endl;
	return 0;
}