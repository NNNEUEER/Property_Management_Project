//主程序
#include "head.h"
yezhu* head = NULL;//业主链表头
yezhu* prear = NULL;
fee* head1 = NULL;//缴费链表头
fee* prear1 = NULL;
yezhu* current = NULL;//当前业主
int main()
{//初始化业主链表
	head = (yezhu*)malloc(sizeof(yezhu));//创建头节点（业主）
	if (head == NULL)
	{
		printf("内存分配失败\a\n");
		return 1;
	}
	strcpy(head->add1, "");//初始化头节点（空的）
	strcpy(head->add2, "");
	strcpy(head->add3, "");
	strcpy(head->name, "");
	strcpy(head->pwd, "");
	strcpy(head->tel, "");
	head->next = NULL;
	prear = head;//尾部指针开始时等于头指针
	//初始化缴费链表
	head1 = (fee*)malloc(sizeof(fee));//创建头节点（缴费）后面的跟业主差不多
	if (head1 == NULL)
	{
		printf("内存分配失败\a\n");
		return 1;
	}
	strcpy(head1->add1, "");
	strcpy(head1->add2, "");
	strcpy(head1->add3, "");
	strcpy(head1->date, "");
	strcpy(head1->sum, "");
	strcpy(head1->yn, "");
	strcpy(head1->date2, "");
	head1->next1 = NULL;
	prear1 = head1;//尾部指针
	///////////////////////////////////
	loadusers();//从文件加载业主和缴费结构体
	loadfee();
	//////////////////////////////////
	while (1)
	{
		int tmp = 0;//接收指令
		qidong();//打开启动界面
		scanf("%d", &tmp);
		if (tmp == 1)
		{
			if (signin() == 0)//登录成功
			{
				while (1)
				{
					caozuo();//打开操作页面
					int a=tiaozhuan();//调用跳转到功能后成功返回1
					if(a==1)
					{
						break;
					}
				}
			}
			else
			{
				continue;//登录失败
			}
		}
		else if (tmp == 2)//退出
		{
			freeList();//释放内存
			return 0;
		}
		else if (tmp == 3)//注册
		{
			if (zhuce() == 0)//注册成功
			{
				while (1)//和登录基本一样
				{
					caozuo();
					int a = tiaozhuan();
					if (a == 1)
					{
						break;
					}
				}
			}
			else
			{
				continue;
			}
		}
		else if (tmp == 4)
		{
			zhaohui();//找回密码
			continue;
		}
		else
		{
			printf("错误的指令，请重新输入\n\a");
			continue;
		}
	}
}
