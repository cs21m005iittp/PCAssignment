/*
Implement iittp barrier() in MPI. Do not use MPI Barrier().
*/

#include <mpi.h>
#include <stdio.h>
#include <time.h>


void iittp_barrier(int data[],int world_size,int world_rank)
{
	   if(world_size>1)
    {
    
    	 int i,j;
	//implementing barrier as until each process didnt receive data array updated by all process
           
         // setting data 
         
         data[world_rank]=world_rank;
         
         /*
				
				MPI_Send(void* data,int count,MPI_Datatype datatype,int destination,int tag,MPI_Comm communicator)
				
				*/
				
				for(i=0;i<world_size;i++)
				{
					if(i!=world_rank)
				   		MPI_Send(data,world_size,MPI_INT,i,0,MPI_COMM_WORLD);
				}
				
				
				
				/*
				
				MPI_Recv(void* data,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm communicator,MPI_Status* status)
				
				*/
				
				for(i=0;i<world_size;i++)
				{
					if(i!=world_rank)
				   		MPI_Recv(data,world_size,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				}
				
				

    }

}
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
    
    clock_t start, end;
     double cpu_time_used;
    int data[world_size],i,j;
    start = clock();
    //(void* data,int world_size,int world_rank,MPI_Comm MPI_COMM_WORLD)
    iittp_barrier(data,world_size, world_rank);//iittp_barrier(data value,world_size, world_rank);
         
		   
		   end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("rank %d out of %d processors come out of barrier in ",
           world_rank, world_size);
     printf("Time:%f secs\n",cpu_time_used);
		   
		  
    // Finalize the MPI environment.
    MPI_Finalize();
}