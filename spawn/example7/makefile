ALL: blib exec slave1 slave2

#compilation and various flags
EXEC    = master
SLAVE1  = worker
SLAVE2  = worker2
CLEANFILES  = ${EXEC}
OFILES= ${wildcard ./*.o}
#CFLAGS = -O3

MDIR=./data
###Tuning Parameters###

MPI_NODES=1
GMRES_RESTART=300
KSP_MONITOR=-ksp_monitor_true_residual
RTOL=1e-100
DIVTOL=1e1000
MAX_ITE=20000
PC=none
ATOL=1e-10
MAT=utm300.mtx_300x300_3155nnz

include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules

blib :
	-@echo "BEGINNING TO COMPILE LIBRARIES "
	-@echo "========================================="
	-@${OMAKE}  PETSC_ARCH=${PETSC_ARCH} PETSC_DIR=${PETSC_DIR} ACTION=libfast tree
	-@echo "Completed building libraries"
	-@echo "========================================="

distclean :
	-@echo "Cleaning application and libraries"
	-@echo "========================================="
	-@${OMAKE} PETSC_ARCH=${PETSC_ARCH}  PETSC_DIR=${PETSC_DIR} clean
	-${RM} ${OFILES} ${EXEC} ${SLAVE1} ${SLAVE2}
	-@echo "Finised cleaning application and libraries"
	-@echo "========================================="	

exec: master.o
	-@echo "BEGINNING TO COMPILE APPLICATION "
	-@echo "========================================="
	-@${CLINKER} -o ${EXEC} master.o ${PETSC_LIB}
	-@echo "Completed building application"
	-@echo "========================================="

slave1: slave.o
	-@echo "BEGINNING TO COMPILE SLAVE1 "
	-@echo "========================================="
	-@${CLINKER} -o ${SLAVE1} slave.o ${PETSC_LIB}
	-@echo "Completed SLAVE1 Compilation"
	-@echo "========================================="

slave2: slave2.o
	-@echo "BEGINNING TO COMPILE SLAVE2 "
	-@echo "========================================="
	-@${CLINKER} -o ${SLAVE2} slave2.o ${PETSC_LIB}
	-@echo "Completed SLAVE2 Compilation"
	-@echo "========================================="
#-ksp_monitor_true_residual -eps_monitor

runa:
	-@${MPIEXEC} -np ${MPI_NODES} ./${EXEC} -ksp fgmres ${GMRES_MONITOR} -ksp_gmres_restart ${GMRES_RESTART} ${KSP_MONITOR} -ksp_rtol ${RTOL} \
		-ksp_divtol ${DIVTOL} -ksp_max_it ${MAX_ITE} -pc_type ${PC} -ksp_atol ${ATOL} -mfile utm300.mtx_300x300_3155nnz 



