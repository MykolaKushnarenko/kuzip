#pragma once
#include <CString>
using namespace std;
#pragma pack(push, 1)
class Local_file_header
{
public:
	unsigned signature;//0x04034b50
	short Version;
	short flags;
	short Compression_method;
	short  Last_mod_file_time;
	short  Last_mod_file_date;
	unsigned  CRC_32;
	unsigned  Compressed_size;// (n)
	unsigned  Uncompressed_size;
	short  Filename_length;// (f)
	short  Extra_field_length;// (e)
	Local_file_header() { memset(this, 0, sizeof(Local_file_header)); signature = 0x04034b50; Compression_method = 0; Version = 10; }
};

class Central_directory
{
public:
	unsigned signature;// (0x02014b50)
	short Version_made_by;
	short Version_needed_to_extract;
	short flags;
	short Compression_method;
	short Last_mod_file_time;
	short Last_mod_file_date;
	unsigned  CRC_32;
	unsigned  Compressed_size;// (n)
	unsigned  Uncompressed_size;
	short Filename_length;//(f)
	short Extra_field_length;//(e)
	short File_comment_length;//(c)
	short Disk_number_start;
	short Internal_file_attributes;
	unsigned External_file_attributes;
	unsigned localFileHeaderOffset;
	Central_directory() {
		memset(this, 0, sizeof(Central_directory)); signature = 0x02014b50;
		Version_made_by = 63;
		Version_needed_to_extract = 10;
		External_file_attributes = 32;
	}
};

const int EOCD_SIG = 0x06054b50;
class EOCD
{
public:
	unsigned signature;// (0x06054b50);
	short  disk_Number;//Number_of_this_disk
	short  r_disk_Number;// of the disk with the start of the central directory;
	short  ntot;//Central Directory on this disk;
	short  Ntot;// Central Directory
	unsigned  Size;//Size of the central directory;
	unsigned  Offset;//Offset of start of central directory with respect to the starting disk number;
	short  comment_length;// (c)
	EOCD() { memset(this, 0, sizeof(EOCD)); signature = EOCD_SIG; }
	bool ok() const {return signature == EOCD_SIG;}
};

#pragma pack(pop)

template<typename T>
void fwr(ofstream& s, T& obj)
{
	s.write((char*)&obj, sizeof(T));
}

template<typename T>
void frd(ifstream& s, T& obj)
{
	s.read((char*)&obj, sizeof(T));
}
