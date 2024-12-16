#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void countSpecial(char *str, int length){
	int count = 0;
	for(int i = 0; i < length; i++){
		if(!isalpha(*(str+i)) && !isdigit(*(str+i))){
			count++;
		}
	}
	printf("\nSo phan tu la ki tu dac biet trong chuoi la: %d\n", count);
}
void countNumber(char *str, int length){
	int count = 0;
	for(int i = 0; i < length; i++){
		if(isdigit(*(str+i))){
			count++;
		}
	}
	printf("\nSo ki tu la chu trong chuoi la: %d\n", count);
}
void countCharacter( char *str, int length){
	int count = 0;
	for(int i = 0; i < length; i++){
		if(isalpha(*(str+i))){
			count++;
		}
	}
	printf("\nSo cac ki tu la chu trong chuoi la: %d\n", count);
}
void printString(char *str){
	printf("\nChuoi ban nhap la: %s\n", str);
}
void checkString(char *str, int length, int choice){
	if(str == NULL){
		printf("\nBan chua nhap chuoi\n");
	}
	else{
		switch(choice){
			case 2:
				printString(str);
				break;
			case 3:
				countCharacter(str, length);
				break;
			case 4:
				countNumber(str, length);
				break;
			case 5:
				countSpecial(str, length);
				break;
		}
	}
}
int main(){
	char *str = NULL;
	int choice, length;
	do{
		printf("1. Nhap vao chuoi\n");
		printf("2. In ra chuoi\n");
		printf("3. Dem so luong chu cai va in ra\n");
		printf("4. Dem so luong chu so va in ra\n");
		printf("5. Dem so luong ki tu dac biet va in ra\n");
		printf("6. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:
				free(str);
				str = (char *)calloc(500, sizeof(char));
				printf("\nNhap chuoi: ");
				fgets(str, 500, stdin);
				length = strlen(str);
				if(str[length - 1] == '\n'){
					str[length - 1] = '\0';
					length--;
				}
				printf("\n");
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				checkString(str, length, choice);
			case 6:
				printf("\nThoat hoan tat\n");
				break;
			default:
				printf("\nChuc nang nhap khong hop le\n\n");
				break;
		}
	}
	while(choice != 6);
	free(str);
}
