/*----------------------------
Created by :	 CAN
File name :		 student.h

---------------------------------*/
#include <cstdint>
#include <iostream>
using namespace std;
// -------------sv data type define--------------
typedef struct sinhvien
{
	unsigned int ages;
	char *name;
} sv;

sv *nhapsv()
{
	sv *sinh_vien = (sv *)malloc(sizeof(sv));
	cout << "nhap ten sinh vien" << endl;
	cin.ignore();
	sinh_vien->name = (char *)malloc(sizeof(100));
	cin.getline(sinh_vien->name, 100);
	cout << "nhap tuoi sinh vien" << endl;
	cin >> sinh_vien->ages;
	return sinh_vien;
}
void xuat(sv *sv_1)
{
	cout << "ten sinh vien : " << sv_1->name << endl;
	cout << "tuoi :" << sv_1->ages << endl;
}
//
//------------check_find_by_ages function define--------------------------------
//
bool check_find_by_ages(void *data_1, void *data_2)
{
	cout << "check_find_by_ages " << endl;
	sv *std = (sv *)data_2;
	// long long ages = (long long)data_1;
	intptr_t val =  reinterpret_cast<intptr_t> (data_1);
	int ages = static_cast<int> (val);
	cout << "std->ages" << std->ages << endl;
	cout << "ages" << ages << endl;
	if (std->ages == ages)
	{
		return true;
	}
	return false;
}
//-------------callback function define --------------
//------------print name of student --------------------
//----------- typedef void (*call_back)(int index,void *data_1,void*data_2);--------

//------------print_student_by_ages function define--------------------------------
void print_student_by_ages(int index, void *data_1, void *data_2)
{
	// long long ages = (long long)data_1;
	intptr_t val =  reinterpret_cast<intptr_t> (data_1);
	int ages = static_cast<int> (val);
	sv *student = (sv *)data_2;
	if (student->ages == ages)
	{
		cout << "sinh vien thu " << index + 1 << " co tuoi bang " << ages << endl;
		cout << student->name << endl;
	}
}
//------------sv_info function define--------------------------------
void sv_info(void *data)
{
	sv *sinhvien = (sv *)data;
	xuat(sinhvien);
}

//---------------------------check to remove item in list function define--------------

bool remove_check_by_index(void *data_1, void *data_2)
{
	// long long index = (long long) data_1;
	// long long itemIdex = (long long)data_2;
	intptr_t val =  reinterpret_cast<intptr_t> (data_1);
	int index = static_cast<int> (val);
	intptr_t val2 =  reinterpret_cast<intptr_t> (data_2);
	int itemIdex = static_cast<int> (val2);
	return index == itemIdex;
}
//------------------release sv function -----------a instance of release_data_function-------------
void release_sv(void *data)
{
	sv *sinhvien = (sv *)data;
	// free(sinhvien->name); release the dinamic allocated variable
	free(sinhvien);
}
// --------------------insert-check-function-------------------------------------
bool insert_by_ages_check(void *data_1, void *data_2)
{
	// long long ages = (long long)data_1;
	intptr_t val =  reinterpret_cast<intptr_t> (data_1);
	int ages = static_cast<int> (val);
	sv *sinhvien = (sv *)data_2;
	int itemAges = sinhvien->ages;
	if (ages == itemAges)
	{
		return true;
	}
	return false;
}
//
// instance function of compare_function for sort list
//
bool ages_compare(void *data_1, void *data_2)
{
	sv *sv_1 = (sv *)data_1;
	sv *sv_2 = (sv *)data_2;
	if (sv_1->ages > sv_2->ages)
	{
		return true;
	}
	return false;
}
