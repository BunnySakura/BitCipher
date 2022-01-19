import tkinter as tk
from tkinter.filedialog import askdirectory  # 用于选择文件夹
from tkinter import ttk  # 用于进度条
import subprocess  # 用于执行系统命令
import threading  # 多线程


# TODO：
# √ 1.进度条
# 2.随窗口变化的控件
# √ 3.底部增设重试，退出按钮
# 4.美化UI
# 5.优化遍历文件的方法
# 6.修改为控制台运行,给予两个路径参数，一个线程池线程数量参数，且输入'q'能中断运行
# 7.开启检查更新功能


class BitMapGUI(tk.Frame):
    def __init__(self, master=None):
        """
        初始化窗口

        :param master:父窗口
        """
        tk.Frame.__init__(self, master)
        self.directory_input = tk.StringVar(value="请选择待处理文件所在路径")  # 输入路径
        self.directory_output = tk.StringVar(value="请选择处理后文件保存路径")  # 输出路径
        self.log_output = None  # 输出日志的文本控件
        self.progress_bar = None  # 进度条
        self.master.title('BitMap文件处理')  # 窗口标题
        self.grid(sticky=tk.N + tk.S + tk.E + tk.W)  # 窗口控件居中
        self.create_widgets()  # 创建窗口
        self.mainloop()  # 主循环

    @staticmethod
    def select_path(dir_path):
        """
        选择路径

        :param dir_path: tk.StringVar方法，即可变字符串
        :return: 所选路径
        """
        get_path = askdirectory()
        get_path.replace('/', '\\')
        dir_path.set(get_path)

    def __do_bitmap(self):
        """
        调用C++程序并获取输出更新到Text控件

        :return: 无
        """
        import multiprocessing  # 获取CPU逻辑处理器数量
        cmd = "BitMap核心程序.exe " \
              + self.directory_input.get().replace('/', '\\') + ' ' \
              + self.directory_output.get().replace('/', '\\') + ' ' \
              + str(multiprocessing.cpu_count() - 2)  # 调用程序本体的指令
        self.results = subprocess.Popen(cmd, shell=False, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                                        stderr=subprocess.PIPE, universal_newlines=True)
        self.progress_bar.start()  # 开始进度条滚动
        for i in iter(self.results.stdout.readline, "GBK"):
            self.log_output.insert(tk.INSERT, i)
            self.log_output.see(tk.END)
            self.update()  # 此上三行将程序本体的输出插入到Text控件并刷新
            print(i)
            if self.results.poll() or not i:  # 检测线程是否完毕或输出是否为空
                self.results.terminate()  # 停止线程
                self.progress_bar.stop()  # 停止进度条滚动
                break
        print("finally----->")
        self.progress_bar.stop()  # 停止进度条滚动

    def do_bitmap(self):
        """
        开始并分离线程避免阻塞GUI主线程

        :return: 无
        """
        detach_thread = threading.Thread(target=self.__do_bitmap, args=())
        detach_thread.setDaemon(True)  # 设置后台进程
        detach_thread.start()

    def redo_bitmap(self):
        """
        重做

        :return: 无
        """
        self.results.terminate()
        self.log_output.delete("1.0", "end")  # 清空Text控件
        self.do_bitmap()

    def quit_bitmap(self):
        """
        退出

        :return: 无
        """
        try:
            self.results.terminate()
        except AttributeError:
            pass
        self.quit()

    def create_widgets(self):
        """
        创建窗口并协调布局

        :return: 无
        """
        tk.Tk.resizable(self.master, False, False)  # 固定窗口大小
        tk.Label(self, text="文件输入：").grid(row=0, column=0, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Entry(self, textvariable=self.directory_input).grid(row=0, column=1, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Button(self, text="选择目录", command=lambda: self.select_path(self.directory_input)).grid(row=0, column=2,
                                                                                                  sticky=tk.N + tk.E + tk.S + tk.W)
        # Button部件command参数的回调函数，如果函数不带参数，直接使用函数名。如果函数带参数，需要使用lambda:function(参数表)的格式。
        tk.Label(self, text="文件输出：").grid(row=1, column=0, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Entry(self, textvariable=self.directory_output).grid(row=1, column=1, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Button(self, text="选择目录", command=lambda: self.select_path(self.directory_output)).grid(row=1, column=2,
                                                                                                   sticky=tk.N + tk.E + tk.S + tk.W)

        tk.Button(self, text="开始处理", command=self.do_bitmap).grid(row=2, column=1)
        self.log_output = tk.Text(self)  # 日志输出控件
        self.log_output.grid(row=3, column=0, rowspan=10, columnspan=3)  # 控件占满3-12行，0-2列
        self.progress_bar = ttk.Progressbar(self, mode="indeterminate", orient=tk.HORIZONTAL)  # 进度条控件
        self.progress_bar.grid(row=13, column=0, columnspan=3, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Button(self, text="重试", command=self.redo_bitmap).grid(row=14, column=0, sticky=tk.N + tk.E + tk.S + tk.W)
        tk.Button(self, text="退出", command=self.quit_bitmap).grid(row=14, column=2, sticky=tk.N + tk.E + tk.S + tk.W)


app_window = BitMapGUI()  # 实例化
