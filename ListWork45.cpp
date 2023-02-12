/*��� �������� ���������� ������, ������, ��������� � ������� 
�������� �������� ����� ������ �1, �2 � �3. ��������� ��� TList, 
������� ��������� ToFirst(L) (������ ������� ������ ������� 
������ L), ToNext(L) (������ ������� � ������ L ��������� �������,
���� �� ����������), SetData(L, D) (����������� �������� �������� 
������ L �������� D ������ ����) � ������� IsLast(L) ����������� 
���� (���������� true, ���� ������� ������� ������ L �������� ���
��������� ���������, � false � ��������� ������). �������� L �����
��� TList; � ���������� ToFirst � ToNext �� �������� ������� � 
��������. � ������� ���� �������� � ������� ��������� ������� 
�������� ��������� ��������� ������ � ��������� �������� � ������� 
���������� ��������� � ������, � ����� ����� ������ ��� �������,
���������� � �������� ��������� (������� ������ ����� ��������� 
������� ������)*/

#include "pt4.h"

using namespace std;

struct TList
{
	PNode First;
	PNode Last;
	PNode Current;
};

TList ToFirst(TList L)
{
	L.Current = L.First;
	return L;
}

TList ToNext(TList L)
{
	L.Current = L.Current->Next;
	return L;
}

TList SetData(TList L, int D)
{
	L.Current->Data = D;
	return L;
}

bool IsLast(TList L)
{
	bool ans;
	ans = L.Current == L.Last;
	return ans;
}

void Solve()
{
    Task("ListWork45");
	TList L;
	PNode p1, p2, p3;
	pt >> p1 >> p2 >> p3;
	L.First = p1; 
	L.Last = p2;
	L.Current = p3;
	int count = 0;
	L = ToFirst(L);
	while (!IsLast(L))
	{
		L = SetData(L, 0);
		count += 1;
		L = ToNext(L);
		if (!IsLast(L))
		{
			count += 1;
			L = ToNext(L);
		}
		else
			count += 1;
	}
	if (count == 0 || ToNext(L).Current == NULL)
	{
		L = SetData(L, 0);
		count += 1;
	}
	if (count % 2 != 0)
	{
		L.Last->Data = 0;
	}
	pt << count << L.First << L.Last << L.Current;

}