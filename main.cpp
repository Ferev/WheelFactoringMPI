#include<iostream>
#include<vector>
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
		printf("Data granulated, now sending it to nodes");
		for(int i=0; i<numberOfProcesses; i++)
		{
			int dataPackage[] = {Begins[i], Ends[i], LeastCommonMultiple};
			MPI_Send(Package, 3, MPI_INT, i+1, 0, MPI_COMM_WORLD);
		}
		printf("Data sent to nodes");
	
		printf("Calculating personal master list");

		for(int i=0; i<numberOfProcesses; i++)
		{
			MPI_Status status;
			int dataSize;
			MPI_Probe(MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
			MPI_Get_count(&status, MPI_INT, &dataSize); 
			MPI_Recv(dataSentBackPacket1, dataSize, MPI_INIT, i+1, 0, MPI_COMM_WORLD);
		}
		 
		printf("Merging Lists");
		std::vector<int> finalList;

		for(int i=0; i<numberOfProcesses; i++)
		{
			
			MPI_Send(finalList, finalList.size(), MPI_INT,i+1, 0, MPI_COMM_WORLD); 
		}

		int finalEndings[100], finalBeginnings[100];
		printf("Dividing list between the nodes and giving low range to the raspberry pi zero");
		
		
		for(int i=0; i<numberOfProcesses; i++)
		{
			int secondPackage[]= {finalBeginnings[i], finalEndings[i], InputNumber};
			MPI_Send(secondPackage, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
		printf("Dividing the input number with the final list");
		
		printf("Receiving answers from the nodes (packet 2)");
		for(int i=0; i<numberOfProcesses; i++)
		{
			std::vector<int> finalAnswersOutputList;
			MPI_Status &receiveDataForFinalMerge;
			int finalListSize;
			MPI_Probe(i+1, 0, MPI_COMM_WORLD, &receiveDataForFinalMerge);
			MPI_Get_count(&receiveDataForFinalMerge, MPI_INT, &finalListSize);
			MPI_Recv(finalAnswersOutputList, finalListSize, i+1, 0, 0, MPI_COMM_WORLD);
			printf("Exporting final answers and preparing the output");
		}
				
	}
	else //Orange Pi and Pi B+ Tasks
	{ 
		int receivedData[3];
		MPI_Irecv(receivedData, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Number is saved in [2]");
		printf("Now processing data received from package 1");
		
		std::vector<int> ProcessedData;
		MPI_Send(ProcessedData, ProcessedData.size(),MPI_INT,0, 0, MPI_COMM_WORLD);
		
		std::vector<int> finalListReceived;
		MPI_Status &statusSecond;
		int receivedDataSize;
		MPI_Probe(0, 0, MPI_COMM_WORLD, &statusSecond);
		MPI_Get_count(&statusSecond, MPI_INT, &receivedDataSize); 
		MPI_Recv(dataSentBackPacket1, receivedDataSize, MPI_INIT, i+1, 0, MPI_COMM_WORLD);
		

		int receivedRangePacket2[3];
		MPI_Recv(receivedRangePacket2, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Dividing the input number with the final list according to personal range");
		
		std::vector<int> outputFinalAnswer;
		MPI_Send(outputFinalAnswer, outputFinalAnswer.size(), MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;

}
