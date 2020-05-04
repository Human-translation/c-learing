#include <iostream>
#include "MD5.h"
#include <math.h>
#include <fstream>

MD5::MD5()
{
	Init();
}

int MD5::_LeftShift[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

void MD5::Init()
{
	for (int i = 0; i < CHUNK_BYTE; ++i)
	{
		_k[i] = static_cast<uint32>(pow(2,32) * abs(sin(i + 1)));
	}
	Reset();
}

void MD5::Reset()
{
	_a = 0x67452301;
	_b = 0xefcdab89;
	_c = 0x98badcfe;
	_d = 0x10325476;

	_LastByte = _TotalByte = 0;
}

void MD5::CalMd5(uint32* Chunk)
{
	uint32 a = _a, b = _b, c = _c, d = _d;
	uint32 f, g;
	for (int i = 0; i < CHUNK_BYTE; ++i)
	{
		if (i >= 0 && i <= 15)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (i >= 16 && i <= 31)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i <= 47)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		int tmp = d;
		d = c;
		c = b;
		b = b + LeftShift(a + f + Chunk[i] + _k[i], _LeftShift[i]);
		a = d;
	}
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}

void MD5::CalFinalMd5()
{
	char* p = _Chunk + _LastByte;
	*p++ = 0x80;
	int SurplusByte = CHUNK_BYTE - _LastByte - 1;
	if (SurplusByte < 8)
	{
		memset(p, 0, SurplusByte);
		CalMd5((uint32*)_Chunk);
		memset(p, 0, CHUNK_BYTE);
	}
	else
	{
		memset(p, 0, SurplusByte);
	}
	unsigned long long TotalByte = _TotalByte * 8;
	((unsigned long long*)_Chunk)[7] = TotalByte;
	CalMd5((uint32*)_Chunk);
}

std::string MD5::ChangeHex(uint32 n)
{
	static std::string StrMap = "0123456789abcdef";
	std::string ret;
	for (int i = 0; i < 4; ++i)
	{
		int CurByte = (n >> (i * 8)) & 0xff;
		std::string CurRet;
		CurRet += StrMap[CurByte / 16];
		CurRet += StrMap[CurByte % 16];
		ret += CurRet;
	}
	return ret;
}

std::string MD5::GetStringMd5(const std::string& str)
{
	if (str.empty())
	{
		return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
	}
	_TotalByte = str.size();
	uint32 ChunkNum = _TotalByte / CHUNK_BYTE;
	const char* Str = str.c_str();
	for (int i = 0; i < ChunkNum; ++i)
	{
		memcpy(_Chunk, Str + i * CHUNK_BYTE, CHUNK_BYTE);
		CalMd5((uint32*)_Chunk);
	}
	_LastByte = _TotalByte % CHUNK_BYTE;
	memcpy(_Chunk, Str + ChunkNum * CHUNK_BYTE, _LastByte);
	CalFinalMd5();
	return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
}

std::string MD5::GetFileMd5(const char* FilePath)
{
	std::fstream fin(FilePath, std::fstream::binary);
	if (!fin.is_open())
	{
		std::cout << FilePath << std::endl;
		perror("File open failed!");
		return "";
	}
	while (!fin.eof())
	{
		fin.read(_Chunk, CHUNK_BYTE);
		if (CHUNK_BYTE != fin.gcount())
			break;
		_TotalByte += CHUNK_BYTE;
		CalMd5((uint32*)_Chunk);
	}
	_LastByte = fin.gcount();
	_TotalByte += _LastByte;
	CalFinalMd5();
	return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
}

int main()
{
	MD5 m;
	std::string s = "aaaaaaaaaaaaaa";
	std::cout<<m.GetStringMd5(s);
	return 0;
}