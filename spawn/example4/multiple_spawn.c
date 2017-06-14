#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
    int np[2] = { 1, 1 };
    int errcodes[2];
<<<<<<< HEAD
    MPI_Comm parentcomm, intercomm, incom;
=======
    MPI_Comm parentcomm, intercomm;
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
    char *cmds[2] = { "spawn1", "spawn2" };
    MPI_Info infos[2] = { MPI_INFO_NULL, MPI_INFO_NULL };

    MPI_Init( &argc, &argv );
    MPI_Comm_get_parent( &parentcomm );
    if (parentcomm == MPI_COMM_NULL)
    {
        /* Create 2 more processes - this example must be called manager for this to work. */
        MPI_Comm_spawn_multiple( 2, cmds, MPI_ARGVS_NULL, np, infos, 0, MPI_COMM_WORLD, &intercomm, errcodes );
<<<<<<< HEAD
        MPI_Comm_spawn( "spawn3", MPI_ARGV_NULL, 2, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &incom, MPI_ERRCODES_IGNORE );
=======
>>>>>>> 18aaf9bc0795c8f6dd6f2addee80b84671487904
        printf("I'm the parent.\n");
    }
    else
    {
        printf("I'm the spawned.\n");
    }
    fflush(stdout);
    MPI_Finalize();
    return 0;
}

