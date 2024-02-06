#include "class.h"
#include "Admin.h"
#include "Customer.h"

//상품 추가를 2번 할수없는 오류
int main(void) {
	int select;
	List* CategoryList = new List();  //카테고리 리스트
	Stack* MainStack = new Stack();
	while (1) {
		MainManu();
		select = choice();
		switch (select)
		{
		case 1: { //고객 페이지
			print_Stack(MainStack);
			Customer_Page();
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
			case 2: {  //상품 추가
				//카테고리가 없는 경우
				if (CategoryList->count == 0) {
					printf("카테고리가 없습니다.\n");
					break;
				}
				print_Category(CategoryList);
				select = choice();

				//만약 카테고리 번호 중 없는 번호를 고를경우
				if (select > CategoryList->count) {
					printf("잘못된 번호입니다.");
					break;
				}
				Product* product = create_product();
				List_Push(CategoryList, product,select); //카테고리 상품 추가
				Stack_Push(MainStack, product); //메인 상품 추가
				break;
			}
			case 3: {  //상품 제거
				print_Stack(MainStack);
				select = choice();
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
