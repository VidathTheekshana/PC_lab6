#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size, message = 42;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Sending to rank 1
        MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent message %d to process 1\n", message);
    } else if (rank == 2) {
        // Waiting on rank 0 (but rank 0 didn’t send to 2 → deadlock!)
        MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 2 received message %d from process 0\n", message);
    }

    MPI_Finalize();
    return 0;
}

