#include "class.h"
#include "Admin.h"
#include "Customer.h"
bool on = false;

//Admin
List* create_List(); //리스트 생성 및 초기화
CategoryList* create_CategoryList(); //카테고리 리스트 생성 및 초기화
List* Category_Find(CategoryList* CategoryList, int count); //카테고리 탐색
void Product_Push(List* list, Product*product,int *number); //상품 추가
void Remove_Product(List* list, int number); //상품 제거
void print_CategoryNum(CategoryList* list); //카테고리 선택 창
void print_List(List* list); //리스트 출력

//Customer
void JoinMenu(); //회원 메뉴
void NotJoinMenu(); //비회원 메뉴
bool Consent();     //회원 가입 동의 여부
Member_List* create_MemberList(); // 회원 목록 생성 및 초기화
bool OverLap_Check(Member_List* list, char id[]); //아이디 중복 체크
bool Password_Check(char pw[], char pw2[]); //비밀번호 재확인 체크
Member* create_Member(Member_List* list);//회원 정보 입력 후 생성
void Member_Push(Member_List* list, Member* member);//회원 저장

int main(void) {
	int select;
	CategoryList* categoryList = create_CategoryList();  //카테고리 리스트
	List* Represent = create_List();  //대표 카테고리
	Member_List* MemberList = create_MemberList();  //회원 리스트
	while (1) {
		MainManu();
		select = choice();
		switch (select)
		{
		case 1: { //고객 페이지
			print_List(Represent);
			Customer_Page();
			select = choice(); 
			switch (select)
			{
			case 1: {  //카테고리
				break;
			}
			case 2: {  //찜
			}
			case 3: {  //마이페이지
				if (on == true) {           //로그인 on
					JoinMenu();
					select = choice();
				}
				else if(on == false) {      //로그인 off
					NotJoinMenu();
					select = choice();
					switch (select)
					{
					case 1: { //로그인

					}
					case 2: { //회원가입
						bool check;

						//회원가입 동의 여부체크
						check = Consent();
						if (check == false) {
							printf("메인으로 돌아갑니다.\n");
							break;
						}
						else if (check == true) {
							Member* member = create_Member(MemberList);
							Member_Push(MemberList, member);
							printf("회원가입이 성공적으로 끝났습니다.\n");
							printf("\n");
						}
						break;
					}
					default:
						break;
					}
				}
				}
			break;
		}
		case 2: {  //관리자 페이지
			Admin_Page();
			select = choice();
			switch (select)
			{
			case 1: { //카테고리 추가
				Category_Push(categoryList);
				break;
			}
			case 2: {  //대표 카테고리 설정
			print_CategoryNum(CategoryList);
			select = choice();

			Represent= Category_Find(CategoryList, select);				printf("대표 카테고리가 설정 되었습니다.\n");
			break;
			}
			case 3: {  //상품 추가
				//카테고리가 없는 경우
				if (categoryList->count == 0) {
					printf("카테고리가 없습니다.\n");
					break;
				}
				print_Category(categoryList);
				select = choice();

				//만약 카테고리 번호 중 없는 번호를 고를경우
				if (select > categoryList->count) {
					printf("잘못된 번호입니다.");
					break;
				}

				List* categoryList = Category_Find(CategoryList,select); //추가할 카테고리 가져오기
				Product* product = create_product();
				Product_Push(categoryList,product,&number);
				number++;
				break;
			}
			case 4: {  //상품 제거
				
				if (CategoryList->count == 0) {
					printf("카테고리가 없습니다.\n");
					break;
				}
				print_Category(CategoryList); 
				select = choice();  //카테고리 선택
				List* categorylist = Category_Find(CategoryList, select); //추가할 카테고리 가져오기
				if (categorylist->count == 0) {
					printf("상품이 없습니다.\n");
					break;
				}
				print_List(categorylist);
				select = choice();  //상품 선택
				
				Remove_Product(categorylist, select);
				break;
			}
			case 5: {
				break;
			}
			default:
				printf("다시 입력해주세요.");
				break;
			}
		}
			  system("pause");
			  system("cls");
		}
	}
	return 0;
}
