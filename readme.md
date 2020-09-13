## 一个微型c运行库的实现

#### 支持如下几个标准：

- 以ANIS C标准库的接口为目标，接口尽量一致
- 开发入口函数（mini_crt_entry）
- 基本进程操作(exit)
- 基本堆操作(malloc,free)
- 基本文件操作(fopen,fread,fwrite,fclose,fseek)
- 基本字符串操作(strcpy,strlen,strcmp)
- 基本格式化字符串和输出操作(printf,fprintf)
- 支持window平台

#### 入口函数

- 使用API，GetCommandLine获取命令行参数
- 初始化堆和IO
- 使用ExitProcess结束进程

#### 堆的实现

- 以空闲链表算法来管理堆
- 固定堆的大小为32MB
- 使用VirtualAlloc向系统申请32MB空间作为堆空间

#### IO与文件操作、

- 使用CreateFile,ReadFIle,WriteFile,CloseHandle,SetFilePointer实现fopen,fread,fwrite,fclose,fseek
- 支持stdin,stdout,stderr三个标准的输入输出
- 为简单起见不实现缓冲机制

#### 字符串操作

- 实现itoa,strcmp,strcpy,strlen

#### 格式化字符串和打印操作

- printf支持%d,%s,暂时不接受格式控制
- 实现fprintf,vfprintf,fputc,fputs



### 通过编译与静态库实现

```powershell
cl /c /DWIN32 /GS- entry.c malloc.c printf.c stdio.c string.c
lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:minicrt.lib
```



### 通过test.c文件进行测试

#### 编译链接test.c

```
cl /c /DWIN32 test.c
link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry
```

#### 运行test.exe

##### 成功