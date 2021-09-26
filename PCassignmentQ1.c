/*
Write an MPI program to compute the sum of an array of elements. Computation
load should be balanced across processes. Input: Number of elements in the array. Output:
Array sum (Print only once).

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
    int remaining_elements=n%world_size;//these are elements which are not equally distributed hence creating imbalance
    int end;
    int data[n],i,j;
	for( j=0;j<n;j++)
	{
	data[j]=j;
	}

    // Print off a hello world message
  //  printf("Hello world from processor %s, rank %d out of %d processors\n",
  //         processor_name, world_rank, world_size);
           
        //   printf("%d\n ",n);
           
           int start=(n/world_size)*world_rank;
           
           //assign extra elements to last process to take care of
    if(world_rank==(world_size-1))
   	{
   		  end=(n/world_size)*(world_rank+1);
   		end+=remaining_elements;
   	}
    else{
     end=(n/world_size)*(world_rank+1);
    }
           
		   
		   int local_sum;
		   for( i=start;i<end;i++)
		   {
				local_sum +=data[i];
		   }
 printf("local_sum %d, rank %d out of %d processors\n",
           local_sum, world_rank, world_size);
		   
		   int total_sum;
		   
		   MPI_Reduce(&local_sum,&total_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		   
		   if(world_rank==0)
		   {
				printf("total_sum %d\n",total_sum);
		   }
    // Finalize the MPI environment.
    MPI_Finalize();
}