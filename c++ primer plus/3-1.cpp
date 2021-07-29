#include <iostream>
using namespace std;
int main() {
	const int yingchi_to_yingcun = 12;
	const double yingcun_to_m = 0.0254;
	const double kg_to_bang = 2.2;
	double yingchi, yingcun,pang;
	cout << "input how much yingchi and how much yingcun(ÓÃ¶ººÅ¸ô¿ª£©\n";
	cin >> yingchi;
	cin >> yingcun;
	cout << "input how much pang\n";
	cin >> pang;
	yingcun += yingchi_to_yingcun * yingchi;
	yingcun *= yingcun_to_m;
	pang /= kg_to_bang;
	cout << "BMI is " << (pang / yingcun) * (pang / yingcun) <<endl;
	return 0;
}
