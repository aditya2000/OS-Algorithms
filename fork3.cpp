#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
	int sum, diff, init1 = 10, init2 = 2;
	pid_t pid, parent_pid, child_pid;
	
	pid = fork();
	
	if(pid < 0) {
		
		cout<<"\n Error!!";
		
	} else if(pid == 0) {
		
		cout<<"\n Child Process ";
		child_pid = getpid();
		cout<<"\n Child Process's PID: "<<child_pid;
		cout<<"\n Performing Subraction...";
		diff = init1 - init2;
		cout<<"\n The result is: "<<diff;
		
	} else {
		
		wait(NULL);
		cout<<"\n Parent Process ";
		parent_pid = getpid();
		cout<<"\n Parent Process's PID: "<<parent_pid;
		cout<<"\n Performing addition...";
		sum = init1 + init2;
		cout<<"\n The result is: "<<sum;
		
	}
}
