/*Дан непустой двусвязный список, первый, последний и текущий 
элементы которого имеют адреса Р1, Р2 и Р3. Используя тип TList, 
описать процедуры ToFirst(L) (делает текущим первый элемент 
списка L), ToNext(L) (делает текущим в списке L следующий элемент,
если он существует), SetData(L, D) (присваивает текущему элементу 
списка L значение D целого типа) и функцию IsLast(L) логического 
типа (возвращает true, если текущий элемент списка L является его
последним элементом, и false в противном случае). Параметр L имеет
тип TList; в процедурах ToFirst и ToNext он является входным и 
выходным. С помощью этих процедур и функций присвоить нулевые 
значения элементам исходного списка с нечетными номерами и вывести 
количество элементов в списке, а также новые адреса его первого,
последнего и текущего элементов (текущим должен стать последний 
элемент списка)*/

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
