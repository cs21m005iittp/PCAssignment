#include <iostream>
#include <cmath>
#include <vector>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;

int printRandoms(int lower, int upper)//this method for finding random indexes for matrix
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
int printRandomsno(int lower, int upper)//this method for finding random values for matrix on indices given by above method it doesnt
                                        //generate zero which as good as not containing element
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



int main()
{
    int m=1,n=1,p=1,TotalElementsinA=0,TotalElementsinB=0;
	float spA=0.0f,spB=0.0f;

	//matrix A
	vector<int> A_Rows;
	vector<int> A_Columns;
	vector<int> A_Values;
	//Matrix B
	vector<int> B_Rows;
	vector<int> B_Columns;
	vector<int> B_Values;


	vector<int>::iterator Ait1;
    vector<int>::iterator Ait2;
    vector<int>::iterator Ait3;
    vector<int>::iterator Bit1;
    vector<int>::iterator Bit2;
    vector<int>::iterator Bit3;

	cout <<"Enter Matrix  m order\n";
	cin >>m ;
	cout <<"Enter Matrix  n order\n";
	cin >>n;
	cout <<"Enter Matrix  p order\n";
	cin >>p;
	cout <<"Enter Matrix A data sparcity percentage(0-100)\n";
	cin >>spA;
	cout <<"Enter Matrix B data sparcity percentage(0-100)\n";
	cin >>spB;
	spA=spA/100;
	spB=spB/100;
	TotalElementsinA=ceil(m*n*spA);
	cout <<"Total no of elements for sparse matrix A:"<< TotalElementsinA<< endl;
	TotalElementsinB=ceil(n*p*spB);
	cout<<"Total no of elements for sparse matrix B:" <<TotalElementsinB<< endl;
   //below code generate random elements of sparse matrix A with random rows and columns
   //which will be storing in a row vector,column vector,value vector
   //We need to make row vector of sparse Matrix A will be in sorted order and
   //column vector of sparse matrix B should be in sorted order for multiplication


   //1.Generate elements for sparse matrix A and store into row,column,value vector
   //2.As elements and position of elements are generated randomly, we need to check for duplicacy for position
   //3.For multipication we need row vector and column vector of matrix A & B sorted respectively.
    cout<<"Generating random rows,columns and values for Matrix A";
    while(TotalElementsinA>0)//random element generation,duplicacy check(means for same position element is generated?), maintaining vector elements of row(indices)  in sorted order for matrix A
    {
        //testing
        cout << endl;
 for (auto i = A_Rows.begin(); i != A_Rows.end(); ++i)
        cout << *i << " ";
 cout << endl;
for (auto i = A_Columns.begin(); i != A_Columns.end(); ++i)
        cout << *i << " ";
cout << endl;;
for (auto i = A_Values.begin(); i != A_Values.end(); ++i)
        cout << *i << " ";
        //testing
        int count=0,matchedRow=-1;
        bool duplicate=false,isElementPushed=false;
        int index=A_Rows.size();
         Ait1=A_Rows.end();
          Ait2=A_Columns.end();
           Ait3=A_Values.end();
        int x=printRandoms(0,m-1);
        int y=printRandoms(0,n-1);
        int randomNo=printRandomsno(-100,100);//random no are generated between -100 to 100
        cout<<"\nrowno:"<<x<<" columnno:"<<y<<" randomNo:"<<randomNo<<endl;

        if(A_Rows.size()==0)//initially row vector empty check
        {
            A_Rows.push_back(x);
            A_Columns.push_back(y);
            A_Values.push_back(randomNo);
            TotalElementsinA--;
        }
        else{//this will handle if vector already have elements 1.duplicacy check(means for same position element is generated?) 2.pushing random no into vector
            //below code for there is already row index present in vector checking random row no generated is exists?
                for (auto i = A_Rows.rbegin(); i != A_Rows.rend(); ++i)
                {
                    index=index-1;
                    cout << *i << " "<<"index for row:"<<index<<endl;
                    if(*i>x)//finding position for random row x to be placed in ordered position counting elements greater than it
                    {
                        count++;
                        continue;
                    }
                    else{
                            if(*i<x)
                            {
                                A_Rows.insert (Ait1-count,1,x);
                                A_Columns.insert (Ait2-count,1,y);
                                A_Values.insert (Ait3-count,1,randomNo);
                                isElementPushed=true;
                                TotalElementsinA--;
                                break;
                            }
                            else{//here means row index is matched need to save index value which further required for
                                //checking respective column position randomly generated has entry in column vector means
                                // correspoding position already random no generated
                                    matchedRow=*i;
                                    cout<<"here means row index is matched " <<matchedRow <<" need to save index value";
                                break;
                            }

                    }

                }//row check done here

                //check count size equals to row vector size it signifies element added at start
                //means all row indices greater than it.
        if(count==A_Rows.size())
        {
             A_Rows.insert (Ait1-count,1,x);
             A_Columns.insert (Ait2-count,1,y);
             A_Values.insert (Ait3-count,1,randomNo);
             isElementPushed=true;
             TotalElementsinA--;
        }
        index=index+1;
         //check if element already pushed
        if(isElementPushed)
        {
           continue;
        }
        else{//if element not pushed means there is row matching index found so check whether column index is also matching?
                for (auto i = A_Columns.rbegin()+count; i != A_Columns.rend(); ++i)
                {
                    index=index-1;

                    cout <<"\n"<< *i << " "<<"column for index:"<<index<<endl;
                    if(*i>y&&A_Rows[index]==matchedRow)//finding position for random row x to be placed in ordered position counting elements greater than it
                    {
                        count++;
                        continue;
                    }
                    else{
                            if(*i==y)
                            {
                                cout<<"Duplicate value found at row:"<<x<<" column:"<<y<<endl;
                                    duplicate=true;
                                break;

                                                           }
                            else{//here means row index is matched need to save index value

                                 A_Rows.insert (Ait1-count,1,x);
                                A_Columns.insert (Ait2-count,1,y);
                                A_Values.insert (Ait3-count,1,randomNo);
                                isElementPushed=true;
                                TotalElementsinA--;
                                break;

                            }

                    }


                }//column check done here

                if(count==A_Rows.size())//means randomly generated column index didnt matched till 1st element so it inserting element at start
                {
                    A_Rows.insert (Ait1-count,1,x);
                    A_Columns.insert (Ait2-count,1,y);
                    A_Values.insert (Ait3-count,1,randomNo);
                    isElementPushed=true;
                    TotalElementsinA--;
                }

                if(duplicate||isElementPushed)
                {
                   continue;
                }
        }//element not pushed else part done here


        }//end empty row check else part


    }//end while loop in #sparseElements in A

    //below code printig row column vector values
 cout << endl;
  cout<<"Generated random rows,columns and values for Matrix A:"<<endl;
   cout<<"rows: ";
 for (auto i = A_Rows.begin(); i != A_Rows.end(); ++i)
        cout << *i << " ";
 cout << endl;
  cout<<"columns: ";
for (auto i = A_Columns.begin(); i != A_Columns.end(); ++i)
        cout << *i << " ";
cout << endl;;
 cout<<"values: ";
for (auto i = A_Values.begin(); i != A_Values.end(); ++i)
        cout << *i << " ";
cout << endl;

//AS ABOVE RANDOM ELEMENTS FOR ROW INDEX,COLUMN INDEX AND VALUE GENERATED FOR MATRIX A SAME WILL BE GENERATED FOR MATRIX B
//BUT HERE REQUIREMENT IS FOR MULTIPLICATION OF BOTH MATRICES A,B IS ROW OF MATRIX A AND COLUMN INDICES OF MATRIX B NEED TO BE SORTED
//SO WHILE GENERATING RANDOM INDICES AND VALUES FOR MATRIX B COLUMN INDICES NEED TO MAINTAINED IN SORTED ORDER



      cout<<"Generating random rows,columns and values for Matrix B";
    while(TotalElementsinB>0)//random element generation,duplicacy check, maintaining column vector elements in sorted order
    {
        //testing
        cout << endl;
 for (auto i = B_Rows.begin(); i != B_Rows.end(); ++i)
        cout << *i << " ";
 cout << endl;
for (auto i = B_Columns.begin(); i != B_Columns.end(); ++i)
        cout << *i << " ";
cout << endl;;
for (auto i = B_Values.begin(); i != B_Values.end(); ++i)
        cout << *i << " ";
        //testing
        int count=0,matchedColumn=-1;
        bool duplicate=false,isElementPushed=false;
        int index=B_Columns.size();
         Ait1=B_Rows.end();
          Ait2=B_Columns.end();
           Ait3=B_Values.end();
        int x=printRandoms(0,n-1);
        int y=printRandoms(0,p-1);
        int randomNo=printRandomsno(-100,100);//random no are generated between -100 to 100
        cout<<"\nrowno:"<<x<<" columnno:"<<y<<" randomNo:"<<randomNo<<endl;

        if(B_Columns.size()==0)//initially column vector empty check
        {
            B_Rows.push_back(x);
            B_Columns.push_back(y);
            B_Values.push_back(randomNo);
            TotalElementsinB--;
        }
        else{//this will handle if vector already have elements 1.duplicacy check 2.pushing random no into vector
            //below code for there is already column index present in vector checking random column no generated is exists?
                for (auto i = B_Columns.rbegin(); i != B_Columns.rend(); ++i)
                {
                    index=index-1;
                    cout << *i << " "<<"column for index:"<<index<<endl;
                    if(*i>y)//finding position for random column y to be placed in ordered position counting elements greater than it
                    {
                        count++;
                        continue;
                    }
                    else{
                            if(*i<y)
                            {
                                B_Rows.insert (Ait1-count,1,x);
                                B_Columns.insert (Ait2-count,1,y);
                                B_Values.insert (Ait3-count,1,randomNo);
                                isElementPushed=true;
                                TotalElementsinB--;
                                break;
                            }
                            else{//here means column index is matched need to save index value
                                    matchedColumn=*i;
                                    cout<<"here means column index is matched " <<matchedColumn <<" need to save index value";
                                break;
                            }

                    }

                }//column check done here

                //check count size equals to column vector size it signifies element added at start
        if(count==B_Columns.size())
        {
             B_Rows.insert (Ait1-count,1,x);
             B_Columns.insert (Ait2-count,1,y);
             B_Values.insert (Ait3-count,1,randomNo);
             isElementPushed=true;
             TotalElementsinB--;
        }
        index=index+1;
         //check if element already pushed
        if(isElementPushed)
        {
           continue;
        }
        else{//if element not pushed means there is column matching index found so check whether row index is also matching?
                for (auto i = B_Rows.rbegin()+count; i != B_Rows.rend(); ++i)
                {
                    index=index-1;

                    cout <<"\n"<< *i << " "<<"row for index:"<<index<<endl;
                    if(*i>x&&B_Columns[index]==matchedColumn)//finding position for random row x to be placed in ordered position counting elements greater than it
                    {
                        count++;
                        continue;
                    }
                    else{
                            if(*i==x)//here means row index is matched need to save index value
                            {
                                cout<<"Duplicate value found at row:"<<x<<" column:"<<y<<endl;
                                    duplicate=true;
                                break;

                                                           }
                            else{

                                 B_Rows.insert (Ait1-count,1,x);
                                B_Columns.insert (Ait2-count,1,y);
                                B_Values.insert (Ait3-count,1,randomNo);
                                isElementPushed=true;
                                TotalElementsinB--;
                                break;

                            }

                    }


                }//row check done here

                 if(count==B_Columns.size())
        {
             B_Rows.insert (Ait1-count,1,x);
             B_Columns.insert (Ait2-count,1,y);
             B_Values.insert (Ait3-count,1,randomNo);
             isElementPushed=true;
             TotalElementsinB--;
        }
                if(duplicate||isElementPushed)
                {
                   continue;
                }
        }//element not pushed else part done here


        }//end empty column check else part


    }//end while loop in #sparseElements in B

    cout<<"Generated random rows,columns and values for Matrix B:"<<endl;
            //testing
        cout << endl;
        cout<<"rows: ";
 for (auto i = B_Rows.begin(); i != B_Rows.end(); ++i)
        cout << *i << " ";
 cout << endl;
  cout<<"columns: ";
for (auto i = B_Columns.begin(); i != B_Columns.end(); ++i)
        cout << *i << " ";
cout << endl;;
 cout<<"values: ";
for (auto i = B_Values.begin(); i != B_Values.end(); ++i)
        cout << *i << " ";
        //testing

//below code is for Matrix multiplication for sparse matrix A and B stored in vector form
	//Result Matrix
	vector<int> R_Rows;
	vector<int> R_Columns;
	vector<int> R_Values(0);

	// below code line 398-406 for calculating time needed for multiplication only requirement

	struct timespec start, end;

    // start timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC, &start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


        //below code is for multiplcation of sparse matrices REFF.GEEKSFORGEEKS
        /*
        LOGIC FOR SPARSE MATRICES MULTIPLICATION
MATRIX A           MATRIX B
Row Col Val      COL ROW Val
1   2   10       1   1   2
1   3   12       1   3   8
2   1   1        2   1   5
2   3   2        2   2   1

Summation of multiplied values:

result[1][1] = A[1][3]*B[1][3] = 12*8 = 96
result[1][2] = A[1][2]*B[2][2] = 10*1 = 10
result[2][1] = A[2][1]*B[1][1] + A[2][3]*B[1][3] = 2*1 + 2*8 = 18
result[2][2] = A[2][1]*B[2][1] = 1*5 = 5

        */

//FOR MULTIPLIYING  BOTH SPARSE MATRICES AS WE MAINTAINED ROW OF MATRIX A AND COLUMN OF MATRIX B IN SORTED ORDER
//FIRST FOR LOOP WILL ITERATE THROUGH FOR EACH COLUMN OF MATRIX A
//SECOND FOR LOOP WILL ITERATE THROUGH FOR EACH ROW OF MATRIX B
//FOR MULTIPLICATION WE NEED EACH COLUMN INDEX OF MATRIX A NEED TO MATCHED WITH ROW INDEX OF MATRIX B
//IF IT MATCHED THEN MULTIPLY VALUES PRESENT AT THOSE INDICES,IF NOT MATCHED THEN NO ACTION
        for(int i=0;i<A_Columns.size();i++)
        {
            for(int j=0;j<B_Rows.size();j++)
        {
            if(R_Rows.size()==0)//CHECKS FOR RESULTANT MATRIX EMPTY
            {
                if(A_Columns[i]==B_Rows[j])//FOR MULTIPLICATION WE NEED EACH COLUMN INDEX OF MATRIX A NEED TO MATCHED WITH ROW INDEX OF MATRIX B
                {
                    R_Rows.push_back(A_Rows[i]);
                R_Columns.push_back(B_Columns[j]);
                R_Values.push_back(A_Values[i]*B_Values[j]);
                }
                else{
                    continue;
                }

            }
            else{//IF RESULTANT MATRIX NOT EMPTY WE NEED TO CHECK WHETHER INDICES I AND J HAS ALREADY PARTIALLY CALCULATED SUM
                     if(A_Columns[i]==B_Rows[j])//FOR MULTIPLICATION WE NEED EACH COLUMN INDEX OF MATRIX A NEED TO MATCHED WITH ROW INDEX OF MATRIX B
                {
                    bool matched=false;
                    int matched_index=-1;
                    //below for loop is for checking whether same index for rows and column are present if yes then add multipliaction
                    //result into it.
                    for(int k=0;k<R_Rows.size();k++)
                    {
                        if(R_Rows[k]==A_Rows[i]&&R_Columns[k]==B_Columns[j])//WE NEED TO CHECK WHETHER INDICES I AND J HAS ALREADY PARTIALLY CALCULATED SUM
                                                                            //IF YES SAVE THAT INDEX WHICH WE WILL NEED TO ADD PARTIAL SUM
                        {
                            matched=true;
                            matched_index=k;
                            break;
                        }
                    }

                    if(matched)
                    {
                        R_Values[matched_index]+=A_Values[i]*B_Values[j];//HERE PARTIAL SUM IS ADDED
                        continue;
                    }
                    else{   //HERE NO INDICES MATCHED MEANS NO PARTIAL SUM GENERATED SO DIRECTLY PUSH VALUE IN RESULTANT MATRIX ALONG
                            //WITH ROW INDEX AND COLUMN INDEX IT MIGHT BE FUTURE USED IF IT IS PARTIAL SUM CALCULATED
                          R_Rows.push_back(A_Rows[i]);
                R_Columns.push_back(B_Columns[j]);
                R_Values.push_back(A_Values[i]*B_Values[j]);
                    }
                }
                else{//HERE FOR MULTIPLICATION WE NEED EACH COLUMN INDEX OF MATRIX A DIDNT MATCHED WITH ROW INDEX OF MATRIX B
                    continue;
                }


            }
        }
        }

        // stop timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    // clock_gettime(CLOCK_REALTIME, &end);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

     // above code 464-470 Calculating total time taken by the program.
        //testing
        cout << endl;
        cout <<"Multiplication result:"<< endl;
        if(R_Rows.size()>0)
        {
             cout <<"Multiplication output result matrix:"<< endl;
              cout <<"Rows: ";
            for (auto i = R_Rows.begin(); i != R_Rows.end(); ++i)
        cout << *i << " ";
 cout << endl;
  cout <<"Column: ";
for (auto i = R_Columns.begin(); i != R_Columns.end(); ++i)
        cout << *i << " ";
cout << endl;;
 cout <<"values: ";
for (auto i = R_Values.begin(); i != R_Values.end(); ++i)
        cout << *i << " ";
        }
        else{
            cout <<"Multiplication result is zero."<< endl;
        }

        //testing
        //printing time taken by sparse matrix multiplication
        cout << endl;;
cout << "\nTime taken by sparse matrix multiplication is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}

