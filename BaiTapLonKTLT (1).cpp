
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DAY "00/00/0000"
#define MAX 1000000

struct KhachHang{     
	char maSoKH[20];
	char tenKH[30];
	char diaChi[50];
	char maSoCT[20];
};
typedef struct KhachHang KH;

struct SuDungDien{
	int chiSoDien;
	char ngayChot[20];
	int ky;
};
typedef struct SuDungDien Dien;

struct ChiSoDien{    
	char maSoKH[20];
	struct SuDungDien suDungDien[12];
	int n;
};
typedef struct ChiSoDien CSDien;

struct GiaDien{
	int chiSoDau;
	int chiSoSau;
	int donGia;
};
typedef struct GiaDien GDien;    

struct DienNang{
	int ky;
	int dienNangTieuThu;
	int tienDien;
};
typedef struct DienNang DienNang;

struct TieuThuDien{     
	char maSoKH[20];
	int n;
	struct DienNang dienNang[12];	
};
typedef struct TieuThuDien TTDien;

// kiem tra ma so nhap vao co trong file hay chua
int kTraMaSoKH(char *maSoKH){
	FILE *fp;
	KH khachHang;
	fp = fopen("D:/KH.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(KH); 

	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(KH), SEEK_SET);
		fread(&khachHang, sizeof(KH), 1, fp);
		if(strcmp(maSoKH, khachHang.maSoKH) == 0){
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

//THEM hoac NHAP danh sach moi
void nhapDanhSach(FILE* fpKH, FILE* fpCSDien, char* str){
	fpKH = fopen("D:/KH.bin", str);
	fpCSDien = fopen("D:/CSDIEN.bin", str);
	if(!fpKH){
		printf("\nCo loi khi mo file!\n");
		fclose(fpKH);
		fclose(fpCSDien);
	}
	else{
		fclose(fpKH);
		fclose(fpCSDien);	
		int soKH;
		do{
			printf("So khach hang can them vao:");
			scanf("%d", &soKH);
			if(soKH <= 0){
			printf("phai la so > 0! Moi nhap lai\n");
			}
		}while(soKH <= 0);
		
		for(int i = 0; i < soKH;i++){
			int tmp;
			KH khachHang;
			CSDien chiSoDien;
			if(i == 0){
				scanf("%c", &tmp);    
			}
			printf("\nKhach hang thu %d\n", i+1);
			do{
				printf(" -Ma so: ");
				gets(khachHang.maSoKH);
				if(!kTraMaSoKH(khachHang.maSoKH)){
					printf("Ma so khach hang da co! Vui long nhap lai!\n");
				}
			}while(!kTraMaSoKH(khachHang.maSoKH));
			printf(" -Ten: ");
			gets(khachHang.tenKH);
			printf(" -Dia chi: ");
			gets(khachHang.diaChi);
			printf(" -Ma so cong to: ");
			gets(khachHang.maSoCT);
			
			strcpy(chiSoDien.maSoKH, khachHang.maSoKH);
			chiSoDien.n = 1;
			chiSoDien.suDungDien[0].chiSoDien = 0;
			strcpy(chiSoDien.suDungDien[0].ngayChot, DAY);
			chiSoDien.suDungDien[0].ky = 0;
			
			fpKH = fopen("D:/KH.bin", "ab+");
			fpCSDien = fopen("D:/CSDIEN.bin", "ab+");
				
			fwrite(&khachHang, sizeof(KH), 1, fpKH);
			fwrite(&chiSoDien, sizeof(CSDien), 1, fpCSDien);
			
			fclose(fpKH);
			fclose(fpCSDien);	
		}
	}
}

// xoa hoac sua thong tin khach hang
void dieuChinh(FILE* fpKH, FILE* fpCSDien, char* str, int luaChon2){
	KH* khachHang;
	CSDien* chiSoDien;
	
	fpKH = fopen("D:/KH.bin", "rb");
	fpCSDien = fopen("D:/CSDIEN.bin", "rb");
	if(!fpKH || !fpCSDien){
		printf("\nCo loi khi mo file!\n");
		fclose(fpKH);
		fclose(fpCSDien);
	}
	
	fseek(fpKH,0,SEEK_END);
	int n = ftell(fpKH) / sizeof(KH);
	khachHang = (KH*)malloc(n*sizeof(KH));
	chiSoDien = (CSDien*)malloc(n*sizeof(CSDien));
	int value = 0;
	int idex;
	
	for(int i = 0;i < n;i++){
		fseek(fpKH, i*sizeof(KH), SEEK_SET);
		fread(&khachHang[i], sizeof(KH), 1, fpKH);
		
		fseek(fpCSDien, i*sizeof(CSDien), SEEK_SET);
		fread(&chiSoDien[i], sizeof(CSDien), 1, fpCSDien);
	
		if(strcmp(str, (khachHang[i].maSoKH))){
			idex = i;
			value = 1;
		}
		if(strlen(str) ==  strlen(khachHang[i].tenKH)) {
			int count = 0;
			for(int j = 0; j < strlen(str);j++) {
				if(toupper(str[j]) == toupper(khachHang[i].tenKH[j]))
					count++;
			}
			if(count == strlen(str)){
				idex = i;
				value = 1;   //found
			}
		}	
	}
	fclose(fpKH);
	fclose(fpCSDien);
	
	if(value == 0){
		printf("Khong tim thay khach hang!");
	}
	else{
		printf("Tim thay khach hang!");
		if(luaChon2 == 3){ // sua doi
			char strtmp[20];
			strcpy(strtmp, khachHang[idex].maSoKH);
			printf("\nThong tin khach hang can sua doi\n");
			do{
				printf(" -Ma so: ");
				gets(khachHang[idex].maSoKH);
				if(!kTraMaSoKH(khachHang[idex].maSoKH) && strcmp(strtmp, khachHang[idex].maSoKH) != 0){
					printf("Ma so khach hang da co! Vui long nhap lai!\n");
				}
			}while(!kTraMaSoKH(khachHang[idex].maSoKH) && strcmp(strtmp, khachHang[idex].maSoKH) != 0);
			printf(" -Ten: ");
			gets(khachHang[idex].tenKH);
			printf(" -Dia chi: ");
			gets(khachHang[idex].diaChi);
			printf(" -Ma so cong to: ");
			gets(khachHang[idex].maSoCT);
			
			strcpy(chiSoDien[idex].maSoKH, khachHang[idex].maSoKH);
			chiSoDien[idex].n = 1;
			chiSoDien[idex].suDungDien[0].chiSoDien = 0;
			strcpy(chiSoDien[idex].suDungDien[0].ngayChot, DAY);
			chiSoDien[idex].suDungDien[0].ky = 0;
			
			printf("Thong tin khach hang da duoc thay doi!");
		}
		
		fpKH = fopen("D:/KH.bin", "wb+");
		fpCSDien = fopen("D:/CSDIEN.bin", "wb+");
		
		for(int i = 0; i < n;i++){
			if(luaChon2 == 4 && i == idex){
				printf("Thong tin khach hang da duoc xoa!");
				continue;
			}
			else{
				fwrite(&khachHang[i], sizeof(KH), 1, fpKH);
				fwrite(&chiSoDien[i], sizeof(CSDien), 1, fpCSDien);
			}
		}
		fclose(fpKH);
		fclose(fpCSDien);	
	}
}

//in danh sach khach hang
void inDanhSach(){
	FILE *fp;
	KH khachHang;
	fp = fopen("D:/KH.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(KH);

	printf("%60s \n%-20s | %-30s | %-30s | %-20s", "Danh sach khach hang", "Ma so Khach Hang", "Ten Khach Hang", "Dia chi", "Ma so cong to Dien");	
	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(KH), SEEK_SET);
		fread(&khachHang, sizeof(KH), 1, fp);
		printf("\n%-20s | %-30s | %-30s | %-20s", khachHang.maSoKH, khachHang.tenKH, khachHang.diaChi, khachHang.maSoCT);
	}
	fclose(fp);
}

//in danh sach chi so dien
void inChiSoDien(){
	FILE *fp;
	CSDien chiSoDien;
	fp = fopen("D:/CSDIEN.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int m = ftell(fp) / sizeof(CSDien);
	printf("%50s \n%-20s | %-20s | %-20s | %-20s","Danh sach chi so dien", "Ma so Khach Hang", "Chi So Dien", "Ngay Chot", "Ky");	
	for(int i = 0;i < m;i++){
		fseek(fp, i*sizeof(CSDien), SEEK_SET);
		fread(&chiSoDien, sizeof(CSDien), 1, fp);
		printf("\n%-20s | %-20d | %-20s | %-20d", chiSoDien.maSoKH, chiSoDien.suDungDien[0].chiSoDien, chiSoDien.suDungDien[0].ngayChot, chiSoDien.suDungDien[0].ky);
		for(int j = 1;j < chiSoDien.n;j++){
			printf("\n%-20s | %-20d | %-20s | %-20d", "", chiSoDien.suDungDien[j].chiSoDien, chiSoDien.suDungDien[j].ngayChot, chiSoDien.suDungDien[j].ky);
		}
	}
	fclose(fp);
}

//sap xep chi so dien cua 1 khach hang theo ky
void sapxep(CSDien* chiSoDien, int idx){
	for(int i = 0;i < chiSoDien[idx].n;i++){
		for(int j = chiSoDien[idx].n - 1; j > i;j--){
			char y1[4];
			char y2[4];
			for(int k = 6; k < 10;k++){
				y1[k-6] = chiSoDien[idx].suDungDien[j].ngayChot[k];
				y2[k-6] = chiSoDien[idx].suDungDien[j-1].ngayChot[k];
			}
			if(atoi(y1) < atoi(y2)){
				Dien tmp;
				tmp = chiSoDien[idx].suDungDien[j];
				chiSoDien[idx].suDungDien[j] = chiSoDien[idx].suDungDien[j - 1];
				chiSoDien[idx].suDungDien[j - 1] = tmp;
			}
			else if(atoi(y1) == atoi(y2)){
				if(chiSoDien[idx].suDungDien[j].ky < chiSoDien[idx].suDungDien[j - 1].ky){
					Dien tmp;
					tmp = chiSoDien[idx].suDungDien[j];
					chiSoDien[idx].suDungDien[j] = chiSoDien[idx].suDungDien[j - 1];
					chiSoDien[idx].suDungDien[j - 1] = tmp;	
				}
			}
		}
	}
}


// sua doi, them hoac xoa chi so dien cua khach hang
void suaChiSoDien(FILE* fpCSDien, char* str, int luaChon2){
	CSDien* chiSoDien;
	fpCSDien = fopen("D:/CSDIEN.bin", "rb");
	if(!fpCSDien){
		printf("\nCo loi khi mo file!\n");
		fclose(fpCSDien);
	}
	
	fseek(fpCSDien,0,SEEK_END);
	int n = ftell(fpCSDien) / sizeof(CSDien);
	chiSoDien = (CSDien*)malloc(n*sizeof(CSDien));
	
	int value = 0;
	int idex;
	
	for(int i = 0;i < n;i++){
		fseek(fpCSDien, i*sizeof(CSDien), SEEK_SET);
		fread(&chiSoDien[i], sizeof(CSDien), 1, fpCSDien);
		if(strlen(str) ==  strlen(chiSoDien[i].maSoKH)) {
			int count = 0;
			for(int j = 0; j < strlen(str);j++) {
				if(str[j] == chiSoDien[i].maSoKH[j])
					count++;
			}
			if(count == strlen(str)){
				idex = i;
				value = 1;
			}
		}	
	}
	fclose(fpCSDien);
	
	int ky = -1;
	if(value == 0){
		printf("Khong tim thay khach hang!");
	}
	else{
		printf("Tim thay khach hang!\n");
		if(luaChon2 == 1){
			do{
				printf("Nhap thong tin ky can sua doi: ");	
				scanf("%d", &ky);
				if(ky <= 0 || ky > 12){
					printf("ky phai tu 1 -> 12. Yeu cau nhap lai.\n");
				}			
			}while(ky <= 0 || ky > 12);
			value = 0;
			for(int i = 0;i < chiSoDien[idex].n;i++){
				if(chiSoDien[idex].suDungDien[i].ky == ky){
					printf("\nThong tin khach hang can sua doi\n");
					printf(" -Chi so Dien: ");
					scanf("%d", &chiSoDien[idex].suDungDien[i].chiSoDien);
					printf(" -Ngay chot (DD/MM/YY): ");
					int tmp; scanf("%c", &tmp);
					gets(chiSoDien[idex].suDungDien[i].ngayChot);
					printf(" -Ky: ");
					char str[2];
					str[0] = chiSoDien[idex].suDungDien[i].ngayChot[3];
					str[1] = chiSoDien[idex].suDungDien[i].ngayChot[4];
					chiSoDien[idex].suDungDien[i].ky = atoi(str);
					printf("%d\n", atoi(str));
	
					value = 1;
					break;
				}
			}
			if(value == 0){
				printf("Khong co ky tuong ung!");
			}	
		}
		else if(luaChon2 == 2){
			if(chiSoDien[idex].suDungDien[0].ky == 0){
				printf("\nThong tin khach hang can them\n");
				printf(" -Chi so Dien: ");
				scanf("%d", &chiSoDien[idex].suDungDien[0].chiSoDien);
				printf(" -Ngay chot (DD/MM/YY): ");
				int tmp; scanf("%c", &tmp);
				gets(chiSoDien[idex].suDungDien[0].ngayChot);
				printf(" -Ky: ");
				char str[2];
				str[0] = chiSoDien[idex].suDungDien[0].ngayChot[3];
				str[1] = chiSoDien[idex].suDungDien[0].ngayChot[4];
				chiSoDien[idex].suDungDien[0].ky = atoi(str);
				printf("%d\n", atoi(str));
				printf("Thong tin khach hang da duoc thay doi!");
			}
			else{
				printf("\nThong tin khach hang can them\n");
				printf(" -Chi so Dien: ");
				scanf("%d", &chiSoDien[idex].suDungDien[chiSoDien[idex].n].chiSoDien);
				printf(" -Ngay chot (DD/MM/YY): ");
				int tmp; scanf("%c", &tmp);
				gets(chiSoDien[idex].suDungDien[chiSoDien[idex].n].ngayChot);
				printf(" -Ky: ");
				char str[2];
				str[0] = chiSoDien[idex].suDungDien[chiSoDien[idex].n].ngayChot[3];
				str[1] = chiSoDien[idex].suDungDien[chiSoDien[idex].n].ngayChot[4];
				chiSoDien[idex].suDungDien[chiSoDien[idex].n].ky = atoi(str);
				printf("%d\n", atoi(str));
				printf("Thong tin khach hang da duoc thay doi!");
				chiSoDien[idex].n += 1;
			}
		}
		else if(luaChon2 == 3){
			do{
				printf("Nhap thong tin ky can xoa: ");	
				scanf("%d", &ky);
				if(ky <= 0 || ky > 12){
					printf("ky phai tu 1 -> 12. Yeu cau nhap lai.\n");
				}			
			}while(ky <= 0 || ky > 12);
			value = 0;
			int id;
			for(int i = 0;i < chiSoDien[idex].n;i++){
				if(chiSoDien[idex].suDungDien[i].ky == ky){
					printf("Thong tin ki da duoc xoa!\n");
					id = i;
					value = 1;
					break;
				}
			}
			if(value == 0){
				printf("Khong co ky tuong ung!");
			}
			else{
				if(chiSoDien[idex].n == 1){
					chiSoDien[idex].suDungDien[0].chiSoDien = 0;
					strcpy(chiSoDien[idex].suDungDien[0].ngayChot, DAY);
					chiSoDien[idex].suDungDien[0].ky = 0;
				}
				else{
					for(int i = id;i < chiSoDien[idex].n - 1;i++){
					chiSoDien[idex].suDungDien[i] = chiSoDien[idex].suDungDien[i+1];
					}
					chiSoDien[idex].n--;
				}
			}
		}
	}
	fpCSDien = fopen("D:/CSDIEN.bin", "wb+");
	for(int i = 0; i < n;i++){
		sapxep(chiSoDien, i);
		fwrite(&chiSoDien[i], sizeof(CSDien), 1, fpCSDien);
	}
	fclose(fpCSDien);	
}

//nhap gia dien moi
void nhapGiaDien(FILE* fpGiaDien,int n){
	fpGiaDien = fopen("D:/GIADIEN.bin", "wb+");
	if(!fpGiaDien){
		printf("Co loi khi mo file!");
		fclose(fpGiaDien);
	}
	GDien* giaDien;
	giaDien = (GDien*)malloc(n*sizeof(GDien));
	giaDien[0].chiSoDau = 1;
	printf("Nhap bang gia dien: \n");
	for(int i = 0;i < n;i++){
		if(i > 0){
			giaDien[i].chiSoDau = giaDien[i-1].chiSoSau + 1;
		}
		printf(" -Chi so dau: %d\n", giaDien[i].chiSoDau);
		if(i == n - 1){
			printf(" -Chi so sau: MAX\n");
			giaDien[i].chiSoSau = MAX;
		}
		else{
			do{
				printf(" -Chi so sau: ");
				scanf("%d", &giaDien[i].chiSoSau);
				if(giaDien[i].chiSoSau <= giaDien[i].chiSoDau){
					printf("Chi so sau khong duoc nho hon chi so dau!\n");
				}
			}while(giaDien[i].chiSoSau <= giaDien[i].chiSoDau);
		}
		do{
			printf(" -Don gia: ");
			scanf("%d", &giaDien[i].donGia);
			if(giaDien[i].donGia <= 0){
				printf("Gia dien khong duoc nho hon 0!\n");
			}
		}while(giaDien[i].donGia <= 0);
		printf("\n");
	}
	for(int i = 0; i < n;i++){
		fwrite(&giaDien[i], sizeof(GDien), 1, fpGiaDien);
	}
	fclose(fpGiaDien);
}

//sua doi don gia tai bac so dien
void suaGiaDien(){
	FILE *fp;
	fp = fopen("D:/GIADIEN.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(GDien);

	GDien giaDien[n];
	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(GDien), SEEK_SET);
		fread(&giaDien[i], sizeof(GDien), 1, fp);
	}
	fclose(fp);
	int bac;
	do{
		printf("Nhap bac don gia dien can sua: ");
		scanf("%d", &bac);
		if(bac <= 0 || bac > n){
			printf("bac khong duoc nho hon 1 hoac lon hon %d!\n", n);
		}
	}while(bac <= 0|| bac > n);
	bac--;
	if(bac == n - 1){
		printf("Nhap gia dien sua tu %d kWh den MAX kWh: ", giaDien[bac].chiSoDau);
	}
	else{
		printf("Nhap gia dien sua tu %d kWh den %d kWh: ", giaDien[bac].chiSoDau, giaDien[bac].chiSoSau);
	}
	scanf("%d", &giaDien[bac].donGia);
	printf("Gia dien da duoc sua!");
	
	fp = fopen("D:/GIADIEN.bin", "wb");
	for(int i = 0;i < n;i++){
		fwrite(&giaDien[i], sizeof(GDien), 1, fp);
	}
	fclose(fp);
}

// in bang gia dien
void inGiaDien(){
	FILE *fp;
	GDien giaDien;
	fp = fopen("D:/GIADIEN.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(GDien);

	printf("%50s \n%-10s | %-20s | %-20s | %-20s", "Danh sach don gia", "Bac", "Chi so dau", "Chi so sau", "Don Gia");	
	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(GDien), SEEK_SET);
		fread(&giaDien, sizeof(GDien), 1, fp);
		char str[10];
		sprintf(str,"%d", giaDien.chiSoSau);
		if(giaDien.chiSoSau == MAX){
			strcpy(str,"MAX");
		}
		printf("\n%-10d | %-20d | %-20s | %-20d", i+1, giaDien.chiSoDau, str, giaDien.donGia);
	}
	fclose(fp);
}

//tinh gia dien va in vao file txt
void tinhGiaDien(){
	FILE *fp;
	fp = fopen("D:/GIADIEN.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(GDien);
	GDien giaDien[n];
	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(GDien), SEEK_SET);
		fread(&giaDien[i], sizeof(GDien), 1, fp);
	}
	fclose(fp);
	fp = fopen("D:/CSDIEN.bin", "rb");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}
	
	fseek(fp,0,SEEK_END);
	int m = ftell(fp) / sizeof(CSDien);	
	CSDien chiSoDien[m];
	TTDien tieuThuDien[m];
	for(int i = 0; i < m;i++){
		fseek(fp, i*sizeof(CSDien), SEEK_SET);
		fread(&chiSoDien[i], sizeof(CSDien), 1, fp);
	}
	fclose(fp);
	
	fp = fopen("D:/HOADON.TXT", "w");
	fprintf(fp, "%-24s%-24s%-24s%-24s\n", "Ma So Khach Hang", "Ky thu phi", "Dien Nang Tieu Thu", "Tien Dien");   

	for(int i = 0; i < m;i++){
		if(chiSoDien[i].n == 1){
			printf("Ma khach hang %s khong du du lieu de tinh tien dien\n", chiSoDien[i].maSoKH);
		}
		else{
			tieuThuDien[i].n = chiSoDien[i].n;
			int idx = 0;
			for(int j = 1;j < chiSoDien[i].n;j++){
				
				char y1[4];
				char y2[4];
				for(int k = 6; k < 10;k++){
					y1[k-6] = chiSoDien[i].suDungDien[j-1].ngayChot[k];
					y2[k-6] = chiSoDien[i].suDungDien[j].ngayChot[k];
				}
				if((atoi(y1) == atoi (y2) && chiSoDien[i].suDungDien[j].ky == chiSoDien[i].suDungDien[j-1].ky + 1) || (atoi(y1) + 1 == atoi (y2) && chiSoDien[i].suDungDien[j].ky == chiSoDien[i].suDungDien[j-1].ky  - 11)){
					idx++;
					strcpy(tieuThuDien[i].maSoKH, chiSoDien[i].maSoKH);
					tieuThuDien[i].dienNang[j].ky = chiSoDien[i].suDungDien[j].ky;
					tieuThuDien[i].dienNang[j].dienNangTieuThu = chiSoDien[i].suDungDien[j].chiSoDien - chiSoDien[i].suDungDien[j-1].chiSoDien;
					tieuThuDien[i].dienNang[j].tienDien = 0;
					for(int k = 0; k < n;k++){
						if(tieuThuDien[i].dienNang[j].dienNangTieuThu >= giaDien[k].chiSoDau && tieuThuDien[i].dienNang[j].dienNangTieuThu <= giaDien[k].chiSoSau){
							for(int l = 0; l < k;l++){
								tieuThuDien[i].dienNang[j].tienDien += (giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1)*giaDien[l].donGia;
								tieuThuDien[i].dienNang[j].dienNangTieuThu -= giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1;	
							}
							tieuThuDien[i].dienNang[j].tienDien += 	tieuThuDien[i].dienNang[j].dienNangTieuThu*giaDien[k].donGia;
							break;
						}
					}
					tieuThuDien[i].dienNang[j].dienNangTieuThu = chiSoDien[i].suDungDien[j].chiSoDien - chiSoDien[i].suDungDien[j-1].chiSoDien;
					if(idx == 1){
						fprintf(fp,"%-24s%-24d%-24d%-24d\n", tieuThuDien[i].maSoKH, tieuThuDien[i].dienNang[j].ky, tieuThuDien[i].dienNang[j].dienNangTieuThu, tieuThuDien[i].dienNang[j].tienDien);					
					}
					else{
						fprintf(fp,"%-24s%-24d%-24d%-24d\n", "", tieuThuDien[i].dienNang[j].ky, tieuThuDien[i].dienNang[j].dienNangTieuThu, tieuThuDien[i].dienNang[j].tienDien);					
					}
				}
				else{
					printf("Ma khach hang %s khong du du lieu de tinh tien dien ky %d chot ngay %s\n do khong co du lieu cua ky truoc do!\n",
												 chiSoDien[i].maSoKH, chiSoDien[i].suDungDien[j].ky, chiSoDien[i].suDungDien[j].ngayChot);
				}
			}
		}
	}
	fclose(fp);
	printf("Da ghi vao file HOADON.TXT\n");

}

//doc so tien dien thanh chu
void so(int n)
{
	if(n == 1)
		printf(" MOT");
	if(n == 2)
		printf(" HAI");
	if(n == 3)
		printf(" BA");
	if(n == 4)
		printf(" BON");
	if(n == 5)
		printf(" NAM");
	if(n == 6)
		printf(" SAU");
	if(n == 7)
		printf(" BAY");
	if(n == 8)
		printf(" TAM");
	if(n == 9)
		printf(" CHIN");
}
void docSoDau(int n)
{
	so(n/100);
	if(n/100 != 0)
		printf(" TRAM");
	if((n/10) % 10 != 0)
	{
		int m = (n/10) % 10;
		if(m == 1)
			printf(" MUOI");
		if(m == 2)
			printf(" HAI MUOI");
		if(m == 3)
			printf(" BA MUOI");
		if(m == 4)
			printf(" BON MUOI");
		if(m == 5)
			printf(" NAM MUOI");
		if(m == 6)
			printf(" SAU MUOI");
		if(m == 7)
			printf(" BAY MUOI");
		if(m == 8)
			printf(" TAM MUOI");
		if(m == 9)
			printf(" CHIN MUOI");
		m = n % 10;
		if(m == 1)
			printf(" MOT");
		if(m == 2)
			printf(" HAI");
		if(m == 3)
			printf(" BA");
		if(m == 4)
			printf(" BON");
		if(m == 5)
			printf(" LAM");
		if(m == 6)
			printf(" SAU");
		if(m == 7)
			printf(" BAY");
		if(m == 8)
			printf(" TAM");
		if(m == 9)
			printf(" CHIN");			
	}	
	else
	{
		if(n > 100)
		{
			printf(" LINH");
			so(n%10);
		}
		else
			so(n);
	}
}
void docSoGiua(int n){
	if(n == 0)
		printf("");
	else
	{
		if(n/100 == 0)
			printf(" KHONG");
		else
			so(n/100);
		printf(" TRAM");
		if((n/10) % 10 != 0)
		{
			int m = (n/10) % 10;
			if(m == 1)
				printf(" MUOI");
			if(m == 2)
				printf(" HAI MUOI");
			if(m == 3)
				printf(" BA MUOI");
			if(m == 4)
				printf(" BON MUOI");
			if(m == 5)
				printf(" NAM MUOI");
			if(m == 6)
				printf(" SAU MUOI");
			if(m == 7)
				printf(" BAY MUOI");
			if(m == 8)
				printf(" TAM MUOI");
			if(m == 9)
				printf(" CHIN MUOI");
			m = n % 10;
			if(m == 1)
				printf(" MOT");
			if(m == 2)
				printf(" HAI");
			if(m == 3)
				printf(" BA");
			if(m == 4)
				printf(" BON");
			if(m == 5)
				printf(" LAM");
			if(m == 6)
				printf(" SAU");
			if(m == 7)
				printf(" BAY");
			if(m == 8)
				printf(" TAM");
			if(m == 9)
				printf(" CHIN");			
		}
		else
		{
			printf(" LINH");
			so(n%10);		
		}
	}
}

void docSo(int n){
	if(n / 1000000 == 0)
	{
		docSoDau(n/1000);
		printf(" NGHIN");
		docSoGiua(n%1000);	
	} 
	else
	{
		docSoDau(n/1000000);
		printf(" TRIEU");
		docSoGiua((n%1000000)/1000);
		if((n%1000000)/1000 != 0)
			printf(" NGHIN");
		docSoGiua(n%1000);	
	}
	printf(" DONG.");
}

//In hoa don
void inHoaDon(FILE* fpKH ,FILE* fpCSDien,FILE* fpGiaDien, char* str){
	KH* khachHang;
	CSDien* chiSoDien;
	GDien* giaDien;
	
	
	fpKH = fopen("D:/KH.bin", "rb");
	fpCSDien = fopen("D:/CSDIEN.bin", "rb");
	if(!fpKH || !fpCSDien){
		printf("\nCo loi khi mo file!\n");
		fclose(fpKH);
		fclose(fpCSDien);
	}
	
	fseek(fpKH,0,SEEK_END);
	int n = ftell(fpKH) / sizeof(KH);
	khachHang = (KH*)malloc(n*sizeof(KH));
	chiSoDien = (CSDien*)malloc(n*sizeof(CSDien));
	int value = 0;
	int idex;
	
	for(int i = 0;i < n;i++){
		fseek(fpKH, i*sizeof(KH), SEEK_SET);
		fread(&khachHang[i], sizeof(KH), 1, fpKH);
		
		fseek(fpCSDien, i*sizeof(CSDien), SEEK_SET);
		fread(&chiSoDien[i], sizeof(CSDien), 1, fpCSDien);
	
		if(strlen(str) ==  strlen(khachHang[i].maSoKH)) {
			int count = 0;
			for(int j = 0; j < strlen(str);j++) {
				if(str[j] == khachHang[i].maSoKH[j])
					count++;
			}
			if(count == strlen(str)){
				idex = i;
				value = 1;
			}
		}
		if(strlen(str) ==  strlen(khachHang[i].tenKH)) {
			int count = 0;
			for(int j = 0; j < strlen(str);j++) {
				if(toupper(str[j]) == toupper(khachHang[i].tenKH[j]))
					count++;
			}
			if(count == strlen(str)){
				idex = i;
				value = 1;
			}
		}	
	}
	fclose(fpKH);
	fclose(fpCSDien);
	
	fpGiaDien = fopen("D:/GIADIEN.bin", "rb");
	if(!fpGiaDien){
		printf("\nCo loi khi mo file!\n");
		fclose(fpGiaDien);
	}

	fseek(fpGiaDien,0,SEEK_END);
	n = ftell(fpGiaDien) / sizeof(GDien);
	giaDien = (GDien*)malloc(n*sizeof(GDien));
	
	for(int i = 0;i < n;i++){
		fseek(fpKH, i*sizeof(KH), SEEK_SET);
		fread(&giaDien[i], sizeof(KH), 1, fpKH);
	}
	if(value == 0){
		printf("Khong tim thay khach hang!");
	}
	else{
		int ky;
		do{
			printf("Nhap thong tin ky can in hoa don: ");	
			scanf("%d", &ky);
			if(ky <= 0 || ky > 12){
				printf("ky phai tu 1 -> 12. Yeu cau nhap lai.\n");
			}			
		}while(ky <= 0 || ky > 12);
		value = 0;
		int id;
		for(int i = 0;i < chiSoDien[idex].n;i++){
			if(chiSoDien[idex].suDungDien[i].ky == ky){
				id = i;
				value = 1;
				break;
			}
		}
		if(value == 0){
			printf("Khong co ky tuong ung!");
		}
		else{
			if(id == 0){
				printf("Khong co du lieu cua thang truoc!");
			}
			else{
				char y1[4];
				char y2[4];
				for(int k = 6; k < 10;k++){
					y1[k-6] = chiSoDien[idex].suDungDien[id-1].ngayChot[k];
					y2[k-6] = chiSoDien[idex].suDungDien[id].ngayChot[k];
				}
				if((atoi(y1) == atoi (y2) && chiSoDien[idex].suDungDien[id].ky == chiSoDien[idex].suDungDien[id-1].ky + 1) || (atoi(y1) + 1 == atoi (y2) && chiSoDien[idex].suDungDien[id].ky == chiSoDien[idex].suDungDien[id-1].ky  - 11)){
					printf("%40s\n", "HOA DON TIEN DIEN");
					TTDien tieuThuDien;
					strcpy(tieuThuDien.maSoKH, chiSoDien[idex].maSoKH);
					tieuThuDien.dienNang[0].ky = chiSoDien[idex].suDungDien[id].ky;
					tieuThuDien.dienNang[0].dienNangTieuThu = chiSoDien[idex].suDungDien[id].chiSoDien - chiSoDien[idex].suDungDien[id-1].chiSoDien;
					tieuThuDien.dienNang[0].tienDien = 0;
					printf(" Ten khach hang: %s\n", khachHang[idex].tenKH);	
					printf(" Dia chi: %s\n", khachHang[idex].diaChi);
					printf(" Ma so khach hang: %s \t\t Ma so cong to: %s\n", khachHang[idex].maSoKH, khachHang[idex].maSoCT);
					printf(" Ki: %d tu ngay %s den ngay %s\n", chiSoDien[idex].suDungDien[id].ky, chiSoDien[idex].suDungDien[id-1].ngayChot, chiSoDien[idex].suDungDien[id].ngayChot);
					printf("%-16s | %-16s | %-20s | %-16s | %-16s\n", "Chi so cu", "Chi so moi", "Dien nang tieu thu", " Don gia", "Thanh tien");
					printf("%-16d | %-16d | %-20d | %-16s | %-16s\n", chiSoDien[idex].suDungDien[id-1].chiSoDien, chiSoDien[idex].suDungDien[id].chiSoDien, tieuThuDien.dienNang[0].dienNangTieuThu, "", "");
					for(int k = 0; k < n;k++){
						if(tieuThuDien.dienNang[0].dienNangTieuThu >= giaDien[k].chiSoDau && tieuThuDien.dienNang[0].dienNangTieuThu <= giaDien[k].chiSoSau){
							for(int l = 0; l < k;l++){
								tieuThuDien.dienNang[0].tienDien += (giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1)*giaDien[l].donGia;
								tieuThuDien.dienNang[0].dienNangTieuThu -= giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1;
								printf("%-16s | %-16s | %-20d | %-16d | %-16d\n", "", "", giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1, giaDien[l].donGia, (giaDien[l].chiSoSau - giaDien[l].chiSoDau + 1)*giaDien[l].donGia);
							}
							tieuThuDien.dienNang[0].tienDien += tieuThuDien.dienNang[0].dienNangTieuThu*giaDien[k].donGia;
							printf("%-16s | %-16s | %-20d | %-16d | %-16d\n", "", "", tieuThuDien.dienNang[0].dienNangTieuThu, giaDien[k].donGia, tieuThuDien.dienNang[0].dienNangTieuThu*giaDien[k].donGia);
							break;
						}
					}
					printf("%-35s | %-20d | %-16s | %-16d\n","Cong", chiSoDien[idex].suDungDien[id].chiSoDien - chiSoDien[idex].suDungDien[id-1].chiSoDien, "", tieuThuDien.dienNang[0].tienDien);
					printf("%-35s | %-39s | %-16d\n","Thue GTGT: 10%", "", tieuThuDien.dienNang[0].tienDien/10);
					printf("%-77s | %-16d\n", "Tong tien thanh toan: ", tieuThuDien.dienNang[0].tienDien/10 + tieuThuDien.dienNang[0].tienDien);
					printf("So viet bang chu: ");
					docSo(tieuThuDien.dienNang[0].tienDien*11/10);
					printf("\n");
				}
				else{
					printf("Ma khach hang %s khong du du lieu de tinh tien dien ky %d chot ngay %s\n do khong co du lieu cua ky truoc do!\n",
												 chiSoDien[idex].maSoKH, chiSoDien[idex].suDungDien[id].ky, chiSoDien[idex].suDungDien[id].ngayChot);
				}
			}
		}
		
	}
	
}
main(){
	FILE* fpKH;
	FILE* fpCSDien;
	FILE* fpGiaDien;
	int luaChon;
	do{
		printf("\n%40s \n %-30s \t %-30s \n %-30s \t %-30s \n %-30s", "Danh sach thao tac", "1. Khach Hang", "2. Chi so dien", "3. Gia dien", "4. Dien nang tieu thu", "0. Thoat");
		printf("\nLua chon: ");
		scanf("%d", &luaChon);
		switch(luaChon){
			case 1:{
					int luaChon2;
					do{
						printf("\n%40s \n %-30s \t %-30s \n %-30s \t %-30s \n %-30s \t %-30s", "Khach Hang", "1. Nhap danh sach moi", "2. Them khach hang" ,
											"3. Sua doi thong tin khach hang", "4. Xoa thong tin khach hang", "5. Xem danh sach", "0. Thoat");
						printf("\nLua Chon: ");
						scanf("%d", &luaChon2);
						switch(luaChon2){
							case 1:{
								char str[] = "wb+";
								nhapDanhSach(fpKH, fpCSDien, str);  // che do wb 
								break;
							}
							
							case 2:{
								char str[] = "ab+";
								nhapDanhSach(fpKH,fpCSDien, str);   //che do ab
								break;
							}
							
							case 3:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ten khach hang hoac ma so khach hang: ");
								gets(str);
								dieuChinh(fpKH,fpCSDien,str,3);
								break;
							}
							
							case 4:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ten khach hang hoac ma so khach hang: ");
								gets(str);
								dieuChinh(fpKH,fpCSDien,str,4);
								break;
							}
							
							case 5:{
								inDanhSach();
								break;
							}
							
							case 0:{
								break;
							}
							
							default:{
								printf("Yeu cau ban nhap khong dung! Hay nhap lai! \n");
								break;
							}
						}
					} while(luaChon2 != 0);
					break;
				}
			case 2:{
					int luaChon2;
					do{
						printf("\n%40s \n %-30s \t %-30s \n %-30s \t %-30s \n %-30s", "Chi so Dien", "1. Sua doi chi so dien khach hang", "2. Them ki moi", "3. Xoa mot ki cua khach hang", "4. Xem danh sach", "0. Thoat");
						printf("\nLua Chon: ");
						scanf("%d", &luaChon2);
						switch(luaChon2){
							case 1:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ma so khach hang: ");
								gets(str);
								suaChiSoDien(fpCSDien, str,1);
								break;
							}
							
							case 2:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ma so khach hang: ");
								gets(str);
								suaChiSoDien(fpCSDien, str,2);
								break;
							}
							
							case 3:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ma so khach hang: ");
								gets(str);
								suaChiSoDien(fpCSDien, str,3);
								break;
							}
							
							case 4:{
								inChiSoDien();
								break;
							}
							
							case 0:{
								break;
							}
							
							default:{
								printf("Yeu cau ban nhap khong dung! Hay nhap lai! \n");
								break;
							}
						}	
					
					} while(luaChon2 !=0);
					break;
				}
				
			case 3:{
					int luaChon2;
					do{
						printf("\n%40s \n %-30s \t %-30s \n %-30s \t %-30s", "Gia Dien", "1. Nhap don gia moi", "2. Sua doi don gia", "3. Xem don gia", "0. Thoat");
						printf("\nLua Chon: ");
						scanf("%d", &luaChon2);
						switch(luaChon2){
							case 1:{
								int n;
								do{
									printf("Nhap so bac don gia dien: ");
									scanf("%d", &n);
									if(n <= 0){
										printf("So bac khong duoc nho hon 0!\n");
									}
								}while(n <=0 );
								nhapGiaDien(fpGiaDien, n);
								break;
							}
							
							case 2:{
								suaGiaDien();
								break;
							}
							
							case 3:{
								inGiaDien();
								break;
							}
							
							case 0:{
								break;
							}
							
							default:{
								printf("Yeu cau ban nhap khong dung! Hay nhap lai! \n");
								break;
							}
						}	
					} while(luaChon2 !=0);
					break;
				}
			
			case 4:{
					int luaChon2;
					do{
						printf("\n%40s \n %-30s \t %-30s \n %-30s", "Tinh Gia Dien", "1. Tinh tien dien", "2. In hoa don", "0. Thoat");
						printf("\nLua Chon: ");
						scanf("%d", &luaChon2);
						switch(luaChon2){
							case 1:{
								tinhGiaDien();
								break;
							}
							
							case 2:{
								int tmp; scanf("%c", &tmp);
								char str[30];
								printf("Nhap ma so khach hang: ");
								gets(str);
								inHoaDon(fpKH, fpCSDien, fpGiaDien, str);
								break;
							}
							
							case 0:{
								break;
							}
							
							default:{
								printf("Yeu cau ban nhap khong dung! Hay nhap lai! \n");
								break;
							}
						}
					}while(luaChon2 != 0);
					break;
				}	
						
			case 0:{
					break;
				}
					
			default:{
					printf("Yeu cau ban nhap khong dung! Hay nhap lai! \n");
					break;
				}
		}
	}while(luaChon != 0);
}
