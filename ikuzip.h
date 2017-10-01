#pragma once

#include <ikuzip_base.h>

class ikuzip:public std::ifstream,public ikuzip_base
{
public:
	ikuzip(const char* p);
	~ikuzip();
	void P(const char*);
	unsigned filesize() const;
};

