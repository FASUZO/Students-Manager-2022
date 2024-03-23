#include "common.h"
#include "library.h"

//字符ASCII网站：https://www.bootschool.net/chinese-to-ascii
void logo() {
	//清屏
	system("cls");
	//打印专属logo
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

// 进度条
void ProgressBar()
{
    // 最后100%时的输出形式
    const char* LastStr = "[####################] 100%";
    const char ICON = '#';
    // 每加载5%打印一个ICON
    const int STEP = 5;
    // ICON的个数
    const int MAXNUMICON = 20;
    // 每隔10ms会让进度加1%
    const int PrintInterval = 10;

    printf("\n\t\t加载中: \t\t");
    for (int i = 0; i <= 100; ++i)
    {
        printf("[");
        // 每加载5%打印一个ICON
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
        // 回删字符，让数字和进度条原地变化
        for (int j = 0; j < strlen(LastStr); j++)
            printf("\b");
    }
    system("cls");
}

bool test(LinkList* L) {
    Node* test = LinkList_CreateNode();
    if (test == NULL) {
        printf("创建结点失败！\n");
        return false;						/* 因为函数体是bool值，所以返回值应为 false or true */
    }
    else
    {
        strcpy(test->Info.Name, "FASUZO");
        strcpy(test->Info.Sex, "男");
        strcpy(test->Info.Id, "2106100221");
        test->Info.Age = 22;
        test->Info.Score = 100;
    }

    //尾插法
    test->Next = NULL;
    L->Tail->Next = test;
    L->Tail = test;
    L->NumOfNodes++;

    printf("\n\n\n\t\t\t初始化成功\t\t\t\n\n\n");
    return true;
}