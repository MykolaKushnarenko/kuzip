#pragma once

#include <ikuzip_base.h>


//! ����� ��� ����� � ������ ������������
/*!
 ������ ����� ���� �� ����� ������������ ���� � ����� ����� � ����������� �� ������ ����������

*/
class iokuzip:public std::ifstream,public ikuzip_base
{
public:
    bool safe_mode;
	iokuzip(const char* p);
	~iokuzip();
	void P(const char*);
	unsigned filesize() const;
};

