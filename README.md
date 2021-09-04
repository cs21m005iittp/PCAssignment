# PCAssignment 1
For submitting PC assignments
Implemented matrix multiplication in C++.
There are two programs 1.dense matrix multiplcation 2.sparse matrix multiplication
This program should take as input m, n and p. i.e. the result matrix C = A X B will be of dimension m X p.
Matrices A and B are initialized by random values.
Sparsity is also another input to this program. What is sparsity? Say sp = 0.1, it implies that only 10% of the entries in the matrix hold data, rest of the entries are zero.
Both A and B will have their own sparsity input. i.e spA and spB
When generating random input to fill the matrix, assume the sparsity is randomly distributed. For example, if A = 4X4 matrix, and spA = 0.5, do not fill up the first two
rows with values, and the last two rows with 0. The sparse entries are also randomly distributed.

sparse matrix multiplication code will store these sparse matrices as vector form.1.row vector 2.column vector 3.value vector
Timed the runtime of these two algorithm for various sparsity values. and Compared them with the
algorithm which stores matrices as dense i.e. with 0s also taking up space.Plotted graph same is uploaded as PCPlot.png
