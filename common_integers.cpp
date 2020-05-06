#include <iostream>



void read_lists(int arr1[8], int arr2[8], int arr3[8],int size){
	int input;
	for (int i=0;i<8;i++){
		std::cin >> arr1[i];
	}
	for (int i=0;i<8;i++){
		std::cin >> arr2[i];
	}
	for (int i=0;i<8;i++){
		std::cin >> arr3[i];
	}
}
void display_common_integers(int arr1[8], int arr2[8], int arr3[8],int size){
	int highest=0;
	for (int i=0;i<8;i++){
		if (arr1[i]>highest){
			highest=arr1[i];
		}
	}
	highest+=10;
	int temp,none=0,count;
	for (int i=0;i<8;i++){
		count=1;
		temp=arr1[i];
		for (int j=0;j<8;j++){
			if (temp==arr2[j]){
				arr2[j]=highest;
				count+=1;
				break;
			}
		}
		for (int k=0;k<8;k++){
			if (temp==arr3[k]){
				arr3[k]=highest;
				none=1;
				count+=1;
				break;
			}
		}
		if (count==3){
			std::cout<< temp << std::endl;
		}	
	}
	if (none==0){
		std::cout<< "None" << std::endl;
	}
}


int main()
{
	const int SIZE = 8;
	int arr1[SIZE]{};
	int arr2[SIZE]{};
	int arr3[SIZE]{};

	// read and store three list of integers to arr1, arr2, arr3
	// each array is of size given by SIZE
	read_lists(arr1, arr2, arr3, SIZE);

	// display all integers that appear in every one of the three arrays
	// arr1, arr2, arr3
	// each array is of size given by SIZE
	display_common_integers(arr1, arr2, arr3, SIZE);

	return 0;
}
