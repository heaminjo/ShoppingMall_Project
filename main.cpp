#include "class.h"
#include "Admin.h"
#include "Customer.h"
int main(void) {
	int select;
	List* CategoryList = new List();  //카테고리 리스트
	Stack* MainStack = new Stack();
	while (1) {
		MainManu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: { //고객 페이지
			print_Stack(MainStack);
			Customer_Page();
			break;
		}
		case 2: {  //관리자 페이지
			Admin_Page();
			scanf_s("%d", &select);
			switch (select)
			{
			case 1: { //카테고리 추가
				Category_Push(CategoryList);
				break;
			}
			case 2: {  //상품 추가
				int num;

				print_Category(CategoryList);
				printf("상품 카테고리:");
				scanf_s("%d", &num);

				//만약 카테고리 번호 중 없는 번호를 고를경우
				if (num > CategoryList->count) {
					printf("잘못된 번호입니다.");
					break;
				}
				Product* product = create_product();
				List_Push(CategoryList, product,num); //카테고리 상품 추가
				Stack_Push(MainStack, product); //메인 상품 추가
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