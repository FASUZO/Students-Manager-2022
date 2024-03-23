#include "common.h"
#include "library.h"

// ��������
bool LinkList_Create(LinkList* L)
{
	//�����������������ڽ��������ݱ��ͷ�(�Ӷѿռ������ڴ棬�� ջ�ռ� �ֲ����� �������ͷ�)
	//��̬�ڴ�����
	//һ���ṹ��Node��ָ�� Node �ڴ��СΪ Node
	L->Head = (Node*)malloc(sizeof(Node)); //����һ��ͷ���

	// �ж��ǽڵ��������Ϊ NULL �����ʧ�ܣ��ɹ�ӦΪ 0
	if (L->Head == NULL) 
	{
		puts("�����ڴ�û�гɹ�!\n");
		return false;
	}

	// ����ɹ�,��ʼ�� ��ʼ���Ӹ��ڵ��γ�����
	L->Head->Next = NULL;	// ͷ�ڵ�� ָ���� ΪNULL ָ�������β��ΪNULL
	L->Tail = L->Head;		// ��ʼʱβ�ڵ�ָ��ͷ�ڵ� ָ�������ͷ��ΪHead

	L->NumOfNodes = 0;		// �ڵ����Ϊ0
	return true;
}

// �����ڵ㣨�ڵ��ʼ��������
Node* LinkList_CreateNode()
{
	Node* n;
	n = (Node*)malloc(sizeof(Node));

	if (n == NULL)
		return NULL;
	else
		n->Next = NULL;
	return n;
}

// ���ѧ��
bool add_student(LinkList* L)
{
	char num[MAXSIZE] = { 0 };
	Node* add = LinkList_CreateNode(); /*����һ���½ڵ�Ϊ�м䣨���룩�ڵ�*/

	if (add == NULL) 
	{
		printf("�������ʧ�ܣ�\n");
		return false;					/* ��Ϊ��������boolֵ�����Է���ֵӦΪ false or true */
	}
	else
	{
		printf("������������");
		scanf("%s", add->Info.Name, MAXSIZE);

		printf("�������Ա�(��/Ů)��");
		scanf("%s", &add->Info.Sex, MAXSIZE);

		printf("����������(ֻ������)��");
		scanf("%d", &add->Info.Age);

		printf("������ѧ��(10λ)��");
		scanf("%s", add->Info.Id, MAXSIZE);

		// ѧ���ظ���飬���������ѧ����ͬ��ѧ��
		if (idonlyone(L, add)) 
		{
			printf("������ɼ���");
			scanf("%lf", &add->Info.Score);
			printf("\n");

			//β�巨
			add->Next = NULL; 		// pNewNode���½ڵ㣩�� next ָ���
			L->Tail->Next = add;	// ��pNewָ��ָ��Ķ���ֵ��tail��next����Ҳ����βָ�����һ����������βָ�������µ�next������˲�����βָ���ˡ�
			L->Tail = add;			// ���ǽ�tailָ���µ�ĩβԪ�� pNew��
			L->NumOfNodes++;		// L �ڵ�������ڵ����� 1

			system("pause");
			return true;
		}
	}
	return false;
}

// ��ʾ����ѧ����Ϣ 
bool show_student(LinkList* L)
{
	int i;
	Node* p = L->Head->Next;

	ListHead_Print2();
	for (i = 0; i < L->NumOfNodes; i++)	//L->NumOfNodes �������ڵ�����
	{
		printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", p->Info.Name, p->Info.Sex, p->Info.Age, p->Info.Id, p->Info.Score);
		p = p->Next;
	}
	printf("\n\t\t======��ϵͳĿǰ��ѧ����Ϣ��Ŀ %d ======\t\t\n\n", L->NumOfNodes);
	system("pause"); /*��ֹ����������������������޷���ȷ��ʾ*/
	return true;
}

// ͨ��ѧ��������ѧ����Ϣ
bool search_student(LinkList* L)
{
	int num = 0;
	int j = 0;
	int search2 = 0;
	char search[MAXSIZE] = { 0 };
	Node* move = L->Head->Next;
	

	printf("��Ϣ��������ѡ��[001]����\t[002]�Ա�\t[003]����\t[004]ѧ��\t[005]�ɼ�\t\n");
	printf("��ѡ��:");
	scanf("%d", &num);

	if (num == 1 || num == 2 || num == 4)
	{
		printf("1������Ҫ����ѧ������Ϣ��");
		scanf("%s", search, MAXSIZE);
	}
	else if (num == 3 || num == 5)
	{
		printf("2������Ҫ����ѧ������Ϣ��");
		scanf("%d", &search2);
	}
	else
	{
		printf("��Ŵ���\n\n");
		system("pause");
		return false;
	}

	//ListHead_Print2();
	for (int i = 0; i < L->NumOfNodes; i++)
	{
		if (num == 1)
		{
			if (strcmp(search, move->Info.Name) == 0)
			{
				j++;
				printf(" \t%s \t%s \t%d \t%s \t%.2lf \n\n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);
			}
		}
		else if (num == 2)
		{
			if (strcmp(search, move->Info.Sex) == 0)
			{
				j++;
				printf(" \t%s \t%s \t%d \t%s \t%.2lf \n\n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);
			}
		}
		else if (num == 3)
		{
			if (move->Info.Age == search2)
			{
				j++;
				printf(" \t%s \t%s \t%d \t%s \t%.2lf \n\n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);
			}
		}
		else if (num == 4)
		{
			if (strcmp(search, move->Info.Id) == 0)
			{
				j++;
				printf(" \t%s \t%s \t%d \t%s \t%.2lf \n\n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);
			}
		}
		else if (num == 5)
		{
			if (move->Info.Score == search2)
			{
				j++;
				printf(" \t%s \t%s \t%d \t%s \t%.2lf \n\n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);
			}
		}
		move = move->Next;
	}
	if (j == 0)
	{
		printf("\n\t\t��������Ϊ �� \t\t\n\n");
		system("pause");
		return false;
	}
	system("pause");
	return false;
}

// ͨ��ѧ������ѧ����Ϣ��ð������
bool sort_student(LinkList* L)
{
	Node* sort = NULL; /* �ⲿѭ�� */
	Node* move = NULL; /* �ڲ�ѭ�� */
	Node* save = NULL; /* β������ */
	
	int upordown = 0;;
	printf("������ѧ����Ϣ��������[001]ѧ������\t[002]ѧ�Ž���\t[003]�ɼ�����\t[004]�ɼ�����\n");
	printf("��ѡ��:");
	scanf("%d", &upordown);

	for (sort = L->Head->Next; sort->Next != NULL; sort = sort->Next)
	{
		//while ((sort != NULL) && (sort->Next != NULL)) //����������ʼ��������
		for (move = L->Head->Next;move->Next != save;move = move->Next)
		{
			if (upordown == 1) 
			{
				//���򣬴�С����
				//printf("�������������£�");
				if (strcmp(move->Info.Id, move->Next->Info.Id) > 0)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else if (upordown == 2)
			{
				//���򣬴Ӵ�С
				if (strcmp(move->Info.Id, move->Next->Info.Id) < 0)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else if (upordown == 3)
			{
				//���򣬴�С����
				//printf("�������������£�");
				if (move->Info.Score > move->Next->Info.Score)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else if (upordown == 4)
			{
				if (move->Info.Score < move->Next->Info.Score)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else
			{
				printf("������Ų��ԣ�\n\n");
				system("pause");
				return false;
			}
		}
		save = move;
	}
	//system("pause");
	return true;
}

// ͨ��ѧ��ɾ��ѧ��
bool delete_student(LinkList* L)
{
	int num = 0;
	char delete_id[MAXSIZE] = { 0 };

	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%s", delete_id, MAXSIZE);

	Node* del;  /* �����м�ڵ�   */
	Node* temp = LinkList_CreateNode(); /* ����ǰ���ڵ㣬����ʼ��   */
	del = L->Head; // head->next��ʾָ��ڶ�����㣬headָ���һ����㣬��ͷ��㣬���ǵ�ͷ��㲻�����ݣ���ô�ӵڶ�����㿪ʼ��������Ҫ������ݣ���ʱӦ��ʹ��head->next��ָ��Ľ�㿪ʼ������

	while (del != NULL)
	{
		if (strcmp(delete_id, del->Info.Id) == 0)/* ���ҳɹ�*/
		{
			ListHead_Print2();
			printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", del->Info.Name, del->Info.Sex, del->Info.Age, del->Info.Id, del->Info.Score);

			printf("ȷ���Ƿ���Ҫɾ����ѧ����Ϣ��[001]ȷ��\t[002]ȡ��\n");
			printf("��ѡ��:");
			scanf("%d", &num);

			if (num == 1) 
			{
				//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
				temp->Next = del->Next;

				// ɾ��β��㣬�޸�βָ��
				if (del->Next == NULL)
				{
					L->Tail = del;
				}
				free(del);

				L->NumOfNodes--;

				printf("ɾ���ɹ���ɾ��ѧ��Ϊ %s ��ѧ����\n\n", delete_id);
				system("pause");
				return true;
			}
			else if (num == 2)
			{
				printf("ȡ��ɾ��\n\n");
				system("pause");
				return false;
			}
			else
			{
				printf("������Ų��ԣ�\n\n");
				system("pause");
				return false;
			}
		}
		temp = del;
		del = del->Next;
	}
	printf("�޸�ʧ�ܣ�������ѧ��Ϊ %s ��ѧ����\n", delete_id);
	system("pause");
	return false;
}

// ͳ��ѧ����Ϣ
bool statistics_student(LinkList* L) 
{
	int num = 0;
	int man_num = 0;
	int woman_num = 0;
	double allscore = 0;
	double avgscore = 0;
	Node* move = L->Head->Next; /* �ڲ�ѭ�� */

	printf("��Ϣͳ�ƣ���ѡ��[001]��������\t[002]Ů������\t[003]ƽ���ɼ�\t\n");
	printf("��ѡ��:");
	scanf("%d", &num);

	//ʹ���������for�ж�ʱ����ʼ���������޷��ҵ�
	//for (move = L->Head->Next; move->Next != NULL; move = move->Next)
	for (int i = 0; i < L->NumOfNodes; i++)
	{
		//�����ж�
		if (num == 1)
		{
			if ((strcmp("��", move->Info.Sex) == 0 || strcmp("M", move->Info.Sex) == 0))
			{
				man_num++;
			}
		}
		else if (num == 2)
		{
			if ((strcmp("Ů", move->Info.Sex) == 0 || strcmp("W", move->Info.Sex) == 0))
			{
				woman_num++;
			}
		}
		else if (num == 3)
		{
			allscore += move->Info.Score;
		}
		else
		{
			printf("��Ŵ��������δ֪����\n\n");
			system("pause");
			return false;
		}
		move = move->Next;
	}

	//����ж�
	if (num == 1)
	{
		printf("��ϵͳѧ����Ϣ�� ������ %d �� \n\n", man_num);
	}
	else if (num == 2)
	{
		printf("��ϵͳѧ����Ϣ�� Ů���� %d �� \n\n", woman_num);
	}
	else if (num == 3) 
	{
		avgscore = allscore / L->NumOfNodes;
		printf("��ϵͳѧ����Ϣ�� ѧ������ %d �� ѧ��ƽ���ɼ� %.2f \n\n", L->NumOfNodes,avgscore);
	}
	system("pause");
	return true;
}

// ͨ��ѧ��������ѧ����Ϣ,���޸�
bool rewrite_student(LinkList* L)
{
	char old[MAXSIZE] = { 0 };
	Node* move;
	move = L->Head->Next;

	printf("������Ҫ�޸�ѧ����ԭѧ�ţ�");
	scanf("%s", old, MAXSIZE);

	for (int i = 0; i < L->NumOfNodes; i++)
	{
		if (strcmp(old, move->Info.Id) == 0)
		{
			printf("��ѧ����ԭ��ϢΪ��\n");
			ListHead_Print2();
			printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);

			printf("\n\t��ѡ��Ҫ�޸�ѧ����Ϣ\t\n");
			printf("\t[001]����\t[002]�Ա�\n");
			printf("\t[003]����\t[004]ѧ��\n");
			printf("\t[005]����\t[000]ȡ��\n");
			printf("��ѡ�������");

			char Options[MAXSIZE] = { 0 };
			scanf("%s", Options, MAXSIZE);

			if (strcmp(Options, "001") == 0 || strcmp(Options, "1") == 0)
			{
				printf("�������µ�������");
				scanf("%s", move->Info.Name, MAXSIZE);
				printf("�������޸�Ϊ��%s \n\n", move->Info.Name);
			}
			else if (strcmp(Options, "002") == 0 || strcmp(Options, "2") == 0)
			{
				printf("�������µ��Ա�");
				//scanf(" %c", &move->Info.Sex, MAXSIZE);
				scanf("%s", &move->Info.Sex, MAXSIZE);
				printf("�Ա����޸�Ϊ��%s \n\n", &move->Info.Sex);
			}
			else if (strcmp(Options, "003") == 0 || strcmp(Options, "3") == 0)
			{
				printf("�������µ����䣺");
				scanf("%d", &move->Info.Age);
				printf("�������޸�Ϊ��%d \n\n", move->Info.Age);
			}
			else if (strcmp(Options, "004" ) == 0 || strcmp(Options, "4") == 0)
			{
				printf("�������µ�ѧ�ţ�");
				scanf("%s", move->Info.Id, MAXSIZE);

				// ѧ���ظ���飬���������ѧ����ͬ��ѧ��
				if (idonlyone(L, move)) {
					printf("ѧ�����޸ġ�\n");
				}
				else
				{
					//���ѧ�Ų�Ψһ������ѧ�����¸�ֵ��old
					strcpy_s(move->Info.Id, MAXSIZE, old);
				}
				
			}
			else if (strcmp(Options, "005") == 0 || strcmp(Options, "5") == 0)
			{
				printf("�������µķ�����");
				scanf_s("%lf", &move->Info.Score);
				printf("�������޸ġ�\n");
			}
			else if (strcmp(Options, "000") == 0) 
			{
				printf("ȡ���޸ģ�\n\n");
				break;
			}
			else
			{
				printf("��Ч��ѡ��\n\n");
			}
		}
		move = move->Next;
	}
	system("pause");
	return true;
}

//�ж�ѧ���Ƿ�Ψһ
bool idonlyone(LinkList * L,Node* newid) 
{
	Node* oldid = L->Head;

	for (int i = 0; i < L->NumOfNodes; i++)
	{
		oldid = oldid->Next;
		{
			//if (newid != oldid) 
			//{
				if (strcmp(newid->Info.Id, oldid->Info.Id) == 0)
				{
					printf("\n�����Ѵ���ѧ��Ϊ%s��ѧ����\n\n", newid->Info.Id);
					system("pause");
					return false;
				}
			//}
		}
	}
	return true;
}

// ����������д���ļ�
bool save_student(LinkList* L, char* file_path)
{
	if (L == NULL)
	{
		puts("����Ϊ��!\n");
		return false;
	}

	Node* p = L->Head->Next;
	// ����ָ���ļ���ָ�����fp
	FILE* fp;
	// wb �Զ�����ģʽ��һ���ļ���ֻд�򿪻��½�һ���������ļ���ֻ����д����,�����ļ�ָ��洢��fp������
	fopen_s(&fp, file_path, "wb");
	// �ļ�������
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}
	// ��������д���ļ�
	fwrite(&(L->NumOfNodes), sizeof(L->NumOfNodes), 1, fp);
	// ��ÿ����������д��fp�ļ�
	while (p != NULL)
	{
		fwrite(&(p->Info), sizeof(p->Info), 1, fp);
		p = p->Next;
	}
	fclose(fp);
	printf("д��ɹ���\n");
	system("pause");
	return true;
}

// ��ȡѧ����Ϣ�����ļ�������ѧ����Ϣд������
bool load_student(LinkList* L, char* fn)
{
	FILE* fp;
	fopen_s(&fp, fn, "rb"); // ��ȡ�������ļ�
	if (fp == NULL)
	{
		puts("�ļ���ʧ��\n");
		return false;
	}

	// ����ֲ�����NumOfNodes�洢�ļ��н��ĸ���
	int NumOfNodes;
	fread(&NumOfNodes, sizeof(int), 1, fp);
	// ��ȡ�ļ���Ϣ�������뵽������
	for (int i = 0; i < NumOfNodes; i++)
	{
		Node* n = LinkList_CreateNode();
		fread(&(n->Info), sizeof(n->Info), 1, fp);

		if (idonlyone(L, n)) 
		{
			//β�巨
			n->Next = NULL;
			L->Tail->Next = n;
			L->Tail = n;
			L->NumOfNodes++;
		}
	}
	fclose(fp);
	printf("��ȡ�ɹ���\n");
	system("pause");
	return true;
}