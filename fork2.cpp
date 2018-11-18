#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main() {
	int div, prod, init1=25, init2=5;
	pid_t pid, child_pid, parent_pid;
	pid = fork();
	
	if(pid<0) {
		
		cout<<"\n Error!!";
		
	} else if(pid == 0) {
		
		cout<<"\n Child Process";
		child_pid = getpid();
		cout<<"\n Child process's PID: "<<child_pid;
		cout<<"\n Performing Division....";
		div = init1/init2;
		cout<<"\n The result is: "<<div;
		
	} else {
		
		wait(NULL);
		cout<<"\n Parent Process";
		parent_pid = getpid();
		cout<<"\n Parent Process's PID: "<<parent_pid;
		cout<<"\n Performing Multiplication.....";
		prod = init1*init2;
		cout<<"\n The result is:"<<prod;
		
	}
}
