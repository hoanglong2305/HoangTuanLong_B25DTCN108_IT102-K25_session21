#include<stdio.h>
#include<string.h>

struct Student{
	char name[50];
	int age;
	float Grade;
};

int main(){
	struct Student student1;
	
	printf("Ten sinh vien: ");
	fgets(student1.name, sizeof(student1.name), stdin);
	student1.name[strcspn(student1.name,"\n")] = '\0';
	
	printf("Tuoi: ");
	scanf("%d",&student1.age);
	getchar();
	
	printf("Diem trung binh hoc sinh: ");
	scanf("%f",&student1.Grade);
	getchar();
	
	printf("----------Thong tin sinh vien---------\n");
	printf("\nTen SV: %s | Tuoi: %d | Diem trung binh: %.2f\n",student1.name,student1.age,student1.Grade);
	return 0;
}
