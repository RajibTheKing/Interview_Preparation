#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int count_bits_naive(long long v)
{
    int bit_count = 0;
    for(int i=0; i<64; i++)
    {

        unsigned long long mask = (1ULL << i);
        //cout<<v<<", "<<mask<<", "<<(v & mask)<<", "<<i<<endl;
        if(v & mask)
        {
            bit_count++;
        }

    }

    return bit_count;

}

int swapValue(int a, int b){

    int temp = a;
    a = b;
    b = a;

}

int swapBitwise(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int count_bits_optimized(long long v)
{
    //int mask[] = {0x55555555, 0x33333333, 0x0f0f0f0f, 0x00ff00ff, 0x0000ffff};

    long long mask[] = {0x5555555555555555, 0x3333333333333333, 0x0f0f0f0f0f0f0f0f, 0x00ff00ff00ff00ff, 0x0000ffff0000ffff, 0x00000000ffffffff};
    long long bit_count = v;
    for(int i=0; i<6; i++)
    {
        bit_count = (bit_count & mask[i]) + ((bit_count >> (1<<i)) & mask[i]);
    }

    return bit_count;

}



int main()
{

    long long totalCount = 0;
    for (int i = 0; i < 100; i++)
    {
        long long v = i;
        int ans = count_bits_optimized(v);
        totalCount += ans;
        cout << i << ", " << totalCount << ", " << ((log10(i)/log10(2)) - ans) << endl;
    }

    cout << "Final Answer: "<< totalCount << endl;
    return 0;
}
