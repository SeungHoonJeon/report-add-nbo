#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#define MAX 1000
void go(uint32_t *file1,uint32_t *file2){
	
	uint32_t n1 = file1[0];
	uint32_t n1_1 = (file1[0] & 0xff000000) >> 24;
	uint32_t n1_2 = (file1[0] & 0x00ff0000) >> 8;
	uint32_t n1_3 = (file1[0] & 0x0000ff00) << 8;
	uint32_t n1_4 = (file1[0] & 0x000000ff) << 24;
	uint32_t result1 = n1_1 | n1_2 | n1_3 | n1_4;

	uint32_t n2 = file2[0];
	uint32_t n2_1 = (file2[0] & 0xff000000) >> 24;
       	uint32_t n2_2 = (file2[0] & 0x00ff0000) >> 8;
	uint32_t n2_3 = (file2[0] & 0x0000ff00) << 8;
	uint32_t n2_4 = (file2[0] & 0x000000ff) >> 24;	
	uint32_t result2 = n2_1 | n2_2 | n2_3 | n2_4;
	
	printf("%d(%#x) + %d(%#x) = %d(%#x)",result1,result1,result2,result2,result1+result2,result1+result2);	
}
int main(int argc,char *argv[]){
	FILE *fp1;
	FILE *fp2;
	uint32_t buffer1[MAX] = {0, };
	uint32_t buffer2[MAX] = {0, };

	if((fp1=fopen(argv[1],"rb")) == NULL){
		perror("fopen1: fail");
		exit(1);
	}
	if((fp2=fopen(argv[2],"rb")) == NULL){
		perror("fopen2: fail");
		exit(1);
	}

	fread(buffer1, 4, MAX, fp1);
	fread(buffer2, 4, MAX, fp2);
	
	go(buffer1,buffer2);

	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
