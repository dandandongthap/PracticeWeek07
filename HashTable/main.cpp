#include <iostream>
#include "HashTable.h"

void testHashTable();

int main()
{
	testHashTable();

	system("pause");
	return 0;
}

void testHashTable()
{
	using namespace std;

	HashTable u_map;

	u_map.readFile("mst.txt");

	cout << "Size: " << u_map.size() << endl << endl;

	string name0 = "CONG TY TNHH THUONG MAI DICH VU MY PHAM NGOC TRAM";
	string name1 = "CONG TY TNHH TMDV TONG HOP PHU TRONG";
	string name2 = "CONG TY TNHH MOT THANH VIEN TRUONG PHAT BINH PHUOC";
	string name3 = "CONG TY TNHH KARGOSMART GLOBAL VIETNAM";
	string name4 = "CONG TY TNHH TINH TAM TRA";
	string name5 = "CONG TY CO PHAN KIEN TRUC XAY DUNG VA NOI THAT MINH HOANG";
	string name6 = "CONG TY 123456";

	cout << u_map.find(name0) << endl;
	cout << u_map.find(name1) << endl;
	cout << u_map.find(name2) << endl;
	cout << u_map.find(name3) << endl;
	cout << u_map.find(name4) << endl;
	cout << u_map.find(name5) << endl;

	if (u_map.find(name6).name.empty())
	{
		cout << "Cannot find \"" << name6 << "\" in hash table.\n";
	}
}