#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//상품
struct Product {
	char name[30];
	int price;
	char type[30];
	char category[30];
	Product* next;
};

//카테고리
struct Stack {
	char category_Name[30];
	Product* data;
	Product* top;
	int count;
	Stack* next;
};

//상품 카테고리들을 저장할 리스트
struct List {
	Stack* data;
	Stack* head;
	int count;
};

//카테고리 리스트 초기화
List* create_List() {
	List* list = new List;
	memset(list, NULL, sizeof(list));
  	list->count = 0;

	return list;
}

//카테고리 출력
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
	printf("=====상품 목록=====\n");
	for (int i = 0; i < stack->count; i++) {
		printf("[상품명]: %s\n", top->name);
		printf("[상품 타입]: %s\n", top->type);
		printf("[가격]: %d\n", top->price);
		printf("\n");
		
		top = top->next;
	}
	printf("=================\n");
	printf("\n");
}
//스택 초기화
Stack* create_Stack() {
	Stack* stack = new Stack;
	memset(stack, NULL, sizeof(stack));
	char name[30];
	printf("카테고리 이름 입력:");
	scanf_s("%s", name, sizeof(name));
	strcpy(stack->category_Name, name);
	stack->count = 0;

	return stack;
}
void MainManu() {
	printf("======메인 메뉴======\n");
	printf("1.고객 페이지\n");
	printf("2.관리자 페이지\n");
	printf("\n");
	printf("입력:");
}
void Customer_Page() {
	printf("======고객 페이지======\n");
}
void Admin_Page() {
	printf("======관리자 페이지======\n");
	printf("1.카테고리 추가\n");
	printf("2.상품 추가\n");
	printf("3.상품 제거\n");
	printf("4.매출현황\n");
	printf("5.종료\n");
	printf("\n");
	printf("입력:");
}
/*
//메인 스택 추가
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
	printf("[%s 목록]\n", category);
	Expend* top = stack->top;

	for (int i = 0; i < stack->count; i++) {
		printf("소비내용:%s\n", top->name);
		printf("금액:%d\n", top->price);
		printf("----------------\n");
		top = top->next;
	}
}
void print(Stack* main, Stack* food, Stack* health, Stack* life) {
	int select;

	printf("=====통계=====\n");
	printf("☆총 지출 금액☆:%d원\n", main->money);
	printf("\n");
	printf("[식비]:%d원\n", food->money);
	printf("[건강]:%d원\n", health->money);
	printf("[문화]:%d원\n", life->money);

	printf("\n");
	printf("---상세보기---\n");
	printf("1.식비 / 2.건강 / 3.문화 / 9.보지않음\n");
	printf("번호 선택:");
	scanf_s("%d", &select);

	switch (select)
	{
	case 1: {
		char cate[10] = "식비";
		detail_Print(food, cate);
		break;
	}
	case 2: {
		char cate[10] = "건강";
		detail_Print(health, cate);
		break;
	}
	case 3: {
		char cate[10] = "문화";
		detail_Print(life, cate);
		break;
	}
	case 9:
		printf("메인으로 돌아갑니다.\n");
		break;
	}
}
*/
