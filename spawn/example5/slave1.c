/* Code example from http://mpi-forum.org/docs/mpi-2.0/mpi-20-html/node98.htm */ 
#include <stdio.h>
#include "mpi.h" 
int main(int argc, char *argv[]) 
{ 
  int size;
  int rank;
  int world_size;
  MPI_Comm parent; 
  MPI_Init(&argc, &argv); 
  MPI_Comm_get_parent(&parent); 
  if (parent == MPI_COMM_NULL) printf("No parent!"); 
  MPI_Comm_remote_size(parent, &size); 
  if (size != 1) printf("Something's wrong with the parent"); 
  
  /* 
   * Parallel code here.  
   * The manager is represented as the process with rank 0 in (the remote 
   * group of) MPI_COMM_PARENT.  If the workers need to communicate among 
   * themselves, they can use MPI_COMM_WORLD. 
   */ 
  MPI_Comm_size(MPI_COMM_WORLD,&world_size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  printf("\n HELLO WORLD (%d/%d) \n",rank,world_size);
 
  MPI_Finalize(); 
  return 0; 
}
