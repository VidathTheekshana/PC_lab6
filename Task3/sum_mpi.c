#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long n = 10000000;
    long long chunk = n / size;
    long long start = rank * chunk + 1;
    long long end = (rank == size-1) ? n : start + chunk - 1;
    long long local_sum = 0;

    double start_time = MPI_Wtime();
    for(long long i=start;i<=end;i++)
        local_sum += i;

    long long total_sum;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    double end_time = MPI_Wtime();

    if(rank==0){
        printf("Total sum = %lld\n", total_sum);
        printf("Time = %f seconds\n", end_time-start_time);
    }

    MPI_Finalize();
    return 0;
}

