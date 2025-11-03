#define MAX 100

int File_Array(char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in) return 0;
    n = 0;
    while (in >> a[n]) n++;
    in.close();
    return 1;
}

void Output(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
}

void XuatMang(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

void HoanVi(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

void SelectionSort(int a[MAX], int n, long& ss, long& hv)
{
    ss = hv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            ss++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            HoanVi(a[i], a[min]);
            hv++;
        }
    }
}

void InsertionSort(int a[MAX], int n, long& ss, long& hv)
{
    ss = hv = 0;
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && ++ss && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            hv++;
            pos--;
        }
        a[pos + 1] = x;
    }
}

void InterchangeSort(int a[MAX], int n, long& ss, long& hv)
{
    ss = hv = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            ss++;
            if (a[i] > a[j])
            {
                HoanVi(a[i], a[j]);
                hv++;
            }
        }
}

void BubbleSort(int a[MAX], int n, long& ss, long& hv)
{
    ss = hv = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
        {
            ss++;
            if (a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
                hv++;
            }
        }
}
