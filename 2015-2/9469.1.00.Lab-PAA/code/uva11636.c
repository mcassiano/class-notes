#include<stdlib.h>
#include<stdio.h>

int calcMinPasteCommands(int numberOfLinesToAchieve) {
	int numberOfPastes = 0;
	int currentNumberOfPrintLines = 1;
	int numberOfLinesCopied = 1;

	while (currentNumberOfPrintLines < numberOfLinesToAchieve) {
		currentNumberOfPrintLines += numberOfLinesCopied;
		numberOfLinesCopied *= 2;
		numberOfPastes++;
	}

	return numberOfPastes;
}

int main (int argc, char** argv) {

	int numberOfPrints;
	int serialOutputNumber = 1;

	while (scanf("%d", &numberOfPrints) != EOF) {
		if (numberOfPrints < 0)
			return 0;

		int minNumberOfPastes = calcMinPasteCommands(numberOfPrints);
		printf("Case %d: %d\n", serialOutputNumber, minNumberOfPastes);
		serialOutputNumber++;
	}

	return 0;
}