#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
 
/* Test intercomm merge, including the choice of the high value */
 
void GetIntercomm( MPI_Comm *comm, int *isLeftGroup, int min_size )
{
    int size, rank, remsize, merr;
    int done=0;
    MPI_Comm mcomm;
    int rleader;

    /* Split comm world in half */
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    printf("In the MPI whole world of size %d, I am %d rank...\n", size, rank);
    if (size > 1) {
        merr = MPI_Comm_split( MPI_COMM_WORLD, (rank < size/2), rank, &mcomm );
        if (rank == 0) {
            rleader = size/2;
        }
        else if (rank == size/2) {
            rleader = 0;
        }
        else {
            /* Remote leader is signficant only for the processes designated local leaders */
            rleader = -1;
        }
        *isLeftGroup = rank < size/2;
        merr = MPI_Intercomm_create( mcomm, 0, MPI_COMM_WORLD, rleader, 12345, comm );
        merr = MPI_Comm_free( &mcomm );
    }
    else 
        *comm = MPI_COMM_NULL;
}

int main( int argc, char *argv[] )
{
    int errs = 0;
    int rank, size, rsize;
    int nsize, nrank;
    int minsize = 2;
    int isLeft;
    MPI_Comm comm, comm1, comm2, comm3, comm4;
 
    MPI_Init( &argc, &argv );
 
    GetIntercomm( &comm, &isLeft, minsize );
    MPI_Barrier(MPI_COMM_WORLD);
     /* Determine the sender and receiver */
    MPI_Comm_rank( comm, &rank );
    MPI_Comm_remote_size( comm, &rsize );
    MPI_Comm_size( comm, &size );

    printf("  ]>In the created comm of size %d, i am rank %d, and the remote size is %d \n", size, rank, rsize); 
    /* Try building intercomms */
    MPI_Intercomm_merge( comm, isLeft, &comm1 );
    /* Check the size and ranks */
    MPI_Comm_size( comm1, &nsize );
    MPI_Comm_rank( comm1, &nrank );
    if (nsize != size + rsize) {
        errs++;
        printf( "(1) Comm size is %d but should be %d\n", nsize, size + rsize );fflush(stdout);
        if (isLeft) {
            /* The left processes should be high */
            if (nrank != rsize + rank) {
                errs++;
                printf( "(1) rank for high process is %d should be %d\n", nrank, rsize + rank );fflush(stdout);
            }
        }
        else {
            /* The right processes should be low */
            if (nrank != rank) {
                errs++;
                printf( "(1) rank for low process is %d should be %d\n", nrank, rank );fflush(stdout);
            }
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    printf(" \n @>After the first merge, the comm size is %d, i am rank %d \n", nsize, nrank); 
    MPI_Intercomm_merge( comm, !isLeft, &comm2 ); 
    /* Check the size and ranks */
    MPI_Comm_size( comm1, &nsize );
    MPI_Comm_rank( comm1, &nrank );
    if (nsize != size + rsize) {
        errs++;
        printf( "(2) Comm size is %d but should be %d\n", nsize, size + rsize );fflush(stdout);
        if (!isLeft) {
            /* The right processes should be high */
            if (nrank != rsize + rank) {
                errs++;
 printf( "(2) rank for high process is %d should be %d\n", nrank, rsize + rank );fflush(stdout);
            }
        }
        else {
            /* The left processes should be low */
            if (nrank != rank) {
                errs++;
                printf( "(2) rank for low process is %d should be %d\n", nrank, rank );fflush(stdout);
            }
        }
    }
 
    MPI_Intercomm_merge( comm, 0, &comm3 ); 
    MPI_Intercomm_merge( comm, 1, &comm4 ); 
 
    MPI_Comm_free( &comm1 );
    MPI_Comm_free( &comm2 );
    MPI_Comm_free( &comm3 ); 
    MPI_Comm_free( &comm4 );
 
    MPI_Finalize();
    return errs;
}

