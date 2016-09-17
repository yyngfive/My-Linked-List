#include "list.h"

int main(int argc,char *argv)
{
	node *list;
	bool info;
	int length,*num,pos;
	int c;
	list = NULL;

	printf("请输入:\n");

	//初始化与创建
	list = list_init(list);     
	list_create(&list);

	//打印链表 Y
//	list_print(list);

	//得到长度 Y
	length = list_get_length(list);
	printf("链表长度是%d\n",length);

//	printf("请输入下标：");
//	scanf("%d",&pos);

	//得到指定下标的数字 Y
//	num = list_get_num_of_idx(list,pos);
//	printf("第%d位置的数字是%d\n",pos,*num);
//	setbuf(stdin,NULL);

//	printf("请输入数字：");
//	scanf("%d",&num);

	//得到指定数字出现的首个下标 Y
//	pos = list_get_idx_of_num(list,num);
//	printf("数字【%d】首次出现在第%d位置\n",num,pos);
	
	//排序链表
	//从小到大 Y
	/*
	info = list_sort(&list);
	
	if(info == true)
	{
		print(list);
	}
	else
	{
		printf("排序失败 !\n");

	}
	*/
	//修改数值 Y
	//list_modify_num(&list,1,25);
	//list_print(list);
	
	
	// 在表尾添加数据 Y
	/*
	info = list_add_end(&list,5712);
	if(info == true)
		printf("yes\n");
	else
		printf("no\n");
	length = list_get_length(list);
	printf("链表长度是%d\n",length);
        list_print(list);	
	*/

	//在表头添加数据 Y
	/*
	info = list_add_head(&list,1256);
	if(info == true)
		puts("yes");
	else
		puts("no");
	length = list_get_length(list);
	printf("链表长度是：%d\n",length);
	list_print(list);
	*/
	//依据索引添加数据 Y
	/*
	list_add_idx(&list,-1,123);
	list_print(list);
	list_add_idx(&list,0,456);
	list_print(list);
	list_add_idx(&list,1,789);
	list_print(list);
	list_add_idx(&list,2,159);
	list_print(list);
	list_add_idx(&list,4,654);
	list_print(list);
	list_add_idx(&list,123,753);
	list_print(list);
	list_add_idx(&list,6,999);
	list_print(list);
	*/
	//清空最后节点 Y
	/*	
	list_del_end(&list);
	list_print(list);
	length = list_get_length(list);
	printf("链表长度为:%d\n",length);
	*/
	//清空开头节点 Y
	/*
	list_del_head(&list);
	list_print(list);
	length = list_get_length(list);
	printf("链表长度为:%d\n",length);
	*/
	
	//依据索引删除数据 Y
	/*
	list_del_idx(&list,1);
	list_print(list);
	length = list_get_length(list);
	printf("链表长度为:%d\n",length);
	*/
	
	//删除第一个出现的指定数字，如需全部删除，可以多次调用 Y
	/*
	list_del_num(&list,5);
	list_print(list);
	list_del_num(&list,1);
	list_print(list);
	list_del_num(&list,6);
	list_print(list);
	info = list_del_num(&list,111111);	
	if(info == false)
		puts("NO!");
	length = list_get_length(list);
	printf("链表长度为:%d\n",length);
	*/

	//多次调用list_del_num Y
	/*
	info = true;
	while(info == true)
	{
		info=list_del_num(&list,2);
		list_print(list);
	}
	*/
	//清空，结束 Y
	info = list_clear(&list);
	if(info == true)
	{
		printf("链表清除成功！！\n");
	}
	else
	{
		printf("链表为空！\n");
	}
	length = list_get_length(list);
	printf("链表长度是%d\n",length);

	setbuf(stdin,NULL);
	return 0;
}

node *list_init(node *head)
{
	head = NULL;
	return head;
}

bool list_create(node **head)
{
	node *p1,*p2;
	p1 = NULL;
	p2 = NULL;

	p1 = p2 = (node *)malloc(sizeof(node));
	memset(p1,0,sizeof(node));

	p1 -> next = NULL;
	scanf("%d",&(p1 -> num));
	
	while(p1 -> num != 0)
	{
		if(*head == NULL)
		{
			*head = p1;
		}
		else
		{
			p2 -> next = p1;
		}
		p2 = p1;

		p1 = (node *)malloc(sizeof(node));
		memset(p1,0,sizeof(node));

		p1 -> next = NULL;
		scanf("%d",&(p1 -> num));

	}
	p1 = NULL;
	free(p1);
	return true;


}

//打印
bool list_print(node *head)
{
	if(head == NULL)
	{
		return false;
	}
	else 
	{	
		printf("打印:\n");
		while(head != NULL)
		{
			printf("\t%d\t\n",head -> num);
			head = head -> next;
		}
		printf("\n");
		return true;		
	}
}

//清空
bool list_clear(node **head)
{
	node *p_next;
	p_next = NULL;
	if(*head == NULL)
	{
		return false;
	}
	else
	{
		//通过不停的地址交换来清空链表
		while(*head != NULL)
		{
			p_next = (*head) -> next;
			free(*head);
			*head = p_next;
		}
		return true;
	}
}


//获得长度
int list_get_length(node *head)
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

int* list_get_num_of_idx(node *head,int idx)
{
	int leng,*number;
	leng = list_get_length(head);

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
		number =&(head -> num);
		return number;	
	}
}

int list_get_idx_of_num(node *head,int number)
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

bool list_sort(node **head)
{
	node *right,*left;
	int leng;
	int i,j;
	int tmp;
	leng = list_get_length(*head);
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

bool list_is_empty(node *head)
{
	if(head == NULL)
	
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool list_modify_num(node **head,int idx,int n)
{
	int leng;
	int *data;
	leng = list_get_length(*head);
	if(leng < idx||idx < 1)
	{
		return false;
	}
	else
	{
		data = list_get_num_of_idx(*head,idx);
		*data = n;
		return true;	
	}
}


bool list_add_end(node **head,int value)
{
	node *new = NULL;
	node *tmp = NULL;
	
	if(*head == NULL)
	{
		*head = (node*)malloc(sizeof(node));
		(*head) -> num = value;
		(*head) -> next = NULL;
		return true;
	}
	else
	{
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
		{
			return false;
		}
		memset(new,0,sizeof(node));

		new -> num = value;
		new -> next = NULL;

		tmp = *head;
	
		//将temp指向最后一个节点
	
		while(tmp -> next != NULL)
		{
			tmp = tmp -> next;
		}
	
	
		tmp -> next = new;

		return true;
	}
}

bool list_add_idx(node **head,int idx,int value)
{
	int leng;

	bool info;

	node *new = NULL;
	node *left = NULL;
	node *right = NULL;
	
	leng = list_get_length(*head);

	if(idx <= 1)
	{
		info = list_add_head(&(*head),value);
		return info;
	}
	else if(idx >= leng)
	{
		info = list_add_end(&(*head),value);
		return info;
	}
	else
	{
		left = *head;
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
			return false;
		memset(new,0,sizeof(node));
		new -> next = NULL;
		new -> num = value;
		
		for(idx;idx > 2;idx--)
		{	
			left = left -> next;
		}
		right = left -> next;

		left -> next = new;
		new -> next = right;
	
		return true;
	}
}

bool list_add_head(node **head,int value)
{
	node *new = NULL;
	node *tmp = NULL;

	bool info;

	if(*head == NULL)
	{
		info = list_add_end(&(*head),value);
		return info;
	}
	else
	{
		tmp = *head;
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
			return false;
		memset(new,0,sizeof(node));

		new -> num = value;
		new -> next = tmp;

		*head = new;
		
		return true;		
	}
}

bool list_del_all(node **head)
{
	bool info;
	info = list_clear(&(*head));
	return info;
}

bool list_del_head(node **head)
{
	node *tmp;
	node *old;

	if(list_is_empty(*head))
	{
		return false;
	}
	else
	{
		old = *head;
		tmp = *head;
		tmp = tmp -> next;

		old ->next = NULL;
		old = NULL;
		free(old);

		*head = tmp;
		return true;

	}
}

bool list_del_end(node **head)
{
	node *tmp;
	
	if(list_is_empty(*head) == true)
	{
		return false;
	}
	else
	{
		tmp = *head;
		while(tmp -> next -> next != NULL)
		{
			tmp = tmp -> next;
		}
		tmp -> next = NULL;
		free(tmp -> next);
		return true;
	}
}

bool list_del_idx(node **head,int idx)
{
	node *tmp;
	node *Last,*Next;
	int i;
	bool info;
	
	if(idx <= 1)
	{
		info = list_del_head(&(*head));
		return info;
	}
	else
	{
	
		tmp = *head;
		for(i = 1;i < (idx - 1);i++)
		{
			tmp = tmp -> next;
		}

		Last = tmp;
		tmp = tmp -> next;
		Next = tmp -> next;
	
		Last -> next = Next;

		tmp -> next = NULL;
		tmp = NULL;
		free(tmp);

		return true;
	}
}

bool list_del_num(node **head,int first_num)
{
	node *tmp;
	node *Last,*Next;
	bool info;
	if(*head == NULL)
		return false;

	if((*head) -> num == first_num)
	{
		info = list_del_head(&(*head));
		return info;
	}
	else
	{
		tmp = *head;
		while((tmp -> next) -> num != first_num)
		{
			tmp = tmp -> next;
			if(tmp -> next == NULL)
			{
				return false;
			}

		}
	
		Last = tmp;
		tmp = tmp -> next;
		Next = tmp -> next;

		Last -> next = Next;

		tmp -> next = NULL;
		tmp = NULL;
		free(tmp);

		return true;
	}
}
