#pragma once

#include <fstream>
#include <map>

class input_file_info
{
public:
	std::streampos pos;
	std::streampos end;
};

class ikuzip_base
{
protected:
	std::map<std::string, input_file_info> info;// информация о всеех файлах в архиве
	unsigned len;
    void read_central_directory(std::ifstream& s);
};

