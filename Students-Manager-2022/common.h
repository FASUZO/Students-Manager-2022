#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  //error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

//编译器自带头文件要用“<>”包括，自己写的头文件要用双引号包括，能正确调用定义的函数。
#include  "windows.h"  /*error C1189: #error:  "No Target Architecture"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <synchapi.h> /*sleep函数要用*/

#define scanf scanf_s /* 因为 VS 不允许不安全的scanf */

//定义外部文件，前向声明
extern void logo();
