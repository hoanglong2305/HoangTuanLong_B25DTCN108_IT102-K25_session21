#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Product {
    int id;
    char name[50];
    float entryPrice;
    float sellPrice;
    int quantity;
};

void insertProducts(Product *arr, int *length, float *revenue) {
    printf("Nhap so luong san pham: ");
    scanf("%d", length);
    getchar();

    for (int i = 0; i < *length; i++) {
        printf("\nSan pham thu %d:\n", i + 1);

        printf("Id san pham: ");
        scanf("%d", &arr[i].id);
        getchar();

        printf("Nhap ten san pham: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

        printf("Gia nhap: ");
        scanf("%f", &arr[i].entryPrice);
        getchar();

        printf("Gia ban: ");
        scanf("%f", &arr[i].sellPrice);
        getchar();

        printf("So luong san pham: ");
        scanf("%d", &arr[i].quantity);
        getchar();

        *revenue -= arr[i].quantity * arr[i].entryPrice;
    }
}

void print(Product *arr, int length) {
    printf("\n=========== Danh sach san pham ===========\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %d | Name: %s | Gia nhap: %.2f | Gia ban: %.2f | So luong: %d\n",arr[i].id, arr[i].name, arr[i].entryPrice, arr[i].sellPrice, arr[i].quantity);
    }
}

void moreProduct(Product *arr, int *length, float *revenue) {
    Product newp;

    printf("Nhap ma san pham: ");
    scanf("%d", &newp.id);
    getchar();

    for (int i = 0; i < *length; i++) {
        if (arr[i].id == newp.id) {
            int addQuantity;
            printf("San pham da ton tai! Nhap so luong muon them: ");
            scanf("%d", &addQuantity);

            arr[i].quantity += addQuantity;
            *revenue -= addQuantity * arr[i].entryPrice;

            printf("Da cap nhat so luong!\n");
            return;
        }
    }

    printf("Ten san pham: ");
    fgets(newp.name, sizeof(newp.name), stdin);
    newp.name[strcspn(newp.name, "\n")] = '\0';

    printf("Gia nhap: ");
    scanf("%f", &newp.entryPrice);
    getchar();

    printf("Gia ban: ");
    scanf("%f", &newp.sellPrice);
    getchar();

    printf("So luong: ");
    scanf("%d", &newp.quantity);
    getchar();

    arr[*length] = newp;
    (*length)++;

    *revenue -= newp.quantity * newp.entryPrice;

    printf("Da them san pham moi!\n");
}

void updateProduct(Product *arr, int length, float *revenue) {
    int index;
    Product product;

    do {
        printf("Nhap vi tri muon sua: ");
        scanf("%d", &index);
    } while (index < 0 || index >= length);

    printf("Nhap id san pham: ");
    scanf("%d", &product.id);
    getchar();

    printf("Nhap ten san pham: ");
    fgets(product.name, sizeof(product.name), stdin);
    product.name[strcspn(product.name, "\n")] = 0;

    printf("Gia nhap: ");
    scanf("%f", &product.entryPrice);
    getchar();
	
    printf("Gia ban: ");
    scanf("%f", &product.sellPrice);
    getchar();

    printf("So luong san pham: ");
    scanf("%d", &product.quantity);
    getchar();
    
    *revenue -= product.quantity * product.entryPrice;

    printf("Cap nhat thanh cong!\n");
}

void sortProductsByPrice(Product *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j].sellPrice > arr[j + 1].sellPrice) {
                Product temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia ban tang dan.\n");
}

void searchProductByName(Product *arr, int length) {
    if (length == 0) {
        printf("Danh sach san pham rong. Vui long them san pham truoc.\n");
        return;
    }

    char searchName[50];
    printf("Nhap ten san pham muon tim kiem: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\n=========== Ket qua tim kiem ===========\n");
    int found = 0;
    
    for (int i = 0; i < length; i++) {
        printf("ID: %d | Name: %s | Gia nhap: %.2f | Gia ban: %.2f | So luong: %d\n",arr[i].id, arr[i].name, arr[i].entryPrice, arr[i].sellPrice, arr[i].quantity);
    }
}

void sellProduct(Product *arr, int length, float *revenue) {
    if (length == 0) {
        printf("Danh sach san pham rong. Khong the ban hang.\n");
        return;
    }

    int sellId, sellQuantity;
    printf("Nhap ID san pham muon ban: ");
    scanf("%d", &sellId);

    for (int i = 0; i < length; i++) {
        if (arr[i].id == sellId) {
            printf("San pham: %s | Gia ban: %.2f | So luong hien co: %d\n", 
                   arr[i].name, arr[i].sellPrice, arr[i].quantity);
            
            printf("Nhap so luong muon ban: ");
            scanf("%d", &sellQuantity);

            if (sellQuantity <= 0) {
                printf("So luong ban phai lon hon 0.\n");
                return;
            }

            if (arr[i].quantity >= sellQuantity) {
                arr[i].quantity -= sellQuantity;
                *revenue += (arr[i].sellPrice - arr[i].entryPrice) * sellQuantity;
                
                printf("Ban hang thanh cong! Da ban %d san pham %s.\n", sellQuantity, arr[i].name);
            } else {
                printf("Khong du so luong trong kho (%d). Ban khong thanh cong.\n", arr[i].quantity);
            }
            return;
        }
    }

    printf("Khong tim thay san pham voi ID %d.\n", sellId);
}



int main() {
    int choice;
    int length = 0;
    float revenue = 0;
    Product arr[100];

    do {
        printf("\n_____________ MENU _____________");
        printf("\n1. Nhap so luong va thong tin san pham");
        printf("\n2. Hien thi danh sach san pham");
        printf("\n3. Nhap san pham");
        printf("\n4. Cap nhat thong tin san pham");
        printf("\n5. Sap xep san pham theo gia");
        printf("\n6. Tim kiem san pham");
        printf("\n7. Ban san pham");
        printf("\n8. Doanh thu hien tai");
        printf("\n9. Thoat");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertProducts(arr, &length, &revenue);
                break;

            case 2:
                print(arr, length);
                break;
            case 3:
            	moreProduct(arr,&length,&revenue);
				break;
			case 4:
				updateProduct(arr,length,&revenue);
				break;
			case 5:
				sortProductsByPrice(arr, length);
                print(arr, length);
				break;
			case 6:
				searchProductByName(arr, length);
				break;
			case 7:
				sellProduct(arr, length, &revenue);
				break;
            case 8:
                printf("\nDoanh thu hien tai: %.2f\n", revenue);
                break;

            case 9:
                printf("Da thoat chuong trinh.\n");
                return 0;

            default:
                printf("Vui long chon tu 1-9!\n");
        }
    } while (1);

    return 0;
}
