#include<stdio.h>

char a = 'A';
char b = 'A';

void Test(char copya, char* pointerb)
{
	printf("copya : %d\n", copya);
	printf("pointerb : %d\n", *pointerb);
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	copya += 1;
	*pointerb += 1;
	printf("\ncopya : %d\n", copya);
	printf("pointerb : %d\n", *pointerb);
	printf("a : %d\n", a);
	printf("b : %d\n", b);
}

int main() {
	Test(a, &b);
	printf("\na : %d\n", a);
	printf("b : %d\n", b);
}