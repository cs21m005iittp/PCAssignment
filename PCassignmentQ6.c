/*
Each process has an array of N elements. Start at Rank 0. Generate a random
number. Compute X = (random number) % (number of processes)). Send the array of data
from Rank 0 to Rank X. At Rank X, generate a random number and compute new X using
the same formula. Send data from Rank X to Rank new X. Continue this process for m
iterations. If you think such a program cannot be written, explain the reasoning behind it as
comments in the code file. Input: Number of elements in the array. Iteration count, m.
Output: Array elements of all processes.


*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    // Initialize the MPI environment
    
    
    MPI_Init(&argc, &argv);
//printf("%d,%c",argc,** argv);


    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    
    int n=atoi(argv[1]);//no of elements to array
     int m=atoi(argv[2]);//iteration count 
    
   int X = rand()% (world_size);
   // as above we are generating a random no(rank of process where need to send data) which means we are sendng data to any random process 
    int data[n],i,j;
	for( j=0;j<n;j++)//initializing array
	{
	data[j]=world_rank;//setting values 
	}

          /*
          To start with rank 0 will send to x
          */  
          
          if(world_rank==0)
          {
          //MPI_Send(void* data,int count,MPI_Datatype datatype,int destination,int tag,MPI_Comm communicator)
          
          MPI_Send(data,n,MPI_INT,X,0,MPI_COMM_WORLD);
          
          } 
          else
          {
          	//starting m iterations of data send
          	
          	MPI_Recv(data,n,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);////except process X other process block here,next iteration process X itself block
          
          for(int i=0;i<m-1;i++)
          {
          	/*
          Here same data sent by rank 0 need to received by rank X process 
          all other process (except rank 0) will wait at receive call because data sent by rank 0 to which (random)process it is not known so all other process
          will wait,it means except the actual process X to which rank 0 randomly selected for sending data will receive in MPI receive call and other process (except rank 0,X)
          will blocked on MPI_Receive,when process X receive data from rank 0 it will again randomly select process to send data and it will go for next iteration where it will block itself
          for waiting data from 0
          */
        
          int X_new = rand()% (world_size);
           MPI_Send(data,n,MPI_INT,X_new,0,MPI_COMM_WORLD);
          /*
          but there way of sending messages is possible in MPI and called non-blocking communications.

           Non-blocking communications always require to be initialised and completed. What that means is that now, we will call a send and a receive commands to initialise  the communication.        Then,instead of waiting to complete the send (or the receive), the process will continue working.
           but here is consistancy issue arise data initialy sent by rank 0 will not be forwarded as process without waiting for actual data they send data of their own, hence whole purpose
           of program defeated.
         
          */
          }
          }  
          
          
          

    // Finalize the MPI environment.
    MPI_Finalize();
}