#pragma warning(disable:4996)
#pragma once

//����error C3861 : ��xxxx��: �Ҳ�����ʶ���Ĵ�����

//�����������
//error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
#define _CRT_SECURE_NO_WARNINGS 1 

#include "common.h"
#include "library.h"

void menu();
void ProgressBar();
void ListHead_Print();