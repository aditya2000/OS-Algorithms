#include <iostream>
using namespace std;

void find_waiting_time(int, int[], int);

int main() {
    
    int no_of_processes;
    cout<<"\n Enter the total number of processes:";
    cin>>no_of_processes;
    
    int burst_time[no_of_processes];
    cout<<"\n Enter the burst time for each process:";
    for(int i=0; i<no_of_processes; i++) {
        cin>>burst_time[i];
    }
    
    int time_quantum;
    cout<<"Enter the time quantum:";
    cin>>time_quantum;

    find_waiting_time(no_of_processes, burst_time, time_quantum);
    
}


void find_waiting_time(int no_of_processes, int burst_time[], int time_quantum) {
    int remaining_time[no_of_processes];
    for(int i=0; i<no_of_processes; i++) {
		remaining_time[i] = burst_time[i];
	}
	
	int curr_time = 0;
	int waiting_time[no_of_processes];
	while(1) {
		int done = true;
		
		for(int i=0; i<no_of_processes; i++) {
			if(remaining_time[i] > 0) {
				done = false;
				if(remaining_time[i] > time_quantum) {
					curr_time += time_quantum;
					remaining_time[i] -= time_quantum;
				} else {
					curr_time += remaining_time[i];
					waiting_time[i] = curr_time - burst_time[i];
					remaining_time[i] = 0;
				}
			}
		}
		
		if(done == true) {
			break;
		}
	}
	
	cout<<"\n Waiting time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<waiting_time[i]<<" ";
	}
	
	int turnaround_time[no_of_processes];
	for(int i=0; i<no_of_processes; i++) {
		turnaround_time[i] = burst_time[i] + waiting_time[i];
	}
	
	cout<<"\n Turnaround time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<turnaround_time[i]<<" ";
	}
}
