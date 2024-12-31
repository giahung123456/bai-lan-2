#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include"fution.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	    Category categories[100];  // Mang danh muc
    int categoryCount = 3;  // So luong danh muc ban dau

    // Khoi tao mot so danh muc mau
    categories[0].id = 1;
    strcpy(categories[0].list, "do an");  

    categories[1].id = 2;
    strcpy(categories[1].list, "do uong");  

    categories[2].id = 3;
    strcpy(categories[2].list, "quan ao");  

    int choice;
    do {
        displayMenu();  // Hien thi menu
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("------------------------------------------------------------\n");  
                displayCategories(categories, categoryCount);  // Hien thi danh sach danh muc
                break;
            case 2:
                printf("------------------------------------------------------------\n");
                printf("                      Them danh muc                        |\n");
                addCategory(categories, &categoryCount);  // Them danh muc
                break;
            case 3:
            	printf("------------------------------------------------------------\n");
                printf("                      Sua danh muc                         |\n");
                editCategory(categories, categoryCount);  // Sua danh muc
                break;
            case 4:
            	printf("------------------------------------------------------------\n");
                printf("                       Xoa danh muc                        |\n");
                deleteCategory(categories, &categoryCount);  // Xoa danh muc
                break;
            case 5:
            	printf("------------------------------------------------------------\n");
                printf("                        Tim kiem danh muc                  |\n");
                searchCategory(categories, categoryCount);  // Tim kiem danh muc
                break;
            case 6:
            	printf("------------------------------------------------------------\n");
                printf("                       Sap xep danh muc                    |\n");
                sortCategories(categories, categoryCount);  // Sap xep danh muc
                break;
            case 7:
            	printf("------------------------------------------------------------\n");
                printf("                      Luu du lieu                          |\n");
                saveData(categories, categoryCount);  // Luu du lieu vao file
                break;
            case 8:
            	printf("------------------------------------------------------------\n");
                printf("                     Doc du lieu tu file                   |\n");
                loadData(categories, &categoryCount);  // Doc du lieu tu file
                break;
            case 9:
            	printf("------------------------------------------------------------\n");                
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 9);  // Lặp lại chương trình cho đến khi người dùng chọn thoát

    return 0;
}