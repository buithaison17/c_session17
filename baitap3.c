#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void addString(char *str, int length){
	char *str2 = NULL;
	str2 = (char *)calloc(500, sizeof(char));
	printf("\nNhap chuoi: ");
	fgets(str2, 500, stdin);
	int lengthStr2 = strlen(str2);
	if(str2[lengthStr2] == '\n'){
		str2[lengthStr2] = '\0';
		lengthStr2--;
	}
	length++;
	str[length - 1] = ' ';
	printf("\nChuoi moi la: %s\n", strcat(str, str2));
	free(str2);
}
void uppercase(char *str, int length){
	printf("\nChuoi duoc in hoa la: %s\n\n", strupr(str));
}
void compareString(char *str, int length){
	char *str2 = NULL;
	str2 = (char *)calloc(500, sizeof(char));
	printf("\nNhap chuoi muon so sanh: ");
	fgets(str2, 500, stdin);
	int length2 = strlen(str2);
	if(str2[length2 - 1] == '\n'){
		str2[length2 - 1] = '\0';
		length2--;
	}
	if(length2 == length){
		printf("\nHai chuoi dai bang nhau\n\n");
	}
	else if(length2 > length){
		printf("\nChuoi hai dai hon chuoi mot\n\n");
	}
	else{
		printf("\nChuoi mot dai hon chuoi hai\n\n");
	}
	free(str2);
}
void countLetter(char *str, int length){
	int count = 0;
	for(int i = 0; i < length; i++){
		if(isspace(*(str+i)) && isalpha(*(str+ i-1)) && isalpha(*(str+i+1))){
			count++;
		}
	}
	if(count == 0){
		printf("\nChuoi ban nhap co 1 tu\n\n");
	}
	else{
		printf("\nChuoi ban nhap co %d tu\n\n", count+1);
	}
}
void printString(char *str){
	printf("\nChuoi ban nhap la: %s\n\n", str);
}
void checkString(char *str, int length, int choice){
	if(length == 0){
		printf("\nChua nhap chuoi\n\n");
	}
	else{
		switch(choice){
			case 2:
				printString(str);
				break;
			case 3:
				countLetter(str, length);
				break;
			case 4:
				compareString(str, length);
				break;
			case 5:
				uppercase(str, length);
				break;
			case 6:
				addString(str, length);
				break;
		}
	}
}
int main(){
	char *str = NULL;
	int length = 0, choice;
	do{
		printf("1. Nhap vao chuoi\n");
		printf("2. In ra chuoi dao nguoc\n");
		printf("3. Dem so luong tu trong chuoi\n");
		printf("4. Nhap vao mot chuoi va so sanh\n");
		printf("5. In hoa tat ca chu cai trong chuoi\n");
		printf("6. Them mot chuoi vao chuoi ban dau\n");
		printf("7. Thoat\n");
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
			case 6:
				checkString(str, length, choice);
				break;
			case 7:
				printf("\nThoat thanh cong\n");
				break;
			default:
				printf("\nChuc nang nhap khong ton tai\n\n");
				break;
		}
	}
	while(choice != 7);
	free(str);
	return 0;
}
