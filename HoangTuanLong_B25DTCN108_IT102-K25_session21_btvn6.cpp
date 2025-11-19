#include<stdio.h>
#include<string.h>

struct Student{
	char name[50];
	int age;
	float grade;
};

int main(){
	int n = 5;
	struct Student students[n];
	
	for(int i = 0; i < n; i++){
		printf("\n--- Hoc sinh thu %d ---\n",i+1);
		
		printf("Ten HS: ");
		fgets(students[i].name,sizeof(students[i].name),stdin);
		students[i].name[strcspn(students[i].name,"\n")] = '\0';
		
		printf("Tuoi: ");
		scanf("%d",&students[i].age);
		getchar();
		
		printf("Diem trung binh: ");
		scanf("%f",&students[i].grade);
		getchar();
	}
	
	printf("\n________________THONG TIN HOC SINH___________________\n");
	for(int i = 0; i < n; i++){
		printf("Ten HS: %s | Tuoi: %d | Diem trung binh: %.2f\n",students[i].name, students[i].age, students[i].grade);
	}
    
    return 0;
}
