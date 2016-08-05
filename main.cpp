#include<iostream>
#include<mpi.h>

int main(){
	MPI_Init(NULL, NULL);

	int numberOfProcesses;  
	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);

	int processRank; 
	MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

	if(threadRank == 0)//Raspberry Pi Zero Tasks
	{
		int InitialList[]= {2,3,5,7,11};
		int LeastCommonMultiple = 1;
		for(int i=0; i<5; i++)
		{
			LeastCommonMultiple*=InitialList[i];
		}

		int Begins[100], Ends[100];
		// Granulate(Begins, Ends, InputNumber); - MACHEN BITTE

		for(int i=0; i<numberOfProcessess; i++)
		{
			int Package[] = {Begins[i], Ends[i], LeastCommonMultiple};
			MPI_Isend(Package, 3, MPI_Int, i+1, 0, MPI_COMM_WORLD);
		}
	}
	else //Orange Pi and Pi B+ Tasks
	{
	}

	MPI_Finalize();
	return 0;
}
