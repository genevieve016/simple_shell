#include <stdio.h>

/**
 * main - asks for your age
 *
 * Return: 0
 */

int main(void)
{
	int age;

	printf("Enter your age: ");
	scanf("%d", &age);

	if (age > 0)
	{
		printf("You are %d years old.\n");
	}
	else
	{
		printf("Invalid input.\n");
	}

	return (0);
}
