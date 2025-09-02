#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size, message = 200;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int bufsize = MPI_BSEND_OVERHEAD + sizeof(int);
    void *buffer = malloc(bufsize);
    MPI_Buffer_attach(buffer, bufsize);

    if (rank == 0) {
        MPI_Bsend(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 buffered and sent message %d to process 1\n", message);
    } else if (rank == 1) {
        MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received message %d from process 0\n", message);
    }

    MPI_Buffer_detach(&buffer, &bufsize);
    free(buffer);

    MPI_Finalize();
    return 0;
}

