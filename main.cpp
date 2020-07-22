/*
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\pixiv\\qidian.png", ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}

//'\r' 回车，回到当前行的行首，而不会换到下一行，如果接着输出的话，本行以前的内容会被逐一覆盖；

//'\n' 换行，换到当前位置的下一行，而不会回到行首；

*/

/*
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\new.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}
*/

/*
1.获取程序当前所在目录
2.遍历当前目录及子目录所有文件并输出文件绝对路径
3.确定需要进行的操作:加密/解密
4.调用"inout"类的in方法进行加密,out方法解密
  使用for循环遍历进行操作
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <io.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex>

using namespace std;

class inout
{
public:
	bool in(const char *str1, const char* str2);
	bool out(const char* str1, const char* str2);

private:

};

bool inout::in(const char *str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot in file." << endl;
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot out file." << endl;
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return true;

//'\r' 回车，回到当前行的行首，而不会换到下一行，如果接着输出的话，本行以前的内容会被逐一覆盖；

//'\n' 换行，换到当前位置的下一行，而不会回到行首；

}

bool inout::out(const char* str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot in file." << endl;
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot out file." << endl;
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}

/*
返回目录及子目录路径的函数,由于无法解决循环往字符串输出路径字符串而搁置
采用标准命名,重命名所有文件,对照list.txt进行替代方案
此方案非个人认为最佳解决方案,以标准命名使得文件名有迹可循,借由循环可以批量加密解密
重命名方案失败,暂时无法解决,搁置,留待以后再议

此方案为弃案.搁置不用,仅遗留问题留待日后解决
#define MAX_PATH 80
void getFiles(string path, string path2, vector<string>& files);
*/

void dir0(const char* str1);
void dir1(const char* str1);


int main()
{
	int i;
	char str[8];

	string folderPath = ".\\BitMap";

	if (0 != _access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}

	cout << "加密请输: 0 ,解密请输: 1 !" << endl;
	cin >> i;
	while (i != 0 && i != 1)
	{
		cout << "请重新输入!" << endl;
		cin >> i;
	}

	cout << "以小写形式输入文件格式" << endl << "如txt,jpg,png,zip等!" << endl;
	cin >> str;

	/* 正则匹配字符串失败,又觉得没有大用,索性放弃
		std::regex reg("^[0-9a-zA-Z]+$");
	bool bValid = std::regex_match(str, reg);

	while (bValid != true)
	{
		cout << "请重新输入!" << endl;
		cin >> str;
	}
	*/

	switch (i)
	{
	case 0:
		dir0((const char*)str);
		break;
	default :
		dir1((const char*)str);
	}

	/*
	vector<string> files;
	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	string filePath;
	filePath.assign(buffer).append("\\");
		////获取该路径下的所有文件
		getFiles(filePath, "", files);
	char str[30];
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
	*/
	
	return 0;
}
/*
void getFiles(string path, string path2, vector<string>& files)
{
	//文件句柄
	long hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p, p2;
	if ((hFile = _findfirst(p.assign(path).append(path2).append("*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "…") != 0)
					getFiles(p.assign(path).append("\\"),p2.assign(fileinfo.name).append("\\"), files );
			}
			else
			{
				files.push_back(p.assign(path2).append(fileinfo.name)); //这一行可以给出相对路径
				//files.push_back(p.assign(fileinfo.name) ); //这一行可以给出文件名
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


*/

//加密
void dir0(const char* str1) {
	int i,j;
	intptr_t Handle;
	inout pic;
	char str0[10]="*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;
	char filename[20];
	struct _finddata_t FileInfo;

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		//组成绝对路径,使用"安全"的strcat_s,失败!
		//strcat_s((char*)str2, sizeof(str2) + 1, FileInfo.name);
		//printf(str2);
		char str[20] = ".\\BitMap\\%d.";
		strcat_s(str, sizeof(str), str1);
		i = 1;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		pic.in(FileInfo.name, filename);
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 2;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//指定文件名为从2开始的整数，每次加1
			j = j + 1;
			pic.in(FileInfo.name, filename);
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}

//解密
void dir1(const char* str1) {
	int i,j;
	intptr_t Handle;
	inout pic;
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;
	char filename[20];
	struct _finddata_t FileInfo;

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		char str[20] = ".\\BitMap\\%d.";
		strcat_s(str, sizeof(str), str1);
		i = 0;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		pic.out(FileInfo.name, filename);
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 1;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//指定文件名为从1开始的整数，每次加1
			j = j + 1;
			pic.out(FileInfo.name, filename);
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
	//遗留代码,tmd有用,解密只能从0号文件开始,然后绝壁多一个莫名其妙的文件
	//用来移除这个文件的,不从零号文件开始,会无法解密...gank
	sprintf_s((char*)filename, sizeof(filename), "%d.jpg", j+1);
	remove(filename);
}