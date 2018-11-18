#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "unistd.h"

using namespace std;

int main() {
	system("cat /proc/cpuinfo |cat > file.txt");
	//system("cat /proc/cpuinfo | grep -m 2 MHz | cat >> file.txt");
	
	ifstream obj("file.txt");
	
	if(!obj) {
		cout<<"Error opening file!!";
	} else {
		string result;
		
		while (obj) {
			getline(obj, result);
			if(obj) {
				cout<<result<<'\n';
			}
		}
		obj.close();
	}
}
