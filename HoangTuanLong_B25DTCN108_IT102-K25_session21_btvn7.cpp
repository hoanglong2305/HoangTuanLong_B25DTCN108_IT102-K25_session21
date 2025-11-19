#include<stdio.h>
#include<string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    float price;
} Book;

void insertbook(Book *arr, int *size) {
    printf("Nhap so sach muon nhap: ");
    scanf("%d", size);
    getchar();

    for (int i = 0; i < *size; i++) {
        printf("Nhap id cua sach: ");
        scanf("%d", &arr[i].id);
        getchar();

        printf("Nhap ten cuon sach: ");
        fgets(arr[i].title, sizeof(arr[i].title), stdin);
        arr[i].title[strcspn(arr[i].title, "\n")] = '\0';

        printf("Nhap ten tac gia: ");
        fgets(arr[i].author, sizeof(arr[i].author), stdin);
        arr[i].author[strcspn(arr[i].author, "\n")] = '\0';

        printf("Nhap gia: ");
        scanf("%f", &array[i].price);
        getchar();
    }
}

void printbook(Book *arr, int *size) {
    for (int i = 0; i < *size; i++) {
        printf("=================================\n");
        printf("ID sach: %d\n", arr[i].id);
        printf("Ten sach: %s\n", arr[i].title);
        printf("Tac gia: %s\n", arr[i].author);
        printf("Gia: %.2f\n", arr[i].price);
        printf("=================================\n");
    }
}

void addbook(Book *arr, int *size) {
    int index;
    printf("Nhap vi tri muon them (0 -> %d): ", *size);
    scanf("%d", &index);
    getchar();

    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    printf("Nhap id sach moi: ");
    scanf("%d", &arr[index].id);
    getchar();

    printf("Nhap ten sach moi: ");
    fgets(arr[index].title, sizeof(arr[index].title), stdin);
    arr[index].title[strcspn(arr[index].title, "\n")] = '\0';

    printf("Nhap ten tac gia moi: ");
    fgets(arr[index].author, sizeof(arr[index].author), stdin);
    arr[index].author[strcspn(arr[index].author, "\n")] = '\0';

    printf("Nhap gia sach moi: ");
    scanf("%f", &array[index].price);

    (*size)++;
    printf("Them thanh cong!\n");
}

void deletebook(Book *arr, int *size) {
    int id;
    printf("Nhap id sach muon xoa: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (arr[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sach!\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    printf("Xoa thanh cong!\n");
}

void updatebook(Book *arr, int *size) {
    int id;
    printf("Nhap id sach muon cap nhat: ");
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (arr[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sach!\n");
        return;
    }

    printf("Nhap ten moi: ");
    fgets(arr[index].title, sizeof(arr[index].title), stdin);
    arr[index].title[strcspn(arr[index].title, "\n")] = '\0';

    printf("Nhap tac gia moi: ");
    fgets(arr[index].author, sizeof(arr[index].author), stdin);
    arr[index].author[strcspn(arr[index].author, "\n")] = '\0';

    printf("Nhap gia moi: ");
    scanf("%f", &arr[index].price);

    printf("Cap nhat thanh cong!\n");
}

void sortbook(Book *arr, int *size) {
    for (int i = 0; i < *size - 1; i++) {
        for (int j = i + 1; j < *size; j++) {
            if (arr[i].price > arr[j].price) {
                Book temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchbook(Book *arr, int *size) {
    char name[100];
    getchar();
    printf("Nhap ten sach muon tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;

    for (int i = 0; i < *size; i++) {
        if (strstr(array[i].title, name) != NULL) {
            printf("\n=== Tim thay sach ===\n");
            printf("ID: %d\n", arr[i].id);
            printf("Ten: %s\n", arr[i].title);
            printf("Tac gia: %s\n", arr[i].author);
            printf("Gia: %.2f\n", arr[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach!\n");
    }
}

int main() {
    int choice = 0;
    Book arr[100];
    int size = 0;

    do {
        printf("\n----------------------------- MENU ----------------------\n");
        printf("\n1. Nhap so luong va thong tin sach");
        printf("\n2. In thong tin sach");
        printf("\n3. Them sach vao vi tri");
        printf("\n4. Xoa sach theo ID");
        printf("\n5. Cap nhat sach theo ID");
        printf("\n6. Sap xep sach theo gia");
        printf("\n7. Tim kiem sach theo ten");
        printf("\n8. Thoat");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
            	insertbook(arr, &size); 
				break;
			}
            case 2:{
            	printbook(arr, &size); 
				break;
			}
            case 3:{
            	addbook(arr, &size);
				break;
			}
            case 4:{
            	deletebook(arr, &size);
				break;
			}
            case 5:{
            	updatebook(arr, &size);
				break;
			}
            case 6:{
            	sortbook(arr, &size);
				break;
			} 
            case 7:{
            	searchbook(arr, &size);
				break;
			}
            case 8:
                printf("Ket thuc chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai\n");
        }
    }while(1);

    return 0;
}
