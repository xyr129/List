# include<stdio.h>
# include<assert.h>
# include<stdlib.h>

typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
}ListNode;

ListNode* BuyNode(DataType x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof (ListNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void print(ListNode* pHead)
{
	ListNode* cur = pHead;
	while (cur)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void PushBack(ListNode*& pHead, DataType x)
{
	if (NULL == pHead)
	{
		pHead = BuyNode(x);
		return;
	}
	else
	{
		ListNode* tail = pHead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
}
void PopBack(ListNode*& head)
{
	if (NULL == head)
	{
		printf("list is empty!\n");
		return;
	}
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		ListNode *prev = NULL, *tail = head;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}

void PushFront(ListNode*& head, DataType x)
{
	if (NULL == head)
	{
		head = BuyNode(x);
	}
	else
	{
		ListNode* tmp = BuyNode(x);
		tmp->next = head;
		head = tmp;
	}
}

void PopFront(ListNode*& head)
{
	if (NULL == head)
	{
		printf("empty!\n");
		return;
	}
	ListNode* prev = head;
	prev = head->next;
	free(head);
	head = prev;
}

void Insert(ListNode* pos, DataType x)
{
	assert(pos);
	ListNode* tmp = BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void Erase(ListNode* pos, ListNode*& head)
{
	assert(pos);
	ListNode* prev = NULL, *cur = head;
	while (cur)
	{
		if (cur == pos)
		{
			prev->next = cur->next;
			free(cur);
			cur = NULL;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	printf("the position not exist\n ");
}

ListNode* Find(ListNode* head, DataType x)
{
	ListNode* cur = head;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Remove(ListNode*& head, DataType x)
{
	ListNode* tmp = Find(head, x);
	if (NULL != tmp)
	{
		Erase(tmp, head);
	}
	else
	{
		printf("%d is not exsit\n");
	}
}


int getLength(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void Swap(DataType* x, DataType* y)
{
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

/*ɾ��һ����ͷ������ķ�β���*/
/*��pos->next��ֵ��pos,Ȼ��ɾ��pos->next*/
void DelNonTailNode(ListNode* pos)
{
	assert(pos && pos->next);
	pos->data = pos->next->data;
	ListNode* _next = pos->next->next;
	free(pos->next);
	pos->next = NULL;
	pos->next = _next;
}

/*����ͷ�������ͷ���ǰ������*/
/*��pos�������ڵ㣬����pos��pos->next��data*/
void InsertFrontNode(ListNode* pos, DataType x)
{
	assert(pos);
	ListNode* tmp = BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
	Swap(&pos->data, &tmp->data);
}

/*����������*/
void Reverse(ListNode*& pHead)
{
	ListNode* cur = pHead;
	ListNode* newHead = NULL;
	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;
	}
	pHead = newHead;
}

/*����һ�β����м���*/
ListNode* FindMidNode(ListNode* pHead)
{
	assert(pHead);
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*����һ�β��ҵ����ڸ����*/
/*fastָ������k��������ָ����һ���ߣ���fastָ��ָ���ʱ������slow*/
ListNode* FindBackNode(ListNode* pHead, int k)
{
	assert(pHead);
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (k != 0 && fast)
	{
		fast = fast->next;
		k--;
	}
	if (k != 0)
	{
		printf("the node not exsit!\n");
		return NULL;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

/*������ð������*/
void BubbleSort(ListNode*& pHead)
{
	int flag = 0;
	int count = getLength(pHead);
	int len = count;
	ListNode* cur = NULL;
	while (count)
	{
		cur = pHead;
		len = count - 1;
		while (len)
		{
			if (cur->data > cur->next->data)
			{
				Swap(&cur->data, &cur->next->data);
				flag = 1;
			}
			cur = cur->next;
			len -= 1;
		}
		if (0 == flag)
		{
			return;
		}
		count -= 1;
	}
}

/*������ѡ������*/
void SelectSort(ListNode*& pHead)
{
	ListNode* cur = pHead;
	ListNode* prev = cur;
	while (prev)
	{
		cur = prev->next;
		while (cur)
		{
			if (prev->data > cur->data)
			{
				Swap(&prev->data, &cur->data);
			}
			cur = cur->next;
		}
		prev = prev->next;
	}
}

void DestoryList(ListNode*& pHead)
{
	ListNode* cur = pHead;
	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
}

