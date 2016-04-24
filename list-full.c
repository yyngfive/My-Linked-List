#include "head.h"

int main(int argc,char *argv)
{
	node *list;
	bool info;
	int length,num,pos;
	int c;
	list = NULL;
	printf("Please input:\n");
	//初始化与创建
	list = init(list);
	create(&list);

	//打印链表
	print(list);

	//得到长度
	length = get_length(list);
	printf("链表长度是%d\n",length);
	printf("请输入下标：");
	scanf("%d",&pos);

	//得到指定下标的数字
	num = get_num_of_idx(list,pos);
	printf("第%d位置的数字是%d\n",pos,num);
	setbuf(stdin,NULL);
	printf("请输入数字：");
	scanf("%d",&num);

	//得到指定数字出现的首个下标
	pos = get_idx_of_num(list,num);
	printf("数字【%d】首次出现在第%d位置\n",num,pos);
	
	//排序链表
	//从小到大
	info = sort_list(&list);
	
	if(info == true)
	{
		print(list);
	}
	else
	{
		printf("SORT WRONG !\n");
	}

	//清空，结束
	info = clear_list(list);
	if(info == true)
	{
		printf("链表清除成功！！\n");
	}
	setbuf(stdin,NULL);
	return 0;
}

node *init(node *head)
{
	head = NULL;
	return head;
}

bool create(node **head)
{
	node *p1,*p2;

	//初始化
	p1 = NULL;
	p2 = NULL;
	p1 = p2 = (node *)malloc(sizeof(node));

	//内存分配检查
	if(p1 == NULL || p2 == NULL)
	{
		return false;
	}

	//清空
	memset(p1,0,sizeof(node));

	//开始赋初值
	scanf("%d",&p1 -> num);

	//Init the next pointer;
	p1 -> next = NULL;
	
	while(p1 -> num != 0)
	{
		if(*head == NULL)
		{
			//接入表头
			*head = p1;
		}
		else
		{
			//如果不是空表，接入表尾
			p2 -> next = p1;
		}

		//用p2保存p1
		//如果p1接入表头，p2与head地址相同
		//如果p1接入了表尾，p2与p2next地址相同
		p2 = p1;

		//重新分配p1
		p1 = (node *)malloc(sizeof(node));
		if(p1 == NULL)
		{
			return false;
		}
		memset(p1,0,sizeof(node));
		scanf("%d",&p1 -> num);
		p1 -> next = NULL;
	}
	return true;
}

bool print(node *head)
{
	if(head == NULL)
	{
		return false;
	}
	else
	{
		while(head != NULL)
		{
			printf("%d\t",head -> num);
			head = head -> next;
		}
		printf("\n");
		return true;		
	}
}

bool clear_list(node *head)
{
	node *p_next;
	p_next = NULL;
	if(head == NULL)
	{
		return false;
	}
	else
	{
		//通过不停的地址交换来清空链表
		while(head != NULL)
		{
			p_next = head -> next;
			free(head);
			head = p_next;
		}
		return true;
	}
}

int get_length(node *head)
{
	int leng = 0;
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		while(head != NULL)
		{
			leng++;
			head = head -> next;		
		}
		return leng;
	}
}

int get_num_of_idx(node *head,int idx)
{
	int leng,number;
	leng = get_length(head);
	if(leng < idx || idx < 1)
	{
		return 0;
	}
	else
	{
		while(idx != 1)
		{
			idx--;
			head = head -> next;	
		}
		number = head -> num;
		return number;	
	}
}

int get_idx_of_num(node *head,int number)
{
	int idx = 0;
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		while(head != NULL)
		{
			idx++;
			if(number == head -> num)
			{
				return idx;
			}
			head = head -> next;	
		}
		return 0;
	}
}

bool sort_list(node **head)
{
	node *right,*left;
	int leng;
	int i,j;
	int tmp;
	leng = get_length(*head);
	if(*head == NULL)
	{
		return false;
	}
	else
	{
		for(i = 0;i < leng - 1;i++)
		{
			//回到表头
			right = (*head) -> next;
			left = *head;
			for(j = 0;j < leng - (1 + i);j++)
			{
				//开始排序
				if((left -> num) > (right -> num))
				{
					tmp = left -> num;
					left -> num = right -> num;
					right -> num = tmp;
				}
				right = right -> next;
				left = left -> next;
			}
		}
	return true;	
	}
}
