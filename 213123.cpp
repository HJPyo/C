#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string b;
	int n;
	int q;
	int w;
	int e;
	int i;
	vector<int> pibo;
	b = "Messi Gimossi";

	q = 5;
	w = 13;
	pibo.push_back(5);
	pibo.push_back(13);

	while (w < 1073741824) {
		e = w;
		w = w + q+1;
		q = e;
		pibo.push_back(w);
	}

	cin >> n;
	i = 0;
	while (pibo[i] < n)
		i++;
	while ( i >= 2) {
		if (n == pibo[i - 1] + 1) {
			n = -1;
			break;
		}
		if (n > pibo[i - 1]) {
			i -= 2;
			n -= pibo[i + 1]+1;
		}
		else
			i -= 1;
	}

	if (n == -1 || n == 6) {
		cout << "Messi Messi Gimossi";
	}
	else {
		cout << b.at(n - 1);
	}

	return 0;
}
