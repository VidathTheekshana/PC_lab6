#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long total_points = 10000000;
    long long points_per_proc = total_points / size;
    long long local_count = 0;
    srand(rank + 1);

    double start_time = MPI_Wtime();
    for(long long i=0;i<points_per_proc;i++){
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if(x*x + y*y <= 1.0) local_count++;
    }

    long long global_count;
    MPI_Reduce(&local_count, &global_count, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    double end_time = MPI_Wtime();

    if(rank==0){
        double pi = 4.0 * global_count / total_points;
        printf("Approximate Pi = %f\n", pi);
        printf("Time = %f seconds\n", end_time-start_time);
    }

    MPI_Finalize();
    return 0;
}

