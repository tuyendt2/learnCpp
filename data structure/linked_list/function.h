/*----------------------------
Created by :	 tuyendt2
File name :		 function.h

---------------------------------*/

#include <iostream>
#include <typeinfo>

using namespace std;
// --------------------function pointer declare--------------------------
#define FORCE_DATA_TYPE(type, item) (type *)(item->data)
typedef bool (*compare_func)(void *, void *);
typedef void (*call_back)(int index, void *data_1, void *data_2);
typedef void (*release_data_function)(void *);

//----------------slist type define---------------------

typedef struct slist
{
	void *data;			/**< the pointer to data */
	struct slist *next; /**< the pointer to next element of list */
} slist;

//----------add node function----------------------------

slist *slist_append(slist *list, void *data)
{
	slist *walk = list;
	slist *new_Item = (slist *)malloc(sizeof(slist));
	if (!new_Item)
	{
		perror("Cannot allocate the mem\n");
		return new_Item;
	}
	else
	{
		new_Item->data = data;
		new_Item->next = NULL;

		if (walk)
		{
			// cout<<"danh sach khong rong"<<endl;
			while (walk)
			{
				if (walk->next == NULL)
				{
					walk->next = new_Item;
					break;
				}
				walk = walk->next;
			}

			return list;
		}
		else
		{
			// cout<<"danh sach rong" <<endl;
			// sv * sv_1=(sv *)new_Item->data;
			// xuat(sv_1);
			return new_Item;
		}
	}
}

//----------------count item function--------------------------------

int count_item(slist *list)
{
	slist *walk = list;
	int i = 0;
	while (walk)
	{
		// cout<<"cout item"<<endl;
		i++;
		walk = walk->next;
	}
	return i;
}

// -------------------output list's data -------------------------
//-----------just for testing ---not allow ,illegal in the fact ---------------
//--------------should be repalced by out_put_list_data function that will be declared using callback as below----------
void output_data(slist *list)
{
	slist *walk = list;
	int i = 1;
	sv *sv_1;
	cout << "xuat danh sach sinh vien" << endl;
	if (walk)
	{
		while (walk)
		{
			cout << "sinh vien thu " << i << endl;
			i++;
			sv_1 = (sv *)walk->data;
			xuat(sv_1);
			walk = walk->next;
		}
	}
	else
	{
		cout << "danh sach rong " << endl;
	}
}
//-------------------------output-list-data-function define--------------------------------------
void out_put_list_data(slist *list, void (*out)(void *data))
{
	cout << "out_put_list_data" << endl;
	slist *walk = list, *temp = list, *outList = list;
	int i = 0;
	if (walk)
	{
		while (walk)
		{
			out(walk->data);
			walk = walk->next;
			i++;
		}
	}
	else
	{
		cout << "danh sach rong ! " << endl;
	}
}

//----------output function use type force -------------haven't finished yet--------------

void output_data_use_call_back(slist *list)
{
	slist *walk = list;
	cout << "xuat danh sach" << endl;
	if (walk)
	{
		while (walk)
		{
			// do some thing
			walk = walk->next;
		}
	}
	else
	{
		cout << "danh sach rong " << endl;
	}
}

slist *slist_find(slist *list, void *data, bool (*compare_func)(void *, void *))
{
	slist *walk = list, *tmp = list, *outList = list;
	if (walk)
	{
		int i = 0;
		while (walk)
		{
			i++;
			if (compare_func(data, walk->data))
			{
				// walk->next=NULL;
				outList = walk->next;
				return walk;
				break;
			}
			walk = walk->next;
		}
		if (walk == NULL)
		{
			cout << "khong tim thay sinh vien " << endl;
			return NULL;
		}
	}
	else
	{
		perror("danh sach rong!\n");
		return NULL;
	}
}

// -----------------------First_Item_OutPut_Function--------------------------------

void out_put_first_Item(slist *list)
{
	slist *walk = list;
	if (walk)
	{
	}
	else
	{
		cout << "danh sach rong!" << endl;
	}
}

// -----------concat 2 list function ---------------------

slist *slist_concat(slist *list, slist *second_list)
{
	slist *walk = list, *temp = list, *s_walk = second_list, *outList;
	if (walk)
	{
		while (walk)
		{

			walk = walk->next;
		}
		walk = s_walk;
		return list;
	}
	else
	{
		return second_list;
	}
}
//------------------trace list function --------------------------------------
//----do something for all the item such output data , change data ...---------
void slist_trace(slist *list, void *data, void (*call_back)(int index, void *data_1, void *data_2))
{
	slist *walk = list, *temp = list, *outList = list;
	int i = 0;
	if (walk)
	{
		while (walk)
		{
			call_back(i, data, walk->data);
			walk = walk->next;
			i++;
		}
	}
	else
	{
		cout << "danh sach rong ! " << endl;
	}
}

//---------------remove flexible function -----------------haven't finshed yet---------------

slist *slist_remove(slist *list, void *data, bool (*compare_func)(void *data_1, void *data_2), void (*release_data_function)(void *))
{
	slist *walk = list, *temp = list, *outList = NULL, *pre_walk = list;
	if (walk)
	{
		int i = 0;
		while (walk)
		{
			i++;
			if (compare_func(data, (void *)i))
			{
				pre_walk = walk->next;
				release_data_function(walk->data);
				free(walk);
				return list;
			}
			walk = walk->next;
			pre_walk = walk;
		}
		if (walk == NULL)
		{
			cout << "danh sach khong co phan tu can xoa " << endl;
			return list;
		}
	}
	else
	{
		cout << "danh sach rong" << endl;
		return outList;
	}
}
//---------------remove-by-index function define -----------------------
slist *slist_remove_by_index(slist *list, int index, void (*release_data_function)(void *))
{
	slist *walk = list, *temp = list, *outList = NULL, *pre_walk = NULL;
	if (walk)
	{
		outList = walk->next;
		if (index == 1)
		{
			cout << "index" << endl;
			if (release_data_function)
			{
				release_data_function(walk->data);
				cout << "release_data_function done!" << endl;
				free(walk);
				cout << "free done!" << endl;
			}
			return outList;
		}
		if (index == count_item(list))
		{
			cout << "count_item(list)=" << count_item(list) << endl;
			if (release_data_function)
			{
				while (walk->next)
				{
					pre_walk = walk;
					walk = walk->next;
				}
				pre_walk->next = NULL;
				release_data_function(walk->data);
				cout << "release_data_function done!" << endl;
				free(walk);
				cout << "free done!" << endl;
			}
			return list;
		}
		int i = 0;
		while (walk)
		{
			i++;
			if (release_data_function)
			{
				// cout<<"release_data_function"<<endl;
				if (i == index)
				{
					cout << "right remove item condition" << endl;
					pre_walk->next = walk->next;
					release_data_function(walk->data);
					cout << "release_data_function done!" << endl;
					free(walk);
					cout << "free done!" << endl;
					return list;
					break;
				}
			}
			pre_walk = walk;
			walk = walk->next;
		}
		if (walk == NULL)
		{
			cout << "danh sach khong co phan tu can xoa " << endl;
			return list;
		}
	}
	else
	{
		cout << "danh sach rong" << endl;
		return outList;
	}
}

//--------------insert-newItem-to-list function define----------------------------------
slist *slist_insert(slist *list, void *data, void *dataCond, bool (*condition)(void *data_1, void *data_2))
{
	slist *walk = list, *pre_walk = list, *outList = NULL, *temp = list;
	slist *new_Item = (slist *)malloc(sizeof(slist));
	if (!new_Item)
	{
		perror("Cannot allocate the mem\n");
		return new_Item;
	}
	else
	{
		new_Item->data = data;
		if (walk)
		{
			while (walk)
			{
				if (condition(dataCond, walk->data))
				{
					cout << "right condition !" << endl;
					if (walk->next != NULL)
					{

						temp = walk->next;
						if (temp->next == NULL)
						{
							cout << "temp->next=NULL " << endl;
						}
						walk->next = new_Item;
						new_Item->next = temp;
						return list;
						break;
					}
					else
					{
						return slist_append(list, data);
					}
				}
				pre_walk = walk;
				walk = walk->next;
			}
			return list;
		}
		else
		{
			return new_Item;
		}
	}
}

//
//--------------sort-item-of-list function define----------------------------------
//
slist *slist_sort(slist *list, bool (*compare_func)(void *data_1, void *data_2))
{

	slist *walk_1 = list, *walk_2 = list, *temp_1 = list, *temp_2 = list, *outList = NULL,
		  *pre_walk_1 = list, *pre_walk_2 = list, *suf_walk_1 = NULL, *suf_walk_2 = NULL;
	if (walk_1)
	{
		while (walk_1->next)
		{
			walk_2 = walk_1->next;
			temp_2 = walk_2;
			while (walk_2)
			{
				if (compare_func)
				{
					cout << "compare_func is being processed! " << endl;
					if (compare_func(walk_1->data, walk_2->data))
					{
						cout << "dieu kien so sanh dung" << endl;
						if (temp_2 != NULL)
						{
							pre_walk_1->next = walk_2;
							temp_2->next = walk_1->next;
							pre_walk_2->next = walk_2;
							temp_1->next = walk_2->next;
						}
						else
						{
						}
					}
				}
				else
				{
					cout << "khong goi dc ham so sanh " << endl;
					return list;
				}
				pre_walk_2 = walk_2;
				walk_2 = walk_2->next;
				temp_2 = walk_2;
			}
			pre_walk_1 = walk_1;
			walk_1 = walk_1->next;
			temp_1 = walk_1;
		}
		return list;
	}
	else
	{
		cout << "danh sach rong !" << endl;
		return list;
	}
}