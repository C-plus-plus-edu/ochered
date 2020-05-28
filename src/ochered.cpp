#include <iostream>
#include <vector>
#include <string>
using namespace std;

void read_command(vector<string>& oname, vector<int>& onum) {
	int q;
	string name;
	int num;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		name = "";
		num = 0;
		cin >> name;
		if (name != "WORRY_COUNT")
			cin >> num;
		oname.push_back(name);
		onum.push_back(num);
	}
}

void come(vector<bool>& o, int num) {
	if (num > 0) {
		for (int i = 0; i < num; ++i) {
			o.push_back(false);
		}
	} else if (num < 0) {
		vector<bool> temp;
		for (auto x : o) {
			temp.push_back(x);
		}
		o.clear();
		for (size_t i = 0; i < (temp.size() + num); ++i) {
			o.push_back(temp[i]);
		}
	}
}

void print_o(vector<bool>& o) {
	int i = 0;
	for (auto x : o) {
		if (x == true) {
			i++;
		}
	}
	cout << i << endl;
}

int main() {
	vector<string> oname;
	vector<int> onum;
	read_command(oname, onum);
	vector<bool> o;
	for (size_t i = 0; i < oname.size(); ++i) {
		if (oname[i] == "COME")
			come(o, onum[i]);
		if (oname[i] == "WORRY") {
			int t = onum[i];
			o[t] = true;
		}
		if (oname[i] == "QUIET") {
			int t = onum[i];
			o[t] = false;
		}
		if (oname[i] == "WORRY_COUNT")
			print_o(o);
 	}
	return 0;
}
