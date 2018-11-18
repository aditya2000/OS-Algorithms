#include <iostream>
using namespace std;


int main() {
    int no_of_processes;
    cout<<"\n Enter the number of processes:";
    cin>>no_of_processes;
    
    int burst_time[no_of_processes];
    cout<<"\n Enter the burst time for each process: ";
    for(int i=0; i<no_of_processes; i++) {
        cin>>burst_time[i];
    }
    
    for(int i=0; i<no_of_processes; i++) {
        for(int j=i+1; j<no_of_processes; j++) {
            int temp = 0;
            if(burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }
    
    cout<<"\n The order of execution: ";
    for(int i=0; i<no_of_processes; i++) {
        cout<<burst_time[i]<<" ";    
    }
    
    int waiting_time[no_of_processes];
    waiting_time[0] = 0;
    for(int i=1; i<no_of_processes; i++) {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
    
    cout<<"\n The Waiting Time for each process: ";
    for(int i=0; i<no_of_processes; i++) {
        cout<<waiting_time[i]<<" ";
    }
    
    int turnaround_time[no_of_processes];
    for(int i=0; i<no_of_processes; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    cout<<"\n The Turnaround Time for each process: ";
    for(int i=0; i<no_of_processes; i++) {
        cout<<turnaround_time[i]<<" ";
    }
}
