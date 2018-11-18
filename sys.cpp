#include <iostream>
#include <cstdlib>
#include "unistd.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	system("cat /proc/meminfo | head -5 | cat > file2.txt");
    system("cat /proc/meminfo | grep -m 2 MHz | cat >> file2.txt");
    system("cat /proc/meminfo | grep -m 2 MHz | cat >> file2.txt");

    ifstream obj("file2.txt");

    if(!obj) {
    	cout<<"Error opening file!!";
    } else {
    	string result;

    	getline(obj, result);
    	cout<<result<<"\n";
    }

    obj.close();
}
