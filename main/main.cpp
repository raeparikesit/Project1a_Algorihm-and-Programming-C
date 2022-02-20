#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


int batas();
int batas() { 
	int awal = 0;
    string baris;
    ifstream file("data_isolasi.txt");
    while (getline(file, baris)) {
        awal++;
    }
    file.close();
    return awal/6;
}
int acak(int angka) {
	if (angka==0){
		return (4);
	}
	else {
		return ((2*angka+acak(angka-1))+1);
	}
}
void pendataan(int *data){
	*data+=1;
}
int main()
{
	struct pasien {
		string nik;
		string nama;
		string jenis_kelamin,asal_daerah,status,kamar;};
		pasien psn[10];
	int pilih,input,angka;
	string kembali;
	int data_input=0;
	fstream file;
	awal:
	cout <<"Data Pasien COVID-19\t\n";
	cout <<"----------------------------------------\n";
	cout <<"1. Denah Kamar\n";
	cout <<"2. Input Pasien\n";
	cout <<"3. Searching Pasien\n";
	cout <<"4. Ganti Data Pasien\n";
	cout <<"5. Cek Out Pasien\n";
	cout <<"6. Data Kamar\n";
	cout <<"7. Exit\n";
	cout <<"----------------------------------------\n";
	cout <<"----------------------------------------\n";
	cout<<"Masukan Pilihan : " ;
	cin>>pilih;
	if (pilih==1) {
		system("cls");
		string denah[3][2]={{"A1","B2"},{"C3","D4"},{"E5","F6"}};
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		//mengubah Matrik
		for (int i=0;i<3;i++){
			for (int j = 0; j < 2; j++){
				if (denah[i][j]==psn[0].kamar||denah[i][j]==psn[1].kamar||denah[i][j]==psn[2].kamar||denah[i][j]==psn[3].kamar||denah[i][j]==psn[4].kamar||denah[i][j]==psn[5].kamar){
					denah[i][j]="XX";
				}
			}
		}
		cout<<"Denah Kamar Isolasi\n";
		cout<<"---------------------\n";
		cout<<endl;
		//Menampilkan Matriks
		for (int i=0;i<3;i++){
			for (int j = 0; j < 2; j++){
				cout<<denah[i][j]<<" | ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"---------------------\n";
		cout<<"Kamar Yang sudah terpakai : \n";\
		//Menampilkan Kamar Yang Telah Ditempatin
		for (int i=0;i<batas();i++) {
			cout<<i+1<<". "<<"Kamar : "<<psn[i].kamar<<endl;
		}
		cout<<"Jumlah kamar yang sudah dipakai :  "<<batas()<<endl;
		cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
		cin>>kembali;
		if (kembali=="y" || kembali=="Y") {
			system("pause");
			system("cls");
			goto awal;
		}
		else { 
			cout<<"Terima Kasih Telah Menggunakan Program\n";
			return 0;
			}
		}
	
	
	else if (pilih==2) {
		system("cls");
		string denah[3][2]={{"A1","B2"},{"C3","D4"},{"E5","F6"}};
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		//Mengubah Matrik
		for (int i=0;i<3;i++){
			for (int j = 0; j < 2; j++){
				if (denah[i][j]==psn[0].kamar||denah[i][j]==psn[1].kamar||denah[i][j]==psn[2].kamar||denah[i][j]==psn[3].kamar||denah[i][j]==psn[4].kamar||denah[i][j]==psn[5].kamar){
					denah[i][j]="X";
				}
			}
		}
		cout <<"Input Data Isolasi COVID-19\t\n";
		cout <<"----------------------------------------\n";
		cout<<"Jumlah Inputan : ";
		cin>>input;
		cin.ignore();
		//Menginput Data Pasien Isolasi
		for (int i=0;i<input;i++) {
		ulang:
		pendataan(&data_input);
		cout<<"Pasien Ke - " <<i+1<<endl;
		cout<<"NIK           : ";
		getline(cin,psn[batas()].nik);
		cout<<"Nama Pasien   : ";
		getline(cin,psn[batas()].nama);
		cout<<"jenis kelamin : ";
		getline(cin,psn[batas()].jenis_kelamin);
		cout<<"asal daerah   : ";
		getline(cin,psn[batas()].asal_daerah);
		cout<<"Status        : "; 
		getline(cin,psn[batas()].status);
		cout<<"Kamar         : ";
		getline(cin,psn[batas()].kamar);
		cout<<endl;
		if (psn[batas()].kamar==denah[0][0]||psn[batas()].kamar==denah[0][1]||psn[batas()].kamar==denah[1][0]||psn[batas()].kamar==denah[1][1]||psn[batas()].kamar==denah[2][0]||psn[batas()].kamar==denah[2][1]){
		}
		else {
			cout<<"Maaf Kamar Telah Dipakai atau Tidak ada,mohon melakukan input ulang\n";
			system("pause");
			system("cls");
			goto ulang;
			}
		//Memasukan Data Ke file
		file.open("data_isolasi.txt",  ios::in | ios::app);
        file <<psn[batas()].nik<<endl;
        file <<psn[batas()].nama<<endl;
        file <<psn[batas()].jenis_kelamin<<endl;
        file <<psn[batas()].asal_daerah<<endl;
        file <<psn[batas()].status<<endl;
        file <<psn[batas()].kamar<<endl;
		file.close();
		}
		cout<<"Data Berhasil Diinput\n";
		//Membuat Fungsi Rekusif
		angka=rand()%10;
		cout<<"Kode Inputan : "<<acak(angka)<<endl;
		cout<<"Harap Perawat Yang Bertugas Mencatat Kode Inputan Untuk Dilaporkan Kepada Gugus Tugas\n";
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		//Memasukan Jumlah Orang Yang Diisolasi
		file.open("isolasi.txt", ios::in | ios::out | ios::trunc); 
		file<<batas();
		file.close();
		cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
		cin>>kembali;
		if (kembali=="y" || kembali=="Y") {
			system("pause");
			system("cls");
			goto awal;
		}
		else { 
			cout<<"Terima Kasih Telah Menggunakan Program\n";
			return 0;
			}
		}
	else if (pilih ==3 ) { 
		system("cls");\
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		bool tes=false;
		string ubah,cari,pilih;
		int data;
		cout <<"Mencari Data Pasien Isolasi COVID-19\t\n";
		cout <<"----------------------------------------\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"Cari NIK Pasien : ";
		cin>>cari;
		cout<<"\n";
		cout <<"----------------------------------------\n";
		//melakukan Searching data
		file.open("Data_Pasien.txt");
		for (int i=0;i<batas();i++) {
				if (cari==psn[i].nik){
				tes=true;
				data=i;
				break;
				}
		}
		if (tes==true) {
			cout <<"Menampilkan Data Pasien COVID-19\t\n";
			cout <<"+ ------------------------------ +\n";
			cout <<"NIK           : "<<psn[data].nik<<endl;
			cout <<"Nama Pasien   : "<<psn[data].nama<<endl;
			cout <<"Jenis Kelamin : "<<psn[data].jenis_kelamin<<endl;
			cout <<"Kecamatan     : "<<psn[data].asal_daerah<<endl;
			cout <<"Status        : "<<psn[data].status<<endl;	
			cout <<"Kamar         : "<<psn[data].kamar<<endl;	
		}
		else {
			cout<<"Maaf Data Tidak ditemukan, Harap Cek ulang\n";
			}
		cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
		cin>>kembali;
		if (kembali=="y" || kembali=="Y") {
			system("pause");
			system("cls");
			goto awal;
		}
		else { 
			cout<<"Terima Kasih Telah Menggunakan Program\n";
			return 0;
			}
		}
	else if (pilih==4) {
		system("cls");
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		bool tes=false;
		string ubah,cari,pilih;
		int s;
		cout <<"Mengubah Data Pasien Isolasi Covid-19\t\n";
		cout <<"----------------------------------------\n";
		cout<<"\n";
		cout<<"Masukan NIK Pasien : ";
		cin>>cari;
		cout<<"\n";
		cout <<"----------------------------------------\n";
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
				if (cari==psn[i].nik){
				tes=true;
				s=i;
				break;
				}
		}
		if (tes==true) {
			//Menampilkan data
				cout <<"Status : "<<psn[s].status<<endl;
				cout<<"Ubah Status Menjadi : ";
				cin>>ubah;
				psn[s].status=ubah;	
				if (psn[s].status=="sehat") {
					cout<<"Pasien dapat melakukan Cek-out\n";
				}
				//menginput ulang data
				for (int i=0;i<batas();i++) {
					file <<psn[i].nik<<endl;
					file <<psn[i].nama<<endl;
					file <<psn[i].jenis_kelamin<<endl;
					file <<psn[i].asal_daerah<<endl;
					file <<psn[i].status<<endl;
					file <<psn[i].kamar<<endl;
		}	
				file.close();
				cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
				cin>>kembali;
				if (kembali=="y" || kembali=="Y") {
					system("pause");
					system("cls");
					file.close();
					goto awal;	
				}	
			}
			else { 
				cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
				cin>>kembali;
				if (kembali=="y" || kembali=="Y") {
					system("pause");
					system("cls");
					file.close();
					goto awal;
				}
				else { 
					cout<<"Terima Kasih Telah Menggunakan Program\n";
					exit(0);
					}
				}
		}
		else if (pilih==5) {
			system("cls");
			cout <<"\tOutput Data Pasien Isolasi Covid-19\t\n";
			cout <<"----------------------------------------\n";
			for (int i=0;i<batas();i++) {
					
					cout <<psn[i].nik<<setw(15)<<psn[i].nama<<setiosflags(ios::right)<<setw(12)<<psn[i].jenis_kelamin<<setw(15)<<psn[i].asal_daerah<<setw(10)<<psn[i].status<<setw(10)<<psn[i].kamar<<endl;
			}
			file.open("data_isolasi.txt");
				for (int i=0;i<batas();i++) {
				getline(file,psn[i].nik);
				getline(file,psn[i].nama);	
				getline(file,psn[i].jenis_kelamin);
				getline(file,psn[i].asal_daerah);
				getline(file,psn[i].status);
				getline(file,psn[i].kamar);			
			}
		file.close();
		cout <<"----------------------------------------\n";
		cout <<"\tMenghapus Data Pasien Isolasi Covid-19\t\n";
		cout<<"\n";
		bool check=false;
		string hapus;
		int look;
		cout<<"Masukan NIK Pasien : ";
		cin>>hapus;
		cout<<"\n";
		cout <<"----------------------------------------\n";
		//mencari data
		for (int i=0;i<batas();i++) {
			if (psn[i].nik==hapus) {
				check=true;
				look=i;
			}
		}
		//Melakukan Penghapusan Data
		if (check==true) {
			int kurang;
			kurang=batas()-1;
			for (int i = look; i < kurang; i++)
			{
				psn[i].nik=psn[i+1].nik;
				psn[i].nama=psn[i+1].nama;
				psn[i].jenis_kelamin=psn[i+1].jenis_kelamin;
				psn[i].asal_daerah=psn[i+1].asal_daerah;
				psn[i].status=psn[i+1].status;
				psn[i].kamar=psn[i+1].kamar;
			}
			file.open("sementara.txt", ios::in | ios::out | ios::trunc);
			for (int i=0;i<batas()-1;i++) {
				file <<psn[i].nik<<endl;
				file <<psn[i].nama<<endl;
				file <<psn[i].jenis_kelamin<<endl;
				file <<psn[i].asal_daerah<<endl;
				file <<psn[i].status<<endl;
				file <<psn[i].kamar<<endl;
			}	
			file.close();
			remove("data_isolasi.txt");
			rename("sementara.txt", "data_isolasi.txt");
			cout << "Data Berhasil Dihapus\n";
			file.open("isolasi.txt", ios::in | ios::out | ios::trunc); 
			file<<batas();
			file.close();
		}
		//jika data tidak ditemukan
		else {
			cout<<"Maaf NIK Tidak Ditemukan Harap Melakukan Pengecekan Ulang\n";
			}
		cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
			cin>>kembali;
			if (kembali=="y" || kembali=="Y") {
				system("pause");
				system("cls");
				goto awal;
			}
			else { 
				cout<<"Terima Kasih Telah Menggunakan Program\n";
				exit(0);
			}	
	}
	else if (pilih==6) {
		system("cls");
		file.open("data_isolasi.txt");
		for (int i=0;i<batas();i++) {
			getline(file,psn[i].nik);
			getline(file,psn[i].nama);	
			getline(file,psn[i].jenis_kelamin);
			getline(file,psn[i].asal_daerah);
			getline(file,psn[i].status);
			getline(file,psn[i].kamar);			
		}
		file.close();
		cout <<"\tOutput Data Pasien Isolasi Covid-19\t\n";
		cout <<"----------------------------------------\n";
		cout<<"\n";
		//melakukan Pengurutan
		string temp,temp1,temp2,temp3,temp4,temp5;
			file.open("data_isolasi.txt", ios::in );
			for (int i = 0; i < batas();i++){
				for (int j =i+1; j < batas(); j++){
							if (psn[i].nik>psn[j].nik){
								temp = psn[i].nik;temp1=psn[i].nama;temp2=psn[i].jenis_kelamin;temp3=psn[i].asal_daerah;temp4=psn[i].status;temp5=psn[i].kamar;
								psn[i].nik = psn[j].nik;psn[i].nama = psn[j].nama;psn[i].jenis_kelamin = psn[j].jenis_kelamin;psn[i].asal_daerah = psn[j].asal_daerah;psn[i].status = psn[j].status;psn[i].kamar=psn[j].kamar;
								psn[j].nik= temp;psn[j].nama= temp1;psn[j].jenis_kelamin= temp2;psn[j].asal_daerah= temp3;psn[j].status= temp4;psn[j].kamar=temp5;
					}
				}
			}
			file.close();
			//output setelah Pengurutan
			cout<<"NIK"<<setw(8)<<"Nama"<<setw(12)<< setiosflags(ios::right)<<"  Jenis_Kelamin"<<setw(10)<<" asal daerah"<<setw(8)<<"Status"<<setw(7)<<"Kamar"<<endl;
			for (int i=0;i<batas();i++) {
					cout <<psn[i].nik<<setw(8)<<psn[i].nama<<setiosflags(ios::right)<<setw(12)<<psn[i].jenis_kelamin<<setw(10)<<psn[i].asal_daerah<<setw(10)<<psn[i].status<<setw(10)<<psn[i].kamar<<endl;
			}
			cout<<"Apakah Anda Ingin Kembali Ke menu ? (y/n) : \n";
			cin>>kembali;
			if (kembali=="y" || kembali=="Y") {
				system("pause");
				system("cls");
				goto awal;
			}
			else { 
				cout<<"Terima Kasih Telah Menggunakan Program\n";
				exit(0);
			}	
			}
		else {
			//data pasien yang dimasukan hari itu
			cout<<"Pendataan Pasien Isolasi Hari Ini : "<<data_input<<endl;
			cout<<"Terima Kasih Telah Menggunakan Program\n";
			exit(0);
		}
}

