#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>

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

void Doccsv(wchar_t a[]){
	FILE* fp = _wfopen(L"C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\Thongtin1.csv", L"r, ccs=UTF-8");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		fgetws(a, 150, fp);
		a[wcslen(a) - 1] = L'\0';
		wprintf(L"%ls\n", a);
	}
	fclose(fp);
}

struct Sinhvien
{
	wchar_t MSSV[7];
	wchar_t Hovaten[35];
	wchar_t Nganh[30];
	char gmail[30];
	int khoa[4];
	char ngsinh[15];
	char image[15];
	wchar_t BThan[70];
	wchar_t Sthich[70];
};
typedef struct Sinhvien SINHVIEN;

void DocStr(wchar_t ch[], SINHVIEN &sv, int &i){
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.MSSV[i] = ch[i];
		i++;
	}
	sv.MSSV[i - 1] = L'\0';
	int j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.Hovaten[j] = ch[i];
		i++;
		j++;
	}
	sv.Hovaten[i - 1] = '\0';
	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.Nganh[j] = ch[i];
		i++;
		j++;
	}
	sv.Nganh[i - 1] = '\0';

}


void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	char ch[200]; int n = 0, i = 0;
	char ch1[] = "</html>";
	wchar_t chw[150];
	SINHVIEN sv;

	Doccsv(chw);
	DocStr(chw, sv, i);
	wprintf(L"%d\n", i);
	wprintf(L"%ls\n", sv.MSSV);
	wprintf(L"%ls\n", sv.Hovaten);
	wprintf(L"%ls\n", sv.Nganh);

	while (1){
		Dochtml(ch, n);
		n += Dem(ch);
		Ghihtml(ch);
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
