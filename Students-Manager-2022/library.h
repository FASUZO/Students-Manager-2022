#pragma once
#define MAXSIZE 64

// http://c.biancheng.net/view/298.html
// typedef 抽象数据类型：下次使用 不加则 struct _Student ，加则 Student

//学生节点的定义 存放数据(学生信息)
typedef struct _Student	/*定义结构体*/
{
	char Name[MAXSIZE];	// 姓名
	char Sex[MAXSIZE];	// 性别
	int Age;			// 年龄
	char Id[MAXSIZE];	// 学号
	double Score;		// 分数

} Student;

typedef struct _Node	/*定义节点*/
{
	Student Info;		//封装
	struct _Node* Next; /*指向下一个节点*/
} Node;

typedef struct _LinkList/*定义链表*/
{
	Node* Head;			/*定义头节点*/
	Node* Tail;			/*定义尾节点*/
	int NumOfNodes;		/*定义节点数*/
} LinkList;

// 声明 创建链表
bool LinkList_Create(LinkList* L);

// 声明 创建结点
Node* LinkList_CreateNode();

bool add_student(LinkList* L);
bool show_student(LinkList* L);
bool search_student(LinkList* L);
bool delete_student(LinkList* L);
bool sort_student(LinkList* L);
bool test(LinkList* L);
bool statistics_student(LinkList* L);
bool rewrite_student(LinkList* L);
bool idonlyone(LinkList* L, Node* newid);
bool save_student(LinkList* L, char* file_path);
bool load_student(LinkList* L, char* file_path);

void ListHead_Print2();