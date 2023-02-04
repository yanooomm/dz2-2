/* ListWork37. ��� ���������� �������� ������ � ��������� �� ������ ������� ����� ������.
���������� ������� � ������ N-�� �� ����� �������. ������� N �� ������ ����� ��������� � 
������.� �������� ���������� ������� ������ �� ������� ������, ��������� �� ���������,
��� nill, ���� ��������� ������� ��� ���������*/

#include "pt4.h"

PNode Head;
PNode Tail;

using namespace std;

void Solve()
{
    Task("ListWork37");
    int n;
    
    PNode p, NewNode = new(TNode);
    pt >> n >> p;
    Head = p;
    for (int i = 1; i < n; i++)
        p = p->Next;
    PNode A = p->Next;
    if (Head == p) //������� � ������ ������
    {
        Head = p->Next; // ������� ������ �������
        if (Head) 
            Head->Prev = NULL;
        else 
            Tail = NULL; // ������� ������������ �������
    }
    else
    {
        p->Prev->Next = p->Next;
        if (p->Next)
            p->Next->Prev = p->Prev;
        else
        {
            Tail = p->Prev; // ������� ��������� �������
            Tail->Next = NULL;
        }
    }
    pt << A;
}


/*

#include "pt4.h"

using namespace std;

void Solve()
{
    Task("ListWork37");
    int n;
    PNode p, NewNode = new(TNode);
    pt >> n >> p;
    for (int i = 0; i < n; i++)
        p = p->Next;
    if (!(p->Prev))
    {
        p = p->Next;
        p->Prev = NULL;
    }
    else
    {
        if (p->Next)
        {
            p->Prev->Next = p->Next;
            if (p->Next)
                p->Next->Prev = p->Prev;
        }
        if (!(p->Next))
        {
            p = p->Prev;
            p->Next = NULL;
        }
    }
    pt << p;
}

*/