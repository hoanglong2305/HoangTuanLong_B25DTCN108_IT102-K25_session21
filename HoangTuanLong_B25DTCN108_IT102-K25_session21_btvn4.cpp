#include<stdio.h>
#include<string.h>

struct Book{
	char title[100];
	char author[50];
	float price;
};

int main(){
	int n = 3; 
	struct Book books[3];

	for(int i=0;i<n;i++){
		printf("\n--- Nhap cuon sach thu %d ---\n",i+1);
		
		printf("Nhap ten sach: ");
		fgets(books[i].title,sizeof(books[i].title),stdin); 
		books[i].title[strcspn(books[i].title,"\n")] = '\0';
		
		printf("Nhap ten tac gia: ");
		fgets(books[i].author,sizeof(books[i].author),stdin);
		books[i].author[strcspn(books[i].author,"\n")] = '\0';
		
		printf("Nhap gia: ");
		scanf("%f",&books[i].price);
		while (getchar() != '\n'); 
	}
	
	printf("\n--- Danh sach sach da nhap ---\n");
	for(int i=0;i<n;i++){
		printf("Title: %s | Author: %s | Price: %.2f\n",books[i].title,books[i].author,books[i].price);
	}
	return 0;
}
