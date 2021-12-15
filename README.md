# BitMap
*全文件格式加密/解密软件*

------------

**多线程重构优化版，以损失一定的稳定性为代价，大幅提升了效率**
## 使用方法：
### 1.将需要加密/解密的文件和程序放到同一个文件夹内

### 2.在弹出窗口中选择输出文件想要保存的目录；
![image](https://user-images.githubusercontent.com/48341563/146028621-9a285648-f074-418d-a4de-478365daa4ea.png)
> 点确定选择目录，点取消则选择默认“BitMap”目录

### 3.输入‘0’回车进行加密操作；输入‘1’回车进行解密操作；
![image](https://user-images.githubusercontent.com/48341563/146029297-2a563057-c483-4d47-b7af-fb7a4469a324.png)

### 4.以小写形式输入文件后缀
![image](https://user-images.githubusercontent.com/48341563/146029857-07e741f6-eea4-4493-9239-9b9e87ed0ee8.png)
> 例如此处我输入的png

### 5.回车确认，等待加密/解密完成
![image](https://user-images.githubusercontent.com/48341563/146030054-c85c08a9-63d1-4ca2-bf0b-087b4b0c3dce.png)
> 完成后的文件在所选的目录中

### *解密的步骤相同*

------------

## 注意：
#### 1.单个文件最大允许2GB，推荐值为1GB左右！
#### 2.文件处理完毕后需要清点一下数量及大小！由于采取了多线程，所以有竞争风险会导致文件输出冲突。如果数量或者大小不对，重试即可。

## 引用：
[ThreadPool.h](https://github.com/progschj/ThreadPool "ThreadPool.h")

# 可能会增加的优化：
##### 1.支持跨平台
##### 2.优化文件列表获取，目前调用WindowsAPI获取太慢，浪费时间
##### 3.图形化界面？
