#include <stdio.h>
#include <mpi.h>
#include "petsc.h"
#include "petscksp.h"
#include "slepceps.h"
//#include "slave.h"

PetscErrorCode loadInput(Mat * A, Vec * x);
PetscErrorCode loadMatrix(Mat * A);
PetscErrorCode loadVector(char * type_v,Vec * b);
PetscErrorCode generateVector(int size, Vec * v);
PetscErrorCode generateVectorRandom(int size, Vec * v);
PetscErrorCode generateVectorNorm(int size, Vec * v);
