#include<vector>
#include<cstdint>

#ifndef DECOMPOSE_H
using number=unsigned long long;

void divide(number X,number* begin,number* end,int threads);

void decompose(number X,number start,number end,std::vector<number> &divisors);

void checkFound(number X,number divisors[],int divisorsSize);
#endif
