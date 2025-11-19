#include<stdio.h>
#include<string.h>

struct Car{
	char model[50];
	int year;
	float price;
};

int main(){
	struct Car myCar = {"M2025",2030,36000};
	printf("Model: %s | Year: %d | Price: %.2f\n",myCar.model,myCar.year,myCar.price);
	return 0;	
}

