#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Data
{
	int nilai;
	Data *next;
};

Data *head;
Data *tail;

void awal()
{
	head = NULL;
	tail = NULL;
}

bool isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

void tambahDataDepan(int DataBaru)
{
	Data *baru;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = NULL;

	if (isEmpty())
	{
		head = baru;
		tail = baru;
		head->next = head; // Menghubungkan head dengan dirinya sendiri
	}
	else
	{
		baru->next = head;
		head = baru;
		tail->next = head; // Menghubungkan tail dengan head untuk membuatnya menjadi circular
	}

	cout << "Data Depan " << DataBaru << " Masuk" << endl;
}

void tambahDataBelakang(int DataBaru)
{
	Data *baru;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = NULL;

	if (isEmpty())
	{
		head = baru;
		tail = baru;
		head->next = head; // Menghubungkan head dengan dirinya sendiri
	}
	else
	{
		tail->next = baru;
		tail = baru;
		tail->next = head; // Menghubungkan tail dengan head untuk membuatnya menjadi circular
	}

	cout << "Data Belakang " << DataBaru << " Masuk" << endl;
}

void tambahDataTengah(int posisi, int DataBaru)
{
	if (isEmpty() || posisi == 1)
	{
		tambahDataDepan(DataBaru);
		return;
	}
	Data *baru;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = NULL;

	Data *bantu = head;
	int count = 1;

	while (count < posisi - 1 && bantu->next != head)
	{
		bantu = bantu->next;
		count++;
	}

	if (bantu->next == head)
	{
		tambahDataBelakang(DataBaru);
		return;
	}

	baru->next = bantu->next;
	bantu->next = baru;

	cout << "Data Tengah " << DataBaru << " Masuk pada Posisi " << posisi << endl;
}

void hapusDepan()
{
	Data *hapus;
	int d;

	if (!isEmpty())
	{
		hapus = head;
		d = hapus->nilai;

		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = hapus->next;
			tail->next = head; // Menghubungkan tail dengan head setelah menghapus elemen pertama
		}

		delete hapus;
		cout << d << " Terhapus" << endl;
	}
	else
	{
		cout << "Masih Kosong" << endl;
	}
}

void hapusBelakang()
{
	Data *hapus;
	Data *bantu;
	int tmp;

	if (!isEmpty())
	{
		hapus = tail;
		tmp = hapus->nilai;

		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			bantu = head;
			while (bantu->next != tail)
			{
				bantu = bantu->next;
			}

			tail = bantu;
			tail->next = head; // Menghubungkan tail dengan head setelah menghapus elemen terakhir
		}

		delete hapus;
		cout << tmp << " Terhapus" << endl;
	}
	else
	{
		cout << "Masih Kosong" << endl;
	}
}

void hapusTengah(int posisi)
{
	if (isEmpty())
	{
		cout << "Linked List Kosong" << endl;
		return;
	}

	if (posisi == 1)
	{
		hapusDepan();
		return;
	}

	Data *hapus;
	Data *bantu = head;
	int count = 1;

	while (count < posisi - 1 && bantu->next != head)
	{
		bantu = bantu->next;
		count++;
	}

	if (bantu->next == head)
	{
		cout << "Posisi " << posisi << " Tidak Ditemukan" << endl;
		return;
	}

	hapus = bantu->next;
	bantu->next = hapus->next;

	if (hapus == tail)
		tail = bantu;

	delete hapus;
	cout << "Data pada Posisi " << posisi << " Terhapus" << endl;
}

void Cetak()
{
	if (!isEmpty())
	{
		Data *bantu;
		bantu = head;

		do
		{
			cout << bantu->nilai << " ";
			bantu = bantu->next;
		} while (bantu != head);

		cout << endl;
	}
}

int panjang()
{
	int count = 0;

	if (!isEmpty())
	{
		count = 1;
		Data *bantu;
		bantu = head;

		if (bantu->next == head)
		{
			count = 1;
		}
		else
		{
			do
			{
				count++;
				bantu = bantu->next;
			} while (bantu->next != head);
		}
	}

	return count;
}

int main()
{
	awal();
	tambahDataBelakang(5);
	tambahDataDepan(7);
	tambahDataBelakang(17);
	tambahDataTengah(3, 11);
	tambahDataBelakang(1);
	tambahDataBelakang(27);
	tambahDataTengah(5, 8);
	tambahDataBelakang(10);

	cout << "Data pada linked list circular:" << endl;
	Cetak();

	cout << "Data paling depan dihapus:" << endl;
	hapusDepan();
	cout << "Data pada linked list circular:" << endl;
	Cetak();

	cout << "Data paling belakang dihapus:" << endl;
	hapusBelakang();
	cout << "Data pada linked list circular:" << endl;
	Cetak();

	cout << "Data pada posisi 3 dihapus:" << endl;
	hapusTengah(3);
	cout << "Data pada linked list circular:" << endl;
	Cetak();

	cout << "Panjang linked list: " << panjang() << endl;

	cout << " Praditus Egi Danuarta - 22.11.4662 " << endl;
	getch();
	return 0;
}
