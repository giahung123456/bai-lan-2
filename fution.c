#include <stdio.h>
#include"fution.h"
#include<string.h>
//#include <string.h>
//khai bao logic ham
// Ham hien thi menu
void displayMenu() {
    printf("\n=== Menu Quan ly Danh Muc ===\n");
    printf("1. Hien thi danh sach danh muc\n");
    printf("2. Them danh muc\n");
    printf("3. Sua danh muc\n");
    printf("4. Xoa danh muc\n");
    printf("5. Tim kiem danh muc theo ten\n");
    printf("6. Sap xep danh muc theo ten\n");
    printf("7. Luu du lieu\n");
    printf("8. Doc du lieu tu file\n");
    printf("9. Thoat\n");
    printf("===============================\n");
    printf("Nhap lua chon: ");
}

// Ham hien thi danh sach danh muc
void displayCategories(Category categories[], int categoryCount) {
	int col1_width = 5;
    int col2_width = 20; 
	printf("   Danh sach danh muc:                                     |\n");
	printf("------------------------------                             |\n");
//	printf("  ID\t|   Ten danh muc\n");
	printf("| %-*s | %-*s |                           |\n", col1_width, "ID", col2_width, "Ten danh muc");
	printf("-------------------------------                            |\n");
    for (int i = 0; i < categoryCount; i++) {
        //printf("%d\t| %s\n", categories[i].id, categories[i].list); 
		printf("| %-*d | %-*s |                           |\n", col1_width,categories[i].id , col2_width,categories[i].list ); 
        printf("------------------------------                             |\n");
    }
    returnMenu();  // Quay lai menu
}

// Ham them danh muc
void addCategory(Category categories[], int *categoryCount) {
    Category newCategory;
     int width = 52;
     
    printf("Nhap ID danh muc:                                          |");
    scanf("%d", &newCategory.id);
    getchar();  // Xoa ky tu '\n' con lai sau scanf
	printf("ID la: %-*d|\n",width,newCategory.id);
    // Kiem tra trung ID
    for (int i = 0; i < *categoryCount; i++) {
        if (categories[i].id == newCategory.id) {
            printf("ID danh muc da ton tai.                                    |\n");
            printf("------------------------------------------------------------\n");
            return;
        }
    }

    printf("Nhap ten danh muc:                                         |");
    fgets(newCategory.list, 100, stdin);  
    newCategory.list[strcspn(newCategory.list, "\n")] = '\0';  // Xoa ky tu '\n'
	printf("Danh muc la:%-47s|\n",newCategory.list);
    categories[*categoryCount] = newCategory;
    (*categoryCount)++;
    printf("Danh muc da duoc them thanh cong!                          |\n");
    returnMenu();  // Quay lai menu
}

// Ham sua danh muc
void editCategory(Category categories[], int categoryCount) {
    int id;
    int w1 = 47;
    printf("Nhap ID danh muc can sua:                                  |");
    scanf("%d", &id);
    getchar();  // Xoa ky tu '\n'
	printf("ID hien tai:%-*d|\n",w1,id);
    int found = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (categories[i].id == id) {
            found = 1;
            printf("Nhap ten moi cho danh muc:                                 |");
            fgets(categories[i].list, 100, stdin);  
            categories[i].list[strcspn(categories[i].list, "\n")] = '\0';  // Xoa ky tu '\n'
            printf("danh muc moi:%-46s|\n",categories[i].list);
            printf("Danh muc da duoc sua thanh cong!                           |\n");
            break;
        }
    }

    if (!found) {
        printf("Danh muc voi ID %d khong ton tai.                           |\n", id);
    }
    returnMenu();  // Quay lai menu
}

// Ham xoa danh muc
void deleteCategory(Category categories[], int *categoryCount) {
    int id;
    int w2=47;
    printf("Nhap ID danh muc can xoa:                                  |");
    scanf("%d", &id);
    getchar();  // Xoa ky tu '\n'
    printf("ID danh muc:%-*d|\n",w2,id);

    int found = 0;
    for (int i = 0; i < *categoryCount; i++) {
        if (categories[i].id == id) {
            found = 1;
            // Di chuyen cac muc sau len
            for (int j = i; j < *categoryCount - 1; j++) {
                categories[j] = categories[j + 1];
            }
            (*categoryCount)--;  // Giam so luong danh muc
            printf("Danh muc voi ID %d da duoc xoa thanh cong!                  |\n", id);
            break;
        }
    }

    if (!found) {
        printf("Danh muc voi ID %d khong ton tai.                           |\n", id);
    }
    returnMenu();  // Quay lai menu
}

// Ham tim kiem danh muc theo ten
void searchCategory(Category categories[], int categoryCount) {
    char list[100];
    int w3=50;
    int col3_width = 2;
    int col4_width = 46;
    printf("Nhap ten danh muc can tim:                                 |");
    getchar();  // Xoa ky tu '\n' con lai
    fgets(list, 100, stdin);
    list[strcspn(list, "\n")] = '\0';  // Xoa ky tu '\n'
	printf("ten can tim:%-47s|\n",list);
    int found = 0;
    printf("Ket qua tim kiem:                                          |\n");
    for (int i = 0; i < categoryCount; i++) {
        if (strstr(categories[i].list, list)) {  
            printf("ID: %-*d, Ten: %-*s|\n",col3_width, categories[i].id,col4_width, categories[i].list);  
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay danh muc nao.                               |\n");
    }
    returnMenu();  // Quay lai menu
}

// Ham sap xep danh muc theo ten
void sortCategories(Category categories[], int categoryCount) {
    for (int i = 0; i < categoryCount - 1; i++) {
        for (int j = i + 1; j < categoryCount; j++) {
            if (strcmp(categories[i].list, categories[j].list) > 0) {  
                Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }
    printf("Danh muc da duoc sap xep theo ten.\n");
    returnMenu();  // Quay lai menu
}

// Ham luu du lieu vao file
void saveData(Category categories[], int categoryCount) {
    FILE *file = fopen("categories.dat", "wb");
    if (file == NULL) {
    	printf("Khong the mo file de luu du lieu.                         |\n");
        return;
    }

    fwrite(&categoryCount, sizeof(int), 1, file);  // Luu so luong danh muc
    fwrite(categories, sizeof(Category), categoryCount, file);  // Luu danh muc vao file
    fclose(file);
    printf("Du lieu da duoc luu vao file.                              |\n");
    returnMenu();  // Quay lai menu
}

// Ham doc du lieu tu file
void loadData(Category categories[], int *categoryCount) {
    FILE *file = fopen("categories.dat", "rb");
    if (file == NULL) {
    printf("Khong the mo file de doc du lieu.                          |\n");
        return;
    }

    fread(categoryCount, sizeof(int), 1, file);  // Doc so luong danh muc
    fread(categories, sizeof(Category), *categoryCount, file);  // Doc danh muc tu file
    fclose(file);
    printf("Du lieu da duoc doc tu file.                               |\n");
    returnMenu();  // Quay lai menu
}

// Ham quay lai menu
void returnMenu() {
    printf("******Nhap so 0 de quay lai menu chinh.******              |");
    int choice;
    do {
                
        scanf("%d", &choice);
        
        if (choice != 0) {
            printf("Ban da nhap sai, hay bam lai so...                         |");
        }
    } while (choice != 0);  // Cho nguoi dung nhap lai cho den khi nhap so 0
    printf("-------------------------------------------------------------\n");
}
