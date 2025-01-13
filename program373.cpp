#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCL
{
public:
    PNODE head;
    PNODE tail;
    int iCount;

    SinglyCL()
    {
        head = NULL;
        tail = NULL;
        iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if (head == NULL)
        {
            head = tail = newn;
            tail->next = head;
        }
        else
        {
            newn->next = head;
            head = newn;
            tail->next = head;
        }
        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if (head == NULL)
        {
            head = tail = newn;
            tail->next = head;
        }
        else
        {
            tail->next = newn;
            tail = newn;
            tail->next = head;
        }
        iCount++;
    }

    void InsertAtPos(int no, int ipos)
    {
        if (ipos < 1 || ipos > iCount + 1)
        {
            cout << "Invalid position\n";
            return;
        }

        if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE temp = head;
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
    }

    void DeleteFirst()
    {
        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            PNODE temp = head;
            head = head->next;
            delete temp;
            tail->next = head;
        }

        iCount--;
    }

    void DeleteLast()
    {
        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            PNODE temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            delete tail;
            tail = temp;
            tail->next = head;
        }

        iCount--;
    }

    void DeleteAtPos(int ipos)
    {
        if (ipos < 1 || ipos > iCount)
        {
            cout << "Invalid position\n";
            return;
        }

        if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = head;

            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            PNODE targ = temp->next;
            temp->next = targ->next;
            delete targ;

            iCount--;
        }
    }

    void Display()
    {
        if (head == NULL)
        {
            return;
        }

        PNODE temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.InsertAtPos(75, 4);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of elements are : " << iRet << "\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of elements are : " << iRet << "\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout << "Number of elements are : " << iRet << "\n";

    return 0;
}
