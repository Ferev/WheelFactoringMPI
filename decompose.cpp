#include "decompose.h"
#include<vector>
#include<cstdint>
using number=unsigned long long;

void divide(number X,number* begin,number* end,int threads){
	number beginBS=2,endBS=X,midBS;
	while(beginBS<endBS){
		midBS=(beginBS+endBS)/2;
		if(X/midBS<midBS){
			endBS=midBS;
		}else{
			beginBS=midBS+1;
		}
	}
	number beginPrime=2;
	number endPrime=beginBS;
	number step=(endPrime-beginPrime)/threads;
	int remainder=(endPrime-beginPrime)%threads;
	for(int i=0;i<threads;i++){
		*begin=beginPrime;
		begin++;
		number endStepPrime=beginPrime+step;
		if(remainder!=0){
			endStepPrime++;
			remainder--;
		}
		*end=endStepPrime-1;
		end++;
		beginPrime=endStepPrime;
	}
}

void decompose(number X,number start,number end,std::vector<number> &primeDivisors){
	for(number i=start;i<=end;i++){
		if(X%i==0){
			primeDivisors.push_back(i);
			if(X/i!=i){
				primeDivisors.push_back(X/i);
			}
		}
	}
}

void checkFound(number X,number primeDivisors[],int divisorsSize){
	for(int i=0;i<divisorsSize;i++){
		if(X%primeDivisors[i]!=0){
			throw "Not a proper divisor";
		}
	}
}
