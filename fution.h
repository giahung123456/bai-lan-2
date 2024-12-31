#include"dtp.h"

//khai bao nguyen mau ham

// Khai báo các hàm
void displayMenu();
void displayCategories(Category categories[], int categoryCount);
void addCategory(Category categories[], int *categoryCount);
void editCategory(Category categories[], int categoryCount);
void deleteCategory(Category categories[], int *categoryCount);
void searchCategory(Category categories[], int categoryCount);
void sortCategories(Category categories[], int categoryCount);
void saveData(Category categories[], int categoryCount);
void loadData(Category categories[], int *categoryCount);
void returnMenu();