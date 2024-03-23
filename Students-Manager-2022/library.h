#pragma once
#define MAXSIZE 64

// http://c.biancheng.net/view/298.html
// typedef �����������ͣ��´�ʹ�� ������ struct _Student ������ Student

//ѧ���ڵ�Ķ��� �������(ѧ����Ϣ)
typedef struct _Student	/*����ṹ��*/
{
	char Name[MAXSIZE];	// ����
	char Sex[MAXSIZE];	// �Ա�
	int Age;			// ����
	char Id[MAXSIZE];	// ѧ��
	double Score;		// ����

} Student;

typedef struct _Node	/*����ڵ�*/
{
	Student Info;		//��װ
	struct _Node* Next; /*ָ����һ���ڵ�*/
} Node;

typedef struct _LinkList/*��������*/
{
	Node* Head;			/*����ͷ�ڵ�*/
	Node* Tail;			/*����β�ڵ�*/
	int NumOfNodes;		/*����ڵ���*/
} LinkList;

// ���� ��������
bool LinkList_Create(LinkList* L);

// ���� �������
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