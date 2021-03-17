# VB DLL

VB调用DLL的参数类型匹配问题（一）

VB调用DLL的缺省调用方式是：传引用调用。即VB传一个指向参数变量的指针，DLL中便可以修改实际参数的值。若要传值方式，则需要在函数申明时在参数前加上ByVal关键字。
下面谈谈字符串调用的约定。 事实上对字符串无论是否使用ByVal关键字，在DLL中均可以修改传入的参数。但，用不用ByVal关键字，还是有区别的。因为VB与DLL接口支持两种类型的字符串，VB是用如下的规则来匹配类型的，若没用关键字ByVal，则传一个VB字符串句柄（数据类型为HLSTR），这种类型或字符串句柄只有专为VB设计的DLL才能识别。所以，通常的DLL如果不是专门为VB设计的，就只有用ByVal关键字了。因为加了ByVal关键字后，VB会在字符串尾加上Null字符，即自动将VB字符串转换成C-style字符串，然后将指向该串的指针传给DLL。

VB调用DLL关于参数的匹配问题（二）
这次谈谈VB与C语言的其他参数类型间的转换。包括布尔型、１６位整数、１６位无符号整数、８位有和无符号整数、３２位有和无符号整数、ＶＢ中Ｖａｒｉａｎｔ类型及结构指针等。
〈布尔量〉ＶＢ和Ｃ中都定义０为“假”，非０为“真”，但Ｃ语言逻辑表达式的结果用１表示“真”，而相应的ＶＢ返回－１做为“真”。这是二者的区别。
〈１６位符号整数〉Ｃ语言中的ｉｎｔ和ｓｈｏｒｔ类型与ＶＢ中的ｉｎｔｅｇｅｒ完全对应匹配，所以可以大胆使用。:)
〈１６位无符号整数〉ＶＢ中没有相应的类型，所以就存在转换的问题了。关键是对于从32768-65535这一区间的数如何处理。事实上可以用一个范围更大的类型（如long）数做“中间代理”，而达到目的。举例如下：
SignedEquivalent% = CInt( UnsighedNumber& - &h10000&)　其中UnsighedNumber&就是我们要的“代理”。这里的诀窍是：ＤＬＬ希望一个无符号的１６位整数，即使ＶＢ把SighedEquivalent解释为负数，ＤＬＬ也会将它解释为我们所需要的在32768-65535间的正整数。当然，反过来的逆变换,如下： LongResult& = (CLng( IntegerResult%) and &h0ffff&)

VB中调用DLL关于参数匹配的问题（三）
* 8位有符号和无符号整数
只要VB的无符号整数在正确的范围内，即-128～+127或0～255之间，就没有任何问题，直接用Integer类型就可以了。
* 32位有符号整数
与VB中的Long 类型完全兼容。真是好运气。呵呵。
* 32位无符号整数
有要转换了，因为VB中无相应的类型。这种转换的需要主要发生在使用的变量值在 2,147,483,647 ～ 4,294,967,295范围内。这里可以采用与前面提到的16位无符号整数类型转换相同的技巧，不过要用 Currency 或 Double 数据类型做中间的“代理”。方法相同，这里就不再罗嗦了。
* VB中的 Variant 类型
这种类型似乎只有VB中有，是不是有点太排他的感觉？所以碰到有这种类型的DLL函数，放心用吧，那DLL肯定是专门为VB而设计的。
* 结构体指针
在很多场合，要构造出一个与DLL（C-Style）完全吻合的结构体是有可能的，但，也存在走不通的情况。下面列出了一些在结构体中常常用到的类型，希望对你有所帮助。
Ｃ－Ｓｔｙｌｅ ＶＢ－Ｓｔｙｌｅ
BYTE长度为1的字符串：string*1
16位整数Integer
32位整数Long
位域把位域里每16位合成一个整数
字符数组（定长）定长字符串
FARPROC（函数指针）Long, 事实上VB不直接支持函数指针:)
句柄Integer
LPSTR（C字符串）Long
数值数组相应的数值数组
结构指针Long
Single或DoubleSingle或Double
* VB中的 Currency 类型
事实是 C 语言中也没有这种类型， 当可以构造出与之相当的类型，如下结构可以实现：
typedef struct currencystruct{
char currency_buf[8];
} Currency;
* vb中的 Any 类型的应用
这种类型申明的参数不进行任何类型的匹配检查，传递的参数类型总是函数调用时传进的参数的类型。当然这就要求调用程序保证传入正确的类型。实际上，这种类型是很有用的。例如，Windows API中很多的函数就支持多种类型的参数的调用，一个典型的例子如下：
HCURSORLoadCursor(hInstance, lpCursorName)
其中的第二个参数 lpCursorName 既可以是字符串指针，也可以是一个整数（即是光标在资源文件中的ID）。对于这种可容许多类型的函数参数，可将相应参数申明为 Any。




# Video




Cheat Engine 由浅入深修改游戏 +外挂辅助原理
https://www.bilibili.com/video/BV1Tb411v7YW/?spm_id_from=333.788.recommend_more_video.8









CE嗨游戏逆向 从入门到精通辅助 基础篇
https://www.bilibili.com/video/BV1qa4y1Y7e6/?spm_id_from=333.788.recommend_more_video.1


CE嗨游戏逆向 从入门到精通辅助 进阶篇
https://www.bilibili.com/video/BV1qg4y1q7Be/?spm_id_from=333.788.recommend_more_video.-1



CE嗨游戏逆向 从入门到精通辅助 高阶篇
https://www.bilibili.com/video/BV1wg4y1v7Xa/?spm_id_from=333.788.recommend_more_video.0



CE教学实例应用-由浅入深学习游戏修改
https://www.bilibili.com/video/BV1cE411E7h7/?spm_id_from=333.788.recommend_more_video.4


一只大笨熊
https://www.bilibili.com/video/BV1wv411s7V2/?spm_id_from=333.788.recommend_more_video.15


2020年CF思路教程
https://www.bilibili.com/video/BV1dV411R7kF/?spm_id_from=333.788.recommend_more_video.7

CF穿越火线CE搜索基址教程大全
https://www.bilibili.com/video/BV1hy4y1z7vL/?spm_id_from=333.788.recommend_more_video.0


VC驿站《VC++动态库DLL与静态库LIB编程》
https://www.bilibili.com/video/BV1Tt411Y7k7/?spm_id_from=333.788.recommend_more_video.2

动态库与静态库讲解
https://www.bilibili.com/video/BV1XE411k7PN/?spm_id_from=333.788.recommend_more_video.0


用C++做出扫雷！//初学者也能做的小游戏
https://www.bilibili.com/video/BV1zK4y1C7z4/?spm_id_from=333.788.recommend_more_video.2
https://www.bilibili.com/read/cv5610404




从零开始写编译器有多难？其实很简单，一学就会！想学？我教你啊。
https://www.bilibili.com/video/BV1L7411C7K1/?spm_id_from=333.788.recommend_more_video.1



DLL注入的四种方法——直接注入、代码注入、PE修改、机器码注入
https://www.bilibili.com/video/BV12541167mJ/?spm_id_from=333.788.videocard.10


TED演讲：顶级黑客给你演示黑客的操作
https://www.bilibili.com/video/BV1x4411g78i/?spm_id_from=333.788.recommend_more_video.2



CE进阶教程1（查找基址和代码注入）[必学！]
https://www.bilibili.com/video/BV14E41117k7/?spm_id_from=333.788.recommend_more_video.-1


《C语言-C++学习指南》18.1-多文件项目,extern的用法
https://www.bilibili.com/video/BV1Fs411k7v7/?spm_id_from=333.788.videocard.3





C/C++动态库和静态库的编译和链接
https://www.bilibili.com/video/BV19t4y1e7YD/?spm_id_from=333.788.recommend_more_video.3









kongxingjiduchunqiu wenshuinengbaituogudumozhou

wendaidangfeng youyirenzhisanqiaolihuazhong
yinyuanjihui nideweixiaodongyaoxinjing


baizailiulian

dangshitongchexinfei erjinyiweibansiaichou
shiwoyumei cuobachixindangkongfurensheng





I Tried Making a 3D RPG Game in JavaScript
https://www.youtube.com/watch?v=SBfZAVzbhCg




I Tried Making a 3D MMORPG Game in JavaScript
https://www.youtube.com/watch?v=IptkgFOoci0












PowerShell part 1 Getting Started
https://www.youtube.com/watch?v=H2MrvlLr-wg




Introduction to Scripting Concepts part 1
https://www.youtube.com/watch?v=blceAJU6Zyw


What is Active Directory?
https://www.youtube.com/watch?v=i9I5poSokow





Understanding Windows Applications: Day 1 What are Windows' Processes?
https://www.youtube.com/watch?v=aSNHMv8AEKg



Understanding Windows Applications: Day 2 What is a Scheduler?
https://www.youtube.com/watch?v=dSEXLXURKGk


Understanding Windows Applications Day 3 Hardware subsystems
https://www.youtube.com/watch?v=ZCmizwyhdvo




Understanding Windows Applications: Day 5 Threads and Handles
https://www.youtube.com/watch?v=MayYZ8HpjNg


Understanding Windows Applications: Day 6 DLLs
https://www.youtube.com/watch?v=gW3khtzm38s



What is a TLS Cipher Suite?
https://www.youtube.com/watch?v=ZM3tXhPV8v0





Windows 10 Architecture: Unlock troubleshooting secrets
https://www.youtube.com/watch?v=OXvGAAnu7FE








Windows's Registry: A Technical Review of this Complex Database
https://www.youtube.com/watch?v=-bsLmDfvF1Y





Understanding Windows Registry
https://www.youtube.com/watch?v=_U78iAem3uo



Understanding DLLs in Processes
https://www.youtube.com/watch?v=XXkxkruDRmA



Windows Registry Tutorial
https://www.youtube.com/watch?v=Zp63Ahunpgc



Introduction to Decorated Names, Dumpbin, Dependency walker (C++) PART 1
https://www.youtube.com/watch?v=xfI1p1egqHM



Introduction to Decorated Names, Dumpbin, Dependency walker (C++) PART 2
https://www.youtube.com/watch?v=UQ3FwxUA2Lk



Windows Registry Add Delete Modify KEYS AND VALUES
https://www.youtube.com/watch?v=MdSIr_z9NLM



Reverse Engineering 1
https://www.youtube.com/watch?v=cATBah30jk0

[Live] GHIDRA HYPE!! - NSA Reverse Engineering Tool
https://www.youtube.com/watch?v=qtoS3CG6ht0


How To Make Your Own Injector (BEGINNER C++ GAME HACKING TUTORIAL 2019)
https://www.youtube.com/watch?v=jbOcaSZ5ZRA

Rink Springer: How hackers grind an MMORPG: by taking it apart!
https://www.youtube.com/watch?v=9pCb0vIp_kg




DLL Injection PART 1
https://www.youtube.com/watch?v=pBdPIzvPn50

DLL Injection PART 2
https://www.youtube.com/watch?v=Chc5MlqX73U



DEFCON 19: Hacking MMORPGs for Fun and Mostly Profit ( w speaker)
https://www.youtube.com/watch?v=hABj_mrP-no


Patching Binaries (with vim, Binary Ninja, Ghidra and radare2) - bin 0x2F
https://www.youtube.com/watch?v=LyNyf3UM9Yc
How To Reverse Engineer ANY GAME For An Internal Hack Using IDA (CreateMove In CSGO)
https://www.youtube.com/watch?v=o2X4fDbfSXA




HackadayU: Reverse Engineering with Ghidra Class 1
https://www.youtube.com/watch?v=d4Pgi5XML8E





GAMEHACKING FOR BEGINNERS (C++)
https://www.youtube.com/watch?v=6vrGQO2pX80




MMORPG Bot Reverse Engineering and Tracking
https://www.youtube.com/watch?v=irhcfHBkfe0

MMORPG Bot part 2 - Some thoughts on the data
https://www.youtube.com/watch?v=aRDGI7UVSuI



C++ Game Hacking Tutorial Ep.1 | Reading/Writing Memory
https://www.youtube.com/watch?v=zFUHrg-wdmo



DLL vs EXE | Windows DLL Hell
https://www.youtube.com/watch?v=HVigruKph74


Dll Injection Explained (how it works + source code)
https://www.youtube.com/watch?v=IBwoVUR1gt8





CppCon 2017: James McNellis “Everything You Ever Wanted to Know about DLLs”
https://www.youtube.com/watch?v=JPQWQfDhICA





Communication Manager: Information about "List Trace" enhancements
https://support.avaya.com/ext/index?page=content&id=ADMN105847


Communication Manager: How to write "List Trace" output into the Log-File
https://support.avaya.com/ext/index?page=content&id=ADMN105861
