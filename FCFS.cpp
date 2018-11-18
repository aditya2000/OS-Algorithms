#include <iostream>
using namespace std; 

int main() {
    // Input the number of processes
    int no_of_processes;
    cout<<"\n Enter the number of processes:";
    cin>>no_of_processes;
    
    // Input the Arrival Time of each process
    int arrival_time[no_of_processes];
    cout<<"\n Enter the Arrival Time of each process:";
    for(int i=0; i<no_of_processes; i++) {
        cin>>arrival_time[i];
    }
    
    // Input the Burst Time of each process
    int burst_time[no_of_processes];
    cout<<"\n Enter the Burst Time of each process:";
    for(int i=0; i<no_of_processes; i++) {
        cin>>burst_time[i];
    }
    
    // Calculating the Completion Time of each process
    int completion_time[no_of_processes];
    for(int i=0; i<no_of_processes; i++) {
        if(i == 0) {
            completion_time[i] = burst_time[i];
        } else {
            completion_time[i] = burst_time[i] + completion_time[i-1];
        }
    }
    
    // Displaying the Completion Time of each process
    cout<<"\n The completion time of each process:";
    for(int i=0; i<no_of_processes; i++) {
        cout<<completion_time[i]<<" ";
    }
    
    // Calculating the Turnaround Time of each process
    int turnaround_time[no_of_processes];
    for(int i=0; i<no_of_processes; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
    }
    
    // Displaying the Turnaround Time of each process
    cout<<"\n The turnaround time of each process:";
    for(int i=0; i<no_of_processes; i++) {
        cout<<turnaround_time[i]<<" ";
    }
    
    // Calculating the Waiting Time of each process
    int waiting_time[no_of_processes];
    int service_time[no_of_processes];
    service_time[0] = 0;
    waiting_time[0] = 0;
    for(int i=1; i<no_of_processes; i++) {
        service_time[i] = service_time[i-1] + burst_time[i-1];
        
        waiting_time[i] = service_time[i] - arrival_time[i];
        
        if (waiting_time[i] < 0) {
			waiting_time[i] = 0;
		}
    }
    
    // Displaying the Waiting Time of each process
    cout<<"\n The Waiting time of each process:";
    for(int i=0; i<no_of_processes; i++) {
        cout<<waiting_time[i]<<" ";
    }
}
