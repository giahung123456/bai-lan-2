#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCategories();
                
                break;
            case 2:
            	printf("---------them danh muc----------\n");
                addCategory();
                break;
            case 3:
            	printf("---------sua danh muc----------\n");
                editCategory();
                break;
            case 4:
            	printf("---------xoa danh muc----------\n");
                deleteCategory();
                break;
            case 5:
            	printf("---------tim kiem danh muc----------\n");
                searchCategory();
                break;
            case 6:
            	printf("---------sap xep danh muc----------\n");
                sortCategories();
                break;
            case 7:
            	printf("---------Luu du lieu----------\n");
                saveData();
                break;
            case 8:
            	printf("---------doc du lieu tu file----------\n");
                loadData();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 9);

	return 0;
}