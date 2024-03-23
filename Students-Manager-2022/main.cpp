#pragma warning(disable:4996)
#include "main.h"

LinkList L; /* 声明结构体的输入变量 *指针 ->L */

int main()
{
	menu();
}


//菜单头表
void menu_head() 
{
	logo();
	printf("\n\
			\t[001]增加学生信息\t[006]统计学生信息\n \
			\t[002]显示学生信息\t[007]修改学生信息\n \
			\t[003]查询学生信息\t[008]导出学生信息\n \
			\t[004]排序学生信息\t[009]导入学生信息\n \
			\t[005]删除学生信息\n \
			\t[000]退出系统 \n");
	printf("输入序号，进行选择:");
}

//菜单主体
void menu() {

	LinkList_Create(&L);
	
	ProgressBar();
	test(&L);
	Sleep(900);

	while (1)
	{
		menu_head(); /*始终保持菜单在顶部：每次 break 出来之后，重新打印菜单头表*/

		char file_path[MAXSIZE] = "./student.data";		//文件保存路径
		int menu_num = 0;
		scanf("%d", &menu_num); 
		
		
		switch (menu_num)
		{
		case 000:
			logo();
			printf("\n\t\t========退出系统========\t\t\n");
			exit(0);			/*关闭整个程序*/
			break;

		case 001:
			logo();
			printf("\n\t\t---[001]增加学生信息---\t\t\n");
			add_student(&L);
			break;

		case 002:
			logo();
			printf("\n\t\t---[002]显示学生信息---\t\t\n");
			show_student(&L);
			break;

		case 003:
			logo();
			printf("\n\t\t---[003]查询学生信息---\t\t\n");
			search_student(&L);
			break;

		case 004:
			logo();
			printf("\n\t\t---[004]排序学生信息---\t\t\n");
			sort_student(&L);
			show_student(&L);	/*排序后打印*/
			break;

		case 005:
			logo();
			printf("\n\t\t---[005]删除学生信息---\t\t\n");
			delete_student(&L);
			break;

		case 006:
			logo();
			printf("\n\t\t---[006]统计学生信息---\t\t\n");
			statistics_student(&L);
			break;

		case 007:
			logo();
			printf("\n\t\t---[007]修改学生信息---\t\t\n");
			rewrite_student(&L);
			break;

		case 8:
			logo();
			printf("\n\t\t---[008]保存学生信息---\t\t\n");
			save_student(&L, file_path);
			break;

		case 9:
			logo();
			printf("\n\t\t---[009]加载学生信息---\t\t\n");
			load_student(&L, file_path);
			break;
			
		default:
			break;
		}
	}
}

// 打印表头
void ListHead_Print()
{
	printf("\n\t序号\t姓名\t性别\t年龄\t学号\t\t分数\n");
	printf("-------------------------------------------------------------------\n");
}

void ListHead_Print2()
{
	printf("\n\t姓名\t性别\t年龄\t学号\t\t分数\n");
	printf("-------------------------------------------------------------------\n");
}