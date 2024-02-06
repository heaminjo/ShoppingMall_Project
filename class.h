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
	Product* prev;
};

//상품 카테고리들을 저장할 리스트
struct List {
	char CategoryName[30];
	Product* head;
	Product* tail;
	List* next;
	List* prev;
	int count;
};
struct CategoryList {
	List* head;
	List* tail;
	int count;
};

//리스트 초기화
List* create_List() {
	List* list = new List;
	memset(list, NULL, sizeof(list));
  	list->count = 0;

	return list;
}
CategoryList* create_CategoryList() {
	CategoryList* list = new CategoryList;
	memset(list, NULL, sizeof(list));
	list->count = 0;

	return list;
}

//카테고리 출력
void print_Category(CategoryList*list) {
		List* pre = list->head;
		for (int i = 0; i < list->count; i++) {
			printf("%d. %s\n", i + 1, pre->CategoryName);
			pre = pre->next;
		}
		printf("\n");
}

//리스트 출력
void print_List(List*list) {
	Product* pre = list->head;
	if (list->count == 0) {
		printf("등록된 상품이 없습니다.");
	}
	else{
		printf("=====상품 목록=====\n");
		for (int i = 0; i < list->count; i++) {
			printf("%d\n", i + 1);
			printf("[상품명]: %s\n", pre->name);
			printf("[상품 타입]: %s\n", pre->type);
			printf("[가격]: %d\n", pre->price);
			printf("\n");

			pre = pre->next;
		}
		printf("=================\n");
	}
	printf("\n");
}

//선택 함수
int choice() {
	int choice;
	printf("입력:");
	scanf_s("%d", &choice);

	return choice;
}
void MainManu() {
	printf("======메인 메뉴======\n");
	printf("1.고객 페이지\n");
	printf("2.관리자 페이지\n");
	printf("\n");
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
}
