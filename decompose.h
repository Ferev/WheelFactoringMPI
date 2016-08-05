#include<vector>
#include<cstdint>

#ifndef DECOMPOSE_H

void decompose(int beginnings[], int endings[], int leastCommonMultiple);

void generatePiZeroList(int primeNumberList[], int intputNumber);  

void generateSlaveList(int startOfRange, int endOfRange, int leastCommonMutiple);

void assembleList(int piZeroList[], int slaveList[], int outputList[]);

void findFinalAnswers(int starts[], int ends[], int output[]);

#endif
