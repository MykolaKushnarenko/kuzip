#include "iokuzip.h"
#include "zip_stuct.h"
#include <stdexcept>

using namespace std;

iokuzip::iokuzip(const char* p): ifstream(p,ios::in|ios::binary)
{
	read_central_directory(*this);
}


iokuzip::~iokuzip()
{
}

void iokuzip::P(const char* name)
{
	input_file_info it = info.at(name);
	seekg(it.pos);
	len = static_cast<unsigned>(it.end - it.pos);
}

unsigned iokuzip::filesize() const 
{
	return len;
}