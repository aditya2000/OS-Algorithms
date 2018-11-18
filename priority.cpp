#include <iostream>
using namespace std;

struct process {
	int priority;
	int burstTime;
};

int main() {
	
	int no_of_processes;
	cout<<"\n Enter the number of processes:";
	cin>>no_of_processes;
	
	process *process_arr =  new process[no_of_processes];
	cout<<"\n Enter the processes:";
	for(int i=0; i<no_of_processes; i++ ) {
		cout<<"\n Process "<<i; 
		cout<<"\n \t Priority:";
		cin>>process_arr[i].priority;
		cout<<"\n \t Burst Time:";
		cin>>process_arr[i].burstTime;
	}
	
	for(int i=0; i<no_of_processes; i++) {
		for(int j=i+1; j<no_of_processes; j++) {
			process temp;
			if(process_arr[i].priority < process_arr[j].priority) {
				temp = process_arr[i];
				process_arr[i] = process_arr[j];
				process_arr[j] = temp;
			} 
		}
	}
	
	cout<<"The order of execution:";
	for(int i=0; i<no_of_processes; i++ ){
		cout<<process_arr[i].burstTime<<" ";
	}
	
	int waiting_time[no_of_processes];
	waiting_time[0] = 0;
	for(int i=1; i<no_of_processes; i++) {
		waiting_time[i] = process_arr[i-1].burstTime + waiting_time[i-1];
	}
	
	int turnaround_time[no_of_processes];
	for(int i=0; i<no_of_processes; i++) {
		turnaround_time[i] = waiting_time[i] + process_arr[i].burstTime;
	}
	
	cout<<"\n Waiting Time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<waiting_time[i]<<" ";
	}
	
	cout<<"\n Turnaround Time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<turnaround_time[i]<<" ";
	}
 }
