#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv[] ) {

  MPI_Init( &argc, &argv );
  int rank;
  MPI_Comm_rank( MPI_COMM_WORLD, &rank );

  MPI_Comm child_comm, child_comm2;
  int  num_processes_to_spawn = 1;
  MPI_Comm_spawn( "./worker", MPI_ARGV_NULL,
		  num_processes_to_spawn, MPI_INFO_NULL,
		  0, MPI_COMM_WORLD,
		  &child_comm, MPI_ERRCODES_IGNORE );

  MPI_Comm_spawn( "./worker2", MPI_ARGV_NULL,
                  num_processes_to_spawn, MPI_INFO_NULL,
                  0, MPI_COMM_WORLD,
                  &child_comm2, MPI_ERRCODES_IGNORE );

  MPI_Comm intra_comm, intra_comm2;
  MPI_Intercomm_merge( child_comm, 0, &intra_comm );
  MPI_Intercomm_merge( child_comm2, 0, &intra_comm2 );

  int intra_rank, intra_rank2;
  MPI_Comm_rank(intra_comm, &intra_rank);
  MPI_Comm_rank(intra_comm2, &intra_rank2);
  printf("I am rank %d of intra_comm\n",intra_rank);
  printf("I am rank %d of intra_comm2\n",intra_rank2);

  if ( rank == 0 ) {
    int tmp_size;
    int tmp_size2;
    MPI_Comm_size( intra_comm, &tmp_size );
    MPI_Comm_size( intra_comm2, &tmp_size2 );
    printf( "size of intra comm world = %d\n", tmp_size );
    printf( "size of intra comm2 world = %d\n", tmp_size2 );

    MPI_Comm_remote_size( child_comm, &tmp_size );
    MPI_Comm_remote_size( child_comm2, &tmp_size2 );
    printf( "size of child comm world = %d\n", tmp_size );
    printf( "size of child comm2 world = %d\n", tmp_size2 );
    MPI_Comm_size( MPI_COMM_WORLD, &tmp_size );
    MPI_Comm_size( MPI_COMM_WORLD, &tmp_size2 );
    printf( "size of parent comm world = %d\n", tmp_size );
    printf( "size of parent comm2 world = %d\n", tmp_size2 );
  }

  int msg;
  MPI_Status status;
  MPI_Recv(&msg,1, MPI_INT, 1,0,intra_comm,&status);
  printf("\n###Recv msg = %d from child \n", msg);
  MPI_Barrier(MPI_COMM_WORLD);
  msg = msg + 89;
  MPI_Send(&msg, 1,MPI_INT, 1,0,intra_comm2); 
  MPI_Comm_free(&child_comm);
  MPI_Comm_free(&intra_comm);
  MPI_Comm_free(&intra_comm2);
  MPI_Finalize();

  return 0;
}
