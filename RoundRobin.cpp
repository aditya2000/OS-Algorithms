#include <iostream>
using namespace std;

void find_waiting_time(int, int[], int);

int main() {
    
    // Taking input the number of processes
    int no_of_processes;
    cout<<"\n Enter the total number of processes:";
    cin>>no_of_processes;
    
    // Taking input the Burst time of each process
    int burst_time[no_of_processes];
    cout<<"\n Enter the burst time for each process:";
    for(int i=0; i<no_of_processes; i++) {
        cin>>burst_time[i];
    }
    
    // Taking input the time quantum
    int time_quantum;
    cout<<"Enter the time quantum:";
    cin>>time_quantum;

    find_waiting_time(no_of_processes, burst_time, time_quantum);
    
}


// Function to find the waiting time for each process
void find_waiting_time(int no_of_processes, int burst_time[], int time_quantum) {
	// this array will keep track of changes in each process's burst time after it is executed for a fixed time quantum
    int remaining_time[no_of_processes];

    // assigining burst time to the temporary array
    for(int i=0; i<no_of_processes; i++) {
		remaining_time[i] = burst_time[i];
	}
	
	//keep track of the time taken for execution of each process
	int curr_time = 0;
	// array to store waiting time for each process
	int waiting_time[no_of_processes];

	while(1) {
		int done = true; // will check if the process is done or not
		
		for(int i=0; i<no_of_processes; i++) {
			// will execute if waiting time is larger then 0
			if(remaining_time[i] > 0) {

				done = false; // which means process is not done
				// if remaining time is greater than the time quantum then reduce the remaining burst time and increase the time counter(curr_time)
				if(remaining_time[i] > time_quantum) { 
					curr_time += time_quantum;
					remaining_time[i] -= time_quantum;
				} else { // else calculate the waiting time
					curr_time += remaining_time[i];
					waiting_time[i] = curr_time - burst_time[i];
					remaining_time[i] = 0;
				}
			}
		}
		// break when process is done
		if(done == true) {
			break;
		}
	}
	
	// Displaying the waiting time
	cout<<"\n Waiting time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<waiting_time[i]<<" ";
	}
	
	// calculating the turnaround time
	int turnaround_time[no_of_processes];
	for(int i=0; i<no_of_processes; i++) {
		turnaround_time[i] = burst_time[i] + waiting_time[i];
	}
	
	// Displaying the turnaround time
	cout<<"\n Turnaround time for each process:";
	for(int i=0; i<no_of_processes; i++) {
		cout<<turnaround_time[i]<<" ";
	}
}
