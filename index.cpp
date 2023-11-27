#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <array>
#include <typeinfo>

using namespace std;

struct dataSiswa
{
	string nama;
	string kelas;
	int bulan[6];
};

void inputData(dataSiswa arr[], int &length)
{
	dataSiswa newData;

	cout << "Masukkan data siswa:\n";
	cout << "Nama: ";
	cin >> newData.nama;
	cout << "Kelas: ";
	cin >> newData.kelas;

	for (int i = 0; i <= 5; i++)
	{
		cout << "Bulan " << i + 1 << " : ";
		cin >> newData.bulan[i];
	}

	arr[length] = newData;
	length++;

	system("CLS");
}

int lengthArr(dataSiswa *arr)
{
	int length = 0;

	for (int i = 0; i <= 100; i++)
	{
		if (!arr[i].nama.empty() && !arr[i].kelas.empty())
		{
			length++;
		}
	}

	return length;
}

void infoData(dataSiswa *arr, int length)
{
	int seharusnya = 720000;
	int total = 0;
	int jumlahKekurangan = 0;
	int kekurangan;

	cout << endl;
	cout << "Informasi keuangan siswa tahun 2021/2022";
	cout << endl
		 << endl;

	cout << left;
	cout << setw(4) << "No";
	cout << setw(10) << "Nama";
	cout << setw(8) << "Kelas";
	cout << setw(10) << "Bulan 1";
	cout << setw(10) << "Bulan 2";
	cout << setw(10) << "Bulan 3";
	cout << setw(10) << "Bulan 4";
	cout << setw(10) << "Bulan 5";
	cout << setw(10) << "Bulan 6";
	cout << setw(8) << "Total";
	cout << setw(12) << "Seharusnya";
	cout << setw(12) << "Kekurangan";
	cout << endl;

	// for (int i = 0; i <= 111; i++)
	// {
	// 	cout << " ";
	// }
	cout << endl;

	for (int x = 0; x <= length - 1; x++)
	{

		if (!arr[x].nama.empty() && !arr[x].kelas.empty())
		{

			int seharusnya = 720000;
			int total = 0;

			cout << left;
			if (x > 1)
			{
				cout << setw(4) << x;
			}
			else
			{
				cout << setw(4) << x + 1;
			}
			cout << setw(10) << arr[x].nama;
			cout << setw(8) << arr[x].kelas;

			for (int y = 0; y <= 5; y++)
			{
				cout << setw(10) << arr[x].bulan[y];
			}

			for (int p = 0; p < 6; p++)
			{
				total = total + arr[x].bulan[p];
			}

			cout << setw(8) << total;
			cout << setw(12) << seharusnya;
			kekurangan = seharusnya - total;
			cout << setw(12) << kekurangan;
			jumlahKekurangan = jumlahKekurangan + kekurangan;
			cout << endl;
		}
	}

	cout << endl;
	cout << endl;
	cout << setw(22) << "Jumlah Pemasukan";

	for (int i = 0; i <= 5; i++)
	{
		int jumlah = 0;
		for (int x = 0; x <= length - 1; x++)
		{
			jumlah = jumlah + arr[x].bulan[i];
		}

		cout << setw(10) << jumlah;
	}
	cout << endl;
	cout << setw(102) << "Jumlah tunggakan siswa";
	cout << setw(10) << jumlahKekurangan << endl;
}

int main()
{
	string lanjut;
	dataSiswa arr[100] = {
		{"Dimas", "if-a", {120000, 0, 0, 120000, 120000, 120000}},
		{"Tedjo", "if-b", {120000, 120000, 120000, 0, 120000, 0}}};
	do
	{
		int pilihan;

		cout << "Selamat datang di data keuangan SPP siswa tahun 2021/2022" << endl;
		cout << endl;
		cout << "#########################################################" << endl;
		cout << endl;

		int size = lengthArr(arr);
		int size1;
		// int size2;

		cout << "Menu : \n1. Input data \n2. Laporan data" << endl;
		cout << endl;

		cout << "Pilih menu : ";
		cin >> pilihan;
		cout << endl;
		system("CLS");
		dataSiswa newData;

		switch (pilihan)
		{
		case 1:
			inputData(arr, size);
			size = lengthArr(arr);
			infoData(arr, size);

			// infoData(arr, size);
			// size1 = lengthArr(arr);
			// inputData(arr, size1);
			// size2 = lengthArr(arr);
			// infoData(arr, size2);
			break;
		case 2:
			infoData(arr, size);

			break;
		default:
			cout << "Pilihan tidak ada" << endl;
		}

		cout << "Apakah anda ingin melanjutkan [Y/N] : ";
		cin >> lanjut;
		system("CLS");
	} while (lanjut == "y" || lanjut == "Y");
}
