#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void searchElement(int *arr, int length){
	int *indexElement, index = 0, target;
	printf("\nNhap phan tu muon tim kiem: ");
	scanf("%d", &target);
	indexElement = (int *)calloc(length, sizeof(int));
	for(int i = 0; i < length; i++){
		if(target == *(arr + i)){
			*(indexElement + index++) = i;
		}
	}
	if(index == 0){
		printf("\nPhan tu khong ton tai trong mang\n\n");
	}
	else{
		printf("\nPhan tu %d co vi tri la: ", target);
		for(int i = 0; i < index; i++){
			printf("arr[%d] ", *(indexElement + i));
		}
		printf("\n\n");
	}
	free(indexElement);	
}
void sortArray(int *arr, int length){
	char choice;
	printf("\na. Tang dan\n");
	printf("b. Giam dan\n");
	printf("Nhap chuc nang: ");
	getchar();
	scanf("%c", &choice);
	if(choice == 'a'){
		for(int i = 0; i < length; i++){
			int minIndex = i;
			for(int j = i; j < length; j++){
				if(*(arr + minIndex) > *(arr + j)){
					minIndex = j;
				}
			}
			int temp = *(arr + i);
			*(arr + i) = *(arr + minIndex);
			*(arr + minIndex) = temp;
			
		}
		printf("\nMang sau khi sap xep la: ");
		for(int i = 0; i < length; i++){
			printf("%d ", *(arr + i));
		}
		printf("\n\n");
	}
	else if(choice == 'b'){
		for(int i = 0; i < length; i++){
			int minIndex = i;
			for(int j = i; j < length; j++){
				if(*(arr + minIndex) < *(arr + j)){
					minIndex = j;
				}
			}
			int temp = *(arr + i);
			*(arr + i) = *(arr+ minIndex);
			*(arr + minIndex) = temp;
		}
		printf("\nMang sau khi sap xep la: ");
		for(int i = 0; i < length; i++){
			printf("%d ", *(arr + i));
		}
		printf("\n\n");
	}
}
void reverseArray(int *arr, int length){
	int *reverse = NULL, index = 0;
	reverse = (int *)calloc(length, sizeof(int));
	for(int i = length - 1; i >= 0; i--){
		*(reverse + index++) = arr[i];
	}
	for(int i = 0; i < index; i++){
		*(arr + i) = *(reverse + i);
	}
	printf("\nMang sau khi dao nguoc la: ");
	for(int i = 0; i < length; i++){
		printf("%d ", *(arr + i));
	}
	printf("\n\n");
	free(reverse);
}
void printPrimeNumber(int *arr, int length){
	int *prime, index = 0;
	prime = (int *)calloc(length, sizeof(int));
	for(int i = 0; i < length; i++){
		int count = 0;
		for(int j = 2; j <= sqrt(*(arr + i)); j++){
			if(*(arr + i) % j ==0){
				count++;
			}
		}
		if(*(arr + i) > 1 && count == 0){
			prime[index++] = *(arr + i);
		}
	}
	if(index == 0){
		printf("\nMang khong co so nguyen to");
	}
	else{
		printf("\nSo nguyen to trong mang la: ");
		for(int i = 0; i < index; i++){
			printf("%d ", *(prime + i));
		}
	}
	printf("\n\n");
	free(prime);
}
void printEvenNumber(int *arr, int length){
	printf("\nCac phan tu la so chan trong mang la: ");
	for(int i = 0; i < length; i++){
		if(*(arr + i) % 2== 0){
			printf("%d ", *(arr + i));
		}
	}
	printf("\n\n");
}
void checkArray(int *arr, int length, int choice){
	if(length == 0){
		printf("\nBan chua them phan tu vao mang\n\n");
	}
	else{
		switch(choice){
			case 2:
				printEvenNumber(arr, length);
				break;
			case 3:
				printPrimeNumber(arr, length);
				break;
			case 4:
				reverseArray(arr, length);
				break;
			case 5:
				sortArray(arr, length);
				break;
			case 6:
				searchElement(arr, length);
				break;
		}
	}
}
void addArray(int *arr, int length){
	for(int i = 0; i < length; i++){
		printf("\nNhap phan tu arr[%d]: ", i);
		scanf("%d", &*(arr + i));
	}
	printf("\n");
}
int main(){
	int *arr = NULL, choice, length;
	do{
		printf("1. Nhap vao so phan tu va tung phan tu\n");
		printf("2. In ra cac phan tu la so chan\n");
		printf("3. In ra cac phan tu la so nguyen to\n");
		printf("4. Dao nguoc mang\n");
		printf("5. Sap xep mang\n");
		printf("6. Tim kiem phan tu\n");
		printf("7. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap so phan tu cua mang: ");
				scanf("%d", &length);
				arr = (int *)calloc(length, sizeof(int));
				if(arr == NULL){
					printf("\nCap phat bo nho khong thanh cong\n\n");
				}
				else{
					addArray(arr, length);
				}
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				checkArray(arr, length, choice);
				break;
			case 7:
				printf("\nThoat hoan tat\n");
				break;
			default:
				printf("\nChuc nang nhap khong hop le\n\n");
				break;
		}
	}
	while(choice != 7);
	free(arr);
	return 0;
}
