#include <iostream>
#include "Array.h"

using namespace std;

int main() {
	Array<int> p(3);
	p += 10;
	p += 20;
	p += 30;
	cout << p.Find(30) << endl;
	Array<int> d(6);

	d += 400;
	d += 300;
	d += 200;
	d += 100;
	d.Sort();
	cout << d.Find(400);
	return 0;
}
