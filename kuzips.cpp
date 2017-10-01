
#include <iostream>
#include "okuzip.h"
#include "ikuzip.h"
#include <assert.h>

using namespace std;

int main() 
{
	{
		okuzip s("a.zip");
		s.P("aaa/file_a");
		s << "|aaa|";
		s.P("aaa/file_b");
		s << "|bbbbb|";
		s.P("aaa/file_c");
		s << "|cccccccccccc|";
	}
	{
		ikuzip s("a.zip");
		unsigned siz;
		char* buf;

		s.P("aaa/file_b");
		siz = s.filesize();
		buf=new char[siz+1];
		s.read(buf, siz);
		buf[siz] = 0;
		assert(string(buf)== "|bbbbb|");
		delete [] buf;

		s.P("aaa/file_a");
		siz = s.filesize();
		buf = new char[siz + 1];
		s.read(buf, siz);
		buf[siz] = 0;
		assert(string(buf) == "|aaa|");
		delete[] buf;

		s.P("aaa/file_c");
		siz = s.filesize();
		buf = new char[siz + 1];
		s.read(buf, siz);
		buf[siz] = 0;
		assert(string(buf) == "|cccccccccccc|");
		delete[] buf;
	}
	return 0;
}