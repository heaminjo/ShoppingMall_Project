#pragma once
#include "class.h"
#include "Admin.h"
void JoinMenu();
void NotJoinMenu();

struct Member{       //회원
	char id[30];
	char pw[30];
	char name[10];
	int age;
};
struct MemberPage {  //회원 페이지
	Member* data;
	List* basket;   //장바구니
	List* buyList;  //구매목록
	List* scrap;    //찜
};

void JoinMenu() {              //회원 메뉴
	printf("1. 장바구니\n");
	printf("2. 찜\n");
	printf("3. 구매목록\n");
	printf("4.로그아웃\n");
	printf("\n");
}
void NotJoinMenu() {             //비회원 메뉴
	printf("1. 로그인\n");
	printf("2. 회원가입\n");
	printf("3. 종료\n");
}
