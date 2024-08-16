/*Copyright:: satriaBagas*/
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define limit 10 //konstanta pembatas jumlah node linked list

using namespace std;

void title()
{
#if defined _WIN32
    system("cls");
#else
    /* system("clear"); */
#endif
    cout << "\t\t<Program Resevasi Hotel C Plus^^>" << endl;
    cout << "\t\t<--------------^^--------------->" << endl;
}

void pause()
{
#if defined _WIN32
    system("pause");
#else
    cin.seekg(0, ios::end);
    cin.clear();
    cin.get();
#endif
}

typedef struct booking *node; //deklarasi pointer node
//deklarasi struct utama
struct room
{
    string nama = "NULL";
    string telpon = "NULL";
};
//struct node linked-list
struct booking
{
    struct room no_kamar[limit];
    int pin;
    node next;
};

void datakmr(node &n); //function create new node dengan data default "NULL"
void customer(node &n); //funtion menampilkan nama customer
void input(node &n); //function memanipulasi data default pada node
void clear(node &n); //function mengembalikan data pada node ke data default  
void statuskmr(node n); //function menampilkan pilihan pengecekan status kamar 
void search(node n); //function searching data tertentu pada seluruh node
void print(node n); //function menampilkan seluruh data pada seluruh node

int main()
{
    node n = NULL;
    datakmr(n);
    int pilihan;
awal:
    title();
    cout << "\t\tDasboard Menu" << endl;
    cout << "\t\t<------------------------------->" << endl;
    cout << "\t\t(1) Status Kamar" << endl;
    cout << "\t\t(2) Check In" << endl;
    cout << "\t\t(3) Check Out" << endl;
    cout << "\t\t(4) Data Customer" << endl;
    cout << "\t\t(5) Exit Program" << endl;
    cout << "\t\tMasukkan pilihan : ";
    cin >> pilihan;
    cout << "\t\t<==============^^===============>" << endl;

    switch (pilihan)
    {
    case 1:
        statuskmr(n);
        pause();
        goto awal;
        break;
    case 2:
        input(n);
        pause();
        goto awal;
        break;
    case 3:
        clear(n);
        pause();
        goto awal;
        break;
    case 4:
        customer(n);
        pause();
        goto awal;
        break;
    case 5:
        break;
    default:
        cout << "\t\tPilihan yang anda Masukkan salah" << endl;
        goto awal;
        break;
    }
    pause();
}

void datakmr(node &n)
{
    for (int i = 0; i < limit; i++)
    {
        node baru;
        baru = new booking;
        if (n == NULL)
        {
            n = baru;
        }
        else
        {
            baru->next = n;
            n = baru;
        }
    }
}

void input(node &n)
{
    node bantu;
    bantu = n;
    int i = 0;
    title();
    cout << "\t\tCheck In KAMAR" << endl;
    cout << "\t\t<------------------------------->" << endl;
    do
    {
        if (bantu->no_kamar[i].nama == "NULL" && bantu->no_kamar[i].telpon == "NULL")
        {
            cout << "\t\tNo. Kamar : " << i + 1 << endl;
            bantu->pin = i;
            cout << "\t\tNama Customer : ";
            cin >> bantu->no_kamar[i].nama;
            cout << "\t\tTelpon Customer : ";
            cin >> bantu->no_kamar[i].telpon;
            return;
        }
        i++;
        bantu = bantu->next;
    } while (bantu != NULL);
    if (i == limit)
    {
        cout << "\t\tMAAF KAMAR PENUH" << endl;
        return;
    }
}

void clear(node &n)
{
    node bantu;
    bantu = n;
    int nomor;
    title();
    cout << "\t\tCheck Out" << endl;
    cout << "\t\t<------------------------------->" << endl;
    cout << "\t\t NO. Kamar : ";
    cin >> nomor;
    int no = nomor - 1;
    do
    {
        if (no == bantu->pin)
        {
            title();
            cout << "\t\t<------------------------------->" << endl;
            cout << "\t\tNo. Kamar : " << nomor << endl;
            bantu->no_kamar[no].nama = "NULL";
            bantu->no_kamar[no].telpon = "NULL";
            cout << "\t\tCheck Out Berhasil" << endl;
            cout << "\t\t<------------------------------->" << endl;
            return;
        }
        bantu = bantu->next;
    } while (bantu != NULL);
}

void statuskmr(node n)
{
    int alpha;
    cout << "\t\t(1) Seluruh Kamar" << endl;
    cout << "\t\t(2) Satu Kamar" << endl;
pin:
    cout << "\t\t<------------------------------->" << endl;
    cout << "\t\tMasukkan Pilihan : ";
    cin >> alpha;
    switch (alpha)
    {
    case 1:
        print(n);
        break;
    case 2:
        search(n);
        break;
    default:
        cout << "\t\tPilihan yang anda Masukkan salah" << endl;
        goto pin;
        break;
    }
}

void customer(node &n)
{
    node bantu;
    bantu = n;
    string data[limit];
    int i = 0;
    
    //Pengambilan data Nama Customer dari seluruh node
    do
    {
        data[i] = bantu->no_kamar[i].nama;
        bantu = bantu->next;
        i++;
    } while (bantu != NULL);

    //Proses INSERTION SORT Ascending Nama Customer
    for(int i=1; i<limit; i++){
		string temp = data[i];
		int j = i-1;
		while(j>=0 && data[j] > temp){
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = temp;
	}

    //Menampilkan Nama Customer setelah pengurutan
    title();
    cout << "\t\tDaftar Customer Saat ini" << endl;
    cout << "\t\t<------------------------------->" << endl;
    int pin = 0;
    for (int i = 1; i <= limit; i++)
    {
        if (data[i-1] != "NULL")
        {
            cout <<"\t\t " << data[i-1]<<endl;
        }
    }
}

void search(node n)
{
    node bantu;
    bantu = n;
    string cari;
    int i = 0;
    cout << "\t\t<------------------------------->" << endl;
    cout << "\t\tNama Customer yang dicari : ";
    cin >> cari;
    //Proses Linear Search(Sequential Search)
    do
    {
        if (cari == bantu->no_kamar[i].nama)
        {
            title();
            cout << "\t\t<------------------------------->" << endl;
            cout << "\t\tNo. Kamar : " << i + 1 << endl;
            cout << "\t\tNama Customer : " << bantu->no_kamar[i].nama
                 << endl;
            cout << "\t\tTelpon Customer : "
                 << bantu->no_kamar[i].telpon << endl;
            cout << "\t\t<------------------------------->" << endl;
            return;
        }
        i++;
        bantu = bantu->next;
    } while (bantu != NULL);
}

void print(node n)
{
    node bantu;
    bantu = n;
    int i = 0;
    title();
    cout << "\t\tDATA KAMAR" << endl;
    do
    {
        cout << "\t\t<------------------------------->" << endl;
        cout << "\t\tNo. Kamar : " << i + 1 << endl;
        if (bantu->no_kamar[i].nama == "NULL" && bantu->no_kamar[i].telpon == "NULL")
        {
            cout << "\t\tKamar Kosong" << endl;
        }
        else
        {
            cout << "\t\tNama Customer : " << bantu->no_kamar[i].nama
                 << endl;
            cout << "\t\tTelpon Customer : "
                 << bantu->no_kamar[i].telpon << endl;
        }
        bantu = bantu->next;
        i++;
    } while (bantu != NULL);
}