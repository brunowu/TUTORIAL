#include <stdio.h> 
#include <mpi.h>

int main( int argc, char *argv[] ) {

  MPI_Init( &argc, &argv );

  int myrank;
  MPI_Comm_rank( MPI_COMM_WORLD, &myrank );

  MPI_Comm parentcomm;
  MPI_Comm_get_parent( &parentcomm );

  MPI_Comm intra_comm2;
  MPI_Intercomm_merge( parentcomm, 1, &intra_comm2 );

  printf("\n\n\nThis is hello from SLAVE2\n\n\n");

  if ( myrank == 0 ) {
    int tmp_size;
    MPI_Comm_remote_size( parentcomm, &tmp_size );

    MPI_Comm_size( MPI_COMM_WORLD, &tmp_size );

    MPI_Comm_size( intra_comm2, &tmp_size );
  }

  MPI_Comm_free(&parentcomm);
  MPI_Comm_free(&intra_comm2);
  MPI_Finalize();

  return 0;
}
