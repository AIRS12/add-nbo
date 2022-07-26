#include <stddef.h> // for size_t
#include <stdio.h> 
#include <netinet/in.h>


int main(int argc, char* argv[]){
	FILE *fp1, *fp2;

	if (argc != 3){
		printf("example: add-nbo <file1> <file2>");
		return 0;
	}

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");
	
	if(fp1 == NULL | fp2 == NULL){
		printf("ERROR");
		return 0;
	}

	uint32_t val32_1, val32_2, result;

	fread(&val32_1, sizeof(uint32_t), 1, fp1);
	fread(&val32_2, sizeof(uint32_t), 1, fp2);
	
	val32_1 = ntohl(val32_1);
	val32_2 = ntohl(val32_2);
	result = val32_1 + val32_2;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", val32_1, val32_1, val32_2, val32_2, result, result);


	fclose(fp1);
	fclose(fp2);
	return 0;
}	

