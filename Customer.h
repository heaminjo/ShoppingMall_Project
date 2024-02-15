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

Member_List* create_MemberList() {
	Member_List* list = new Member_List;
	memset(list, NULL, sizeof(list));
	list->count = 0;

	return list;
}

bool Consent() { //회원가입 동의 출력
	char result;
	printf("회원가입하는것에 동의합니까?(Y / N)\n");
	printf("입력:");

	scanf_s("%c", &result, sizeof(result));
	scanf_s("%c", &result, sizeof(result));
	if (result == 'Y') {
		return 1;
	}
	else if (result == 'N') {
		return 0;
	}
}
//아이디 중복 체크
bool OverLap_Check(Member_List* list, char id[]) {
	if (list->count == 0) {
		return false;
	}
	else {
		Member* temp = list->head;
		for (int i = 0; i < list->count; i++) {
			if (temp->id == id) {
				return true;
			}
		}
	}
	return false;
}
//비밀번호 재확인
bool Password_Check(char pw[],char pw2[]) {
	int check;
	check = strcmp(pw, pw2);

	if (check == 0) {
		return true;
	}
	else {
		return false;
	}
}
//회원 생성
Member* create_Member(Member_List * list) {
	bool check;
	Member* member= new Member();
	memset(member, NULL, sizeof(member));

	char id[30];
	char pw[30];
	char pw2[30];
	char name[10];
	int age;

	printf("\n");
	//아이디 중복 검사
	while (1) {         
		printf("아이디:");
		scanf_s("%s", name, sizeof(name));

		check = OverLap_Check(list, name);     //아이디 중복 체크
		if (check == true) {
			printf("중복된 아이디 입니다.\n다시 입력해주세요.\n");
		}
		else if (check == false) {
			printf("사용가능한 아이디 입니다.\n");
			break;
		}
	}
	//비밀번호 일치 검사
	while (1) {
		printf("비밀번호:");
		scanf_s("%s", pw, sizeof(pw));
		printf("비밀번호 확인:");
		scanf_s("%s", pw2, sizeof(pw2));

		check= Password_Check(pw, pw2);
		if (check == false) {
			printf("입력한 비밀번호가 일치 하지않습니다.\n다시 입력해주세요.\n");
		}
		else if(check = true) {
			break;
		}
	}
	printf("이름:");
	scanf_s("%s", name, sizeof(name));

	printf("나이:");
	scanf_s("%d", &age);
	printf("\n");

	strcpy(member->id, id);
	strcpy(member->pw, pw);
	strcpy(member->name, name);
	member->age = age;

	return member;
}
void Member_Push(Member_List* list, Member* member) {

	if (list->count == 0) {
		list->head = list->tail = member;
	}
	else {
		member->prev = list->tail;
		list->tail->next = member;
		list->tail = member;
	}
	list->count++;
}

//회원 목록
void Member_Print(Member_List* list) {
	Member* member = list->head;
	if (list->count == 0) {
		printf("등록된 회원이 없습니다.\n");
	}
	else {
		printf("=====회원 목록=====\n");
		for (int i = 0; i < list->count; i++) {
			printf("[이름]: %s\n", member->name);
			printf("[나이]: %d\n", member->age);
			printf("\n");

			member = member->next;
		}
		printf("=================\n");
	}
	printf("\n");
}
