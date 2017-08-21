#include <stdio.h> 
#include <mpi.h>

int main( int argc, char *argv[] ) {

  MPI_Init( &argc, &argv );

  int myrank;
  MPI_Comm_rank( MPI_COMM_WORLD, &myrank );

  MPI_Comm parentcomm;
  MPI_Comm_get_parent( &parentcomm );

  MPI_Comm intra_comm;
  MPI_Intercomm_merge( parentcomm, 1, &intra_comm );

  if ( myrank == 0 ) {
    int tmp_size;
    MPI_Comm_remote_size( parentcomm, &tmp_size );
    printf( "child size of parent comm world = %d\n", tmp_size );

    MPI_Comm_size( MPI_COMM_WORLD, &tmp_size );
    printf( "child size of child comm world = %d\n", tmp_size );

    MPI_Comm_size( intra_comm, &tmp_size );
    printf( "child size of intra comm world = %d\n", tmp_size );
  }
  //MPI_Barrier(MPI_COMM_WORLD);
  int intra_rank;

  MPI_Comm_rank(intra_comm, &intra_rank);
  printf("I am rank %d in intra_rank \n", intra_rank);
  int msg = 911;
  MPI_Send(&msg, 1, MPI_INT, 0,0,intra_comm);
  MPI_Comm_free(&parentcomm);
  MPI_Comm_free(&intra_comm);
  MPI_Finalize();

  return 0;
}
