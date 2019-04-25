#include "stdint.h"
#include "stdio.h"

struct MyFlags
{
	MyFlags(){}
	MyFlags(const MyFlags& other) : mBits(other.mBits){}
	uint16_t mBits;
};

extern "C" __declspec(dllexport) void testmf(MyFlags flags){
	printf("%d", flags.mBits);
}

struct MyFlags2
{
	MyFlags2(){}
	uint16_t mBits;
};

extern "C" __declspec(dllexport) void testmf2(MyFlags2 flags){
	printf("%d", flags.mBits);
}

extern "C" __declspec(dllexport) void testmf3(char flags[sizeof MyFlags]){
	printf("%d", (*(MyFlags*)&flags).mBits);
}