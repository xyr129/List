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
	printf("ð������\n");
	BubbleSort(pHead);
	print(pHead);
	printf("���ã�\n");
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
	printf("���ҵ�����������㣺\n");
	ListNode* tmp = FindBackNode(pHead, 3);
	printf("the node you found is %d\n", tmp->data);
	printf("�ڵ������������ǰ������:8\n");
	InsertFrontNode(tmp, 8);
	print(pHead);
	printf("ѡ������\n");
	SelectSort(pHead);
	print(pHead);
	printf("�����м��㣺\n");
	printf("the middle node is %d\n", FindMidNode(pHead)->data);
	printf("ɾ����ͷ��β��㣺\n");
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