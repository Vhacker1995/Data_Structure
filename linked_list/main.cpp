#include <iostream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;



template <class T>
class linkedList
{
    class LinkNode
    {
        T data;
        LinkNode *next;
    public:
        LinkNode(T _data)
        {
            data=_data;
            next=NULL;
        }
        ~LinkNode() {}
        friend class linkedList;
    };
    LinkNode *first;
    int length;
public:
    linkedList()
    {
        int i,j;
        cin>>length;
        T data[length],temp;
        for(i=0; i<length; i++)
        {
            cin>>data[i];
        }
        for(i=0; i<length; i++)
        {
            for(j=0; j<length-i-1; j++)
            {
                if(data[j]<data[j+1])
                {
                    temp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
        LinkNode *current=first=new LinkNode(data[0]);

        //current=current->next;//空指针并非指向0x0，data!=next
        for(i=1; i<length; i++)
        {
            current->next=new LinkNode(data[i]);
            current=current->next;
        }
    }
    ~linkedList() {}

    void _insert(T x,int i)
    {
        int j;
        LinkNode *current=first;//函数结束后current被回收，current和first指向统一内存，但不是引用！！！！！！
        if(i==1)
        {
            first=new LinkNode(x);
            first->next=current;
        }
        else
        {
            for(j=1; j<i-1; j++)
            {
                current=current->next;
            }
            LinkNode *_next=current->next;
            current->next= new LinkNode(x);
            current->next->next=_next;
            //getchar();
        }
        length++;
    }
    void output()
    {
        //int i;
        LinkNode *current=first;
        for(; current!=NULL; current=current->next)
            cout<<current->data<<' ';
            cout<<endl;
    }
    void _delete(int i)
    {
        int j;
        LinkNode *current=first;
        if(i==1)
        {
            first->next=current;
            delete first;
            first=current;

        }
        else
        {
            for(j =1; j<i-1; j++)
            {
                current=current->next;
            }
            LinkNode *_next=current->next->next;
            delete current->next;
            current->next=_next;
            //getchar();
        }
        length--;
    }

    int _search(T data)
    {
        int i;
        LinkNode *current=first;
        for(i=1; current!=NULL && current->data!=data ; current=current->next)
        {
            i++;
        }
        if (current==NULL)
        {
            cout<<"Not found!"<<endl;
            return 0;
        }
        else
            cout<<i<<endl;
        return i;
    }
    void inversion()
    {
        int i;
        LinkNode *current=first,*_current;
        LinkNode *a[length];
        for(i=0; current!=NULL; i++,current=current->next)
        {
            a[i]=current;
        }
        current=first->next;
        for(i=0; current!=NULL; i++)
        {
            _current=current->next;
            current->next=a[i];
            current=_current;
        }
        first->next=NULL;
        first=a[length-1];
    }
    void _merge(linkedList &other)
    {
        int i;
        LinkNode *Ocurrent=other.first;
        LinkNode *current=first;
        for(; Ocurrent!=NULL; Ocurrent=Ocurrent->next)
        {
            for(i=1; current!=NULL; i++,current=current->next)
            {
                if(Ocurrent->data<current->data)
                {


                    _insert(Ocurrent->data,i);
                    current=first;
                    break;
                }
            }
            if (current==NULL)
             {
                _insert(Ocurrent->data,i);
             }
        }

    }
};
int main()
{
    linkedList<int> a;

    int x,i;
    //a.output();
    cin>>x>>i;
    a._insert(x,i);
    a.output();
    cin>>i;
    a._delete(i);
    a.output();
    cin>>x;
    a._search(x);
    //getchar();
    a.inversion();
    a.output();
    //getchar();
    linkedList<int> b;
    b.inversion();
    a._merge(b);
    a.output();
//getchar();
//getchar();
//getchar();
//getchar();
    return 0;
}
