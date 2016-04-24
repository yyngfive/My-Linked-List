#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int num;
	struct Node *next;
};

typedef struct Node node;

/*初始化链表，即把链表置空
 *Value : head pointer
 *Return: head pointer
 **/
node *init(node *head);

/*创建链表
 * 即将数据写入链表
 * Value : head pointer's address
 * Return: false or true*/
bool create(node **head);

bool print(node *head);

bool clear_list(node *head);

int get_length(node *head);

/*******************************************************
**依据下标寻找数字
**方法：从链表头查找到尾
**TODO：可以改进效率
**Value  : head pointer(type:node),index number
**Return : 0 (error) or the number of 'idx'
*******************************************************/
int get_num_of_idx(node *head,int idx);

//依据数字寻找第一个出现位置的下标
//方法：从链表头找到尾
//TODO：可以改进效率
int get_idx_of_num(node *head,int number);

/*对链表进行排序
 *采用冒泡排序方法
 *TODO:循环次数过多，可以改进
 *TODO:排序算法可以改进
 *Value ：head pointer's address
 *Return: false or true
 * */
bool sort_list(node **head);

