#include "ikuzip.h"
#include "zip_stuct.h"
#include <stdexcept>

using namespace std;


ikuzip::ikuzip(const char* p): ifstream(p,ios::in|ios::binary)
{
	read_central_directory(*this);
}


ikuzip::~ikuzip()
{
}

void ikuzip::P(const char* name)
{
	input_file_info it = info.at(name);
	seekg(it.pos);
	len = static_cast<unsigned>(it.end - it.pos);
}

unsigned ikuzip::filesize() const 
{
	return len;
}