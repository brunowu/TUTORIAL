#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
  MPI_Init(NULL, NULL);

  // Get the rank and size in the original communicator
  int world_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int color = world_rank % 3; // Determine color based on row
  int colors;
  // Split the communicator based on the color and use the original rank for ordering
  MPI_Comm row_comm, firstcomm, secondcomm, subsubcomm, thirdcomm;
  MPI_Comm_split(MPI_COMM_WORLD, color, world_rank, &row_comm);

  int row_rank, row_size;
  MPI_Comm_rank(row_comm, &row_rank);
  MPI_Comm_size(row_comm, &row_size);

  printf("WORLD RANK/SIZE: %d/%d --- ROW RANK/SIZE: %d/%d -- COMM NB %d\n",
	 world_rank, world_size, row_rank, row_size, color) ;

  MPI_Barrier(MPI_COMM_WORLD);
//  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 0, 1, &firstcomm);
/*
  if(color == 0){
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 1, 1, &firstcomm);
  }
*/

  int sub_rank, sub_size;
  int f1, f2, f01,f02,f10, f12, f20, f21;
  MPI_Comm subfirst, subsecond;
  if(color == 0){
//	printf("HELLO FORM THE HEART \n");
	colors = row_rank % 2;
  	MPI_Comm_split(row_comm, colors, row_rank, &subsubcomm);
 	MPI_Comm_rank(subsubcomm, &sub_rank);
  	MPI_Comm_size(subsubcomm, &sub_size);
//  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 0, 1, &firstcomm);
    	printf("\n\nsub rank /size : %d/%d --- subsub rank /SIZE: %d/%d -- sub COMM NB %d\n", row_rank, row_size, sub_rank, sub_size, colors) ;
	//MPI_Barrier(MPI_COMM_WORLD);
  	if(colors == 0){
  		MPI_Intercomm_create(subsubcomm, 0, row_comm, 1, 2, &subfirst);
		MPI_Comm_test_inter(subfirst, &f1);
		int size1;
		MPI_Comm_remote_size(subfirst, &size1);
		if(f1 && sub_rank == 0){printf(" = = 0) subfirst OK / remote = %d\n", size1);}
	}
	if(colors == 1){
                MPI_Intercomm_create(subsubcomm, 0, row_comm, 0, 2, &subfirst);
                MPI_Comm_test_inter(subfirst, &f2);
	 	int size2;
                MPI_Comm_remote_size(subfirst, &size2);
                if(f2 && sub_rank == 0){printf(" = = 1) subfirst OK / remote = %d\n", size2);}
	}
  
   }
 
  //MPI_Barrier(MPI_COMM_WORLD); 
  if(color == 0){
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 2, 1, &firstcomm);  
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 1, 3, &secondcomm);
  int size3, size4;
  MPI_Comm_remote_size(firstcomm, &size3);
  MPI_Comm_remote_size(secondcomm, &size4);
  MPI_Comm_test_inter(firstcomm, &f02);
  if(f02 && row_rank == 0){printf("0) F02 OK / remote = %d\n",size3);}
    MPI_Comm_test_inter(secondcomm, &f01);
  if(f01 && row_rank == 0){printf("0) F01 OK / remote = %d\n",size4);}
  }
  else if(color == 2){
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 0, 1, &firstcomm);
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 1, 4, &thirdcomm);

  int size5, size6;
  MPI_Comm_remote_size(firstcomm, &size5);
  MPI_Comm_remote_size(thirdcomm, &size6);
  MPI_Comm_test_inter(firstcomm, &f20);
  if(f20 && row_rank == 0){printf("2) F20 OK / remote = %d\n", size5);}
    MPI_Comm_test_inter(thirdcomm, &f21);
  if(f21 && row_rank == 0){printf("2) F21 OK / remote = %d\n", size6);}
  }
  else if(color == 1){
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 0, 3, &secondcomm);
  MPI_Intercomm_create(row_comm, 0, MPI_COMM_WORLD, 2, 4, &thirdcomm);
  int size7, size8;
  MPI_Comm_remote_size(secondcomm, &size7);
  MPI_Comm_remote_size(thirdcomm, &size8);
  MPI_Comm_test_inter(secondcomm, &f10);
  if(f10 && row_rank == 0){printf("1) F10 OK / remote = %d\n", size7);}
    MPI_Comm_test_inter(thirdcomm, &f12);
  if(f12 && row_rank == 0){printf("1) F12 OK / remote = %d\n", size8);}
  }
  MPI_Comm_free(&row_comm);

  MPI_Finalize();
}
