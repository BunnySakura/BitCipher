#pragma once
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "io.h"					//在FileProcess.cpp中用于获取目录下文件名
#include "direct.h"				//在main.cpp中用于创建BitMap目录
#include <shlobj.h>				//在SelectDirectory.cpp用于开启目录选择窗口
#include "ThreadPool.h"

using namespace std;

//加密成员函数
int Encryption(string file_in, string file_out);
//解密成员函数
int Decryption(string file_in, string file_out);


//文件处理:加密函数
void FileProcessIn(string file_suffix,string folder_path);
//文件处理:解密函数
void FileProcessOut(string file_suffix,string folder_path);


//目录选择窗口
string SelectWindow(TCHAR szBuffer[255]);