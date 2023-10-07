/*----------------------------
Created by :	 CAN
File name :		 main.cpp

---------------------------------*/
#include "student.h"
#include "function.h"
#include<string>
#include <iostream>
#include<typeinfo>
using namespace std;
int main(){
	/*
	int n;
	cout<<"nhap so sinh vien"<<endl;
	cin>>n;
	//sv  *sinh_vien =(sv *) malloc(n*sizeof(sv));
	sv sinhvien[10] ;
	for(int i=0;i<n;i++){
	*(sinhvien+i)=nhapsv();
	xuat(*(sinhvien+i));
	}*/


	int n;
	cout<<"nhap so sinh vien list 1 : "<<endl;
	cin>>n;
	  slist *list =NULL;

	/*for(int i=0;i<n;i++){
		sv *sinhvien_1=(sv*)malloc(sizeof(sv));
	//sinhvien_1=nhapsv();
	//list=slist_append(list,(void *)&nhapsv());
	sinhvien_1->name=(char *)malloc(32);
	sinhvien_1->name[0]='a'+i;
	sinhvien_1->name[1]=0;
	sinhvien_1->ages=i;
	list=slist_append(list,(void *)sinhvien_1);
	}*/
	for(int i=0;i<n;i++){
	//sv *sinhvien_1=(sv*)malloc(sizeof(sv));
	//sv *sinhvien_1;
	//sinhvien_1=nhapsv();
	//cout<<"dia chi cua ham nhap"<<sinhvien_1;
		list=slist_append(list,(void *)nhapsv());
	}
	cout<<"so phan tu la: "<<count_item(list)<<endl;
	//output_data(list);
	out_put_list_data(list,sv_info);
	cout<<"nhap tuoi can tim :"<<endl;
	int tuoi;
	cin>>tuoi;
	slist  *outList ;
	outList=slist_find(list,(void *)tuoi,check_find_by_ages);
	out_put_list_data(outList,sv_info);
	//output_data(outList);
	//output_data(list);
	int m;
	cout<<"nhap so sinh vien list 2 : "<<endl;
	cin>>m;
	  slist *s_list =NULL;
	for(int i=0;i<m;i++){
		list=slist_append(list,(void *)nhapsv());
	}
	slist* oList = slist_concat(list,s_list);
	//output_data(oList);
	out_put_list_data(oList,sv_info);
	int ages;
	cout<<"nhap tuoi sinh vien can liet ke :"<<endl;
	cin>>ages;
	slist_trace(oList,(void *)ages,print_student_by_ages);
	// remove test
	int index;
	cout<<"nhap vi tri can xoa :"<<endl;
	cin>>index;
	list=slist_remove_by_index(list,index,release_sv);
	out_put_list_data(list,sv_info);
	cout<<"nhap sinh vien can chen"<<endl;
	sv *sinh_vien=nhapsv();
	int tuoi_insert;
	cout<<"nhap tuoi sinh vien ma new Item se duoc chen sau do :"<<endl;
	cin>>tuoi_insert;
	list=slist_insert(list,(void*)sinh_vien,(void *)tuoi_insert,insert_by_ages_check);
	out_put_list_data(list,sv_info);
	//count_item(list);
	// list=slist_sort(list,ages_compare);
	cout<<"danh sach da sap xep"<<endl;
	out_put_list_data(list,sv_info);
	system("pause");
}