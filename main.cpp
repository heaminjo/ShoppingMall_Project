#include "class.h"
#include "Admin.h"
#include "Customer.h"

//상품 추가를 2번 할수없는 오류
int main(void) {
	int select;
	CategoryList* categoryList = create_CategoryList();  //카테고리 리스트
	List* MainList =create_List();
	while (1) {
		MainManu();
		select = choice();
		switch (select)
		{
		case 1: { //고객 페이지
			print_List(MainList);
			Customer_Page();
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
			case 2: {  //상품 추가
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
				Product* product = create_product();
				List* list = Category_PushList(categoryList,select); //카테고리 상품 추가
				printf("리스트:%s 추가\n", list->CategoryName);
				Product_Push(MainList, product); //메인 상품 추가
				Product_Push(list, product);
				break;
			}
			case 3: {  //상품 제거
				
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
