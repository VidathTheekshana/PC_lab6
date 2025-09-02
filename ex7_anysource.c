#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size, message;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank != 0) {
        message = rank * 10;
        MPI_Send(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process %d sent message %d to process 0\n", rank, message);
    } else {
        for (int i = 1; i < size; i++) {
            MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process 0 received message %d\n", message);
        }
    }

    MPI_Finalize();
    return 0;
}

