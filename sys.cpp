#include <iostream>
#include <cstdlib>
#include "unistd.h"

using namespace std;

int main() {
	system("cat /proc/meminfo | awk 'NR == 1{print $2}'\n");
    system("cat /proc/meminfo | awk 'NR == 2{print $2}'\n");
    system("cat /proc/meminfo | awk '{ if(NR==1) a=$2; if(NR==2) b=$2; }END {print a-b}'\n");
}
