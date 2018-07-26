### An example pass the argv from father to the execuable spawned by root

```bash
mpicc mpi\_spawn\_pass\_argv\_child.c -o prog\_B
```

```bash
mpicc mpi\_spawn\_pass\_argv\_child.c -o prog\_A
```

```bash
mpiexec -n 1 ./prog\_A 200 100 10
```
