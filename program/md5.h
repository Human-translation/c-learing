#pragma once
#define CHUNK_BYTE 64
typedef unsigned int uint32;

class MD5
{
public:
	uint32 F(uint32 b,uint32 c,uint32 d)
	{
		return (b&c) | ((~b)&d);
	}
	uint32 G(uint32 b, uint32 c, uint32 d)
	{
		return (b&d) | (c&(~d));
	}
	uint32 H(uint32 b, uint32 c, uint32 d)
	{
		return b ^ c ^ d;
	}
	uint32 I(uint32 b, uint32 c, uint32 d)
	{
		return c ^ (b | (~d));
	}

	uint32 leftShift(uint32 number, int shiftNumber)
	{

	}

	void init();

	void reset();

	void calMD5(uint32* chunk);

	void calFinalMD5();

private:
	static int _leftShift[64];

	uint32 _k[64];

	char _chunk[CHUNK_BYTE];

	uint32 _lastByte;

	uint32 _totalByte;

	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};