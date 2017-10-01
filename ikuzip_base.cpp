#include "ikuzip.h"
#include "zip_stuct.h"
#include <stdexcept>

using namespace std;

void ikuzip_base::read_central_directory(std::ifstream& s)
{
	char filename[FILENAME_MAX];
	EOCD eocd;
	s.seekg(-sizeof(EOCD), ios::end);
	frd(s, eocd);
	if (!eocd.ok()) { throw runtime_error("fail eocd check"); }
	s.seekg(eocd.Offset);
	Central_directory cd;
	input_file_info rec;
	for (int i = 0; i < eocd.ntot; ++i) 
	{
		frd(s, cd);
		s.read(filename, cd.Filename_length);
		filename[cd.Filename_length] = 0;
		rec.pos = cd.localFileHeaderOffset + sizeof(Local_file_header) + cd.Filename_length;
		rec.end = ((unsigned)(rec.pos) + cd.Compressed_size);
		info[filename] = rec;
	}

}
