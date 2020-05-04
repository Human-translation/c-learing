#pragma once
#include <string>
#define CHUNK_BYTE 64
typedef unsigned int uint32;

class MD5
{
public:
	MD5();
	uint32 F(uint32 b, uint32 c, uint32 d)
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

	uint32 LeftShift(uint32 Number, int ShiftNumber)
	{
		return (Number << ShiftNumber) | (Number >> (32 - ShiftNumber));
	}

	void Init();
	void Reset();
	void CalMd5(uint32* Chunk);
	void CalFinalMd5();
	std::string ChangeHex(uint32 n);
	std::string GetStringMd5(const std::string& str);
	std::string GetFileMd5(const char* FilePath);

private:
	char _Chunk[CHUNK_BYTE];
	uint32 _LastByte;
	uint32 _TotalByte;
	uint32 _k[CHUNK_BYTE];
	static int _LeftShift[CHUNK_BYTE];

	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};