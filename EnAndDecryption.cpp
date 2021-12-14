#include"BitMap.h"

int Encryption(string file_in, string file_out)
{
	ifstream file_read;
	file_read.open(file_in, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!file_read)
	{
		cout << file_in << "无法读取，请重试！！！！！！！！！" << endl;
		return 1;
	}
	//一次性读取整个文件
	stringstream buffer;
	buffer << file_read.rdbuf();
	string FileStr(buffer.str());
	for (int i = 0; i < FileStr.length(); i++) {
		FileStr[i] ^= char(0xFF);
		//file_write.put(FileStr[i] ^ char(0xFF));		//逐位输出，字符的二进制码为01100000，它与11111111作异或后变为10011111；
	}
	file_read.close();


	ofstream file_write;
	file_write.open(file_out, ios::binary);
	if (!file_write) {

		cout << file_out << "无法写入，请重试！！！！！！！！！" << endl;
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	file_write << FileStr;
	file_write.close();

	cout << file_in << "加密完成！" << endl;		//调试用

	return 0;
}

int Decryption(string file_in, string file_out)
{
	ifstream file_read;
	file_read.open(file_in, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!file_read)
	{
		cout << file_in << "无法读取，请重试！！！！！！！！！" << endl;
		return 1;
	}
	//一次性读取整个文件
	stringstream buffer;
	buffer << file_read.rdbuf();
	string FileStr(buffer.str());
	for (int i = 0; i < FileStr.length(); i++) {
		FileStr[i] ^= char(0xFF);
		//file_write.put(FileStr[i] ^ char(0xFF));		//逐位输出，字符的二进制码为01100000，它与11111111作异或后变为10011111；
	}
	file_read.close();


	ofstream file_write;
	file_write.open(file_out, ios::binary);
	if (!file_write) {

		cout << file_out << "无法写入，请重试！！！！！！！！！" << endl;
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	file_write << FileStr;
	file_write.close();

	cout << file_in << "解密完成！" << endl;		//调试用

	return 0;
}