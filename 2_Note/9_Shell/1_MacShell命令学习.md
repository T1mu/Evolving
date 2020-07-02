# StudyNotes-iTerm
学习笔记之--iterm终端命令操作

标签
===

新建标签：command + t

关闭标签：command + w

切换全屏：command + enter

查找：command + f

分屏
===
垂直分屏：command + d

水平分屏：command + shift + d

切换屏幕：**command** + **option** + 方向键 / `command + [ 或 command + ]`

查看历史命令：command + ;

查看剪贴板历史：command + shift + h

** 其他**

清除当前行：ctrl + u

到行首：ctrl + a

到行尾：ctrl + e

前进后退：ctrl + f/b (相当于左右方向键)

上一条命令：ctrl + p

搜索命令历史：ctrl + r

删除当前光标的字符：ctrl + d

删除光标之前的字符：ctrl + h

删除光标之前的单词：ctrl + w

删除到文本末尾：ctrl + k

交换光标处文本：ctrl + t

清屏1：command + r

清屏2：ctrl + l

## 自带有哪些很实用的功能/快捷键

⌘ + 数字在各 tab 标签直接来回切换

选择即复制 + 鼠标中键粘贴，这个很实用

⌘ + f 所查找的内容会被自动复制

⌘ + d 横着分屏 / ⌘ + shift + d 竖着分屏

⌘ + r = clear，而且只是换到新一屏，不会想 clear 一样创建一个空屏

ctrl + u 清空当前行，无论光标在什么位置

输入开头命令后 按 ⌘ + ; 会自动列出输入过的命令

⌘ + shift + h 会列出剪切板历史

可以在 Preferences > keys 设置全局快捷键调出 iterm，这个也可以用过 Alfred 实现

## 常用的一些快捷键

⌘ + 1 / 2 左右 tab 之间来回切换，这个在 前面 已经介绍过了

⌘← / ⌘→ 到一行命令最左边/最右边 ，这个功能同 C+a / C+e

⌥← / ⌥→ 按单词前移/后移，相当与 C+f / C+b，其实这个功能在Iterm中已经预定义好了，⌥f / ⌥b，看个人习惯了

好像就这几个

设置方法如下

当然除了这些可以自定义的也不能忘了 linux 下那些好用的组合

C+a / C+e 这个几乎在哪都可以使用

C+p / !! 上一条命令

C+k 从光标处删至命令行尾 (本来 C+u 是删至命令行首，但iterm中是删掉整行)

C+w A+d 从光标处删至字首/尾

C+h C+d 删掉光标前后的自负

C+y 粘贴至光标后

C+r 搜索命令历史，这个较常用

**## 选中即复制**
### **iterm2 有 2 种好用的选中即复制模式。**

    一种是用鼠标，在 iterm2 中，选中某个路径或者某个词汇，那么，iterm2 就自动复制了。 　　
    另一种是无鼠标模式，command+f,弹出 iterm2 的查找模式，输入要查找并复制的内容的前几个字母，确认找到的是自己的内容之后，输入 tab，查找窗口将自动变化内容，并将其复制。如果输入的是 shift+tab，则自动将查找内容的左边选中并复制。

**## 自动完成**

输入打头几个字母，然后输入 command+; iterm2 将自动列出之前输入过的类似命令。

 　　
**## 剪切历史**

输入 command+shift+h，iterm2 将自动列出剪切板的历史记录。如果需要将剪切板的历史记录保存到磁盘，在 Preferences > General > Save copy/paste history to disk 中设置。

Posted by 陈斌彬 Jun 20th, 2015 9:43 am mac 



==================================================================================
==================================================================================

终端操作，在iTerm里


**## 来源：http://www.jianshu.com/p/3291de46f3ff**

# **Mac 终端命令大全**

## **目录操作**
命令名 	功能描述 	使用举例
mkdir 	创建一个目录 	mkdir dirname  
rmdir 	删除一个目录 	rmdir dirname  
mvdir 	移动或重命名一个目录 	mvdir dir1 dir2  
cd 	改变当前目录 	cd dirname  
pwd 	显示当前目录的路径名 	pwd  
ls 	显示当前目录的内容 	ls -la  
dircmp 	比较两个目录的内容 	dircmp dir1 dir2   

## **文件操作**
命令名 	功能描述 	使用举例  
cat 	显示或连接文件 	cat filename  
pg 	分页格式化显示文件内容 	pg filename  
more 	分屏显示文件内容 	more filename  
od 	显示非文本文件的内容 	od -c filename  
cp 	复制文件或目录 	cp file1 file2  
rm 	删除文件或目录 	rm filename  
mv 	改变文件名或所在目录 	mv file1 file2  
ln 	联接文件 	ln -s file1 file2  
find 	使用匹配表达式查找文件 	find . -name "*.c" -print  
file 	显示文件类型 	file filename  
open 	使用默认的程序打开文件 	open filename  

## **选择操作**
命令名 	功能描述 	使用举例  
head 	显示文件的最初几行 	head -20 filename  
tail 	显示文件的最后几行 	tail -15 filename  
cut 	显示文件每行中的某些域 	cut -f1,7 -d: /etc/passwd  
colrm 	从标准输入中删除若干列 	colrm 8 20 file2  
paste 	横向连接文件 	paste file1 file2  
diff 	比较并显示两个文件的差异 	diff file1 file2  
sed 	非交互方式流编辑器 	sed "s/red/green/g" filename  
grep 	在文件中按模式查找 	grep "^[a-zA-Z]" filename  
awk 	在文件中查找并处理模式 	awk '{print $1 $1}' filename  
sort 	排序或归并文件 	sort -d -f -u file1  
uniq 	去掉文件中的重复行 	uniq file1 file2  
comm 	显示两有序文件的公共和非公共行 	comm file1 file2  
wc 	统计文件的字符数、词数和行数 	wc filename  
nl 	给文件加上行号 	nl file1 >file2   

## **安全操作**
命令名 	功能描述 	使用举例  
passwd 	修改用户密码 	passwd  
chmod 	改变文件或目录的权限 	chmod ug+x filename    
umask 	定义创建文件的权限掩码 	umask 027  
chown 	改变文件或目录的属主 	chown newowner filename  
chgrp 	改变文件或目录的所属组 	chgrp staff filename  
xlock 	给终端上锁 	xlock -remote   

## **编程操作**
命令名 	功能描述 	使用举例  
make 	维护可执行程序的最新版本 	make  
touch 	更新文件的访问和修改时间 	touch -m 05202400 filename  
dbx 	命令行界面调试工具 	dbx a.out  
xde 	图形用户界面调试工具 	xde a.out   

## **进程操作**

|命令名|功能描述|使用举例|
|-----|------|--------|
|ps |显示进程当前状态|ps u|
kill 	|终止进程 |	kill -9 30142
nice |	改变待执行命令的优先级| 	nice cc -c *.c
renice |	改变已运行进程的优先级 	|renice +20 32768 

## **时间操作**
命令名 	功能描述 	使用举例
date 	显示系统的当前日期和时间 	date
cal 	显示日历 	cal 8 1996
time 	统计程序的执行时间 	time a.out 

## **网络与通信操作**
命令名 	功能描述 	使用举例
telnet 	远程登录 	telnet hpc.sp.net.edu.cn
rlogin 	远程登录 	rlogin hostname -l username
rsh 	在远程主机执行指定命令 	rsh f01n03 date
ftp 	在本地主机与远程主机之间传输文件 	ftp ftp.sp.net.edu.cn
rcp 	在本地主机与远程主机 之间复制文件 	rcp file1 host1:file2
ping 	给一个网络主机发送 回应请求 	ping hpc.sp.net.edu.cn
mail 	阅读和发送电子邮件 	mail
write 	给另一用户发送报文 	write username pts/1
mesg 	允许或拒绝接收报文 	mesg n 

## **Korn Shell 命令**
命令名 	功能描述 	使用举例
history 	列出最近执行过的 几条命令及编号 	history
r 	重复执行最近执行过的 某条命令 	r -2
alias 	给某个命令定义别名 	alias del=rm -i
unalias 	取消对某个别名的定义 	unalias del

## **其它命令**
命令名 	功能描述 	使用举例
uname 	显示操作系统的有关信息 	uname -a
clear 	清除屏幕或窗口内容 	clear
env 	显示当前所有设置过的环境变量 	env
who 	列出当前登录的所有用户 	who
whoami 	显示当前正进行操作的用户名 	whoami
tty 	显示终端或伪终端的名称 	tty
stty 	显示或重置控制键定义 	stty -a
du 	查询磁盘使用情况 	du -k subdir
df 	显示文件系统的总空间和可用空间 	df /tmp
w 	显示当前系统活动的总信息 	w