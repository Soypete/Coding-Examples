//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string in;
	vector<string> hi;
	vector<string> bi;
	vector <string> ti;
	bool tf = false;

	do{
		cin >> in;
		hi.push_back(in);

	} while (in != "#");

	for (int i = hi.size() ; i >= 0; i--){
		bi.push_back(hi[i]);
		cout << bi[i];
	}


	return(0); 
}
//
