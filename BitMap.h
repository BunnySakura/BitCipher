#pragma once
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "io.h"					//��FileProcess.cpp�����ڻ�ȡĿ¼���ļ���
#include "direct.h"				//��main.cpp�����ڴ���BitMapĿ¼
#include <shlobj.h>				//��SelectDirectory.cpp���ڿ���Ŀ¼ѡ�񴰿�
#include "ThreadPool.h"

using namespace std;

//���ܳ�Ա����
int Encryption(string file_in, string file_out);
//���ܳ�Ա����
int Decryption(string file_in, string file_out);


//�ļ�����:���ܺ���
void FileProcessIn(string file_suffix,string folder_path);
//�ļ�����:���ܺ���
void FileProcessOut(string file_suffix,string folder_path);


//Ŀ¼ѡ�񴰿�
string SelectWindow(TCHAR szBuffer[255]);