void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n=================== CHUONG TRINH QUAN LY SINH VIEN ===================";
	cout << "\n1. Doc du lieu tu file";
	cout << "\n2. Xuat danh sach sinh vien";
	cout << "\n3. Sap xep sinh vien theo DTB bang QuickSort";
	cout << "\n4. Sap xep sinh vien theo DTB bang HeapSort";
	cout << "\n5. Sap xep sinh vien theo DTB bang MergeSort";
	cout << "\n6. Sao chep mang sinh vien";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n======================================================================";
	cout << endl;
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << ") de chon menu: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	char filename[MAX];
	int kq;
	sinhvien b[MAX];
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh.\n";
		break;

	case 1:
		system("cls");
		cout << "\n1. Doc du lieu tu file.";
		cout << "\nNhap ten file: ";
		cin >> filename;

		kq = File_Array(filename, a, n);
		if (kq)
			cout << "\nDoc file thanh cong. Co " << n << " sinh vien.";
		else
			cout << "\nKhong mo duoc file!";
		break;

	case 2:
		system("cls");
		cout << "\n2. Xuat danh sach sinh vien.\n";
		if (n > 0)
			Output_Arr(a, n);
		else
			cout << "\nDanh sach rong!";
		break;

	case 3:
		system("cls");
		cout << "\n3. Sap xep sinh vien theo DTB bang QuickSort.\n";
		if (n > 0)
		{
			Copy(b, a, n);
			QuickSort(b, n);
			Output_Arr(b, n);
		}
		else
			cout << "\nChua co du lieu!";
		break;

	case 4:
		system("cls");
		cout << "\n4. Sap xep sinh vien theo DTB bang HeapSort.\n";
		if (n > 0)
		{
			Copy(b, a, n);
			HeapSort(b, n);
			Output_Arr(b, n);
		}
		else
			cout << "\nChua co du lieu!";
		break;

	case 5:
		system("cls");
		cout << "\n5. Sap xep sinh vien theo DTB bang MergeSort.\n";
		if (n > 0)
		{
			Copy(b, a, n);
			MergeSort(b, n);
			Output_Arr(b, n);
		}
		else
			cout << "\nChua co du lieu!";
		break;

	case 6:
		system("cls");
		cout << "\n6. Sao chep mang sinh vien.\n";
		if (n > 0)
		{
			Copy(b, a, n);
			cout << "\nMang sau khi sao chep:\n";
			Output_Arr(b, n);
		}
		else
			cout << "\nChua co du lieu!";
		break;

	default:
		cout << "\nKhong co chuc nang nay!";
		break;
	}
}
