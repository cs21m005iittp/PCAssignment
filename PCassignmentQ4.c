/*
Write an MPI program to compute the sum of an array of elements. Assume that
the array cannot be stored on a single process i.e., you cannot have int array[N] in one
process, and then send the data to other processes. Initialize the array with its index values
i.e., array[i] = i. Distribute the array such that the amount of computation work across
processes is balanced. Your program should support block distribution, cyclic distribution,
and block cyclic distribution of the array. Read about distribution of data. Why do you think
various distribution schemes are required? Input: Number of elements in the array. Array
distribution = block, cyclic, block cyclic. Output: Array sum (Print only once).
*/

#include <mpi.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


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
    
    //below code uses block distribution
    /*
    Block distribution:
    The block distribution is often used when the computational load is distributed homogeneously over a regular data structure.((array elements are perfectly divisible by no of process))
    Decomposition based on output data.
    Each block of process use the same amount of computation.
    If the amount of work differs for different entries of a array(array elements not perfectly divisible by no of process), a block distribution can lead to load imbalances. 
    
        
        
    */
    
    {
    	clock_t start, end;
     double cpu_time_used;
    
    start = clock();
    
    int n=atoi(argv[1]);
    int elements=n/world_size;
    int remaining_elements=n%world_size;//these are elements which are not equally distributed hence creating imbalance
    
    //assign extra elements to last process to take care of
    if(world_rank==(world_size-1))
   	{
   		elements+=remaining_elements;
   	}
    int data[elements],i,j;
   	
    
	
           
           int start1=(n/world_size)*world_rank;
		  // int end1=(n/world_size)*(world_rank+1);
		   int local_sum;
		   
		   //initialzing array
		   
		   for( j=0;j<elements;j++)
	{
	data[j]=start1;
	start1++;
	}
	
	
		   
		   for( i=0;i<elements;i++)
		   {
				local_sum +=data[i];
		   }
   //printf("local_sum %d, rank %d out of %d processors ",local_sum, world_rank, world_size);
		   
		   int total_sum;
		   
		   		   
		   MPI_Reduce(&local_sum,&total_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		   
		   end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     
    // printf("Time:%f secs\n",cpu_time_used);

		   
		   if(world_rank==0)
		   {
				printf("total_sum computed in block distribution %d in Time:%f\n",total_sum,cpu_time_used);
		   }

    }
    
    //below code uses block cyclic distribution
    
    /*
    	Block_cyclic:
    A variation of block distribution that can be used to alleviate the load-imbalance. 
    steps:
    1.Partition an array into many more blocks than the number of available processes
    2.Assign blocks to processes in a round-robin manner so that each process gets several nonadjacent blocks.
    3.Here is issue can occur when data elements are not perfectly divided by block size (say block size=2 and process=4,data elements=9 so p0=0,1 p1=2,3 p2=4,5 p3=6,7 still 8th array element not distrbuted

    
    */
    
    {
    		clock_t start, end;
     double cpu_time_used;
    
    start = clock();
    
    int n=atoi(argv[1]);
    //setting block size
   
    int Block_size=2;
    int blocks=n/Block_size;
    int elements=(blocks/world_size)*Block_size;//elements in indivsual process can holds
    
    
    int data[elements],i,j;
	      
        
		  // int end1=(n/world_size)*(world_rank+1);
		   int local_sum=0;
		   
		   //initialzing array and distributing data according to block-cyclic distributions
	 int start1=(Block_size)*world_rank;
           
           //while(start1<n)
           {
           for(int i=0;i<elements;i=i+2)
           {
           	for(int j=0;j<Block_size;j++)
	{
		if(start1<n)
		data[i+j]=start1;
		start1++;
	}
	start1+=((world_size-1)*Block_size);
           }
           	
	
	
	
           }
           		   //till here distribution done
		   
		   for( i=0;i<elements;i++)
		   {
				local_sum +=data[i];
		   }
 //printf("local_sum %d, rank %d out of %d processors ",
  //         local_sum, world_rank, world_size);
		   
		   int total_sum;
		   
		   
		   
		   MPI_Reduce(&local_sum,&total_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		   
		   end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     
     //printf("Time:%f secs\n",cpu_time_used);
		   
		   if(world_rank==0)
		   {
				printf("total_sum computed in block-cyclic distribution %d in Time:%f\n",total_sum,cpu_time_used);
		   }
	
    	}	
 
    	
    	
    	//below code uses cyclic distribution
    	/*
    	Cyclic distribution: when the block size =1
    
    The cyclic distribution (also known as the wrapped or scattered decomposition) is commonly used to improve load balance when the computational load is distributed inhomogeneously over a regular data structure. The cyclic distribution assigns consecutive entries of the global vector to successive processes.

    	
    	*/
    	{
    		clock_t start, end;
     double cpu_time_used;
    
    start = clock();
    
    int n=atoi(argv[1]);
    int Block_size=1;//cyclic distribution
    int blocks=n/Block_size;
    int elements=(blocks/world_size)*Block_size;//elements in indivsual process can holds
    
    int remaining_elements=n%Block_size;//these are elements which are not equally distributed hence creating imbalance
    
    //assign extra elements to last process to take care of
    if(world_rank==(world_size-1))
   	{
   		elements+=remaining_elements;
   	}
    int data[elements],i,j;
   // int data[elements],i,j;
	      
  int local_sum=0;
		   
		   //initialzing array and distributing data according to block-cyclic distributions
	 int start1=(Block_size)*world_rank;
           
           //while(start1<n)
           
           for(int i=0;i<elements;i=i+1)
           {
           	//for(int j=0;j<Block_size;j++)
	{
		if(start1<n)
		data[i]=start1;
		
	}
	start1+=((world_size-1)*Block_size)+1;
	//start1++;
           }
           	
	
	 		   
		   for( i=0;i<elements;i++)
		   {
				local_sum +=data[i];
		   }
 //printf("local_sum %d, rank %d out of %d processors ",
//           local_sum, world_rank, world_size);
		   
		   int total_sum;
		   
		  
		   
		   MPI_Reduce(&local_sum,&total_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		    end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     
     //printf("Time:%f secs\n",cpu_time_used);
		   
		   if(world_rank==0)
		   {
				printf("total_sum computed in cyclic distribution %d in Time:%f\n",total_sum,cpu_time_used);
		   }
	
    	}	
    	
    	
	 	   
    // Finalize the MPI environment.
    MPI_Finalize();
}