#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char ** argv) {

    char ** newargv = malloc(sizeof(char *)*4);
    int numchildprocs = 1;
    MPI_Comm father;

    MPI_Init(&argc, &argv);
    MPI_Comm_get_parent(&father);

    if (MPI_COMM_NULL != father) {
        fprintf(stderr, "SPAWNED!\n");
    } else {
        newargv[0] = (char *) malloc(sizeof(char)*50);
        newargv[1] = (char *) malloc(sizeof(char)*50);
        newargv[2] = (char *) malloc(sizeof(char)*50);
        newargv[3] = NULL;

        strncpy(newargv[0],argv[1], 50);
        strncpy(newargv[1],argv[2], 50);
        strncpy(newargv[2],argv[3], 50);

        fprintf(stderr, "SPAWNING!\n");
        MPI_Comm_spawn("./prog_B",newargv,numchildprocs,
                MPI_INFO_NULL, 0, MPI_COMM_SELF, &father,
                MPI_ERRCODES_IGNORE);
    }

    MPI_Comm_free(&father);

    MPI_Finalize();
}
