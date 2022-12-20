
//program atm c++ menggunakan struktur data pohon setimbang

#include <iostream>
#include <conio.h>

using namespace std;

// mendefinisikan struktur pohon setimbang
struct node {
    int data;
    node* left;
    node* right;
};

// fungsi untuk membuat node baru
node* getNewNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// fungsi untuk menyisipkan data baru ke pohon setimbang
node* insert(node* rootPtr, int data)
{
    if(rootPtr == NULL)
    {
        rootPtr = getNewNode(data);
    }
    else if(data <= rootPtr->data)
    {
        rootPtr->left = insert(rootPtr->left, data);
    }
    else
    {
        rootPtr->right = insert(rootPtr->right, data);
    }
    return rootPtr;
}

// fungsi untuk memeriksa apakah data yang dimasukkan ada di pohon setimbang
bool search(node* rootPtr, int data)
{
    if(rootPtr == NULL)
    {
        return false;
    }
    else if(rootPtr->data == data)
    {
        return true;
    }
    else if(data <= rootPtr->data)
    {
        return search(rootPtr->left, data);
    }
    else
    {
        return search(rootPtr->right, data);
    }
}

// deklarasi kelas ATM
class ATM
{
private:
    // data member
    double saldo;
    string nama;
    int pin;
public:
    // konstruktor
    ATM(double sal, string nama, int pin) {
        saldo = sal;
        this->nama = nama;
        this->pin = pin;
    }
    
    // fungsi
    void cekSaldo() {
        cout << "Saldo Anda saat ini adalah Rp" << saldo << endl;
    }
    
    void tarikUang(double jml) {
        if (jml > saldo) {
            cout << "Maaf, saldo Anda tidak mencukupi untuk melakukan transaksi tersebut" << endl;
        } else {
            saldo -= jml;
            cout << "Anda telah berhasil menarik uang sebesar Rp" << jml << endl;
        }
    }
    
    void setorUang(double jml) {
        saldo += jml;
        cout << "Anda telah berhasil menyetor uang sebesar Rp" << jml << endl;
    }
};

// fungsi utama
int main()
{
    node* rootPtr = NULL; // pohon setimbang kosong
    int angka = 0;
    
    double saldoAwal;
    string nama;
    int pin;

    cout << "Masukkan angka untuk memulai program atm: ";
    cin >> angka;

    rootPtr = insert(rootPtr, angka);

    // lakukan operasi atm dengan memeriksa data yang dimasukkan ada di pohon setimbang
    cout << "Masukkan angka berikutnya: ";
    cin >> angka;

    if(search(rootPtr, angka) == true)
    {
        //"Operasi berhasil"
        system("cls");
        cout << "Selamat datang di ATM" << endl;
    	cout << "Masukkan saldo awal Anda: ";
    	cin >> saldoAwal;
    	cout << "Masukkan nama Anda: ";
    	cin >> nama;
    	cout << "Masukkan pin Anda: ";
    	cin >> pin;
    
    	ATM atm(saldoAwal, nama, pin);
    
    	int pilihan;
    	do 
		{
			cout << "================" << endl;
			cout << "Menu ATM" << endl;
        	cout << "1. Cek Saldo" << endl;
        	cout << "2. Tarik Uang" << endl;
        	cout << "3. Setor Uang" << endl;
        	cout << "4. Keluar" << endl;
        	cout << "================" << endl;
        	cout << "Masukkan pilihan Anda: ";
        	cin >> pilihan;
        
        	switch (pilihan) 
			{
				case 1:
					atm.cekSaldo();
                	break;
            	case 2:
                	double jml;
                	cout << "Masukkan jumlah uang yang ingin ditarik: ";
                	cin >> jml;
                	atm.tarikUang(jml);
                	break;
            	case 3:
                	cout << "Masukkan jumlah uang yang ingin disetor: ";
                	cin >> jml;
                	atm.setorUang(jml);
                	break;
            	case 4:
                	cout << "Terima kasih telah menggunakan ATM kami" << endl;
                	break;
            	default:
                	cout << "Pilihan yang Anda masukkan salah" << endl;
        	}
    	} 	while (pilihan != 4);
    	
    }else{
        cout << "Operasi gagal" << endl;
    }
    
    return 0;
}


/* program di atas adalah contoh program atm c++ yang menggunakan struktur data pohon setimbang.
 Program di atas melakukan operasi atm dengan memeriksa data yang dimasukkan ada di pohon setimbang. 
 Jika data yang dimasukkan ada di pohon setimbang, maka operasi atm berhasil. Jika tidak, maka operasi atm gagal. */

