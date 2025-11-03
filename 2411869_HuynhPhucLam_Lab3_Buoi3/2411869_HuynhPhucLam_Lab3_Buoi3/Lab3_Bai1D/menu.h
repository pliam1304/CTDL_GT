void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================= HE THONG CHUC NANG =================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu tap tin";
	cout << "\n2. Xem du lieu hien hanh";
	cout << "\n3. Sap xep bang Selection Straight Sort";
	cout << "\n4. Sap xep bang Insertion Straight Sort";
	cout << "\n5. Sap xep bang Interchange Straight Sort";
	cout << "\n6. Sap xep bang Bubble Sort";
	cout << "\n7. Sap xep bang Binary Insertion Sort";
	cout << "\n8. Sap xep bang Radix Sort";
	cout << "\n=======================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << ") de chon menu: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int b[MAX];
	char filename[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh.\n";
		break;

	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu tu tap tin\n";
		do
		{
			cout << "\nNhap ten tap tin (vi du: test1.txt): ";
			cin >> filename;
			kq = File_Array(filename, a, n);
			if (!kq)
				cout << "\nLoi mo tap tin, vui long nhap lai!\n";
		} while (!kq);
		cout << "\nDu lieu vua doc tu tap tin:\n";
		Output(a, n);
		cout << endl;
		break;

	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu hien hanh:\n";
		Output(a, n);
		cout << endl;
		break;

	case 3:
		system("CLS");
		cout << "\n3. Sap xep bang Selection Straight Sort\n";
		Copy(b, a, n);
		Selection_L(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;

	case 4:
		system("CLS");
		cout << "\n4. Sap xep bang Insertion Straight Sort\n";
		Copy(b, a, n);
		Insertion_L(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;

	case 5:
		system("CLS");
		cout << "\n5. Sap xep bang Interchange Straight Sort\n";
		Copy(b, a, n);
		Interchange_L(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;

	case 6:
		system("CLS");
		cout << "\n6. Sap xep bang Bubble Sort\n";
		Copy(b, a, n);
		Buble_L(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;

	case 7:
		system("CLS");
		cout << "\n7. Sap xep bang Binary Insertion Sort\n";
		Copy(b, a, n);
		Binary_Insertion(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;

	case 8:
		system("CLS");
		cout << "\n8. Sap xep bang Radix Sort\n";
		Copy(b, a, n);
		Radix(b, n);
		cout << "\nMang sau khi sap xep:\n";
		Output(b, n);
		cout << endl;
		break;
	}
}
