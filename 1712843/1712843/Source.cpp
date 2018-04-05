#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>

struct Sinhvien
{
	wchar_t MSSV[8];
	wchar_t Hovaten[35];
	wchar_t Nganh[30];
	wchar_t gmail[30];
	wchar_t khoa[5];
	wchar_t ngsinh[15];
	wchar_t image[15];
	wchar_t BThan[70];
	wchar_t Sthich[70];
};
typedef struct Sinhvien SINHVIEN;

void Thecho(SINHVIEN sv, char c, char ch[], wchar_t ch1[])
{
	FILE*ft = _wfopen(ch1, L"at,ccs=UTF-8");
	if (ft == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		switch (c)
		{
		case '1':
			fputws(sv.MSSV, ft);
			break;
		case'2':
			fputws(sv.Hovaten, ft);
			break;
		case'3':
			fputws(sv.Nganh, ft);
			break;
		case'4':
			fputws(sv.gmail, ft);
			break;
		case'5':
			fputws(sv.khoa, ft);
			break;
		case'6':
			fputws(sv.ngsinh, ft);
			break;
		case'7':
			fputws(sv.image, ft);
			break;
		case'8':
			fputws(sv.BThan, ft);
			break;
		case'9':
			fputws(sv.Sthich, ft);
			break;
		}
		fclose(ft);
		FILE* fp = fopen(ch, "at");
	}
}

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

void SoLuong(char ch[], int &w){
	FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\Thongtin1.csv", "rt");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		while (!feof(fp)){
			fgets(ch, 200, fp);
			w++;
		}
		w--;
	}
	fclose(fp);
}

void Ghihtml(char ch[], SINHVIEN sv, char v[], wchar_t b[]){
	FILE* fp = fopen(v, "at");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		int i = 0;
		while (ch[i] != '\n'){
			if (ch[i] == '*'){
				char c = ch[i + 1];
				fclose(fp);
				Thecho(sv, c, v, b);
				i = i + 2;
			}
			else{
				putc(ch[i], fp);
				i++;
			}
		}
		ch[i] = '\n';
		putc(ch[i], fp);
	}
	fclose(fp);
}

void DMSSV(char a[], int x){
	FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\Thongtin1.csv", "r");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		int dd = 1;
		if (x == 1){
			fseek(fp, 3, SEEK_SET);
			fgets(a, 8, fp);
			a[8] = '\0';
		}
		else{
			while (!feof(fp)){
				char c = fgetc(fp);
				if (c == '\n')dd++;
				if (dd == x){
					fgets(a, 8, fp);
					a[8] = '\0';
					break;
				}
			}
		}

	}
	fclose(fp);
}

void Doccsv(wchar_t a[], int x){
	FILE* fp = _wfopen(L"C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\Thongtin1.csv", L"r, ccs=UTF-8");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		for (int h = 0; h < x; h++){
			fgetws(a, 150, fp);
			a[wcslen(a) - 1] = L'\0';
		}
	}
	fclose(fp);
}

void DocStr(wchar_t ch[], SINHVIEN &sv){
	int i = 0;
	while (ch[i] != ';'){
		sv.MSSV[i] = ch[i];
		i++;
	}
	sv.MSSV[i] = L'\0';

	int j = 0;
	i++;
	while (ch[i] != ';'){
		sv.Hovaten[j] = ch[i];
		i++;
		j++;
	}
	sv.Hovaten[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.Nganh[j] = ch[i];
		i++;
		j++;
	}
	sv.Nganh[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.gmail[j] = ch[i];
		i++;
		j++;
	}
	sv.gmail[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.khoa[j] = ch[i];
		i++;
		j++;
	}
	sv.khoa[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.ngsinh[j] = ch[i];
		i++;
		j++;
	}
	sv.ngsinh[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.image[j] = ch[i];
		i++;
		j++;
	}
	sv.image[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'){
		sv.BThan[j] = ch[i];
		i++;
		j++;
	}
	sv.BThan[j] = '\0';

	j = 0;
	i++;
	char q[5] = "<li>";
	char w[6] = "</li>";
	while (ch[i] != '\0'){
		if (ch[i] == ';'){
			i++;
			for (int m = 0; m < 5; m++){
				sv.Sthich[j] = w[m];
				j++;
			}
			sv.Sthich[j] = '\n';
			j++;
			for (int m = 0; m < 4; m++){
				sv.Sthich[j] = q[m];
				j++;
			}
		}
		else{
			sv.Sthich[j] = ch[i];
			i++;
			j++;
		}
	}
	sv.Sthich[j] = '\0';
}

void main()
{
	int sl = 0;
	char ch[200];
	SoLuong(ch, sl);
	for (int z = 1; z <= sl; z++){
		int n = 0;
		char ch1[] = "</html>";
		char ch2[9];
		char ch3[100] = "C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\WEBSITE\\";
		char ch4[6] = ".html";
		wchar_t chw[150];
		SINHVIEN sv;

		DMSSV(ch2, z);
		strcat(ch3, ch2);
		strcat(ch3, ch4);

		_setmode(_fileno(stdout), _O_U16TEXT);
		_setmode(_fileno(stdin), _O_U16TEXT);

		Doccsv(chw, z);
		DocStr(chw, sv);

		wchar_t chw1[100] = L"C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\WEBSITE\\";
		wchar_t chw2[6] = L".html";

		wcscat(chw1, sv.MSSV);
		wcscat(chw1, chw2);

		while (1){
			Dochtml(ch, n);
			n += Dem(ch);
			Ghihtml(ch, sv, ch3, chw1);
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
}