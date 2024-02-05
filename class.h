#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ǰ
struct Product {
	char name[30];
	int price;
	char type[30];
	char category[30];
	Product* next;
};

//ī�װ�
struct Stack {
	char category_Name[30];
	Product* data;
	Product* top;
	int count;
	Stack* next;
};

//��ǰ ī�װ����� ������ ����Ʈ
struct List {
	Stack* data;
	Stack* head;
	int count;
};

//ī�װ� ����Ʈ �ʱ�ȭ
List* create_List() {
	List* list = new List;
	memset(list, NULL, sizeof(list));
  	list->count = 0;

	return list;
}

//ī�װ� ���
void print_Category(List*list) {
	Stack* pre = list->head;

	for (int i = 0; i < list->count; i++) {
		printf("%d. %s\n", i+1,pre->category_Name);
		pre = pre->next;
	}
	printf("\n");
}
void print_Stack(Stack* stack) {
	Product* top = stack->top;
	printf("=====��ǰ ���=====\n");
	for (int i = 0; i < stack->count; i++) {
		printf("[��ǰ��]: %s\n", top->name);
		printf("[��ǰ Ÿ��]: %s\n", top->type);
		printf("[����]: %d\n", top->price);
		printf("\n");
		
		top = top->next;
	}
	printf("=================\n");
	printf("\n");
}
//���� �ʱ�ȭ
Stack* create_Stack() {
	Stack* stack = new Stack;
	memset(stack, NULL, sizeof(stack));
	char name[30];
	printf("ī�װ� �̸� �Է�:");
	scanf_s("%s", name, sizeof(name));
	strcpy(stack->category_Name, name);
	stack->count = 0;

	return stack;
}
void MainManu() {
	printf("======���� �޴�======\n");
	printf("1.�� ������\n");
	printf("2.������ ������\n");
	printf("\n");
	printf("�Է�:");
}
void Customer_Page() {
	printf("======�� ������======\n");
}
void Admin_Page() {
	printf("======������ ������======\n");
	printf("1.ī�װ� �߰�\n");
	printf("2.��ǰ �߰�\n");
	printf("3.��ǰ ����\n");
	printf("4.������Ȳ\n");
	printf("5.����\n");
	printf("\n");
	printf("�Է�:");
}
/*
//���� ���� �߰�
void add(Stack* stack, Expend* ex) {
	if (stack == 0) {
		stack->top = ex;
	}
	else {
		ex->next = stack->top;
		stack->top = ex;
	}
	stack->data = ex;
	stack->money += ex->price;
	stack->count++;
}
void detail_Print(Stack* stack, char category[]) {
	printf("\n");
	printf("[%s ���]\n", category);
	Expend* top = stack->top;

	for (int i = 0; i < stack->count; i++) {
		printf("�Һ񳻿�:%s\n", top->name);
		printf("�ݾ�:%d\n", top->price);
		printf("----------------\n");
		top = top->next;
	}
}
void print(Stack* main, Stack* food, Stack* health, Stack* life) {
	int select;

	printf("=====���=====\n");
	printf("���� ���� �ݾס�:%d��\n", main->money);
	printf("\n");
	printf("[�ĺ�]:%d��\n", food->money);
	printf("[�ǰ�]:%d��\n", health->money);
	printf("[��ȭ]:%d��\n", life->money);

	printf("\n");
	printf("---�󼼺���---\n");
	printf("1.�ĺ� / 2.�ǰ� / 3.��ȭ / 9.��������\n");
	printf("��ȣ ����:");
	scanf_s("%d", &select);

	switch (select)
	{
	case 1: {
		char cate[10] = "�ĺ�";
		detail_Print(food, cate);
		break;
	}
	case 2: {
		char cate[10] = "�ǰ�";
		detail_Print(health, cate);
		break;
	}
	case 3: {
		char cate[10] = "��ȭ";
		detail_Print(life, cate);
		break;
	}
	case 9:
		printf("�������� ���ư��ϴ�.\n");
		break;
	}
}
*/
