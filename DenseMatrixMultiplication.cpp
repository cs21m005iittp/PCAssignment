
#include <math.h>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


int printRandoms(int lower, int upper)
{
    int i;
    {

        {
             int num = (rand() %
           (upper - lower + 1)) + lower;

           {
                return(num);
           }

           }

        }
        }
int printRandomsno(int lower, int upper)
{
    int i;
    {
        while(1)
        {
             int num = (rand() %
           (upper - lower + 1)) + lower;
           if(num!=0)
           {
                return(num);
           }
           else{
            continue;
           }
           }

        }
        }


int main(void) {
	// your code goes here
	int m=1,n=1,p=1,TotalElementsinA=0,TotalElementsinB=0;
	float spA=0.0f,spB=0.0f;
	printf("Enter Matrix  m order\n");
	scanf("\n%d",&m);
	printf("Enter Matrix  n order\n");
	scanf("\n%d",&n);
	printf("Enter Matrix  p order\n");
	scanf("\n%d",&p);
	printf("Enter Matrix A data sparcity percentage(0-100)\n");
	scanf("\n%f",&spA);
	printf("Enter Matrix B data sparcity percentage(0-100)\n");
	scanf("\n%f",&spB);
	spA=spA/100;
	spB=spB/100;
	TotalElementsinA=ceil(m*n*spA);
	printf("\n%d\n",TotalElementsinA);
	TotalElementsinB=ceil(n*p*spB);
	printf("\n%d\n",TotalElementsinB);
	int arrA[m][n];
	int i=0,j=0;
	for( i=0;i<m;i++){
 for( j=0;j<n;j++){
        arrA[i][j]=0;
   printf("\narrA[%d] [%d] = %d \n",i,j,arrA[i][j]);
 }//end of j
}//end of i

while(TotalElementsinA>0)
{
    int x=printRandoms(0,m-1);
    int y=printRandoms(0,n-1);

    int randomNo=printRandomsno(-100,100);
    printf("\nrowno:%d columnno:%d randomNo:%d",x,y,randomNo);
    if(arrA[x][y]==0)
    {

          arrA[x][y]=  randomNo;
          TotalElementsinA--;
    }
    else{
        continue;
    }
    }


for( i=0;i<m;i++){
 for( j=0;j<n;j++){

   printf("\narrA[%d] [%d] = %d \n",i,j,arrA[i][j]);
 }//end of j
}//end of i



//printing random array B elements
int arrB[n][p];

	for( i=0;i<n;i++){
 for( j=0;j<p;j++){
        arrB[i][j]=0;
   printf("\narrB[%d] [%d] = %d \n",i,j,arrB[i][j]);
 }//end of j
}//end of i

while(TotalElementsinB>0)
{
    int x=printRandoms(0,n-1);
    int y=printRandoms(0,p-1);

    int randomNo=printRandomsno(-100,100);
    printf("\nrowno:%d columnno:%d randomNo:%d",x,y,randomNo);
    if(arrB[x][y]==0)
    {

          arrB[x][y]= randomNo;
          TotalElementsinB--;
    }
    else{
        continue;
    }
    }


for( i=0;i<n;i++){
 for( j=0;j<p;j++){

   printf("\narrB[%d] [%d] = %d \n",i,j,arrB[i][j]);
 }//end of j
}//end of i

struct timespec start, end;

    // start timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC, &start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


//multiply arrA and arrB
int Result[m][p];
int k=0;
printf("multiply of the matrix=\n");
for(i=0;i<m;i++)
{
for(j=0;j<p;j++)
{
Result[i][j]=0;

for(k=0;k<n;k++)
{
Result[i][j]+=arrA[i][k]*arrB[k][j];
}
}
}

 // stop timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    // clock_gettime(CLOCK_REALTIME, &end);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculating total time taken by the program.
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;


  for( i=0;i<m;i++){
 for( j=0;j<p;j++){

   printf("\nResult[%d] [%d] = %d \n",i,j,Result[i][j]);
 }//end of j
}//end of i

 cout << "Time taken by matrix multiplication is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
	return 0;
}



