/*
Write an MPI program to exchange an array of elements. Each process has an
array of N elements. Rank 0 sends data to Rank 1, Rank 1 to Rank 2, ..., Rank n-1 to Rank
n, and Rank n to Rank 0. Input: Number of elements in the array. Output: Array elements
of all processes.
*/
#include <mpi.h>
#include <stdio.h>

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
    
    int n=atoi(argv[1]);
    
    int data[n],i,j;
	for( j=0;j<n;j++)//initializing data array at each process
	{
	data[j]=j;
	}
   

    
   
	

          if(world_rank==world_size-1)//last rank send to 0th rank
		  {
				data[0]=world_rank;//set 0th index of data to its rank
				MPI_Send(data,world_size,MPI_INT,0,0,MPI_COMM_WORLD);
				MPI_Recv(data,world_size,MPI_INT,world_rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
   
		  }
		  else{
				data[world_rank+1]=world_rank;//each process other than last set data value as its rank for index(which is next rank process)
				MPI_Send(data,world_size,MPI_INT,world_rank+1,0,MPI_COMM_WORLD);
				if(world_rank==0)//0th process will receive from last
				{
					MPI_Recv(data,world_size,MPI_INT,world_size-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				}
				else{
					MPI_Recv(data,world_size,MPI_INT,world_rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				}
				
		  }
		  
		 
		  {
		 // printf(" \ndata received:\n");
		  
		  printf("data received at rank %d out of %d processors\n", world_rank, world_size);
  
			for(i=0;i<world_size;i++)
			{
				printf(" %d ",data[i]);
			}
			  printf("\n");
		  }
		   
		      // Finalize the MPI environment.
    MPI_Finalize();
}