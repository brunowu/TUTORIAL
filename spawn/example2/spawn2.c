#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define MASTER    0
#define BUFSIZE   1024
<<<<<<< HEAD
#define NUM2SPAWN 10
=======
<<<<<<< HEAD
#define NUM2SPAWN 10
=======
#define NUM2SPAWN 2
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904

int main( int argc, char *argv[] )
{
  int rank;
  int size;
  int np = NUM2SPAWN;
  char message[BUFSIZE];
  MPI_Comm parentcomm, spawnedcomm, allcomm;
  
  /* the usual start-up for any process */
  MPI_Init( &argc, &argv );

  /* This function provides a convenient way to determine whether
 *   ** this process is part of the original communicator (has a null
 *     ** parent), or part of the newly spawned communicator */
  MPI_Comm_get_parent( &parentcomm );

  /* write output according to which communicator this process is a part of */
  if (parentcomm == MPI_COMM_NULL) {
    /* Create 2 more processes.
 *     ** Here we spawn 2 more instances of this program.
 *         ** argv[0] contains the name of the executable for this program. */
    MPI_Comm_spawn( "spawn2", MPI_ARGV_NULL, np, MPI_INFO_NULL, 0, 
		    MPI_COMM_WORLD, &spawnedcomm, MPI_ERRCODES_IGNORE );
    /* get the process rank, in this case within the parent communicator */
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
<<<<<<< HEAD
    printf("]> rank %d (of %d) in the parent intra-communicator.\n",rank,size);
=======
<<<<<<< HEAD
    printf("]> rank %d (of %d) in the parent intra-communicator.\n",rank,size);
=======
    printf("rank %d (of %d) in the parent intra-communicator.\n",rank,size);
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
  }
  else {
    /* notice that the spawned processes have an intra-communicator
 *     ** called MPI_COMM_WORLD, too */
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
<<<<<<< HEAD
    printf("---> rank %d (of %d) in the spawned intra-communicator.\n",rank,size);
=======
<<<<<<< HEAD
    printf("---> rank %d (of %d) in the spawned intra-communicator.\n",rank,size);
=======
    printf("rank %d (of %d) in the spawned intra-communicator.\n",rank,size);
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
  }

  /* we can broadcast to all processes associated with an
 *   ** inter-communicator, e.g. the spawned processes */
  if (rank == MASTER) {
<<<<<<< HEAD
    message[0] = 'B'; message[1] = 'o'; message[2] = 'n'; message[3] = 'j';
    message[4] = 'o'; message[5] = 'u'; message[6] = 'r'; message[7] = '\0';
=======
<<<<<<< HEAD
    message[0] = 'B'; message[1] = 'o'; message[2] = 'n'; message[3] = 'j';
    message[4] = 'o'; message[5] = 'u'; message[6] = 'r'; message[7] = '\0';
=======
    message[0] = 'g'; message[1] = 'a'; message[2] = 'l'; message[3] = 'o';
    message[4] = 'r'; message[5] = 'e'; message[6] = '!'; message[7] = '\0';
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
  }
  /* BUT remember that broadcast is a collective operation, so all must call..
 *   ** but it's a tad fiddly with all the different groups of processors that
 *     ** we have.
 *       ** Note also that the inter-communicator has different names
 *         ** according to the (parent/spawned) perspective. */
  if (parentcomm == MPI_COMM_NULL) {
    if (rank == MASTER) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
       MPI_Bcast(message,BUFSIZE,MPI_CHAR,MPI_ROOT,spawnedcomm);
    }
    //MPI_Bcast(message,BUFSIZE,MPI_CHAR,MPI_PROC_NULL,spawnedcomm);
  }
  else {
    MPI_Bcast(message,BUFSIZE,MPI_CHAR,MASTER,parentcomm);
    printf("---> spawned rank %d (of %d).  Master broadcasts: %s\n",rank,size,message);
<<<<<<< HEAD
=======
=======
      MPI_Bcast(message,BUFSIZE,MPI_CHAR,MPI_ROOT,spawnedcomm);
    }
    MPI_Bcast(message,BUFSIZE,MPI_CHAR,MPI_PROC_NULL,spawnedcomm);
  }
  else {
    MPI_Bcast(message,BUFSIZE,MPI_CHAR,MASTER,parentcomm);
    printf("spawned rank %d (of %d).  Master broadcasts: %s\n",rank,size,message);
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
  }
  
  /* A simpler manoeuvre is to (collectively) merge 
 *   ** the processes associated with an inter-communicator: */
  if (parentcomm == MPI_COMM_NULL) {
    MPI_Intercomm_merge(spawnedcomm, 0, &allcomm);
  }
  else {
    MPI_Intercomm_merge(parentcomm, 0, &allcomm);
  }

  /* all processes can make calls associated with the
 *   ** merged communicator */
  MPI_Comm_rank(allcomm,&rank);
  MPI_Comm_size(allcomm,&size);
<<<<<<< HEAD
  printf("]> rank %d (of %d) in the merged intra-communicator.\n",rank,size);
=======
<<<<<<< HEAD
  printf("]> rank %d (of %d) in the merged intra-communicator.\n",rank,size);
=======
  printf("rank %d (of %d) in the merged intra-communicator.\n",rank,size);
>>>>>>> 5481855a5cef0b6d08847a22818babd0c94666f3
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
  
  /* free communicators when we've finished with them
 *   ** remembering the different names as seen from different
 *     ** perspectives */
  if (parentcomm == MPI_COMM_NULL) {
    MPI_Comm_free(&spawnedcomm);
    MPI_Comm_free(&allcomm);
  }
  else {
    MPI_Comm_free(&parentcomm);
    MPI_Comm_free(&allcomm);
  }

  /* and finalise */
  fflush(stdout);
  MPI_Finalize();
  return 0;
}
