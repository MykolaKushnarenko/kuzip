#pragma once

#include <ikuzip_base.h>


//! класс дл€ ввода и вывода одновременно
/*!
 данные пишем либо по месту расположени€ либо в конец файла в зависимости от ключей компил€ции

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

