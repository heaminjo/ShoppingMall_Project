#pragma once
#include "class.h"
//2.ī�װ� ����Ʈ�� ī�װ� ���� �߰�
void Category_Push(List* list) {
	printf("\n");
	printf("ī�װ��� �߰��մϴ�.\n");
	Stack* category = create_Stack();  //ī�װ� ��ȯ
	Stack* pre = list->head;
	int count = list->count;
	if (count == 0) {
		list->head = category;
	}
	else {
		for (int i = 0; i < count - 1; i++) {
			pre = pre->next;
		}
		pre->next = category;
	}
	list->count++;
}

//��ǰ �߰�
//1.��ǰ �Է�
//2.������ ī�װ� �Է�
//���ÿ� ��ǰ �߰�
Product* create_product() {
	Product* product = new Product();
	memset(product, NULL, sizeof(product));

	char name[30];
	int price;
	char type[30];

	printf("��ǰ�̸�:");
	scanf_s("%s", name, sizeof(name));
	printf("����:");
	scanf_s("%d", &price);
	printf("����:");
	scanf_s("%s", type, sizeof(type));

	strcpy(product->name, name);
	strcpy(product->type, type);
	product->price = price;

	return product;
}

//���ÿ� ���� �Լ�
void Stack_Push(Stack* stack, Product* product) {
	Product* top = stack->top;
	int count = stack->count;
	if (count == 0) {
		stack->top = product;
	}
	else{
		product->next = top;
		top = product;
	}
	stack->count++;
}

//ī�װ� ����Ʈ �� ���ÿ� ��ǰ����
void List_Push(List* CategoryList, Product* product, int count) {
	Stack* pre = CategoryList->head;
	if (count == 1) {
		Stack_Push(pre, product);
	}
	else if (count > 1) {
		for (int i = 0; i < count-1; i++) {
			pre = pre->next;       //������ ���� ã��
		}
		Stack_Push(pre, product);  //���� �����Լ� ȣ��
	}
	CategoryList->count++;
}