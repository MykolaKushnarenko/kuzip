#pragma once
#include <vector>
#include <fstream>
#include "crc32.h"
#include "zip_stuct.h"

//using namespace std;

struct recinfo
{
	ios::streamoff beg, data_beg, end;
	std::string filename;
	unsigned crc_32;
};

class Tmy_streambuff :public filebuf
{
public:
	unsigned crc;
	streamsize xsputn(const char* s, streamsize n) override
	{
		crc = crc32(crc, (unsigned char*)s, n);
		return filebuf::xsputn(s, n);
	}
};

class okuzip :public ostream
{
	unsigned data_begin;
	std::vector<recinfo> files;
	recinfo info;
	bool firstfile;
	Tmy_streambuff buff;

public:
	okuzip(const char* p);
	~okuzip();
	void push_info();
	void P(const char* p);
};