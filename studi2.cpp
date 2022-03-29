#include <iostream>
#include <conio.h>
 
using namespace std;
 
int main(){
	char nama[50];
	int menu, x, kode[20], total, totharga[20], harga, jarak, subtotal, jumlah[20], ongkir;
	float bayar;
	cout << "Menu Rumah Makan Sederhana"<<endl;
	cout << "=========================="<<endl;
	cout << "1. Ayam Geprek  : Rp 21000"<<endl;
	cout << "2. Ayam Goreng  : Rp 17000"<<endl;
	cout << "3. Udang Goreng : Rp 19000"<<endl;
	cout << "4. Cumi Goreng  : Rp 20000"<<endl;
	cout << "5. Ayam Bakar   : Rp 25000"<<endl;

	cout << "Nama Pemesan : "; cin.getline(nama,sizeof(nama));
	cout << "Banyak pesanan : "; cin >> menu;
	cout << "Masukkan Jarak Rumah(Meter) : "; cin >> jarak;
	
	for(x=1; x<=menu; x++){
		cout << "---------------------------" << endl;
		cout << "Pesanan Ke-" << x << endl;
		cout << "Pilihan Menu : "; cin >> kode[x];
		cout << "Jumlah : "; cin >> jumlah[x];
		cout << endl;
	} 
	if(jarak == 0){
		ongkir=0;
	}
	else if(jarak <= 3000){
		ongkir=15000;
		cout << "Ongkir anda senilai Rp 15000" << endl;
	}
	else if(jarak > 3000){
		ongkir=25000;
		cout << "Ongkir anda senilai Rp 18000" << endl;
	}
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
	totharga[x]=jumlah[x]*harga;
	cout << "Rp " << totharga[x] << endl;
	bayar = bayar + totharga[x];
	}
	cout << "Total Bayar : Rp " << bayar << endl;
 
	if ((bayar >= 25000) && (bayar < 50000)) {
    subtotal = bayar + (ongkir - 3000);
    cout << "Selamat, anda mendapat potongan ongkir Rp 3000" << endl;
	}
	else if((bayar >= 50000) && (bayar < 150000)){
	subtotal = bayar - (0.15*bayar) + (ongkir - 5000);
    cout << "Selamat, anda mendapat diskon 15% dan potongan ongkir Rp 5000" << endl;
	} 
	else if(bayar >= 150000){
		subtotal = bayar - (0.35*bayar) + (ongkir - 8000);
	cout << "Selamat, anda mendapat diskon 35% dan potongan ongkir Rp 8000" << endl;
	}
	else if(bayar >= 0) {
    subtotal = bayar + ongkir;
    cout << "Terima Kasih" << endl;
	}
  	else {
    subtotal = bayar;
  	}
 	
  	cout << "Subtotal : Rp" << subtotal << endl;
	return 0;
}
