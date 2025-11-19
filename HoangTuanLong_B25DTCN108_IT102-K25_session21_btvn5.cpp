#include<stdio.h>
#include<string.h>

struct Product{
	char name[50];
	float price;
	int quantity;
};

int main(){
	int n = 5; 
	struct Product products[5]; 
	
    printf("Chuong trinh nhap thong tin cho 5 san pham.\n");

	for(int i = 0; i < n; i++){
		printf("\n--- Nhap san pham thu %d ---\n",i+1);
		
		printf("Nhap ten san pham: ");
		fgets(products[i].name,sizeof(products[i].name),stdin);
		products[i].name[strcspn(products[i].name,"\n")] = '\0';
		
		printf("Nhap gia san pham: ");
		scanf("%f",&products[i].price);
		while (getchar() != '\n');
		
		printf("Nhap so luong san pham: ");
		scanf("%d",&products[i].quantity);
		while (getchar() != '\n');
		
		printf("Tong gia tri cua SP %d: %.2f\n", i+1, products[i].price * products[i].quantity);
	}
	

	printf("\n--- Danh sach san pham da nhap ---\n");
	for(int i = 0; i < n; i++){
		printf("Ten SP: %s | Gia SP: %.2f | So luong SP: %d | Tong tri gia: %.2f\n",products[i].name, products[i].price, products[i].quantity, products[i].price * products[i].quantity);
	}
	
    return 0;
}
