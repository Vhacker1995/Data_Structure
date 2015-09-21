#include <iostream>

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
    friend class linkedList;
};
    LinkNode *first=NULL;
    int length;
public:
    linkedList()
    {
        int i;
       T data;
        cin>>length;
        cin>>data;
       LinkNode *current=first=new LinkNode(data);
        for(i=1;i<length;i++)
        {
            cin>>data;
            current=new LinkNode(data);
            current=current->next;
        }
    }
};
int main()
{
    linkedList<int> a;
    return 0;
}
