#define		MAX		100

struct NhanVien
{
	char	maNV[8];
	char	ho[15];
	char	tenLot[11];
	char	ten[11];
	char	diaChi[16];
	int		namSinh;
	int		luong;
};

int File_Array(char* filename, NhanVien a[MAX], int& n);
void Heading();
void Output_Struct(NhanVien p);
void Output_Arr(NhanVien a[MAX], int n);
void Copy(NhanVien b[MAX], NhanVien a[MAX], int n);
void HoanVi(NhanVien& a, NhanVien& b);
void SapTangTheoMa(NhanVien ds[], int n);
void SapTangTheoDiaChi(NhanVien ds[], int n);
void radixSortNamSinh(NhanVien ds[], int n);
void quickSortLuong(NhanVien ds[], int low, int high);
void heapSortLuong(NhanVien ds[], int n);
void mergeSortLuong(NhanVien ds[], int left, int right);
void shakerSortLuong(NhanVien ds[], int n);

int File_Array(char* filename, NhanVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;

	n = 0;
	while (!in.eof())
	{
		in >> a[n].maNV;
		in >> a[n].ho;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].diaChi;
		in >> a[n].namSinh;
		in >> a[n].luong;
		n++;
	}
	in.close();
	return 1;
}

void Heading()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma NV"
		<< ':'
		<< setw(37) << "Ho va Ten nhan vien"
		<< ':'
		<< setw(10) << "Dia chi"
		<< ':'
		<< setw(5) << "NS"
		<< ':'
		<< setw(6) << "Luong";
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Output_Struct(NhanVien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maNV
		<< ':'
		<< setw(15) << p.ho
		<< setw(15) << p.tenLot
		<< setw(15) << p.ten
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(8) << p.luong
		<< ':';
}

void Output_Arr(NhanVien a[MAX], int n)
{
	int i;
	Heading();
	for (i = 0; i < n; i++)
	{
		Output_Struct(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Copy(NhanVien b[MAX], NhanVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void HoanVi(NhanVien& a, NhanVien& b)
{
    NhanVien t = a;
    a = b;
    b = t;
}

void SapTangTheoMa(NhanVien ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(ds[i].maNV, ds[j].maNV) > 0)
                HoanVi(ds[i], ds[j]);
}

void SapTangTheoDiaChi(NhanVien ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(ds[i].diaChi, ds[j].diaChi) > 0)
                HoanVi(ds[i], ds[j]);
}

void heapify(NhanVien ds[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && ds[l].luong > ds[largest].luong) largest = l;
    if (r < n && ds[r].luong > ds[largest].luong) largest = r;
    if (largest != i)
    {
        HoanVi(ds[i], ds[largest]);
        heapify(ds, n, largest);
    }
}

void heapSortLuong(NhanVien ds[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ds, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        HoanVi(ds[0], ds[i]);
        heapify(ds, i, 0);
    }
}

int partition(NhanVien ds[], int low, int high)
{
    long pivot = ds[high].luong;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ds[j].luong <= pivot)
        {
            i++;
            HoanVi(ds[i], ds[j]);
        }
    }
    HoanVi(ds[i + 1], ds[high]);
    return i + 1;
}

void quickSortLuong(NhanVien ds[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(ds, low, high);
        quickSortLuong(ds, low, pi - 1);
        quickSortLuong(ds, pi + 1, high);
    }
}

void merge(NhanVien ds[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    NhanVien* L = new NhanVien[n1];
    NhanVien* R = new NhanVien[n2];
    for (int i = 0; i < n1; i++) L[i] = ds[left + i];
    for (int j = 0; j < n2; j++) R[j] = ds[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].luong <= R[j].luong)
            ds[k++] = L[i++];
        else
            ds[k++] = R[j++];
    }
    while (i < n1) ds[k++] = L[i++];
    while (j < n2) ds[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSortLuong(NhanVien ds[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSortLuong(ds, left, mid);
        mergeSortLuong(ds, mid + 1, right);
        merge(ds, left, mid, right);
    }
}

void shakerSortLuong(NhanVien ds[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
            if (ds[i].luong > ds[i + 1].luong)
            {
                HoanVi(ds[i], ds[i + 1]);
                k = i;
            }
        right = k;
        for (int i = right; i > left; i--)
            if (ds[i].luong < ds[i - 1].luong)
            {
                HoanVi(ds[i], ds[i - 1]);
                k = i;
            }
        left = k;
    }
}

int getMaxNamSinh(NhanVien ds[], int n)
{
    int mx = ds[0].namSinh;
    for (int i = 1; i < n; i++)
        if (ds[i].namSinh > mx)
            mx = ds[i].namSinh;
    return mx;
}

void countSortNamSinh(NhanVien ds[], int n, int exp)
{
    NhanVien* output = new NhanVien[n];
    int count[10] = { 0 };
    for (int i = 0; i < n; i++)
        count[(ds[i].namSinh / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(ds[i].namSinh / exp) % 10] - 1] = ds[i];
        count[(ds[i].namSinh / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        ds[i] = output[i];
    delete[] output;
}

void radixSortNamSinh(NhanVien ds[], int n)
{
    int m = getMaxNamSinh(ds, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortNamSinh(ds, n, exp);
}