#include <stdio.h>
#include <stdlib.h>

void factorize(int num) {
	int factor1 = 2;
	int factor2 = num / factor1;
	printf("%d=%d*%d\n", num, factor1, factor2);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error opening file");
		return (1);
	}

	char buffer[100];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		int num = atoi(buffer);
		if (num <= 1) {
			printf("Invalid number: %d\n", num);
			continue;
		}
		factorize(num);
	}

	fclose(file);
	return (0);
}
