//Twordle Program
//Author: Vegas Del Pardo
//Date: 5/1/26
#include <stdio.h>
#define LENGTH 100
int loadMystery(char mystery[]);
int letterCheck(char guess[][LENGTH], int count);
int lengthCheck(char guess[][LENGTH], int count);
int winCondition(char guess[][LENGTH], char mystery[], int count);
void printWin(char mystery[], int count);
void checkGuess(char guess[][LENGTH], char mystery[], int count);
int main() {
	char mystery[6];
	char guess[6][LENGTH];
	int check1 = 0;
	int check2 = 0;
	int check = loadMystery(mystery);
	if (check == 1) {
			printf("Cannot open file\n");
			return 1;
	}
	for(int count = 0; count < 6; count++) {
		
		 do {
			printf("GUESS %d! Enter your guess: ", count + 1);
			scanf("%s", guess[count]);
			check1 = letterCheck(guess, count);
			if (check1 == 1) {
				printf("Your guess must only contain letters.");
			}
			check2 = lengthCheck(guess, count);
			if (check2 == 1) {
				printf("Your guess must be 5 letters long.");
			}
			if(check1 == 1 || check2 == 1) {
				printf("\nPlease try again.\n");
			}
		} while(check1 == 1 || check2 == 1);
		int winCon = winCondition(guess, mystery, count);
		if (winCon == 0) {
			printWin(mystery, count);
			count = 6;
		}
		else {
			checkGuess(guess, mystery, count);
		}
	}
		
	}

int loadMystery(char mystery[]) {
	FILE *word = fopen("mystery.txt", "r");
	if(word == NULL) {
		return 1;
	}
	fscanf(word, "%s", mystery);
	fclose(word);
	return 0;
}
int letterCheck(char guess[][LENGTH], int count) {
	for(int i = 0; i < 5; i++) {
		if(guess[count][i] >= 'A' && guess[count][i] <= 'Z') {
			guess[count][i] = guess[count][i] + 32;
		}
		if(guess[count][i] < 'a' || guess[count][i] > 'z') {
			return 1;
		}
	}
	return 0;
}
int lengthCheck(char guess[][LENGTH], int count) {
	int i = 0;
	while(guess[count][i] != '\0') {
		i++;
	}
	if(i != 5) {
		return 1;
	}
	return 0;
}
int winCondition(char guess[][LENGTH], char mystery[], int count) {
	for(int i = 0; i < 6; i++) {
		if(guess[count][i] != mystery[i]) {
			return 1;
		}
	}
	return 0;
}
void printWin(char mystery[], int count) {
	printf("========================================\n");
	for(int i = 0; i < 5; i++) {
		mystery[i] = mystery[i] - 32;
	}
	printf("%s\n", mystery);
	if(count == 0) {
		printf("GOATED!\n");
		printf("You won in 1 guess!\n");
	}
	else {
		printf("You win in %d guesses!\n", count + 1);
		if(count == 1 || count == 2) {
			printf("Amazing!\n");
		}
		else if(count == 3 || count == 4) {
			printf("Nice!\n");
		}
	}
}
void checkGuess(char guess[][LENGTH], char mystery[], int count) {
	printf("========================================\n");
	for(int i = 0; i <= count; i++) {
		for(int j = 0; j < 5; j++) {
			if (guess[i][j] == mystery[j]) {
				printf("%c", guess[i][j] - 32);
			}
			else {
				printf("%c", guess[i][j]);
			}
		}
		printf("\n");
		
	
		for(int j = 0; j < 5; j++) {
			int found = 0;
			int correctPos = 0;
			int duplicateCarrot = 0;
			for(int k = 0; k < 5; k++) {
				if(guess[i][j] == mystery[k]) {
					found = 1;
				}
			
				if(guess[i][j] == guess[i][k] && guess[i][k] == mystery[k]) {
					correctPos = 1;
				}
			}
			for(int l = 0; l < j; l++) {
				if(guess[i][l] == guess[i][j]) {
					duplicateCarrot = 1;
				}
			}
					
			if (found == 1 && correctPos == 0 && duplicateCarrot == 0) {
				printf("^");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
}


