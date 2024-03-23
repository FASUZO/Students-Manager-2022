#include "common.h"
#include "library.h"

//�ַ�ASCII��վ��https://www.bootschool.net/chinese-to-ascii
void logo() {
	//����
	system("cls");
	//��ӡר��logo
	printf("\n\
===========================================================================================================\n\
        #  #   #             #            ##     ##           #      #             ##        #    ##       \n\
       ## ##  ##        #   ##          ##  #  ##  #       # #########       ########       ##    ##       \n\
      # #  # ##  #      ##  ##          ###### ######  ######## ## ##    #### #            ##     #   #    \n\
     ##############    ##   ##   #     ## ##  #  ##      ##  ## ## ##        ###          ##  ##########   \n\
    ###         ##     ############   # #  # ##   ##     ##  ########       ##   #        #  #   ## #      \n\
     #       #  #     ##    ##         ##############    ##  ## ## ##      ##   ###      #   ## ##   #     \n\
        #######       #     ##        ### #     # ##   ######## ## ##     #######        ##### ##    ##    \n\
            ##       #      ##  #      #  #########      ##  ########      #  ##  ##       ## ##########   \n\
           ##           ##########        ##   ##        ##  #  ## #        ##     ##     ##    ## ## #    \n\
           ##   #           ##            #######        ##     ##       #############   #####  ## ##      \n\
     #############          ##            ##     #       ##  ########     # #  ##   #     #     ## ##      \n\
           ##               ##            #########      ####   ##          ## ####           # ## ##      \n\
           ##               ##            ##    ##     ####     ##         ##  ## ###       ## ##  ##  #   \n\
           ##               ##    #       ##    ##      #       ##  #     ##   ##  ###   ####  ##  ##  #   \n\
         ####        ###############      ########          ##########  ##   ####   #     #   ##   #####   \n\
           #                              #     #                              #             #      ####   \n\
===================================================V1.6====================================================\n");
}

// ������
void ProgressBar()
{
    // ���100%ʱ�������ʽ
    const char* LastStr = "[####################] 100%";
    const char ICON = '#';
    // ÿ����5%��ӡһ��ICON
    const int STEP = 5;
    // ICON�ĸ���
    const int MAXNUMICON = 20;
    // ÿ��10ms���ý��ȼ�1%
    const int PrintInterval = 10;

    printf("\n\t\t������: \t\t");
    for (int i = 0; i <= 100; ++i)
    {
        printf("[");
        // ÿ����5%��ӡһ��ICON
        int Index = i / STEP;
        for (int j = 0; j < MAXNUMICON; j++)
        {
            if (j < Index)
                printf("%c", ICON);
            else
                printf(" ");
        }
        printf("] ");
        printf("%3d%%", i);
        Sleep(PrintInterval);
        // ��ɾ�ַ��������ֺͽ�����ԭ�ر仯
        for (int j = 0; j < strlen(LastStr); j++)
            printf("\b");
    }
    system("cls");
}

bool test(LinkList* L) {
    Node* test = LinkList_CreateNode();
    if (test == NULL) {
        printf("�������ʧ�ܣ�\n");
        return false;						/* ��Ϊ��������boolֵ�����Է���ֵӦΪ false or true */
    }
    else
    {
        strcpy(test->Info.Name, "FASUZO");
        strcpy(test->Info.Sex, "��");
        strcpy(test->Info.Id, "2106100221");
        test->Info.Age = 22;
        test->Info.Score = 100;
    }

    //β�巨
    test->Next = NULL;
    L->Tail->Next = test;
    L->Tail = test;
    L->NumOfNodes++;

    printf("\n\n\n\t\t\t��ʼ���ɹ�\t\t\t\n\n\n");
    return true;
}