// MS C++

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	long long int usbnum, psnum, bothnum;
	scanf_s("%I64d %I64d %I64d", &usbnum, &psnum, &bothnum);
	long long int mouse_num;
	scanf_s("%I64d", &mouse_num);
	vector<long long int> usbmouse;
	vector<long long int> psmouse;
	long long int temp_val;
	char tmp[4];
	string a;
	for (long long int i = 1; i <= mouse_num; i++) {
		cin >> temp_val >> a;
		if (a == "USB") {
			usbmouse.push_back(temp_val);
		}
		else {
			psmouse.push_back(temp_val);
		}
	}
	sort(usbmouse.begin(), usbmouse.begin() + usbmouse.size());
	sort(psmouse.begin(), psmouse.begin() + psmouse.size());
	long long int result = 0, usbcounter = 0, pscounter = 0, counter = 0;
	for (long long int i = 1; i <= (int)usbmouse.size() && i <= usbnum; i++) {
		result += usbmouse[i - 1];
		usbcounter += 1;
		counter++;
	}
	for (long long int j = 1; j <= (int)psmouse.size() && j <= psnum; j++) {
		result += psmouse[j - 1];
		pscounter += 1;
		counter++;
	}
	long long int bcounter = 0;
	while (bcounter < bothnum && pscounter <= (int)psmouse.size() && usbcounter <= (int)usbmouse.size()) {
		if (pscounter >= (int)psmouse.size() && usbcounter >= (int)usbmouse.size())break;
		if (usbcounter <= (int)usbmouse.size() - 1 && pscounter <= (int)psmouse.size() - 1) {
			if (usbmouse[usbcounter] < psmouse[pscounter]) {
				result += usbmouse[usbcounter];
				usbcounter++;
				bcounter++;
			}
			else {
				result += psmouse[pscounter];
				pscounter++;
				bcounter++;
			}
		}
		else {
			if (usbcounter < (int)usbmouse.size()) {
				result += usbmouse[usbcounter];
				usbcounter++;
				bcounter++;
			}
			else {
				result += psmouse[pscounter];
				pscounter++;
				bcounter++;
			}
		}
	}
	printf("%I64d %I64d", counter + bcounter, result);
}
