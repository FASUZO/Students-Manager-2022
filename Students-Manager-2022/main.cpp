#pragma warning(disable:4996)
#include "main.h"

LinkList L; /* �����ṹ���������� *ָ�� ->L */

int main()
{
	menu();
}


//�˵�ͷ��
void menu_head() 
{
	logo();
	printf("\n\
			\t[001]����ѧ����Ϣ\t[006]ͳ��ѧ����Ϣ\n \
			\t[002]��ʾѧ����Ϣ\t[007]�޸�ѧ����Ϣ\n \
			\t[003]��ѯѧ����Ϣ\t[008]����ѧ����Ϣ\n \
			\t[004]����ѧ����Ϣ\t[009]����ѧ����Ϣ\n \
			\t[005]ɾ��ѧ����Ϣ\n \
			\t[000]�˳�ϵͳ \n");
	printf("������ţ�����ѡ��:");
}

//�˵�����
void menu() {

	LinkList_Create(&L);
	
	ProgressBar();
	test(&L);
	Sleep(900);

	while (1)
	{
		menu_head(); /*ʼ�ձ��ֲ˵��ڶ�����ÿ�� break ����֮�����´�ӡ�˵�ͷ��*/

		char file_path[MAXSIZE] = "./student.data";		//�ļ�����·��
		int menu_num = 0;
		scanf("%d", &menu_num); 
		
		
		switch (menu_num)
		{
		case 000:
			logo();
			printf("\n\t\t========�˳�ϵͳ========\t\t\n");
			exit(0);			/*�ر���������*/
			break;

		case 001:
			logo();
			printf("\n\t\t---[001]����ѧ����Ϣ---\t\t\n");
			add_student(&L);
			break;

		case 002:
			logo();
			printf("\n\t\t---[002]��ʾѧ����Ϣ---\t\t\n");
			show_student(&L);
			break;

		case 003:
			logo();
			printf("\n\t\t---[003]��ѯѧ����Ϣ---\t\t\n");
			search_student(&L);
			break;

		case 004:
			logo();
			printf("\n\t\t---[004]����ѧ����Ϣ---\t\t\n");
			sort_student(&L);
			show_student(&L);	/*������ӡ*/
			break;

		case 005:
			logo();
			printf("\n\t\t---[005]ɾ��ѧ����Ϣ---\t\t\n");
			delete_student(&L);
			break;

		case 006:
			logo();
			printf("\n\t\t---[006]ͳ��ѧ����Ϣ---\t\t\n");
			statistics_student(&L);
			break;

		case 007:
			logo();
			printf("\n\t\t---[007]�޸�ѧ����Ϣ---\t\t\n");
			rewrite_student(&L);
			break;

		case 8:
			logo();
			printf("\n\t\t---[008]����ѧ����Ϣ---\t\t\n");
			save_student(&L, file_path);
			break;

		case 9:
			logo();
			printf("\n\t\t---[009]����ѧ����Ϣ---\t\t\n");
			load_student(&L, file_path);
			break;
			
		default:
			break;
		}
	}
}

// ��ӡ��ͷ
void ListHead_Print()
{
	printf("\n\t���\t����\t�Ա�\t����\tѧ��\t\t����\n");
	printf("-------------------------------------------------------------------\n");
}

void ListHead_Print2()
{
	printf("\n\t����\t�Ա�\t����\tѧ��\t\t����\n");
	printf("-------------------------------------------------------------------\n");
}