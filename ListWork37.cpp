/* ListWork37. Дан двусвязный линейный список и указатель на первый элемент этого списка.
Необходимо удалить в списке N-ый по счету элемент. Элемент N не больше числа элементов в 
списке.В качестве результата вывести ссылку на элемент списка, следующий за удаленным,
или nill, если удаленный элемент был последним*/

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
    if (Head == p) 
    {
        Head = p->Next;
        if (Head) 
            Head->Prev = NULL;
        else 
            Tail = NULL;
    }
    else
    {
        p->Prev->Next = p->Next;
        if (p->Next)
            p->Next->Prev = p->Prev;
        else
        {
            Tail = p->Prev;
            Tail->Next = NULL;
        }
    }
    pt << A;
}
