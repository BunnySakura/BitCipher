/*
1.获取程序当前所在目录
2.遍历当前目录及子目录所有文件并输出文件绝对路径
3.确定需要进行的操作:加密/解密
4.调用"EnAndDecryption"类的Encryption方法进行加密,Decryption方法解密
  使用for循环遍历进行操作
*/
#include"Bitmap.h"

int main()
{
	cout << "使用方法：将软件放到需要加/解密的文件的同目录下" << endl <<
		"单个文件最大支持2GB!" << endl <<
		"不选择保存目录默认保存到软件同目录下的BitMap文件夹!" << endl << endl;

	int i;
	string file_suffix;
	string folder_path;
	TCHAR szBuffer[255] = { 0 };
	folder_path = SelectWindow(szBuffer) + '\\';

	if (0 != _access(folder_path.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		if (_mkdir(folder_path.c_str()) != 0)return -1;		// 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}

	cout << "加密请输: 0 ,解密请输: 1 !" << endl;
	cin >> i;
	while (i != 0 && i != 1)
	{
		cout << "请重新输入！！！" << endl;
		cin >> i;
	}

	cout << endl <<
		"以小写形式输入文件后缀" << endl <<
		"如txt,jpg,png,zip,匹配多种格式的通配符‘*’等" << endl <<
		"完成后请确认文件数量，如果数量不对，那么请重试！！！" << endl;
	cin >> file_suffix;

	switch (i)
	{
	case 0:
		FileProcessIn(file_suffix, folder_path);
		break;
	default:
		FileProcessOut(file_suffix, folder_path);
	}

	system("PAUSE");
	return 0;
}