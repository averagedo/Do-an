#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>

struct Sinhvien
{
	wchar_t MSSV[7];
	wchar_t Hovaten[35];
	wchar_t Nganh[30];
	wchar_t gmail[30];
	wchar_t khoa[5];
	wchar_t ngsinh[11];
	wchar_t image[15];
	wchar_t BThan[70];
	wchar_t Sthich[70];
};
typedef struct Sinhvien SINHVIEN;

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

void Thecho(SINHVIEN sv, char c)
{
	FILE*ft = _wfopen(L"C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\ghiKQ.html", L"at,ccs=UTF-8");
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
		FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\ghiKQ.html", "at");

	}
}

void Ghihtml(char ch[], SINHVIEN sv){
	FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\Documents\\hoc ky 2 - nam 1\\ky thuat lap trinh\\Do an 1\\ghiKQ.html", "at");
	if (fp == NULL){
		printf("Khong doc duoc file.");
	}
	else{
		int i = 0;
		while (ch[i] != '\n'){
			if (ch[i] == '*'){
				char c = ch[i + 1];
				fclose(fp);
				Thecho(sv, c);
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
	sv.Hovaten[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.Nganh[j] = ch[i];
		i++;
		j++;
	}
	sv.Nganh[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.gmail[j] = ch[i];
		i++;
		j++;
	}
	sv.gmail[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.khoa[j] = ch[i];
		i++;
		j++;
	}
	sv.khoa[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.ngsinh[j] = ch[i];
		i++;
		j++;
	}
	sv.ngsinh[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.image[j] = ch[i];
		i++;
		j++;
	}
	sv.image[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != ';'&&ch[i] != '\0'){
		sv.BThan[j] = ch[i];
		i++;
		j++;
	}
	sv.BThan[j] = '\0';

	j = 0;
	i++;
	while (ch[i] != '\0'){
		sv.Sthich[j] = ch[i];
		i++;
		j++;
	}
	sv.Sthich[j] = '\0';
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

	while (1){
		Dochtml(ch, n);
		n += Dem(ch);
		Ghihtml(ch,sv);
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
