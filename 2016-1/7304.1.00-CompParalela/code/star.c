#include <stdio.h>
#include <mpi.h>
#define TAG 1

void main(int argc, char* argv[]) {
    int p, rank, val, numProcs;
    MPI_Status status;
    MPI_Init(&argc, &argv) ;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	
    if (rank == 0) {
		
		int val = 12/(numProcs - 1);
		int lastOffset = 0;
        int  i, partial;
		
		for (i = 1; i < numProcs; i++)
			MPI_Send(&val, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
			
		int total = 0;
		
		for (i = 1; i < numProcs; i++) {
			MPI_Recv(&partial, 1, MPI_INT, i, TAG, MPI_COMM_WORLD, &status);
			total += partial;
		}
		
		printf("Valor de total: %d\n", total);
		
        // enviar tamanho dos intervalos (10000/N) para todos os processos
        // receber somatorio parcial de todos os processos
        // somar valores exibir total
    }
    else {
		
		int val;

		MPI_Recv(&val, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
		
		int startOffset = (rank-1)*val + 1;
		int localSum = 0;
        int i;

        for (i = startOffset; i < startOffset + val; i++)
			localSum += i;
		
		MPI_Send(&localSum, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD);
        // receber intervalo
        // fazer somatorio de acordo com o seu rank
        // enviar o resultado para o processo mestre
    }
    MPI_Finalize();
}
