#include <iostream>
#include <conio.h>
#include <fstream>
 
using namespace std;
 
int main(){
	char nama[50];
	int menu, x, kode[20], total, totharga[20], harga, jarak, subtotal, jumlah[20], ongkir;
	float bayar;
	cout << "\t\tMenu Rumah Makan Sederhana"<<endl;
	cout << "============================================================="<<endl;
	cout << "1. Ayam Geprek  : Rp 21000"<<endl;
	cout << "2. Ayam Goreng  : Rp 17000"<<endl;
	cout << "3. Udang Goreng : Rp 19000"<<endl;
	cout << "4. Cumi Goreng  : Rp 20000"<<endl;
	cout << "5. Ayam Bakar   : Rp 25000"<<endl;
	cout << "=============================================================" << endl;
	cout << "Nama Pemesan \t\t: "; cin.getline(nama,sizeof(nama));
	cout << "Banyak Pesanan \t\t: "; cin >> menu;
	cout << "Masukkan Jarak Rumah(Meter) \t: "; cin >> jarak;
	cout << endl << endl;
	
	for(x=1; x<=menu; x++){
		cout << "--------------------------------------------------------" << endl;
		cout << "\t\tPesanan Ke-" << x << endl;
		cout << "Pilihan Menu \t: "; cin >> kode[x];
		cout << "Jumlah \t\t: "; cin >> jumlah[x];
		cout << endl;
		cout << "--------------------------------------------------------" << endl;
	} 
	if(jarak == 0){
		ongkir=0;
	}
	else if(jarak <= 3000){
		ongkir=15000;
		cout << "Ongkir Anda Senilai Rp 15000" << endl;
	}
	else if(jarak > 3000){
		ongkir=25000;
		cout << "Ongkir anda senilai Rp 25000" << endl;
	}
	cout << endl;
	for(x=1; x<=menu; x++){
		if(kode[x]==1){
			cout << "Ayam Geprek ";
			harga = 21000;
		}
		else if(kode[x]==2){
			cout << "Ayam Goreng ";
			harga = 17000;
		}
		else if(kode[x]==3){
			cout << "Udang Goreng ";
			harga = 19000;
		}
		else if(kode[x]==4){
			cout << "Cumi Goreng ";
			harga = 20000;
		}
		else if(kode[x]==5){
			cout << "Ayam Bakar ";
			harga = 25000;
		}
		else {
			cout << "Kode tidak tersedia di menu" << endl;
			harga=0;
		}
	cout << endl;
	totharga[x]=jumlah[x]*harga;
	cout << "Rp " << totharga[x] << endl;
	bayar = bayar + totharga[x];
	cout << "=============================================================" << endl;
	}
	cout << "Total Bayar \t: Rp " << bayar << endl;
	cout << "Biaya ongkir \t: Rp " << ongkir << endl;
 
	if ((bayar >= 25000) && (bayar < 50000)) {
    subtotal = bayar + (ongkir - 3000);
    cout << "Selamat, Anda Mendapat Potongan Ongkir Rp 3000" << endl;
	}
	else if((bayar >= 50000) && (bayar < 150000)){
	subtotal = bayar - (0.15*bayar) + (ongkir - 5000);
    cout << "Selamat, Anda Mendapat Diskon 15% dan Potongan Ongkir Rp 5000" << endl;
	} 
	else if(bayar >= 150000){
		subtotal = bayar - (0.35*bayar) + (ongkir - 8000);
	cout << "Selamat, Anda Mendapat Diskon 35% dan Potongan Ongkir Rp 8000" << endl;
	}
	else if(bayar >= 0) {
    subtotal = bayar + ongkir;
    cout << "Terima Kasih..." << endl;
	}
  	else {
    subtotal = bayar;
  	}
 	
  	cout << "Subtotal \t: Rp " << subtotal << endl;
  	cout << "========================Terima Kasih=========================" << endl;
  	cout << "=====================Atas Kunjungan Anda=====================" << endl;
  	
  	ofstream struk("Struk_Pemesanan.txt");
  	struk << "\t\t\t Bukti Pemesanan Makanan" << endl;
  	struk << "\t\t\t Menu Rumah Makan Sederhana" << endl;
  	struk << "============================================================" << endl;
  	struk << "Nama Pemesan \t: " << nama << endl;
  	struk << "Jumlah Pesanan \t: " << menu << endl;
  	struk << "Jarak Rumah \t: " << jarak << " Meter" << endl;  
  	struk << "============================================================" << endl;
  	
	if(jarak == 0){
		ongkir=0;
	}
	else if(jarak <= 3000){
		ongkir=15000;
		struk << "Ongkir Anda Senilai Rp 15000" << endl;
	}
	else if(jarak > 3000){
		ongkir=25000;
		struk << "Ongkir anda senilai Rp 18000" << endl;
	}
	struk << endl;
  	for(x=1; x<=menu; x++){
		if(kode[x]==1){
			struk << "Ayam Geprek ";
			harga = 21000;
		}
		else if(kode[x]==2){
			struk << "Ayam Goreng ";
			harga = 17000;
		}
		else if(kode[x]==3){
			struk << "Udang Goreng ";
			harga = 19000;
		}
		else if(kode[x]==4){
			struk << "Cumi Goreng ";
			harga = 20000;
		}
		else if(kode[x]==5){
			struk << "Ayam Bakar ";
			harga = 25000;
		}
		else {
			struk << "Kode tidak tersedia di menu" << endl;
			harga=0;
		}
	struk << endl;
	totharga[x]=jumlah[x]*harga;
	struk << "Rp " << totharga[x] << endl;
	bayar = bayar + totharga[x];
	total = bayar/2;
	struk << "=============================================================" << endl;
	}
	struk << "Total Bayar \t: Rp " << total << endl;
	struk << "Biaya ongkir \t: Rp " << ongkir << endl;
	struk << "-------------------------------------------------------------" << endl;
	
	if ((total >= 25000) && (total < 50000)) {
    subtotal = total + (ongkir - 3000);
    struk << "Selamat, Anda Mendapat Potongan Ongkir Rp 3000" << endl;
	}
	else if((total >= 50000) && (total < 150000)){
	subtotal = total - (0.15*total) + (ongkir - 5000);
    struk << "Selamat, Anda Mendapat Diskon 15% dan Potongan Ongkir Rp 5000" << endl;
	} 
	else if(total >= 150000){
	subtotal = total - (0.35*total) + (ongkir - 8000);
	struk << "Selamat, Anda Mendapat Diskon 35% dan Potongan Ongkir Rp 8000" << endl;
	}
	else if(total >= 0) {
    subtotal = total + ongkir;
    struk << "Terima Kasih..." << endl;
	}
	struk << "Subtotal \t\t: Rp " << subtotal << endl << endl;
	struk << "========================Terima Kasih=========================" << endl;
	struk << "=====================Atas Kunjungan Anda=====================" << endl;
	struk.close();
	
	return 0;
}
