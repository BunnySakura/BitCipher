# BitMap-GUI
*全文件格式加密/解密软件。(Full file format encryption / decryption software.)*

------------

## 本次更新内容
1. 增加了图形化窗口；
2. 使用C++17新的`filesystem`优化了遍历文件的步骤；
3. 优化了代码逻辑；
4. 改进了文件读写操作，进行10MB的分块读写，大大降低了内存占用，且基本没有了文件大小的限制；

## 使用方法
**加密和解密步骤相同**
### 1. 下载程序压缩包并解压
> ![image](https://user-images.githubusercontent.com/48341563/150064951-433f23c0-971d-4690-b168-ecc776ca561d.png)

**[下载](https://github.com/BunnySakura/BitMap-FileEncryption/releases "下载")** 并解压，解压后的文件如上图所示：  
上面是图形化操作界面，下面是命令行操作界面，二者互相配合使用，故需放在**同一目录**下。

### 2. 双击BitMapGUI.exe，并调整对应参数，点击“开始处理”
![image](https://user-images.githubusercontent.com/48341563/150065597-a718c6ea-169e-4c11-84f7-33d7853b0912.png)
- `文件输入`：需要进行加密/解密的文件所在的文件夹
- `文件输出`：处理完成的文件的保存路径

### 3. 进度条开始移动，等待处理完成，进度条停止移动
![image](https://user-images.githubusercontent.com/48341563/150066406-28261aeb-a3ec-4ebf-92b8-f0a35759b86d.png)

------------

## 注意
- 本程序会对子目录的文件进行递归处理，并在目标目录生成相同的目录结构。**请确认选择的路径下只有待处理的文件，避免覆盖了其他文件！**
- 文件处理完毕后，输出的文件总大小应该和输入的相等，且文件和文件夹数量均对应，否则就是处理失败，需要 **`重试`**。
- 本次优化后，在文件处理完成后基本上不会出现文件处理失败，不输出有效文件的情况。但是程序嘛，就像酒吧永远都有概率发生顾客点了一份炒饭的事，无法避免发生问题。尽管我已经进行了较为周密的测试，但是不排除仍有遗漏。所以对于能够稳定复现的问题，可以提交 **[issue](https://github.com/BunnySakura/BitMap-FileEncryption/issues "issue")**，万分感谢你的支持。

## 思路
本程序主体为C++开发，接收命令行参数，调用方法为：
```bash
BitMap核心程序.exe <文件输入路径> <文件输出路径> <线程数>
```
**参数不可缺漏**，其中：
- `文件输入路径`：图形化界面的`文件输入`。
- `文件输出路径`：图形化界面的`文件输出`。
- `线程数`：即多线程处理文件所使用的线程数量，8核16线程CPU建议使用14线程以下，图形化界面默认给的是物理线程数减2。

图形化界面基于Python的`Tkinter`库开发，实际上就是给调用程序主体加上了一层封装，本质还是在用户配完参数后，转换为指令执行。

**VS2022开发环境部署**  
- C++语言标准选C++17，以调用`filesystem`
- 调试中命令参数可自行构造
- SDL检查选否，绕过`ThreadPool.h`的`result_of`报错，`result_of`是C++14的内容，之后弃用，暂未找到替代。

![image](https://user-images.githubusercontent.com/48341563/150073426-cabf4626-3834-420a-a8f1-dfc7022846fd.png)
![image](https://user-images.githubusercontent.com/48341563/150073436-ac03985d-4fef-420f-860b-583d6058ff0e.png)
![image](https://user-images.githubusercontent.com/48341563/150073472-8a006151-9471-4374-864b-2ee5f98730be.png)

## 引用
[ThreadPool.h](https://github.com/progschj/ThreadPool "ThreadPool.h")  
[文件处理方法](https://blog.csdn.net/bily_on/article/details/88597520 "文件处理方法")  