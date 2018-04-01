#include<stdio.h>

void Dochtml(char ch[], int &n){
	FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\html goc.txt", "rt");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{

		fseek(fp, n, SEEK_CUR);
		fgets(ch, 200, fp);
	}
	fclose(fp);
}

int Dem(char a[]){
	int i = 0;
	while (a[i] != '\n'){
		i++;
	}
	return i + 2;
}
void Ghihtml(char ch[]){
	FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\ghiKQ.html", "at");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		fputs(ch, fp);
	}
	fclose(fp);
}

void main()
{
	char ch[200]; int n = 0; int j = 0;
	char ch1[] = "</html>";
	while (1){
		Dochtml(ch, n);
		n += Dem(ch);
		Ghihtml(ch);
		j++;
		int kiemtra = 1;
		for (int i = 0; i < 6; i++){
			if (ch[i] != ch1[i]){
				kiemtra = 0;
				break;
			}
		}
		if (kiemtra == 1)break;
	}
}
