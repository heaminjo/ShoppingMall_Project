#include "class.h"
#include "Admin.h"
#include "Customer.h"
int main(void) {
	int select;
	List* CategoryList = new List();  //ī�װ� ����Ʈ
	Stack* MainStack = new Stack();
	while (1) {
		MainManu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: { //�� ������
			print_Stack(MainStack);
			Customer_Page();
			break;
		}
		case 2: {  //������ ������
			Admin_Page();
			scanf_s("%d", &select);
			switch (select)
			{
			case 1: { //ī�װ� �߰�
				Category_Push(CategoryList);
				break;
			}
			case 2: {  //��ǰ �߰�
				int num;

				print_Category(CategoryList);
				printf("��ǰ ī�װ�:");
				scanf_s("%d", &num);

				//���� ī�װ� ��ȣ �� ���� ��ȣ�� �����
				if (num > CategoryList->count) {
					printf("�߸��� ��ȣ�Դϴ�.");
					break;
				}
				Product* product = create_product();
				List_Push(CategoryList, product,num); //ī�װ� ��ǰ �߰�
				Stack_Push(MainStack, product); //���� ��ǰ �߰�
				break;
			}
			case 5: {
				break;
			}
			default:
				printf("�ٽ� �Է����ּ���.");
				break;
			}
		}
			  system("pause");
			  system("cls");
		}
	}
	return 0;
}