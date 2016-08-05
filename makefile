EXECS=decomposeNumber
MPICXX=mpicxx
MPI_HOSTS=hosts

all:${EXECS}

decomposeNumber: main.cpp decompose.cpp
	${MPICXX} --std=c++11 -o decomposeNumber decompose.cpp main.cpp

clean:
	rm ${EXECS}
