#pragma warning(disable:4996)
#pragma once

//关于error C3861 : “xxxx”: 找不到标识符的处理方法

//解决以下问题
//error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
#define _CRT_SECURE_NO_WARNINGS 1 

#include "common.h"
#include "library.h"

void menu();
void ProgressBar();
void ListHead_Print();