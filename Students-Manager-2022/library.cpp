#include "common.h"
#include "library.h"

// 创建链表
bool LinkList_Create(LinkList* L)
{
	//函数结束，生命周期结束，数据被释放(从堆空间申请内存，否 栈空间 局部变量 结束被释放)
	//动态内存申请
	//一个结构体Node，指向 Node 内存大小为 Node
	L->Head = (Node*)malloc(sizeof(Node)); //创建一个头结点

	// 判断是节点的数据域，为 NULL 则分配失败，成功应为 0
	if (L->Head == NULL) 
	{
		puts("分配内存没有成功!\n");
		return false;
	}

	// 分配成功,初始化 开始链接各节点形成链表
	L->Head->Next = NULL;	// 头节点的 指针域 为NULL 指明链表的尾部为NULL
	L->Tail = L->Head;		// 开始时尾节点指向头节点 指明链表的头部为Head

	L->NumOfNodes = 0;		// 节点个数为0
	return true;
}

// 创建节点（节点初始化函数）
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

// 添加学生
bool add_student(LinkList* L)
{
	char num[MAXSIZE] = { 0 };
	Node* add = LinkList_CreateNode(); /*创建一个新节点为中间（插入）节点*/

	if (add == NULL) 
	{
		printf("创建结点失败！\n");
		return false;					/* 因为函数体是bool值，所以返回值应为 false or true */
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", add->Info.Name, MAXSIZE);

		printf("请输入性别(男/女)：");
		scanf("%s", &add->Info.Sex, MAXSIZE);

		printf("请输入年龄(只能数字)：");
		scanf("%d", &add->Info.Age);

		printf("请输入学号(10位)：");
		scanf("%s", add->Info.Id, MAXSIZE);

		// 学号重复检查，不允许存在学号相同的学生
		if (idonlyone(L, add)) 
		{
			printf("请输入成绩：");
			scanf("%lf", &add->Info.Score);
			printf("\n");

			//尾插法
			add->Next = NULL; 		// pNewNode（新节点）的 next 指向空
			L->Tail->Next = add;	// 将pNew指针指向的对象赋值给tail的next对象，也就是尾指针的下一个对象。由于尾指针有了新的next对象，因此不再是尾指针了。
			L->Tail = add;			// 就是将tail指向新的末尾元素 pNew。
			L->NumOfNodes++;		// L 节点的数量节点增加 1

			system("pause");
			return true;
		}
	}
	return false;
}

// 显示所有学生信息 
bool show_student(LinkList* L)
{
	int i;
	Node* p = L->Head->Next;

	ListHead_Print2();
	for (i = 0; i < L->NumOfNodes; i++)	//L->NumOfNodes 人数（节点数）
	{
		printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", p->Info.Name, p->Info.Sex, p->Info.Age, p->Info.Id, p->Info.Score);
		p = p->Next;
	}
	printf("\n\t\t======本系统目前总学生信息条目 %d ======\t\t\n\n", L->NumOfNodes);
	system("pause"); /*防止闪屏，不加这个会闪屏，无法正确显示*/
	return true;
}

// 通过学号来检索学生信息
bool search_student(LinkList* L)
{
	int num = 0;
	int j = 0;
	int search2 = 0;
	char search[MAXSIZE] = { 0 };
	Node* move = L->Head->Next;
	

	printf("信息检索，请选择[001]姓名\t[002]性别\t[003]年龄\t[004]学号\t[005]成绩\t\n");
	printf("请选择:");
	scanf("%d", &num);

	if (num == 1 || num == 2 || num == 4)
	{
		printf("1请输入要查找学生的信息：");
		scanf("%s", search, MAXSIZE);
	}
	else if (num == 3 || num == 5)
	{
		printf("2请输入要查找学生的信息：");
		scanf("%d", &search2);
	}
	else
	{
		printf("序号错误！\n\n");
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
		printf("\n\t\t查找数据为 零 \t\t\n\n");
		system("pause");
		return false;
	}
	system("pause");
	return false;
}

// 通过学号排序学生信息（冒泡排序）
bool sort_student(LinkList* L)
{
	Node* sort = NULL; /* 外部循环 */
	Node* move = NULL; /* 内部循环 */
	Node* save = NULL; /* 尾部定量 */
	
	int upordown = 0;;
	printf("即将对学生信息进行排序，[001]学号升序\t[002]学号降序\t[003]成绩升序\t[004]成绩降序\n");
	printf("请选择:");
	scanf("%d", &upordown);

	for (sort = L->Head->Next; sort->Next != NULL; sort = sort->Next)
	{
		//while ((sort != NULL) && (sort->Next != NULL)) //检索不到初始化的数据
		for (move = L->Head->Next;move->Next != save;move = move->Next)
		{
			if (upordown == 1) 
			{
				//升序，从小到大
				//printf("现升序排列如下：");
				if (strcmp(move->Info.Id, move->Next->Info.Id) > 0)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else if (upordown == 2)
			{
				//降序，从大到小
				if (strcmp(move->Info.Id, move->Next->Info.Id) < 0)
				{
					Student temp = move->Info;

					move->Info = move->Next->Info;
					move->Next->Info = temp;
				}
			}
			else if (upordown == 3)
			{
				//升序，从小到大
				//printf("现升序排列如下：");
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
				printf("输入序号不对！\n\n");
				system("pause");
				return false;
			}
		}
		save = move;
	}
	//system("pause");
	return true;
}

// 通过学号删除学生
bool delete_student(LinkList* L)
{
	int num = 0;
	char delete_id[MAXSIZE] = { 0 };

	printf("请输入要删除的学生学号：");
	scanf("%s", delete_id, MAXSIZE);

	Node* del;  /* 创建中间节点   */
	Node* temp = LinkList_CreateNode(); /* 创建前驱节点，并初始化   */
	del = L->Head; // head->next表示指向第二个结点，head指向第一个结点，即头结点，我们的头结点不存数据，那么从第二个结点开始才是我们要存的数据，这时应该使用head->next所指向的结点开始存数据

	while (del != NULL)
	{
		if (strcmp(delete_id, del->Info.Id) == 0)/* 查找成功*/
		{
			ListHead_Print2();
			printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", del->Info.Name, del->Info.Sex, del->Info.Age, del->Info.Id, del->Info.Score);

			printf("确认是否是要删除的学生信息，[001]确认\t[002]取消\n");
			printf("请选择:");
			scanf("%d", &num);

			if (num == 1) 
			{
				//删除某个结点的方法就是更改前一个结点的指针域
				temp->Next = del->Next;

				// 删除尾结点，修改尾指针
				if (del->Next == NULL)
				{
					L->Tail = del;
				}
				free(del);

				L->NumOfNodes--;

				printf("删除成功，删除学号为 %s 的学生！\n\n", delete_id);
				system("pause");
				return true;
			}
			else if (num == 2)
			{
				printf("取消删除\n\n");
				system("pause");
				return false;
			}
			else
			{
				printf("输入序号不对！\n\n");
				system("pause");
				return false;
			}
		}
		temp = del;
		del = del->Next;
	}
	printf("修改失败，不存在学号为 %s 的学生！\n", delete_id);
	system("pause");
	return false;
}

// 统计学生信息
bool statistics_student(LinkList* L) 
{
	int num = 0;
	int man_num = 0;
	int woman_num = 0;
	double allscore = 0;
	double avgscore = 0;
	Node* move = L->Head->Next; /* 内部循环 */

	printf("信息统计，请选择[001]男生数量\t[002]女生数量\t[003]平均成绩\t\n");
	printf("请选择:");
	scanf("%d", &num);

	//使用下面这个for判断时，初始化的数据无法找到
	//for (move = L->Head->Next; move->Next != NULL; move = move->Next)
	for (int i = 0; i < L->NumOfNodes; i++)
	{
		//输入判断
		if (num == 1)
		{
			if ((strcmp("男", move->Info.Sex) == 0 || strcmp("M", move->Info.Sex) == 0))
			{
				man_num++;
			}
		}
		else if (num == 2)
		{
			if ((strcmp("女", move->Info.Sex) == 0 || strcmp("W", move->Info.Sex) == 0))
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
			printf("序号错误或其他未知错误！\n\n");
			system("pause");
			return false;
		}
		move = move->Next;
	}

	//输出判断
	if (num == 1)
	{
		printf("本系统学生信息中 男生有 %d 人 \n\n", man_num);
	}
	else if (num == 2)
	{
		printf("本系统学生信息中 女生有 %d 人 \n\n", woman_num);
	}
	else if (num == 3) 
	{
		avgscore = allscore / L->NumOfNodes;
		printf("本系统学生信息中 学生总数 %d 人 学生平均成绩 %.2f \n\n", L->NumOfNodes,avgscore);
	}
	system("pause");
	return true;
}

// 通过学号来检索学生信息,并修改
bool rewrite_student(LinkList* L)
{
	char old[MAXSIZE] = { 0 };
	Node* move;
	move = L->Head->Next;

	printf("请输入要修改学生的原学号：");
	scanf("%s", old, MAXSIZE);

	for (int i = 0; i < L->NumOfNodes; i++)
	{
		if (strcmp(old, move->Info.Id) == 0)
		{
			printf("该学生的原信息为：\n");
			ListHead_Print2();
			printf(" \t%s \t%s \t%d \t%s \t%.2lf \n", move->Info.Name, move->Info.Sex, move->Info.Age, move->Info.Id, move->Info.Score);

			printf("\n\t请选择要修改学生信息\t\n");
			printf("\t[001]姓名\t[002]性别\n");
			printf("\t[003]年龄\t[004]学号\n");
			printf("\t[005]分数\t[000]取消\n");
			printf("请选择操作：");

			char Options[MAXSIZE] = { 0 };
			scanf("%s", Options, MAXSIZE);

			if (strcmp(Options, "001") == 0 || strcmp(Options, "1") == 0)
			{
				printf("请输入新的姓名：");
				scanf("%s", move->Info.Name, MAXSIZE);
				printf("姓名已修改为：%s \n\n", move->Info.Name);
			}
			else if (strcmp(Options, "002") == 0 || strcmp(Options, "2") == 0)
			{
				printf("请输入新的性别：");
				//scanf(" %c", &move->Info.Sex, MAXSIZE);
				scanf("%s", &move->Info.Sex, MAXSIZE);
				printf("性别已修改为：%s \n\n", &move->Info.Sex);
			}
			else if (strcmp(Options, "003") == 0 || strcmp(Options, "3") == 0)
			{
				printf("请输入新的年龄：");
				scanf("%d", &move->Info.Age);
				printf("年龄已修改为：%d \n\n", move->Info.Age);
			}
			else if (strcmp(Options, "004" ) == 0 || strcmp(Options, "4") == 0)
			{
				printf("请输入新的学号：");
				scanf("%s", move->Info.Id, MAXSIZE);

				// 学号重复检查，不允许存在学号相同的学生
				if (idonlyone(L, move)) {
					printf("学号已修改。\n");
				}
				else
				{
					//如果学号不唯一，将旧学号重新赋值给old
					strcpy_s(move->Info.Id, MAXSIZE, old);
				}
				
			}
			else if (strcmp(Options, "005") == 0 || strcmp(Options, "5") == 0)
			{
				printf("请输入新的分数：");
				scanf_s("%lf", &move->Info.Score);
				printf("分数已修改。\n");
			}
			else if (strcmp(Options, "000") == 0) 
			{
				printf("取消修改！\n\n");
				break;
			}
			else
			{
				printf("无效的选择！\n\n");
			}
		}
		move = move->Next;
	}
	system("pause");
	return true;
}

//判断学号是否唯一
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
					printf("\n错误！已存在学号为%s的学生！\n\n", newid->Info.Id);
					system("pause");
					return false;
				}
			//}
		}
	}
	return true;
}

// 将链表数据写入文件
bool save_student(LinkList* L, char* file_path)
{
	if (L == NULL)
	{
		puts("链表为空!\n");
		return false;
	}

	Node* p = L->Head->Next;
	// 声明指向文件的指针变量fp
	FILE* fp;
	// wb 以二进制模式打开一个文件，只写打开或新建一个二进制文件；只允许写数据,并将文件指针存储在fp变量中
	fopen_s(&fp, file_path, "wb");
	// 文件不存在
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}
	// 将结点个数写入文件
	fwrite(&(L->NumOfNodes), sizeof(L->NumOfNodes), 1, fp);
	// 将每个结点的数据写入fp文件
	while (p != NULL)
	{
		fwrite(&(p->Info), sizeof(p->Info), 1, fp);
		p = p->Next;
	}
	fclose(fp);
	printf("写入成功！\n");
	system("pause");
	return true;
}

// 读取学生信息数据文件，并将学生信息写入链表
bool load_student(LinkList* L, char* fn)
{
	FILE* fp;
	fopen_s(&fp, fn, "rb"); // 读取二进制文件
	if (fp == NULL)
	{
		puts("文件打开失败\n");
		return false;
	}

	// 定义局部变量NumOfNodes存储文件中结点的个数
	int NumOfNodes;
	fread(&NumOfNodes, sizeof(int), 1, fp);
	// 读取文件信息，并插入到链表中
	for (int i = 0; i < NumOfNodes; i++)
	{
		Node* n = LinkList_CreateNode();
		fread(&(n->Info), sizeof(n->Info), 1, fp);

		if (idonlyone(L, n)) 
		{
			//尾插法
			n->Next = NULL;
			L->Tail->Next = n;
			L->Tail = n;
			L->NumOfNodes++;
		}
	}
	fclose(fp);
	printf("读取成功！\n");
	system("pause");
	return true;
}