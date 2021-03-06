#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
void tampilan_awal(){
	printf("1. Login sebagai tenaga kesehatan\n"); 
	printf("2. Login sebagai pasien\n"); 
}
int pilihan(){
	int choose; 
	printf("=====================================================================\n"); 
	printf("Ketik pilihan anda : "); 
	scanf("%d", &choose);
    return choose; 
}
typedef struct {
	char nama_pasien[50];
	char nama_dokter[50];
	char alamat[50]; 
	char riwayat_penyakit[50];
	char keluhan[50];
	char pekerjaan[20];
	char no_telepon[12];
	char jam_konsultasi[5]; 
	char tanggal_masuk[20];
	int id;  
}patient_identity;
int menu_perawat(){
	int input;
	printf("=====================================================================\n"); 
	printf("1. Jadwal Kerja\n");
	printf("2. Total Gaji\n");
	printf("3. Tampilkan Data Pasien Rawat Inap\n");
	printf("=====================================================================\n"); 
	printf("Ketik pilihan anda : "); 
	scanf("%d", &input); 
	return input; 
}
int get_ID(){
	srand(time(0));
	int nilai = rand() % 10000;
	return nilai;
}
void formulir_pasien_rawat_inap(){
	back:
	char cek;
	FILE *formulir = fopen("formulir_pasien_rawat_inap.txt","w");
	FILE *data_inap = fopen("data_rawat_inap.txt", "a"); 
	patient_identity inap;
	printf("ketik nama pasien             : ");
	fflush(stdin); 
	scanf("%[^\n]", inap.nama_pasien);
	printf("ketik no telepon pasien       : "); 
	fflush(stdin); 
	scanf("%[^\n]",inap.no_telepon);
	printf("ketik alamat pasien           : "); 
	fflush(stdin); 
	scanf("%[^\n]", inap.alamat); 
	printf("ketik pekerjaan pasien        : "); 
	fflush(stdin); 
	scanf("%[^\n]", inap.pekerjaan); 
	printf("ketik keluhan pasien          : ");
	fflush(stdin); 
	scanf("%[^\n]", inap.keluhan); 
	printf("ketik nama dokter             : "); 
	fflush(stdin); 
	scanf("%[^\n]", inap.nama_dokter); 
	printf("ketik tanggal masuk pasien    : "); 
	fflush(stdin); 
	scanf("%[^\n]", inap.tanggal_masuk);
	printf("=====================================================================\n"); 
	printf("\t\t DATA PASIEN RAWAT INAP RUMAH SAKIT BALIMED \n"); 
	printf("=====================================================================\n"); 
	printf("Nama Pasien       : %s\n", inap.nama_pasien); 
	printf("No telepon pasien : %s\n", inap.no_telepon);
	printf("Alamat pasien     : %s\n", inap.alamat); 
	printf("Pekerjaan pasien  : %s\n", inap.pekerjaan); 
	printf("Keluhan pasien    : %s\n", inap.keluhan); 
	printf("Nama dokter       : %s\n", inap.nama_dokter);
	printf("tanggal masuk     : %s\n", inap.tanggal_masuk); 
	inap.id = get_ID();
	printf("ID Pasien         : %d\n", inap.id);
	printf("apakah data yang anda masukan benar? : ");
	fflush(stdin);
	scanf("%c", &cek); 
	if(cek == 'y'){
		// masukan data ke dalam file formulir ;
		fputs("\t\t\t\t\t\t\t\tPEMERINTAH KABUPATEN DENPASAR\n", formulir); 
		fputs("\t\t\t\t\t\t\t\t   RUMAH SAKIT UMUM BALIMED\n", formulir); 
		fputs("\t\t\t\t\t\t  Jl. Mahendrata No 57 X,  Padangsambian, Kecamatan Barat\n", formulir); 
		fputs("\t\t\t\t\t\t\t     Provinsi Bali Telp./fax (0361)484872\n", formulir); 
		fputs("\t\t\t\t\t\t\t        Email : rsudbalimed@gmail.com\n", formulir); 
		fputs("\t\t\t\t\t  =======================================================================\n", formulir); 
		fputs("DATA PASIEN RAWAT INAP RUMAH SAKIT BALIMED\n", formulir);
		fputs("Nama Pasien       : ", formulir);
		fputs(inap.nama_pasien, formulir);
		fputs("\n", formulir);
		fputs("No telepon pasien : ", formulir); 
		fputs(inap.no_telepon, formulir); 
		fputs("\n", formulir);
		fputs("Pekerjaan pasien  : ", formulir); 
		fputs(inap.pekerjaan, formulir);
		fputs("\n", formulir); 
		fputs("Keluhan pasien    : ", formulir); 
		fputs(inap.keluhan, formulir); 
		fputs("\n", formulir);
		fputs("Nama dokter       : ", formulir);
		fputs(inap.nama_dokter, formulir); 
		fputs("\n", formulir);
		fputs("Tanggal masuk     : ", formulir); 
		fputs(inap.tanggal_masuk, formulir);
		fputs("\n", formulir);
		fputs("ID Pasien         : ", formulir); 
		fprintf(formulir, "%d", inap.id);
		fputs("\n", formulir);  
		printf("=====================================================================\n");
		printf("\t   FORMULIR RAWAT INAP PASIEN AKAN DICETAK, MOHON MENUNGGU\n"); 
		printf("=====================================================================\n");
		system("START /MIN NOTEPAD /P formulir_pasien_rawat_inap.txt");
		// masukan data ke dalam file data rawat inap
		fprintf(data_inap, "%d", inap.id); 
		fputs("\n", data_inap);
		fputs(inap.nama_pasien, data_inap);
		fputs("\n", data_inap);
		fputs(inap.no_telepon, data_inap); 
		fputs("\n",data_inap);
		fputs(inap.pekerjaan, data_inap);
		fputs("\n", data_inap); 
		fputs(inap.keluhan, data_inap); 
		fputs("\n", data_inap);
		fputs(inap.nama_dokter, data_inap); 
		fputs("\n", data_inap);
		fputs(inap.tanggal_masuk, data_inap);
		fputs("\n", data_inap);
		fclose(data_inap);
		fclose(formulir); 
	}else{
		system("cls");
		goto back; 
	}
	
}

void read_data_pasien(){
	patient_identity idn; 
	FILE *read = fopen("riwayat_pasien.txt", "r");
	char ch = fgetc(read); 
	printf("\t\t\t\t\t\t\t\tPEMERINTAH KABUPATEN DENPASAR\n"); 
	printf("\t\t\t\t\t\t\t\t   RUMAH SAKIT UMUM BALIMED\n"); 
	printf("\t\t\t\t\t\t  Jl. Mahendrata No 57 X,  Padangsambian, Kecamatan Barat\n"); 
	printf("\t\t\t\t\t\t\t     Provinsi Bali Telp./fax (0361)484872\n"); 
	printf("\t\t\t\t\t\t\t        Email : rsudbalimed@gmail.com\n"); 
	printf("\t\t\t\t\t  =======================================================================\n");
	while((ch = fgetc(read)) != EOF){ 
		printf("%c", ch);
	}
	fclose(read); 
}
void formulir_pasien_konsultasi(){
	back: 
	char cek;
	patient_identity identitas; 
	FILE *formulir = fopen("formulir_pasien_konsultasi.txt", "w"); // ini file yang digunakan untuk memasukan data ke dalam formulir
	FILE *data_konsultasi = fopen("data_konsultasi.txt", "a");
	printf("ketik nama pasien       : ");
	fflush(stdin); 
	scanf("%[^\n]", identitas.nama_pasien);
	printf("ketik no telepon pasien : "); 
	fflush(stdin); 
	scanf("%[^\n]",identitas.no_telepon);
	printf("ketik alamat pasien     : "); 
	fflush(stdin); 
	scanf("%[^\n]", identitas.alamat); 
	printf("ketik pekerjaan pasien  : "); 
	fflush(stdin); 
	scanf("%[^\n]", identitas.pekerjaan); 
	printf("ketik keluhan pasien    : ");
	fflush(stdin); 
	scanf("%[^\n]", identitas.keluhan); 
	printf("ketik nama dokter       : "); 
	fflush(stdin); 
	scanf("%[^\n]", identitas.nama_dokter); 
	printf("ketik jam konsultasi    : "); 
	fflush(stdin); 
	scanf("%[^\n]", identitas.jam_konsultasi);
	printf("=====================================================================\n"); 
	printf("\t\t DATA PASIEN KONSULTASI RUMAH SAKIT BALIMED \n"); 
	printf("=====================================================================\n"); 
	printf("Nama Pasien       : %s\n", identitas.nama_pasien); 
	printf("No telepon pasien : %s\n", identitas.no_telepon);
	printf("Alamat pasien     : %s\n", identitas.alamat); 
	printf("Pekerjaan pasien  : %s\n", identitas.pekerjaan); 
	printf("Keluhan pasien    : %s\n", identitas.keluhan); 
	printf("Nama dokter       : %s\n", identitas.nama_dokter);
	printf("Jam Konsultasi    : %s\n", identitas.jam_konsultasi);
	identitas.id = get_ID(); 
	printf("ID Pasien         : %d\n", identitas.id);  
	printf("apakah data yang anda masukan benar? : ");
	fflush(stdin);
	scanf("%c", &cek); 
	if(cek == 'y'){
		// masukan data;
		
		fputs("\t\t\t\t\t\t\t\tPEMERINTAH KABUPATEN DENPASAR\n", formulir); 
		fputs("\t\t\t\t\t\t\t\t   RUMAH SAKIT UMUM BALIMED\n", formulir); 
		fputs("\t\t\t\t\t\t  Jl. Mahendrata No 57 X,  Padangsambian, Kecamatan Barat\n", formulir); 
		fputs("\t\t\t\t\t\t\t     Provinsi Bali Telp./fax (0361)484872\n", formulir); 
		fputs("\t\t\t\t\t\t\t        Email : rsudbalimed@gmail.com\n", formulir); 
		fputs("\t\t\t\t\t  =======================================================================\n", formulir); 
		fputs("DATA PASIEN KONSULTASI RUMAH SAKIT BALIMED", formulir);
		fputs("\n", formulir);
		fputs("Nama pasien    : ",formulir);
		fputs(identitas.nama_pasien, formulir);
		fputs("\n", formulir);
		fputs("No telepon     : ", formulir);
		fputs(identitas.no_telepon, formulir); 
		fputs("\n", formulir);
		fputs("Alamat pasien  : ", formulir);
		fputs(identitas.alamat, formulir);
		fputs("\n", formulir); 
		fputs("Pekerjaan      : ", formulir); 
		fputs(identitas.pekerjaan, formulir);
		fputs("\n", formulir);
		fputs("Keluhan pasien : ", formulir);
		fputs(identitas.keluhan, formulir); 
		fputs("\n", formulir);
		fputs("Nama dokter    : ", formulir); 
		fputs(identitas.nama_dokter, formulir); 
		fputs("\n", formulir);
		fputs("jam konsultasi : ", formulir);
		fputs(identitas.jam_konsultasi, formulir);
		fputs("\n", formulir);
		fputs("ID pasien      : ", formulir);
		fprintf(formulir, "%d", identitas.id); 
		fputs("\n", formulir);
		//masukan data ke dalam file data konsultasi 
		fputs(identitas.nama_pasien, data_konsultasi);
		fputs("\t\t", data_konsultasi); 
		fputs(identitas.no_telepon, data_konsultasi);
		fputs("\t\t", data_konsultasi); 
		fputs(identitas.alamat, data_konsultasi); 
		fputs("\t\t", data_konsultasi);
		fputs(identitas.pekerjaan, data_konsultasi);
		fputs("\t\t", data_konsultasi); 
		fputs(identitas.keluhan, data_konsultasi); 
		fputs("\t\t", data_konsultasi);
		fputs(identitas.nama_dokter, data_konsultasi);
		fputs("\t\t", data_konsultasi); 
		fputs(identitas.jam_konsultasi, data_konsultasi);
		fputs("\t\t", data_konsultasi);
		fprintf(data_konsultasi, "%d", identitas.id);
		fputs("\n", data_konsultasi); 
		printf("=====================================================================\n");
		printf("\t\tFORMULIR KONSULTASI PASIEN AKAN DICETAK, MOHON MENUNGGU\n"); 
		printf("=====================================================================\n");
		system("START /MIN NOTEPAD /P formulir_pasien_konsultasi.txt");

	}else{
		system("cls");
		goto back; 
	}
	
}
void proses_menu_perawat(int *a){
	int pilih_menu = *a; 
	switch(pilih_menu){
		case 1: 
		system("cls"); 
		char isi_file[100];
		FILE *jadwal_kerja; 
		jadwal_kerja = fopen("jadwal_kerja_perawat.txt", "r"); 
		while(fgets(isi_file, sizeof(isi_file), jadwal_kerja)){
			printf("%s", isi_file); 
		} 
		fclose(jadwal_kerja);
		// baca file txt jadwal kerja 
		break; 
		case 2: 
		// baca file total gaji
		system("cls");
		char isi_file_2[100];
		FILE *total_gaji; 
		total_gaji = fopen("gaji_perawat.txt", "r"); 
		while(fgets(isi_file_2, sizeof(isi_file_2), total_gaji)){
			printf("%s", isi_file_2); 
		}
		fclose(total_gaji); 
		break; 
		case 3: 
		read_data_pasien();
		break;
		
	}
}
int main(){
	menu_utama:
	time_t waktu; 
	time(&waktu);
	printf("=====================================================================\n"); 
	printf("                         PROGRAM RUMAH SAKIT BALIMED\n");
	printf("=====================================================================\n");
	printf("        Jl. Mahendrata No 57 X,  Padangsambian, Kecamatan Barat\n");
	printf("                                0361484872 \n");
	printf("                 Waktu diakses : %s\n",   ctime(&waktu)); 
	printf("=====================================================================\n");
    tampilan_awal();
    int inputan_user = pilihan();
    if(inputan_user == 1){
        int menu_1; 
        system("cls");  
        printf("=====================================================================\n"); 
        printf("                   Menu untuk tenaga kesehatan\n");
        printf("=====================================================================\n"); 
        printf("1.Perawat\n");
        printf("Ketik pilihan anda : ");
        scanf("%d", &menu_1); 
       if(menu_1 == 1){
        	char nama_perawat[50];
        	printf("=====================================================================\n"); 
        	printf("Ketik nama perawat : "); 
			scanf("%[^\n]", nama_perawat);  
			system("cls");
			printf("=====================================================================\n");
			printf("                Selamat datang perawat %s  \n", nama_perawat); 
			int menu = menu_perawat(); 
			proses_menu_perawat(&menu); 
			
		}
    }
    else if(inputan_user == 2){
    	system("cls"); 
    	int input_pasien; 
    	printf("=====================================================================\n"); 
        printf("                   Menu untuk pasien\n");
        printf("=====================================================================\n"); 
        printf("1.Formulir pendaftaran pasien konsultasi \n");
        printf("2.Formulir pendaftaran pasien rawat inap\n"); 
        printf("Ketik pilihan anda : ");
        scanf("%d", &input_pasien);
        switch(input_pasien){
        	case 1: 
        	formulir_pasien_konsultasi();
        	break; 
        	case 2: 
        	formulir_pasien_rawat_inap();
        	break;
        	default: 
        	printf("INPUTAN ANDA SALAH ! SILAHKAN ULANGI\n");
        	goto menu_utama;  
		}
	}
	return 0;
}
