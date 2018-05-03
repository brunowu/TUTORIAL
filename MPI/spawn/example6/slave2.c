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

  if ( myrank == 0 ) {
    int tmp_size;
    MPI_Comm_remote_size( parentcomm, &tmp_size );
  //  printf( "child size of parent comm world = %d\n", tmp_size );

    MPI_Comm_size( MPI_COMM_WORLD, &tmp_size );
 //   printf( "child size of child comm2 world = %d\n", tmp_size );

    MPI_Comm_size( intra_comm2, &tmp_size );
 //   printf( "child size of intra comm2 world = %d\n", tmp_size );
  }
  //MPI_Barrier(MPI_COMM_WORLD);
  int intra_rank2;

  MPI_Comm_rank(intra_comm2, &intra_rank2);
//  printf("I am rank %d in intra_rank2 \n", intra_rank2);
  int msg = 990;
  MPI_Status status;
  int flag = 0,count;
  while(!flag){
  	MPI_Iprobe(0,0,intra_comm2,&flag, &status);
  	if(flag){
  		MPI_Recv(&msg,1, MPI_INT, 0,0,intra_comm2,&status);
        	printf("\n###Child 2 recv msg = %d from parent flg = %d \n", msg,flag);  
	}
	else{
		printf("\n###Child 2 recv NOTHING \n");
	}
//  	printf("\n###Child 2 recv msg = %d from parent flg = %d \n", msg,flag);
  }
//  MPI_Send(&msg, 1, MPI_INT, 0,0,intra_comm);
  MPI_Comm_free(&parentcomm);
  MPI_Comm_free(&intra_comm2);
  MPI_Finalize();

  return 0;
}
