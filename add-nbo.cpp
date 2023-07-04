#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");

	uint32_t num1;
	uint32_t num2;

	fread(&num1, sizeof(num1), 1, fp1);
	fread(&num2, sizeof(num2), 1, fp2);

	fclose(fp1);
	fclose(fp2);

	uint32_t rnum1 = ntohl(num1);
	uint32_t rnum2 = ntohl(num2);

	uint32_t result = rnum1 + rnum2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", rnum1, rnum1, rnum2, rnum2, result, result);
	return 0;
}
