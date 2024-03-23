# 目录
1 前言
1\.1 功能分析
1\.2 课程设计分工情况
2 概要设计
2\.1 系统的目标
2\.1\.1 需求分析
2\.1\.2 类的定义与声明
2\.2 系统的功能结构
2\.2\.1 系统的功能包括
2\.2\.2 增加学生信息
2\.2\.3 显示学生信息
2\.2\.4 删除学生记录
2\.2\.5 修改学生信息
2\.2\.6 查询学生信息
2\.2\.7 排序学生信息
2\.2\.8 统计学生信息
2\.2\.9 学生信息的导入/导出
3 详细设计
3\.1 主函数模块设计
3\.1\.1 模块概述
3\.1\.2 技术分析
3\.1\.3 功能实现
3\.2基本框架
3\.2\.1 框架
3\.2\.2 功能实现
4、运行结果与调试
4\.1运行结果
5 特殊问题及解决方法
6 总结与体会
参考文献

# 1 前言

本论文旨在介绍一种基于 C 语言编写的学生信息管理系统软件，旨在为广大高校提供一种可行且易操作的解决方案。作为一种高级计算机语言，C 语言在软件开发领域应用广泛，而学生信息管理系统正是 C 语言的重要应用之一。
近年来，中国高等教育扩大招生规模，高校在校学生人数稳步增长。为了保证学生信息的安全性，各分院的学生信息通常在一个相对封闭的闭环内共享。然而，传统的学生信息管理工作由于工作量大、易出错且时效性差等问题，给高校信息管理带来不小的压力。
因此，设计一种可行且易操作的基于 C 语言的学生信息管理系统非常重要。该系统将具备信息的录入、删除、编辑、查询、分析、汇总和打印等功能，有助于高校实现高效的信息管理。
本论文将详细介绍系统的设计和实现过程，涵盖了系统架构、功能模块以及算法原理。通过阅读本论文，读者将能够了解学生信息管理系统的重要性，以及如何利用 C 语言进行系统开发和管理。

## 1\.1 功能分析

学生信息模块：
1. 学生信息的录入：可以根据要插入的序号，将学生的个人信息，如姓名、性别、年龄、学号、分数等添加到系统中。
2. 学生信息的删除：可以根据要删除的序号，将学生的个人信息从系统中删除。
3. 学生信息的修改：可以根据学生的学号，对学生的个人信息进行修改。
4. 学生信息的查找：可以根据学生的学号，查找对应学号的学生信息，并将要查找学生的信息和其所对应的序号一起输出到终端。
5. 学生信息的显示：可以将系统中所有学生的信息输出到终端。
6. 清除所有学生信息：可以将系统中所有学生的信息都删除掉。

数据存读模块：

1. 生成学生信息文件：可以将系统中所有学生的信息以二进制形式存入到指定路径的文件中，若没有文件则创建文件再储存。
2. 读取学生信息文件：可以读取指定路径的存储学生信息的二进制文件，并将学生信息按序号以单链表“尾插”的方式依次添加到系统中。


# 2 概要设计
## 2\.1 系统的目标
用户可以通过信息管理系统对学生信息进行录入、删除、修改、查找等操作，并且系统支持用户将学生信息导出到文件中保存，并且系统还要有读取文件中学生信息并录入到系统的功能，并且系统有较强的稳定性。

### 2\.1\.1 需求分析

1\. 实现学生信息的录入和修改功能：系统应该提供方便的界面和功能，允许用户输入和修改学生的个人信息，包括姓名、性别、年龄、学号、分数等。
2\. 支持学生信息的查询和删除功能：系统应该提供强大的查询功能，使用户能够根据学号、姓名等条件快速查找学生信息，也应该提供通过学号或者序号删除学生信息的功能。
3\. 提供友好的用户界面：系统应该具备易于使用和导航的用户界面，使用户可以轻松地进行录入、删除、查看和修改学生信息。

### 2\.1\.2 类的定义与声明

本文所实现的学生信息管理系统主要包括三个类：

\(1\) Student类：
Student类表示学生，具有姓名（Name）、性别（Gender）、年龄（Age）、学号（Id）和分数（Score）等属性。

\(2\) Node类：
Node类表示链表中的节点，具有包含一个Student结构体的Info属性和指向下一个节点的Next指针，并有创建节点的方法。

\(3\) LinkList类：
LinkList类表示单链表的结构，据有头节点（Head），尾节点（Tail）和节点数量（NumOfNodes）等属性，以及执行各种链表操作的方法，如插入、删除、修改、查找、打印、文件的导入与导出等。

这三种类的类图如图2\.1所示：

![图2 Student,Node,LinkList结构体的结构体图](https://telegraph-image-15h.pages.dev/file/33b1e809aa5ddfe66149e.png)
<center>图2\.1\.2 Student,Node,LinkList类的类图</center>

其中，要访问Student类的属性，只能直接通过Student访问或通过Node类的Info属性间接访问，所以Student类的属性都是私有的。同理，Node类与LinkList类的属性都是私有的。

因为Node类中的Info属性是Student类的，用于存储学生对象的信息，这种关系表示了每个节点都持有一个学生对象的信息，但Node对象的创建和销毁并不受Student对象的影响，即Node对象和Student对象的生命周期是独立的，所以Student类与Node类之间为聚合关系。

因为LinkList类中的Head与Tail属性是Node\*类的，分别指向单链表的第一个和最后一个节点，当LinkList对象被销毁时，与LinkList对象关联的所有Node对象也会随之消失，即Node对象的生命周期依赖于LinkList对象的生命周期，所以Node类与LinkList类之间为组合关系。

LinkList类中的Node结构持有Student类的属性，除此之外，LinkList类与Student类之间没有直接的关联或引用，因此LinkList类与Student类的关系不属于六类关系中的任何一种。

## 2\.2 系统的功能结构

### 2\.2\.1 系统的功能包括

学生信息的录入、学生信息的删除、学生信息的修改、学生信息的查找、学生信息的显示、生成学生信息文件、读取学生信息文件、清除所有学生信息、退出系统。学生信息系统的功能结构如图2\.1所示：

![](https://telegraph-image-15h.pages.dev/file/3b50ebe4bb8109ef2becc.png)
图2\.1 学生信息系统的功能结构图

### 2\.2\.2 增加学生信息

学生信息的录入操作可以简要概括为如图2\.2所示：

![](https://telegraph-image-15h.pages.dev/file/f29ee12a7bc6cd3d1507a.png)
图2\.2 学生信息录入操作流程图

在菜单中输入“增加学生信息”功能所对应的序号，接着就可以输入姓名、性别、年龄、学号、分数等学生的基本信息，此外，在输入学号后，系统会将你输入的学号与系统中已有学生的学号进行比较，如果要输入的学号已在系统中存在，则插入失败，否则插入成功。系统还提供了“尾插法”的功能，插入位置输入\-1即可在最后一个学生信息后面插入新的学生信息。插入成功或失败后，系统界面会返回菜单。

### 2\.2\.3 显示学生信息

在菜单中输入“显示学生信息”功能所对应的序号，接着系统显示所有的学生信息并对系统目前总学生信息条目计数。

![](https://telegraph-image-15h.pages.dev/file/11a9c40e4526c246b7c5e.png)
图2\.3 显示学生信息操作流程图

### 2\.2\.4 删除学生记录

学生信息的删除操作可以简要概括为如图2\.4所示：

![](https://telegraph-image-15h.pages.dev/file/7ea63ccfdbb0d37727b19.png)
图2\.4 学生信息删除操作流程图

在菜单中输入“学生信息删除”功能所对应的序号，。如果删除的学号输入错误，都会删除失败；如果删除的学号正确，则删除成功。删除成功或失败后，系统界面会返回菜单。

### 2\.2\.5 修改学生信息

学生信息的修改操作可以简要概括为如图2\.5所示：

![](https://telegraph-image-15h.pages.dev/file/9dce73285041b91127100.png)
图2\.5 学生信息修改操作流程图

在菜单中输入“学生信息修改”功能所对应的序号，接着输入修改学生原学号。如果系统中没有学生的学号与要输入学号相同，则会查找失败；如果系统中存在要输入的学号，则允许修改该学生信息，当修改学号信息时，系统会将你输入的学号学生信息进行显示，从而进行更改，修改完成后系统界面会返回菜单。

### 2\.2\.6 查询学生信息

学生信息的查找操作可以简要概括为如图2\.6所示：

![](https://telegraph-image-15h.pages.dev/file/516d8c193f3f294b83c08.png)
图2\.6 学生信息查找操作流程图

在菜单中输入“查询学生信息”功能所对应的序号，接着输入需要查询信息的序号。并输入要查询的内容，查找成功，将该学生的信息输出，反之则查找失败。查找成功或失败后，系统界面会00返回菜单。

### 2\.2\.7 排序学生信息

学生信息的查找操作可以简要概括为如图2\.6所示：

![](https://telegraph-image-15h.pages.dev/file/496ad0de96114713bcfd4.png)
图2\.7 学生信息查找操作流程图

在菜单中输入“排序学生信息”功能所对应的序号，接着输入001学号升序 002学号降序，003成绩升序 004成绩降序，如果升序则升序排列并显示，反之降序也一样。最后会显示本系统目前总学生信息条数

### 2\.2\.8 统计学生信息

学生信息的查找操作可以简要概括为如图2\.6所示：

![](https://telegraph-image-15h.pages.dev/file/253da0d1e0e6119ae87ae.png)
图2\.8 学生信息查找操作流程图

在菜单中输入“统计学生信息”功能所对应的序号，接着输入001男生数量 002女生数量，003平均成绩。如果001则显示本系统学生信息中男生有n人，反之002也一样。003会显示本系统学生信息中 学生总数n人 学生平均成绩=成绩之和/n。

### 2\.2\.9 学生信息的导入/导出

学生信息的导入/导出操作可以简要概括为如图所示：

![](https://telegraph-image-15h.pages.dev/file/0c19b0efd05f10ae8101c.png)
图2\.7\.1 学生信息的导出操作流程图

![](https://telegraph-image-15h.pages.dev/file/28062f329c6897668d583.png)
图2\.7\.2 学生信息的导入操作流程图

在菜单中输入“学生信息的导入/导出”功能所对应的序号，则会显示写入/导

出成功或失败，然后系统界面会返回菜单。

# 3 详细设计

## 3\.1 主函数模块设计

### 3\.1\.1 模块概述

主函数是程序的入口点，它用于启动和控制程序的执行流程。主函数包含了一系列的预处理命令和函数调用的语句，菜单\(Menu函数\)及相关操作的全部功能。

### 3\.1\.2 技术分析

能正确使用 \#include 指令，编译器自带头文件要用<>包括，自己写的头文件要用双引号""括，能正确调用定义的函数。

### 3\.1\.3 功能实现
```C
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  //error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

//编译器自带头文件要用“<>”包括，自己写的头文件要用双引号包括，能正确调用定义的函数。
#include  "windows\.h"  /*error C1189: \#error:  "No Target Architecture"*/
#include <stdio\.h>
#include <stdlib\.h>
#include <string\.h>
#include <synchapi\.h> /*sleep函数要用*/
#define scanf scanf\_s /* 因为 VS 不允许不安全的scanf */

//定义外部文件，前向声明

extern void logo();
```

## 3.2基本框架
### 3\.2\.1 框架
首先因为学生有以下几个基本信息：姓名、年龄、学号、性别，依次由Name、Sex、Age，Id和Score来表示，所以可以通过结构体实现，struct语句定义存储不同类型的数据项，定义一个结构体名为Student，用于存储每个学生的信息。
### 3\.2\.2 功能实现

```C
#pragma once
#define MAXSIZE 64
// 头文件放函数的声明及类型的定义

// http://c\.biancheng\.net/view/298\.html
// typedef 抽象数据类型：下次使用 不加则 struct \_Student ，加则 Student

//学生节点的定义 存放数据

typedef struct Student	/*定义结构体*/
{
	char NameMAXSIZE;	// 姓名
	char SexMAXSIZE;	// 性别
	int Age;			// 年龄
	char IdMAXSIZE;	// 学号
	double Score;		// 分数
} Student;
```

# 4、运行结果与调试

## 4\.1运行结果

\(1\)在程序开始是进入学生管理系统界面。该界面为主界面，该界面可以进行增加学生信息、显示学生信息、查询学生信息、排序学生信息、删除学生信息、统计学生信息、修改学生信息、导出和导入学生信息、退出系统。主界面如图4\-1所示。


图4\-1 主界面

（2）在增加学生信息完成后或者从下一级界面返回后输出该界面。该界面可以输入姓名、性别（男/女）、年龄（只能数字）、学号（10位）、成绩来操作。增加学生信息界面如图4\-2所示。


图4\-2 增加学生信息界面

（3）该界面为显示学生信息界面，可以显示学生信息，返回上一级菜单的功能。显示学生信息界面如图4\-3所示。


图4\-3显示学生信息界面

（4）该界面可以实现学生信息查询功能，可以按学生的学号进行查询、返回上一级菜单的功能。查找功能界面如图4\-4所示。

 

图4\-4 查询学生信息界面

（5）该界面可以进行排序的操作。可以进行按学号排序、按学号升序排序、按学号降序排序，还可以返回上一级菜单。排序功能是在内存中进行，所以不进行输出。排序功能界面如图4\-5所示。

图4\-5排序功能界面

（6）该界面可以实现删除学生信息、返回上一级菜单的功能。删除功能界面如图4\-6所示。

图4\-6删除功能界面

（7）该界面可以实现对学生男生数量、女生数量、平均成绩的查询、返回上一级菜单的功能。统计学生信息界面如图4\-7所示。

图4\-7统计学生信息界面

（8）该界面可以实现对学生姓名、性别、年龄、学号、分数的修改、返回上一级菜单的功能。修改学生信息界面如图4\-8所示。

图4\-8修改学生信息界面

（9）该界面可以实现对学生信息的导出/导入、返回上一级菜单的功能。导出/导入学生信息界面如图4\-9所示。

图4\-9导出/导入学生信息界面

# 5 特殊问题及解决方法

1. 问题：scanf,fopen等函数安全性报错：'scanf': This function or variable maybe unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.

解决方法：这是Visual Studio特有的报错，换用更安全的函数scanf_s,fopen_s等即可消除错误。

2. 问题：在包含字符类输入的函数，无法用scanf函数正确读入输入。

解决办法：两个相邻输入项直接有个回车操作，回车输入后仍在缓冲区中，由于scanf读取字符型时会读取缓冲区中的内容，所以才导致输入异常。在“%c”前面加一个空格抵消掉缓冲区中的回车即可正常输入。

3. 问题：在菜单选项中输入字符串会出现一系列错误输出，

解决方法：产生原因同2，是因为使用了switch case语句，但是它只能识别整型和字符型，当输入为字符串时，相当于输入了多次字符。使用级联的if\-else if语句，加上strcmp函数即可解决该问题10。

# 6 总结与体会


本学生信息管理系统是有头节点的单链表多文件的C\+\+项目。设计目标是实现对学生信息的增、删、查、改、统计、排序、导出、导入等功能，其中增删是对链表中节点位置的调整，查改、统计、排序是对链表中节点成员的调整，导出、导入是数据持久化。本项目采用C\+\+语言和Visual Studio 2022软件进行开发，以单链表作为主要的数据结构。

1. 软件使用。自此之前未用过VS软件，但是有使用VS Code和Dev\-C\+\+的经验。因为使用的是多文件方式，在软件的使用中出现了许多VS 2022版本中出现的特有问题，如因安全因素VS特有的scanf\_s、strcpy\_s、fopen\_s等\_s系列问题，让我认识到同一项目对于不同开发软件的运行结果也有可能有所不同，对于项目开发在一个团体或者组织中也需要统一的软件开发和测试。另外在开发过程中，要学会断点调试，针对运行中的程序进程可以更好的看到数值（成员赋值）变化，也能更好观察指针地址变化。
2. 语言学习。本项目使用了C\+\+语言，但是我个人对于C语言和C\+\+语言并不能精确区分。 C\+\+ 是对 C 的延续，在本项目中主要是使用了其面向对象、类和对象、异常处理等特点或特色，针对对象使用的是结构体 Struct 函数，未使用类Class函数。
3. 项目设计及流程。对于项目而言，是我们团队的任务工作，首先要进行任务分解、时间安排等，能发挥个人特长，提高工作效率。我本人主要进行开发，数据结构的设计，调试、测试及优化，负责部分文档编写。本项目主要分模块进行开发，有利于项目集成和调试。本项目使用的是有头结点的链表存储数据的原因是，相对于数组存储①动态内存分配，节约内存资源；②插入、删除效率高，针对大型信息流优异；③灵活性和动态长度，数值长度变化较大仍能保存。但是缺点在于查找成员需要遍历整个链表，对于学生信息这个大、杂、乱的信息流而言链表是具有一定优势性的。
4. 程序设计及流程。程序模块流程增删查改\->统计\->排序\->导入\\导出。在所有节点使用之前应该进行初始化，否则会出现节点为 nullptr ，当然可以用断点逐步调试解决。①增删主要是对于节点指针域的指向，牢记“先链接后断开”原则。②查改、统计主要是对与链表中节点成员的查询，还需要对成员进行判断。所以要搞清楚 \-> 是结构体指针运算符，用于从指向结构体的指针中访问结构体成员； \. 是成员运算符，用于从结构体变量中访问结构体成员。因为使用结构体，个别变量需要使用地址&来赋值给指针。③排序主要是使用冒泡算法，对节点的数据域进行交换。④导入、导出主要是对文件操作，重要的是对链表中数据条目的把握。
5. 心得。本次程序设计，使我系统的、深入的学习了C语言，并对自我知识、构想进行实践、验证、实现。我深入理解了链表数据结构的特点和应用，掌握了指针操作的技巧，加强了对文件储存和读取的理解，提升了编程和问题解决能力。我相信这些经验将对我的日后学习和工作具有持久的影响。通过这个项目，我对数据结构和算法有了更深入的认识，并且学会了如何将不同的概念和知识应用到实际项目中。这次经历让我对计算机程序设计产生了更大的兴趣，也激发了我进一步学习和探索的动力。


# 参考文献
[1]	宋福英. C语言基于结构体的学生信息管理系统实现 [J]. 计算机时代, 2020, (3): 4.
[2]	曹贯强, 刘睿鑫, 刘志杰. 基于VisualC语言的学生信息管理系统 [J]. 电脑编程技巧与维护, 2013, (08): 55-7.
[3]	ALHIR S S. Learning Uml [M]. " O'Reilly Media, Inc.", 2003.
[4]	普拉塔. C++ Primer Plus (第五版) 中文版 [M]. C++ Primer Plus (第五版) 中文版, 2005.
[5]	朱昌杰, 肖建于. 数据结构(C语言版) [M]. 数据结构(C语言版), 2011.
[6]	严蔚敏, 李冬梅, 吴伟民. 数据结构(C语言版) [J]. 计算机教育, 2012, (12): 1.
[7]	HOATH M. Loops - For In, If Else, Switch [M]. Swift 4.2 Essentials, 2019.
[8]	WAITE M, PRATA S, MARTIN D. C primer plus [M]. Sams, 1987.
[9] 夜风~. \033[0;30m 之超级终端的字体背景和颜色显示等[EB/OL]. 2018[2023].https://blog.csdn.net/u014470361/article/details/81512330.
[10]Microsoft.scanf_s,_scanf_s_l,wscanf_s,_wscanf_s_l[EB/OL]. 2023[2023].https://learn.microsoft.com/zh-cn/cpp/c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l?view=msvc-170.
[11]学生管理系统_学生管理系统csdn_程序员子衿的博客-CSDN博客
[12]学生信息管理系统_菜小生的博客-CSDN博客
[13]【C语言-学生管理系统】_学生管理系统c语言-CSDN博客
[14]C语言学生管理系统_学生管理系统c语言-CSDN博客
[15]C++学生管理系统c++学生信息管理系统_永恒有多远的博客-CSDN博客
中国高等院校计算机基础教育课程体系规划教材_C语言程序设计（第五版）谭浩强
