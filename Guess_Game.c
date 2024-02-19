/* Guessing Game by m4jbz */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool guessNumber(int n, int randomNumber);
bool itsHot(int n, int randomNumber);

int main() {

	srand(time(NULL));
	int randNum = rand() % 10 + 1;
	int attempts = 3;
	int number;

	while (attempts > 0)
	{
		printf("Type a number between [1 - 10] --> ");
		scanf("%d", &number);

		if (guessNumber(number, randNum))
		{
			printf("You guessed the number!\n");
			break;
		}

		if (itsHot(number, randNum)) 
			printf("It's hot!\n");

		attempts--;

		if (attempts == 0) 
			printf("Out of attempts. The number was: %d\n", randNum);
		else 
		{
			printf("You missed, try again\n");
			printf("You have: %d attempts left.\n", attempts);
		}
	}

	return 0;
}

bool guessNumber(int n, int randomNumber)
{
	return n == randomNumber;
}

bool itsHot(int n, int randomNumber)
{
	return (n >= randomNumber - 2 && n <= randomNumber + 2);
}
