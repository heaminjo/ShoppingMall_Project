#pragma once
#include "class.h"
#include "Admin.h"

struct Member{       //회원
	char id[30];
	char pw[30];
	char name[10];
	int age;
	Member* next;
	Member* prev;
};
struct Member_Page {  //회원 페이지
	Member* data;
	List* basket;   //장바구니
	List* buyList;  //구매목록
	List* scrap;    //찜
};
struct Member_List { // 추가 !
	Member* head;
	Member* tail;
	int count;
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
void ShoppingMenu() {
	printf("1. 구매하기\n");
	printf("2. 찜하기\n");
	printf("3. 장바구니 넣기\n");
	printf("4.로그아웃\n");
	printf("\n");
}
void GoBack() {
	printf("1. 쇼핑한다.\n");
	printf("2. 뒤로가기.\n");
}

Member_List* create_MemberList() {
	Member_List* list = new Member_List;
	memset(list, NULL, sizeof(list));
	list->count = 0;

	return list;
}
Member_Page* create_Page() {
	Member_Page* list = new Member_Page;
	memset(list, NULL, sizeof(list));

	return list;
}
bool Consent() { //회원가입 동의 출력
	char result;
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
		int check=1;
		Member* temp = list->head;
		for (int i = 0; i < list->count; i++) {
			check = strcmp(temp->id, id);
			if (check ==0) {
				return true;
			}
			temp = temp->next;
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
//회원 초기화
Member* create_Member() {
	Member* member = new Member();
	memset(member, NULL, sizeof(member));

	return member;
}
Member* create_Member_Data(Member_List* list, Member* member) {
	bool check;
	
	char id[30];
	char pw[30];
	char pw2[30];
	char name[10];
	int age;

	printf("\n");
	//아이디 중복 검사
	while (1) {         
		printf("아이디:");
		scanf_s("%s", id, sizeof(id));

		check = OverLap_Check(list, id); //아이디 중복 체크

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
//회원페이지에 로그인 회원 저장
void Page_Login(Member_Page* page, Member* member) {
	page->data = member;
	printf("로그인에 성공하셨습니다.\n");
}
//일치하는 Member변수 탐색
bool Login_Member_Search(Member_Page* page,Member_List* list,char* id,char* pw) {
	Member* member = list->head;
	int str1, str2;

	for (int i = 0; i < list->count; i++) {
		str1 = strcmp(member->id, id);
		str2 = strcmp(member->pw, pw);
		//둘다 일치 할경우 로그인 후 true 리턴
		if (str1 == 0 && str2 == 0) {
			Page_Login(page, member);
			return true;
		}
		member = member->next;
	}
	//일치하는것이 없을 경우 그대로 false 리턴
	return false;
}
//아이디 입력
char* ID_Enter() {
	char* ptr = (char*)malloc(sizeof(char) * 30);
	char id[30];

	printf("아이디:");
	scanf_s("%s", id, sizeof(id));

	strcpy(ptr, id);
	return ptr;
}
//비밀번호 입력
char* Password_Enter() {
	char* ptr = (char*)malloc(sizeof(char) * 30);
	char pw[30];
	printf("비밀번호:");
	scanf_s("%s", pw, sizeof(pw));

	strcpy(ptr, pw);
	return ptr;
}
bool Login(Member_Page* page, Member_List* list) {
	bool check;
	//아이디&비밀번호 입력
	char* id = ID_Enter();
	char* pw = Password_Enter();

	check = Login_Member_Search(page,list, id, pw);
	return check;
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
//회원페이지 출력
void Page_print(Member_Page* page) {
	Member* member = page->data;

	printf("%s님 환영합니다.\n", member->name);
}

