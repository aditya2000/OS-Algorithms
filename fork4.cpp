#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {
	pid_t pid;
	pid = fork();
	
	if(pid < 0) {
		cout<<"An Error has occurred";
	} else if (pid == 0) {
		cout<<"Child Process PID:"<<pid;
	} else {
		cout<<" Main process PID:"<<pid;
	}
}
