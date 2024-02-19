#include "class.h"
#include "Admin.h"
#include "Customer.h"
bool on = false;

//Admin
List* create_List(); //리스트 생성 및 초기화
CategoryList* create_CategoryList(); //카테고리 리스트 생성 및 초기화
List* Category_Find(CategoryList* CategoryList, int count); //카테고리 탐색
void Product_Push(List* list, Product*product,int* number); //상품 추가
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
Member* create_Member(); //회원 생성 및 초기화
Member* create_Member_Data(Member_List* list,Member*member);//회원 정보 새로입력
void Member_Push(Member_List* list, Member* member);//회원 저장
void Member_Print(Member_List* list);  //회원 목록 출력
Member_Page* create_Page();   //회원페이지 생성 및 초기화
char* ID_Enter();  //아이디 입력
char* Password_Enter();  //비밀번호 입력

//아이디&비밀번호 일치 체크
bool Login_Member_Search(Member_Page* page, Member_List* list, char* id, char* pw);
void Page_Login(Member_Page* page, Member* member);//페이지에 로그인
void Page_print(Member_Page* page); //회원 페이지 출력

int main(void) {

	int select;
	CategoryList* CategoryList = create_CategoryList();  //카테고리 리스트
	List* Represent = create_List();
	Member_List* MemberList = create_MemberList();
	Member_Page* memberpage = create_Page();
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
				if (on == true) {
					Page_print(memberpage);
					JoinMenu();
					select = choice();
				}
				else if(on == false) {
					NotJoinMenu();
					select = choice();
					switch (select)
					{
					case 1: { //로그인
						bool check;
						while (1) {
							//아이디&비밀번호 입력
							char * id = ID_Enter();
							char* pw = Password_Enter();

							check = Login_Member_Search(memberpage, MemberList, id,pw);
							if (check == true) {
								on = true;
								break;
							}
							else {
								printf("아이디 또는 비밀번호가 틀렸습니다.\n");
							}
						}
						break;
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
							Member* member = create_Member();
							create_Member_Data(MemberList,member);
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
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2: {  //관리자 페이지
			Admin_Page();
			select = choice();
			switch (select)
			{
			case 1: { //카테고리 추가
				Category_Push(CategoryList);
				break;
			}
			case 2: {  //대표 카테고리 설정
				print_CategoryNum(CategoryList);
				select = choice();  //카테고리 선택

				Represent= Category_Find(CategoryList, select);
				printf("대표 카테고리가 설정 되었습니다.\n");
				break;
			}
			case 3: {  //상품 추가
				//카테고리가 없는 경우
				if (CategoryList->count == 0) {
					printf("카테고리가 없습니다.\n");
					break;
				}
				print_CategoryNum(CategoryList);
				select = choice();
				
				//만약 카테고리 번호 중 없는 번호를 고를경우
				if (select > CategoryList->count) {
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
				print_CategoryNum(CategoryList);
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
			case 5: {  //구매하기

			}
			case 6: {
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
