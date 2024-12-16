#include<stdio.h>
#include<stdlib.h>
void findMax(int *arr, int *length){
	int max = *(arr + 0);
	for(int i = 0; i < *length; i++){
		if(max < *(arr + i)){
			max = *(arr + i);
		}
	}
	printf("\nPhan tu lon nhat trong mang la: %d\n\n", max);
}
void sumArray(int *arr, int *length){
	int sum = 0;
	for(int i = 0; i < *length; i++){
		sum += arr[i];
	}
	printf("\nTong cac phan tu co trong mang: %d\n\n", sum);
}
void printArray(int *arr, int *length){
	printf("\nCac phan tu co trong mang la:\n");
	for(int i = 0; i < *length; i++){
		printf("\narr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");
}
void addElement(int *arr, int length){
	for(int i = 0; i < length; i++){
		printf("\nNhap phan tu arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\nThem phan tu hoan tat\n\n");
}
void checkArray(int *arr, int *length, int choice){
	if(*length == 0){
		printf("\nChua them phan tu vao mang\n\n");
	}
	else{
		switch(choice){
			case 2:
				printArray(arr, length);
				break;
			case 4:
				sumArray(arr, length);
				break;
			case 5:
				findMax(arr, length);
				break;
		}
	}
}
int main(){
	int *arr = NULL, choice, length;
	do{
		printf("1. Nhap vao so phan tu va tung phan tu\n");
		printf("2. Hien thi cac phan tu trong mang\n");
		printf("3. Tinh do dai mang\n");
		printf("4. Tinh tong cac phan tu\n");
		printf("5. Hien thi phan tu lon nhat\n");
		printf("6. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap so phan tu: ");
				scanf("%d", &length);
				arr = (int *)calloc(length, sizeof(int));
				if(arr == NULL){
					printf("\nKhong the cap phat bo nho\n\n");
				}
				else{
					addElement(arr, length);
				}
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				checkArray(arr, &length, choice);
				break;
			case 6:
				printf("\nThoat thanh cong\n");
				break;
			default:
				printf("\nNhap khong dung chuc nang\n\n");
				break;
		}
	}
	while(choice != 6);
	free(arr);
	return 0;
}
