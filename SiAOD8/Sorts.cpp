#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include <chrono>

using namespace std;

string sortOptions();
vector<int> inputArr(vector<int> arr, int n, int type);
void outArr(vector<int> arr, int n);
vector<int> insertionSort(vector<int> arr, int n);
int getMax(vector<int> arr, int n);
vector<int> countSort(vector<int>& arr, int n, int exp);
vector<int> radixSort(vector<int>& arr, int n);
void quickSort(vector<int>& arr, int p, int n);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n", option;
	short problem;
	int n, pivot_key;
	bool flag = true;
	vector<int> arr;
	auto begin = chrono::steady_clock::time_point();
	auto end = chrono::steady_clock::time_point();
	while (flag)
	{
		system("cls");
		cout << "������������ ������ �8 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"����\n"
			"1) ���������� ������� �������.\n"
			"2) ����������� ����������.\n"
			"3) ������� ����������������� ����������.\n"
			"4) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
		{
			option = sortOptions();
			n = 10 * pow(10, (option[0] - '0'));
			arr = inputArr(arr, n, option[1] - '0');
			begin = chrono::steady_clock::now();
			arr = insertionSort(arr, n);
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "���������� �������: " << elapsed_ms.count() << " ��.\n";
			system("pause");
			break;
		}
		case 2:
		{
			option = sortOptions();
			n = 10 * pow(10, (option[0] - '0'));
			arr = inputArr(arr, n, option[1] - '0');
			begin = chrono::steady_clock::now();
			arr = insertionSort(arr, n);
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "���������� �������: " << elapsed_ms.count() << " ��.\n";
			system("pause");
			break;
		}
		case 3:
		{
			option = sortOptions();
			n = 10 * pow(10, (option[0] - '0'));
			arr = inputArr(arr, n, option[1] - '0');
			int pivot_key = rand() % n;
			swap(arr.at(pivot_key), arr.at(n - 1));
			begin = chrono::steady_clock::now();
			quickSort(arr, 0, n - 1);
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "���������� �������: " << elapsed_ms.count() << " ��.\n";
			system("pause");
			break;
		}
		case 4:
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

string sortOptions()
{
	short number, type;
	string options = "";
	cout << "����� ���������� ��������� ���������� �������������?\n"
		"1) 100.\n"
		"2) 1000.\n"
		"3) 10000.\n"
		"4) 100000.\n"
		"5) 1000000.\n";
	cout << "��� �����: ";
	cin >> number;
	options += to_string(number);
	switch (number)
	{
	case 1:
		cout << "��� ���������� ������ ���� ������������ ������?\n"
			"1) � ������ ��������� �������.\n"
			"2) � ��������� �������.\n"
			"3) � ������ ������������ �������.\n";
		cout << "��� �����: ";
		cin >> type;
		options += to_string(type);
		break;
	case 2:
		cout << "��� ���������� ������ ���� ������������ ������?\n"
			"1) � ������ ��������� �������.\n"
			"2) � ��������� �������.\n"
			"3) � ������ ������������ �������.\n";
		cout << "��� �����: ";
		cin >> type;
		options += to_string(type);
		break;
	case 3:
		cout << "��� ���������� ������ ���� ������������ ������?\n"
			"1) � ������ ��������� �������.\n"
			"2) � ��������� �������.\n"
			"3) � ������ ������������ �������.\n";
		cout << "��� �����: ";
		cin >> type;
		options += to_string(type);
		break;
	case 4:
		cout << "��� ���������� ������ ���� ������������ ������?\n"
			"1) � ������ ��������� �������.\n"
			"2) � ��������� �������.\n"
			"3) � ������ ������������ �������.\n";
		cout << "��� �����: ";
		cin >> type;
		options += to_string(type);
		break;
	case 5:
		cout << "��� ���������� ������ ���� ������������ ������?\n"
			"1) � ������ ��������� �������.\n"
			"2) � ��������� �������.\n"
			"3) � ������ ������������ �������.\n";
		cout << "��� �����: ";
		cin >> type;
		options += to_string(type);
		break;
	default:
		break;
	}
	return options;
}

vector<int> inputArr(vector<int> arr, int n, int type)
{
	srand(time(0));
	arr.reserve(n);
	if (type == 1)
	{
		for (int i = 0; i < n; i++)
		{
			arr.push_back(n - i);
		}
	}
	else if (type == 2)
	{
		for (int i = 0; i < n; i++)
		{
			arr.push_back(rand() % 100);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr.push_back(50 + i);
		}
	}
	return arr;
}

void outArr(vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr.at(i) << " ";
		if (i % 10 == 9) cout << '\n';
	}
}

vector<int> insertionSort(vector<int> arr, int n)
{
	int i, j, x;
	for (j = 1; j < n; j++)
	{
		x = arr.at(j);
		i = j - 1;
		if (arr.at(i) > x)
		{
			while (i > -1 && arr.at(i) > x)
			{
				arr.at(i + 1) = arr.at(i);
				i = i - 1;
			}
		}
		arr.at(i + 1) = x;
	}
	return arr;
}

int getMax(vector<int> arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

vector<int> countSort(vector<int>& arr, int n, int exp)
{
	vector<int> output;
	output.resize(n);
	int i;
	vector<int> count;
	count.resize(10);
	for (i = 0; i < n; i++)
		count.at((arr.at(i) / exp) % 10)++;
	for (i = 1; i < 10; i++)
		count.at(i) += count.at(i - 1);
	for (i = n - 1; i >= 0; i--) 
	{
		output.at(count.at((arr.at(i) / exp) % 10) - 1) = arr.at(i);
		count.at((arr.at(i) / exp) % 10)--;
	}
	for (i = 0; i < n; i++)
		arr.at(i) = output.at(i);
	return arr;
}

vector<int> radixSort(vector<int>& arr, int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		arr=countSort(arr, n, exp);
	return arr;
}

void quickSort(vector<int>& arr, int p, int n)
{
	if (p < n)
	{
		int q = p;
		for (int u = p; u < n; ++u)
		{
			if (arr.at(u) <= arr.at(n))
			{
				swap(arr.at(q), arr.at(u));
				q++;
			}
		}
		swap(arr.at(q), arr.at(n));
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, n);
	}
}