#include "okuzip.h"
#include <iostream>
#include <vector>
#include "zip_stuct.h"

using namespace std;

okuzip::okuzip(const char* p) :ostream(&buff), firstfile(1)
{
	buff.open(p, ios::out | ios::binary);
	buff.crc = 0;
}

okuzip::~okuzip() 
{
	info.end = tellp();
	if (files.empty()) { return; }
	push_info();
	Central_directory cd;
	ios::streampos beg_of_cd = tellp();
	for (recinfo inf : files)
	{
		cd.Compressed_size = inf.end - inf.data_beg;
		cd.Uncompressed_size = cd.Compressed_size;
		cd.Filename_length = inf.filename.size();
		cd.localFileHeaderOffset = inf.beg;
		cd.CRC_32 = inf.crc_32;
		write((char*)&cd, sizeof(cd));
		write(inf.filename.c_str(), cd.Filename_length);
	}
	ios::streampos end_of_cd = tellp();
	EOCD eocd;
	eocd.Size = end_of_cd - beg_of_cd;
	eocd.ntot = (short)files.size();
	eocd.Ntot = eocd.ntot;
	eocd.Offset = beg_of_cd;
	write((char*)&eocd, sizeof(eocd));
}

void okuzip::push_info() 
{
	unsigned file_len = unsigned(info.end - info.data_beg);
	info.crc_32 = buff.crc;
	seekp(info.beg + offsetof(Local_file_header, CRC_32));
	write((char*)&info.crc_32, sizeof(unsigned));
	write((char*)&file_len, sizeof(unsigned));
	write((char*)&file_len, sizeof(unsigned));
	buff.crc = 0;
	seekp(info.end);
	files.push_back(info);
}

void okuzip::P(const char* p)
{
	Local_file_header hdr;
	info.end = tellp();
	if (!firstfile)
	{
		push_info();
	}
	hdr.Filename_length = strlen(p);
	info.filename = p;
	info.beg = tellp();
	this->write((char*)&hdr, sizeof(hdr));
	this->write(p, hdr.Filename_length);
	info.data_beg = tellp();
	firstfile = 0;
	buff.crc = 0;
}