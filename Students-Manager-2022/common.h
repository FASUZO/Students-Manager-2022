#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  //error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

//�������Դ�ͷ�ļ�Ҫ�á�<>���������Լ�д��ͷ�ļ�Ҫ��˫���Ű���������ȷ���ö���ĺ�����
#include  "windows.h"  /*error C1189: #error:  "No Target Architecture"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <synchapi.h> /*sleep����Ҫ��*/

#define scanf scanf_s /* ��Ϊ VS ��������ȫ��scanf */

//�����ⲿ�ļ���ǰ������
extern void logo();
