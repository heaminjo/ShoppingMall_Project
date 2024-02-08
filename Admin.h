#pragma once
#include "class.h"
//카테고리 추가
void Category_Push(CategoryList* list) {
	char name[30];
	printf("\n");
	printf("카테고리를 추가합니다.\n");
	printf("카테고리 이름:");
	scanf_s("%s", name, sizeof(name));

	List* category = create_List(); //카테고리 리스트 생성
	strcpy(category->CategoryName, name);
	int count = list->count;

	if (count == 0) {
		list->head = list->tail = category;
	}
	else {
		category->prev = list->tail;
		list->tail->next = category;
		list->tail = category;
	}
	list->count++;
}

//상품 추가
//1.상품 입력
//2.저장할 카테고리 입력
//스택에 상품 추가
Product* create_product() {
	Product* product = new Product();
	memset(product, NULL, sizeof(product));

	char name[30];
	int price;
	char type[30];

	printf("상품이름:");
	scanf_s("%s", name, sizeof(name));
	printf("가격:");
	scanf_s("%d", &price);
	printf("종류:");
	scanf_s("%s", type, sizeof(type));

	strcpy(product->name, name);
	strcpy(product->type, type);
	product->price = price;

	return product;
}
void Product_Push(List*list,Product*product) {
	strcpy(product->category, list->CategoryName);
	if (list->count == 0) {
		list->head = list->tail = product;
	}
	else {
		product->prev = list->tail;
		list->tail->next = product;
		list->tail = product;
	}
	list->count++;
}
//카테고리 탐색
List* Category_Find(CategoryList* CategoryList,int count) {
	List* pre = CategoryList->head;
	if (count == 1) {
		return pre;
	}
	else if (count > 1) {
		for (int i = 0; i < count - 1; i++) {
			pre = pre->next;       //저장할 스택 찾기
		}
	}
	return pre;
}

//상품 제거
void Remove_Product(List* list, int number) {
	Product* del = NULL;
	Product* pre = list->head;

	if (number == 1) {
		del = list->head;
		list->head = del->next;
	}
	else if (number > 1) {
		for (int i = 1; i < number-1; i++) {
			pre = pre->next;
		}
		del = pre->next;
		pre->next = del->next;
		del->next->prev = pre;
	}
	delete del;
	list->count--;
}

