#pragma once
#include "class.h"
//2.카테고리 리스트에 카테고리 스택 추가
void Category_Push(List* list) {
	printf("\n");
	printf("카테고리를 추가합니다.\n");
	Stack* category = create_Stack();  //카테고리 반환
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

//스택에 저장 함수
void Stack_Push(Stack* stack, Product* product) {
	Product* top = stack->top;
	int count = stack->count;
	if (count == 0) {
		stack->top = product;
	}
	else{
		product->next = top;
		stack->top = product;
	}
	stack->count++;
}

//카테고리 리스트 안 스택에 상품저장
void List_Push(List* CategoryList, Product* product, int count) {
	Stack* pre = CategoryList->head;
	if (count == 1) {
		Stack_Push(pre, product);
	}
	else if (count > 1) {
		for (int i = 0; i < count-1; i++) {
			pre = pre->next;       //저장할 스택 찾기
		}
		Stack_Push(pre, product);  //스택 저장함수 호출
	}
	pre->count++;
}
