#ifndef PATH_H
#define PATH_H
#include <string>
#include <fstream>

std::string path="D:\\Embarcadero\\Win32\\ѧ���ɼ�����\\";

std::string getCurrentUsername(){
	std::string currentUsername;
	std::ifstream file(path+"temp.txt");
	file>>currentUsername;
	file.close();
	 return currentUsername;
 }

std::string getPath(){return path;}
#endif
