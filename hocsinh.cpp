#include <string.h>
#include <ctype.h>

#define DAY "00/00/0000"
#define MAX 1000000

struct studentInformation{
	char maSoHS[4];
	char hoTen[30];
	char diaChi[50];
	char soDTPhuHuynh[20];
};
typedef struct studentInformation stInfor;

struct start{
	char maSoHS[4];
	char day_start[10];
	char voPhuc[10];
};
typedef struct stt start;

struct hocPhi{
	char maSoHS[4];
	char hoTen[30];
	char hocPhi[10];
};
typedef struct hocPhi hocPhi;

// kiem tra ma so nhap vao co trong file hay chua
int kTraMaSoHS(char *maSoHS){
	FILE *fp;
	stInfor studentInformation;
	fp = fopen("D:/Hocsinh.TXT", "r");
	if(!fp){
		printf("\nCo loi khi mo file!\n");
		fclose(fp);
	}

	fseek(fp,0,SEEK_END);
	int n = ftell(fp) / sizeof(stInfor); //kiem tra do dai

	for(int i = 0;i < n;i++){
		fseek(fp, i*sizeof(stInfor), SEEK_SET);
		fread(&studentInformaton, sizeof(stInfor), 1, fp);
		if(strlen(maSoHS) ==  strlen(studentInformation.maSoHS)) {
			int count = 0;
			for(int j = 0; j < strlen(maSoHS);j++) {
				if(maSoHS[j] == studentInformation.maSoHS[j])
					count++;
			}
			if(count == strlen(maSoHS))
				return 0;
		}
	}
	fclose(fp);
	return 1;
}

//them hoac nhap danh sach vo sinh moi
void nhapDanhSach(FILE* fpstInfor, FILE* fpstart, char* str){
	fpstInfor = fopen("D:/Hocsinh.TXT", str);
	fpstart = fopen("D:/NhapHoc.TXT", str);
	if(!fpstInfor){
		printf("\nCo loi khi mo file!\n");
		fclose(fpstInfor);
		fclose(fpstart);
	}
	else{
		fclose(fpstInfor);
		fclose(fpstart);	
		int soHS;
		do{
			printf("So luong hoc sinh can them:");
			scanf("%d", &soHS);
			if(soHS <= 0){
			printf("So hoc sinh phai la so > 0! Moi nhap lai\n");
			}
		}while(soHS <= 0);
		
		for(int i = 0; i < soHS;i++){
			int tmp;
			stInfor studentInformation;
			stt start;
			if(i == 0){
				scanf("%c", &tmp);    //thay cho fflush(stdin)
			}
			printf("\nHoc sinh thu %d\n", i+1);
			do{
				printf(" -Ma so: ");
				gets(stInfor.maSoHS);
				if(!kTraMaSoKH(stInfor.maSoHS)){
					printf("Ma so hoc sinh da co! Vui long nhap lai!\n");
				}
			}while(!kTraMaSoKH(stInfor.maSoHS));
			printf(" -Ho Ten: ");
			gets(stInfor.maSoHS);
			printf(" -Dia chi: ");
			gets(stInfor.diaChi);
			printf(" -SDT Phu Huynh: ");
			gets(stInfor.soDTPhuHuynh);
			
			strcpy(stInfor.maSoHS, stt.maSoHS);
			stt.n = 1;
			stt.;
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


