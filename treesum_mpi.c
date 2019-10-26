/*
 * File:     treesum_mpi.c
 *
 * Purpose:  Use tree-structured communication to find the global sum
 *           of a random collection of ints.  This version doesn't
 *           require that comm_sz be a power of 2.
 *
 */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------
 * Function:
 *  global_sum
 *
 * Purpose:
 *  Implement a global sum using tree-structured communication
 *
 * Notes:
 *  1.  The return value for global sum is only valid on process 0
 */
int global_sum(int my_int /* in */, int my_rank /* in */, int comm_sz /* in */,
               MPI_Comm comm /* in */) {
  int my_sum = my_int;
  int other_sum = 0;
  MPI_Status status;
  int result;

  if (comm_sz <= 0 || my_rank < 0 || my_rank >= comm_sz)
    return 0;
   printf("comm size = %d \n", comm_sz);
  if(my_rank % 2 !=0 && my_rank > 0){
    printf("sending myrank = %d \n", my_rank);
    MPI_Send (&my_sum, 1, MPI_INT, my_rank -1, 0, comm);
  }
  for( int gap = 1; gap < comm_sz; gap = gap * 2){
    if(my_rank % (2 * gap) == 0 && my_rank + gap < comm_sz ){
      printf("gap = %d  myrank = %d \n", gap, my_rank);
      MPI_Recv(&other_sum, 1, MPI_INT, my_rank + gap, 0, comm, &status);
      my_sum= other_sum + my_sum;
      if((my_rank % (4 * gap)) != 0 && my_rank >= 2 * gap)
        printf("sending myrank = %d \n", my_rank);
        MPI_Send (&my_sum, 1, MPI_INT,  my_rank - 2 * gap, 0, comm);
    }
  }
  return my_sum;
} /* Global_sum */
