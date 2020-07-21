#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <malloc.h>
#define KH "KHACHHANG.BIN"
#define CSD "CSD.BIN"
#define DG "GIADIEN.BIN"
#define M 100

typedef struct KhachHang
{
    char MaKH[M];
    char HoTen[M];
    char DiaChi[M];
    char MaCongTo[M];
}kh;
typedef struct CongSuatDien
{
    char MaKH[M];
    char ChiSoDien[M];
    char NgayChot[M];
    char Ky[M];
}csd;
typedef struct GiaDien
{
    char DienNangTieuThu[M];
    char DonGia[M];
}gd;

void nhap(); //
void nhapKH(); //
void nhapCSD(); //

void read(); //
void readKH(); //
void readCSD(); //
void readGiaDien(); //

void search(); //

void themSuaXoa();
void themSuaXoaKH();
void themSuaXoaCSD();

void themKH();
void suaKH();
//tạo các hàm con để lồng vào hàm suaKH để sửa thông tin theo từng trường trong bảng KH.BIN
//Cụ thể: tạo 1 case để lựa chọn trường muốn sửa thông tin (viết hàm hơi khoai :v)
// sẽ cố định mã số khách hàng ( thậm chí cả họ tên để đỡ phải code nhiều), chỉ đổi các trường còn lại. Tương tự với bảng CSDIEN.BIN
void suaHoTen();
void suaDiaChi();
void suaMaCT();
void xoaKH();

void themCSD();
void suaCSD();
void suaChiSoDien();
void suaNgayChot();
void suaKy();
void xoaCSD();

void nhap()
{
    int luaChon;
    int c;
	char fileName[100];
	char F1 [100];
	char F2 [100];
    do
    {
        printf("====================================\n");
        printf("=====THAO TAC NHAP THONG TIN!======\n ");
        printf("Moi ban chon chuc nang:\n");
        printf("1. Nhap thong tin khach hang.\n");
        printf("2. Nhap thong tin cong suat dien.\n");
        printf("3. Nhap thong tin gia dien.\n");
        printf("0. Thoat.\n");
        printf("Bam phim bat ki de tiep tuc!\n");
        printf("====================================\n");
        printf("Nhap lua chon cua ban: \n");
	    scanf("%d",&luaChon);
	    fflush(stdin);

        switch (luaChon)
        {
        case 0:
            printf("Thoat chuong chuc nang nhap thong tin!\n");
            break;
        case 1:
            printf("=== NHAP THONG TIN KHACH HANG ===\n");
            //ném vào đây hàm nhập thông tin cho bảng KH.BIN
            printf("Nhap vao ten file: ");
            gets(fileName);
            nhapKH(fileName);
            break;
        case 2:
            printf("=== NHAP THONG TIN CONG SUAT DIEN ===\n");
            //ném vào đây hàm nhập thông tin cho bảng CSDIEN.BIN
            printf("Nhap vao ten file: ");
            gets(fileName);
            nhapCSD(fileName);
            break;
        case 3:
            printf("=== NHAP BANG GIA DIEN === \n");
            printf("Nhap ten file:");
            gets(fileName);
            nhapGiaDien(fileName);
        default:
            printf("Chuc nang ban chon khong hop le! Hay nhap lai!\n");
            break;
        }
    }
    while(luaChon != 0);
}

void nhapKH(char *FileName )
{
	FILE *f ;
	int n,i;
	struct KhachHang kh;
	struct CongSuatDien csd;
	f=fopen(FileName,"ab+");
	printf("Nhap so luong khach hang: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Khach hang thu %d\n",i);
		fflush(stdin);
		printf(" - MSKH: ");
		gets(kh.MaKH);
		while(makhcmp(FileName,kh.MaKH) > 0)
        {
            printf("Ma so ban nhap da ton tai! Hay nhap ma so khac!\n");
            printf(" - MSKH khac: ");
            gets(kh.MaKH);
        }
		printf(" - Ho Ten: ");
		gets(kh.HoTen);
		printf(" - Dia chi: ");
		gets(kh.DiaChi);
		printf(" - Ma So Cong To Dien: ");
		gets(kh.MaCongTo);
		fwrite(&kh,sizeof(kh),1,f);
    }
		fclose(f);
		f = fopen(FileName,"ab+");

	fclose(f);
	printf("Bam phim bat ki de tiep tuc!\n");
	getch();
}
void nhapCSD( char *F2 )
{
	FILE *f2;
	int n,i;
	long fileSize;
    int numEntries;
    //char *luu[100];
	struct KhachHang kh;
	struct CongSuatDien csd;
	f2 = fopen(F2,"ab+");
	/*printf("Nhap so luong khach hang: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Khach hang thu %i\n",i);
		fflush(stdin);
		printf(" - MSKH: ");
		gets(csd.MaKH);
		while(makhcmp(F2,csd.MaKH) > 0)
        {
            printf("Ma so ban nhap da ton tai! Hay nhap ma so khac!\n");
            printf(" - MSKH khac: ");
            gets(csd.MaKH);
        }*/

    strcpy(csd.MaKH , kh.MaKH);
    gets(csd.MaKH);
    fileSize = ftell( f2 );
	numEntries = (int)(fileSize / sizeof(csd));
	printf("numEntries : %d\n", numEntries );
    for(i = 1; i <= numEntries; i++)
    {
        printf("Khach hang thu %d\n", i);
        fflush(stdin);
        printf(" - Chi So Dien: ");
        gets(csd.ChiSoDien);
        printf(" - Ngay Chot: ");
        gets(csd.NgayChot);
        printf(" - Ky: ");
        gets(csd.Ky);
        fwrite(&csd,sizeof(csd),1,f2);
        fclose(f2);
        f2 = fopen(F2,"ab+");
    }
		/*printf(" - Chi So Dien: ");
		gets(csd.ChiSoDien);
		printf(" - Ngay Chot: ");
		gets(csd.NgayChot);
		printf(" - Ky: ");
		gets(csd.Ky);
		fwrite(&csd,sizeof(csd),1,f2);
		fclose(f2);
		f2 = fopen(F2,"ab+");
	}*/
	fclose(f2);
	printf("Bam phim bat ki de tiep tuc!");
	getch();
}

void nhapGiaDien( char *F )
{
	FILE *f;
	int n,i;
	struct GiaDien gd;
	f = fopen(F,"ab+");
	printf("Nhap vao bang gia dien: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf(" - Muc gia dien thu: %d\n",i);
		fflush(stdin);
		printf(" - Dien Dien Nang Tieu Thu: ");
		gets(gd.DienNangTieuThu);
		while(makhcmp(F,gd.DienNangTieuThu) > 0)
        {
            printf("Ban da nhap muc dien nang tieu thu nay! Hay nhap muc tiep theo!\n");
            printf(" - Muc dien nang tieu thu tiep theo: ");
            gets(gd.DienNangTieuThu);
        }
		printf(" - Don Gia (vnd/kWh): ");
		gets(gd.DonGia);
		fwrite(&gd,sizeof(gd),1,f);
		fclose(f);
		f = fopen(F,"ab+");
	}
	fclose(f);
	printf("Bam phim bat ki de tiep tuc!\n");
	getch();
}


void read()
{
    int luaChon;
    int c;
	char fileName[100];
	char F1 [100];
	char F2 [100];
	char F3 [100];
    do
    {
        printf("===================================\n");
        printf("=====THAO TAC DOC THONG TIN!======\n ");
        printf("Moi ban chon chuc nang:\n");
        printf("1. Doc thong tin khach hang.\n");
        printf("2. Doc thong tin cong suat dien.\n");
        printf("3. Doc bang gia dien.\n");
        printf("0. Thoat.\n");
        printf("Bam phim bat ki de tiep tuc!\n");
        printf("===================================\n");
        printf("Nhap lua chon cua ban: \n");
	    scanf("%d",&luaChon);
	    fflush(stdin);

        switch (luaChon)
        {
        case 0:
            printf("Thoat chuong chuc nang doc thong tin!\n");
            break;
        case 1:
            printf("=== DOC THONG TIN KHACH HANG ===\n");
            //ném vào đây hàm nhập thông tin cho bảng KH.BIN
            printf("Nhap vao ten file: ");
            gets(fileName);
            readKH(fileName);
            break;
        case 2:
            printf("=== DOC THONG TIN CONG SUAT DIEN ===\n");
            printf("Nhap vao ten file: ");
            gets(fileName);
            readCSD(fileName);
            break;
        case 3:
            printf("=== DOC BANG GIA DIEN ===\n");
            printf("Nhap vao ten file: ");
            gets(fileName);
            readGiaDien(fileName);
        default:
            printf("Chuc nang ban chon khong hop le! Hay nhap lai!\n");
            break;
        }
    }
    while(luaChon != 0);
}

void readKH(char *FileName)
{
	FILE *f;
	struct KhachHang kh;
    long fileSize;
    int numEntries;
	f=fopen(FileName,"rb");
	if ( f == NULL)
    {
        printf("File ban nhap khong ton tai!\n");
        fclose(f);
    }
    else
    {

        fseek(f, 0, SEEK_END );
        fileSize = ftell( f );
        numEntries = (int)(fileSize / sizeof(kh));
        //printf("numEntries : %d\n", numEntries );
        printf("\tMS\t|Ho va Ten \t| Dia Chi \t| Ma So Cong To\n");
        for(  int i = 0; i < numEntries; ++i ){
            fseek( f, i * sizeof( kh ), SEEK_SET );
            fread( &kh, sizeof( kh ), 1, f );
            printf(" %12s | %12s | %12s | %12s \n",kh.MaKH,kh.HoTen,kh.DiaChi,kh.MaCongTo);
        }

        fclose(f);
    }
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}


void readCSD(char *FileName)
{
	FILE *f;
	struct CongSuatDien csd;
    long fileSize;
    int numEntries;
	f=fopen(FileName,"rb");
	if ( f == NULL)
    {
        printf("File ban nhap khong ton tai!\n");
        fclose(f);
    }
    else
    {
        fseek(f, 0, SEEK_END );
        fileSize = ftell( f );
        numEntries = (int)(fileSize / sizeof(csd));
        //printf("numEntries : %d\n", numEntries );
        printf("\tMa KH\t|Chi So Dien \t| Ngay Chot \t| Ky\n");
        for(  int i = 0; i < numEntries; ++i ){
            fseek( f, i * sizeof( csd ), SEEK_SET );
            fread( &csd, sizeof( csd ), 1, f );
            printf(" %12s | %12s | %12s | %12s \n",csd.MaKH,csd.ChiSoDien,csd.NgayChot,csd.Ky);
        }
        fclose(f);
    }
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}

void readGiaDien(char *FileName)
{
	FILE *f;
	struct GiaDien gd;
    long fileSize;
    int numEntries;
	f=fopen(FileName,"rb");
	if ( f == NULL)
    {
        printf("File ban nhap khong ton tai!\n");
        fclose(f);
    }
    else
    {
        fseek(f, 0, SEEK_END );
        fileSize = ftell( f );
        numEntries = (int)(fileSize / sizeof(gd));
        //printf("numEntries : %d\n", numEntries );
        printf("\tDien Nang Tieu Thu (kWh)\t|Don Gia (vnd/kWh) \n");
        for(  int i = 0; i < numEntries; ++i ){
            fseek( f, i * sizeof( gd ), SEEK_SET );
            fread( &gd, sizeof( gd ), 1, f );
            printf(" %12s | %12s  \n", gd.DienNangTieuThu, gd.DonGia);
        }

        fclose(f);
    }
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}

/*void searchKH(char *FileName)
{
	char MaKH[M];
	FILE *f ;
	int Found=0;
	struct KhachHang kh;
	fflush(stdin);
	printf("Ma so khach hang can tim: ");
	gets(MaKH);
	f=fopen(FileName,"rb");

	while (!feof(f))
	{
		fread(&kh,sizeof(kh),1,f);
		if(strcmps(kh.MaKH,MaKH) > 0){
        Found = 1;
        break;
		}


	}
	fclose(f);
	if (Found == 1)
	{
		printf("Tim thay khach hang co ma %s. Ho ten la: %s. Dia chi la: %s. Ma So cong to: %s",kh.MaKH,kh.HoTen,kh.DiaChi,kh.MaCongTo);
	}
	else
	{
		printf("Khong tim thay khach hang co ma: %s",MaKH);
	}
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}
void searchCSD(char *FileName)
{
	char MaKH[M];
	FILE *f ;
	int Found=0;
	struct CSDIEN csd;
	fflush(stdin);
	printf("Ma so khach hang can tim: ");
	gets(MaKH);
	f=fopen(FileName,"rb");

	while (!feof(f))
	{
		fread(&csd,sizeof(csd),1,f);
		if(strcmps(csd.MaKH,MaKH) > 0){
        Found = 1;
        break;
		}


	}
	fclose(f);
	if (Found == 1)
	{
		printf("Tim thay khach hang co ma %s. \nChi so dien: %s. \nNgay chot: %s \nKy: %s. \n", csd.MaKH, csd.ChiSoDien, csd.NgayChot, csd.Ky);
	}
	else
	{
		printf("Khong tim thay khach hang co ma: %s",MaKH);
	}
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}

void searchGiaDien(char *FileName)
{
	char MaKH[M];
	FILE *f ;
	int Found=0;
	struct GiaDien gd;
	fflush(stdin);
	printf("Ma so khach hang can tim: ");
	gets(DienNangTieuThu);
	f=fopen(FileName,"rb");

	while (!feof(f))
	{
		fread(&gd,sizeof(gd),1,f);
		if(strcmps(gd.DienNangTieuThu, DienNangTieuThu) > 0){
        Found = 1;
        break;
		}


	}
	fclose(f);
	if (Found == 1)
	{
		printf("Dien nang tieu thu: %s.\nDon Gia: %s.\n", gd.DienNangTieuThu, gd.DonGia);
	}
	else
	{
		printf("Dien nang tieu thu ban nhap khong hop le!",);
	}
	printf("\nBam phim bat ki de tiep tuc!\n");
	getch();
}

*/

void themSuaXoa()
{
    int luaChon;
    do
    {
        printf("==============================================\n");
        printf("========= CHUC NANG THEM - SUA - XOA =========\n");
        printf("Moi ban chon chuc nang:\n");
        printf("1. Them - Sua - Xoa thong tin khach hang.\n");
        printf("2. Them - Sua - Xoa thong tin cong suat dien.\n");
        printf("0. Thoat!\n");
        printf("Bam phim bat ki de tiep tuc!\n");
        printf("==============================================\n");
        switch(luaChon)
        {
            case 0:
                printf("Thoat chuc nang Them - Sua - Xoa.\n");
                break;
            case 1:
                printf("Them - Sua - Xoa thong tin khach hang.\n");
                //themSuaXoaKH();
                break;
            case 2:
                printf("Them - Sua - Xoa thong tin cong suat dien.\n");
                //themSuaXoaCSD();
                break;
            default:
                printf("Chuc nang ban chon khong hop le!\n");
                break;
        }
    }
    while (luaChon != 0);
}
void themSuaXoaKH()
{
    int luaChon;
    do
    {
        printf("============================================");
        printf("=== THAO TAC VOI THONG TIN KHACH HANG. ===\n");
        printf("1. Them khach hang.\n");
        printf("2. Sua thong tin khach hang.\n");
        printf("3. Xoa thong tin khach hang.\n");
        printf("0. Thoat!");
        printf("Bam phim bat ki de tiep tuc!\n");
        printf("============================================");

        switch(luaChon)
        {
            case 0:
                printf("Thoat thao tac voi thong tin khach hang.\n");
                break;
            case 1:
                printf("Them khach hang.\n");
                //themKH();
                break;
            case 2:
                printf("Sua thong tin khach hang.\n");
                //Tạo một case con trong hàm sửa để sửa từng nội dung
                //suaKH();
                break;
            case 3:
                printf("Xoa thong tin khach hang.\n");
                //xoaKH();
                break;
            default:
                printf("Chuc nang ban chon khong hop le!\n");
                break;
        }
    }
    while (luaChon != 0);
}

void themSuaXoaCSD()
{
    int luaChon;
    do
    {
        printf("================================================\n");
        printf("=== THAO TAC VOI THONG TIN CONG SUAT DIEN. ===\n");
        printf("1. Them thong tin.\n");
        printf("2. Sua thong tin.\n");
        printf("3. Xoa thong tin.\n");
        printf("0. Thoat!");
        printf("Bam phim bat ki de tiep tuc!\n");
        printf("================================================\n");

        switch(luaChon)
        {
            case 0:
                printf("Thoat thao tac voi thong tin cong suat dien.\n");
                break;
            case 1:
                printf("Them thong tin.\n");
                //themCSD();
                break;
            case 2:
                printf("Sua thong tin.\n");
                //Tạo một case con trong hàm sửa để sửa từng nội dung
                ////suaCSD();
                break;
            case 3:
                printf("Xoa thong tin.\n");
                //xoaCSD();
                break;
            default:
                printf("Chuc nang ban chon khong hop le!\n");
                break;
        }
    }
    while (luaChon != 0);
}

//Hàm sửa với thông tin khách hàng.
void suaKH()
{
    int luaChon;
    do
    {
        printf("===============================================\n");
        printf("========== SUA THONG TIN KHACH HANG. ==========\n");
        printf("1. Sua ten khach hang.\n");
        printf("2. Sua dia chi khach hang.\n");
        printf("3. Sua ma so cong to.\n");
        printf("0. Thoat!");
        printf("Bam phim bat ky de tiep tuc!");
        printf("===============================================\n");
        switch (luaChon)
        {
            case 0:
                printf("Thoat chuc nang sua thong tin khach hang.\n");
                break;
            case 1:
                printf("=== Sua ten khach hang ===\n");
                //suaHoTen();
                break;
            case 2:
                printf("=== Sua dia chi khach hang. ===\n");
                //suaDiaChi();
                break;
            case 3:
                printf("=== Sua ma so cong to. ===\n");
                //suaMaCT();
                break;
            default:
                printf("Chuc nang ban chon khong hop le!\n");
                break;
        }
    }
    while (luaChon != 0);
}

//Sửa đối với bảng CSDIEN.BIN
void suaCSD()
{
    int luaChon;
    do
    {
        printf("=============================================\n");
        printf("======= SUA THONG TIN CONG SUAT DIEN. =======\n");
        printf("1. Sua chi so dien.\n");
        printf("2. Sua ngay chot chi so dien.\n");
        printf("3. Sua ky.\n");
        printf("0. Thoat!");
        printf("Bam phim bat ky de tiep tuc!\n");
        printf("=============================================\n");
        switch (luaChon)
        {
            case 0:
                printf("Thoat chuc nang sua thong tin cong suat dien.\n");
                break;
            case 1:
                printf("=== Sua chi so dien ===\n");
                //suaHoTen();
                break;
            case 2:
                printf("=== Sua ngay chot chi so dien. ===\n");
                //suaDiaChi();
                break;
            case 3:
                printf("=== Sua ky. ===\n");
                //suaMaCT();
                break;
            default:
                printf("Chuc nang ban chon khong hop le!\n");
                break;
        }
    }
    while (luaChon != 0);
}
int strcmps(char a[M], char b[M])
{
    if(strlen(a) != strlen(b)){
        return -1;
        }
    else{
        for(int i = 0;i < strlen(a);i++){
        if(a[i] != b[i]){
        return -1; }
          }
        }
    return 1;
}

int makhcmp(char *FileName, char *str){
    int tmp = -1;
    FILE *f;
    struct KhachHang kh;
    f=fopen(FileName,"rb");
	while (!feof(f))
	{
		fread(&kh,sizeof(kh),1,f);
		if(strcmps(kh.MaKH,str) > 0)
        {
        tmp = 1;
        break;
		}
	}
	fclose(f);
	return tmp;
}


void main()
{

	char *luu[100];
	int luaChon;
	char fileName[100];
	char F1 [100];
	char F2 [100];
	FILE *f;
	do
    {
    printf("========================================\n");
	printf("=========== BAI TAP LON KTLT ===========\n");
	printf("1. NHAP THONG TIN KHACH HANG.\n");
	printf("2. XEM THONG TIN KHACH HANG.\n");
	printf("3. TIM KIEM THONG TIN KHACH HANG.\n");
	printf("4. SUA THONG TIN KHACH HANG.\n");
	printf("5. XOA THONG TIN KHACH HANG.\n");
	printf("0. THOAT!\n");
	printf("========================================\n");
	printf("Nhap lua chon cua ban: \n");
	scanf("%d",&luaChon);
	fflush(stdin);

	switch (luaChon)
	{
        case 0:
            printf("THOAT CHUONG TRINH!\n");
            break;
		case 1:
		    printf("=== CHUC NANG NHAP THONG TIN KHACH HANG. ===\n");
            nhap();
		    break;
        case 2:
            printf("=== CHUC NANG XEM THONG TIN KHACH HANG. ===\n");
            read();
            break;
        case 3:
            printf("=== CHUC NANG TIM KIEM THONG TIN KHACH HANG. ===\n");
            printf("Nhap ten file: ");

            break;
        case 4:
            printf("=== CHUC NANG SUA THONG TIN KHACH HANG.=== \n");
            printf("");

            break;
        case 5:
            printf("=== CHUC NANG XOA THONG TIN KHACH HANG. ===\n");
            printf("");

            break;
        default:
            {
                printf("Yeu cau cua ban khong hop le! Hay nhap lai!\n");
                break;
            }
	}
    }while(luaChon != 0);
}


