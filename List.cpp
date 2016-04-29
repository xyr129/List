#include"List.h"

void Test1(ListNode*& pHead)
{
	printf("Test1:\n");
	PushBack(pHead, 3);
	PushBack(pHead, 5);
	PushBack(pHead, 1);
	PushBack(pHead, 6);
	PushBack(pHead, 2);
	PushBack(pHead, 4);
	print(pHead);
	printf("冒泡排序：\n");
	BubbleSort(pHead);
	print(pHead);
	printf("逆置：\n");
	Reverse(pHead);
	print(pHead);
}

void Test2(ListNode*& pHead)
{
	printf("\nTest2:\n");
	pHead = NULL;
	PushBack(pHead, 3);
	PushBack(pHead, 5);
	PushBack(pHead, 1);
	PushBack(pHead, 6);
	PushBack(pHead, 2);
	PushBack(pHead, 4);
	print(pHead);
	printf("查找倒数第三个结点：\n");
	ListNode* tmp = FindBackNode(pHead, 3);
	printf("the node you found is %d\n", tmp->data);
	printf("在倒数第三个结点前插入结点:8\n");
	InsertFrontNode(tmp, 8);
	print(pHead);
	printf("选择排序：\n");
	SelectSort(pHead);
	print(pHead);
	printf("查找中间结点：\n");
	printf("the middle node is %d\n", FindMidNode(pHead)->data);
	printf("删除无头非尾结点：\n");
	DelNonTailNode(tmp);
	print(pHead);
}

int main()
{
	ListNode* list;
	list = NULL;
	Test1(list);
	Test2(list);
	DestoryList(list);
	system("pause");
	return 0;
}