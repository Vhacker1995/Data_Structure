#include <iostream>
using namespace std;
template <class T>
class seqList
{
    T *a;
    int len;
public:
    seqList(int _len)
    {
        len=_len;
        a= new T[len];
        for (int i = 0; i <len ; ++i)
        {
            cin>>a[i];
        }
    }
    ~seqList()
    {
        delete []a;
    }
    void _sort()
    {
        int i,j;
        T temp;
        for(i=0; i<len; i++)
        {
            for(j=0; j<len-i-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
    void reSize(int _size=1)
    {
        int i=0;
        T *prea=a;
        a=new T[_size+len];
        for(i=0; i<len; i++)
        {
            a[i]=prea[i];
        }
        delete []prea;
        len++;
    }
    void _insert(int i,T x)
    {
        reSize();
        int j;
        for(j=len-1; j>i-1; j--)
        {
            a[j]=a[j-1];
        }
        a[j]=x;
    }
    void  _delete(int i)
    {
        for(i=i-1; i<=len-1; i++)
        {
            a[i]=a[i+1];
        }
        len--;

    }
    int _search(T x)
    {
        int i;
        for(i=0; i<len; i++)
        {
            if(a[i]==x)
            {

                cout<<i+1<<endl;
                return i;
            }
        }
        cout<<"Not found"<<endl;
        return 0;
    }
    int getLenth()
    {
        return len;
    }
    void fanzhi()
    {
        T temp;
        int mid=len/2-1,i;
        for(i=0; i<=mid; i++)
        {
            temp=a[i];
            a[i]=a[len-i-1];
            a[len-i-1]=temp;
        }
    }
    void _merge(seqList &b)
    {
        reSize(b.len);
        int i,j;
        for(i=0; i<b.len; i++)
        {
            for (j=0; j<len; j++)
            {
                if (b.a[i]>a[j])
                {
                    _insert(j,b.a[i]);
                }
            }
        }
    }
    void output()
    {
        int i;
        for(i=0; i<len; i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

}
;
int main()
{
    int len,x,i;
    cin>>len;
    seqList<int> a(len);
    cin>>x>>i;
    a._insert(i,x);
    a.output();
    cin>>i;
    a._delete(i);
    a.output();
    cin>>x;
    a._search(x);
       a.fanzhi();
    a.output();
    seqList<int> b(4);

    a._merge(b);
    a.output();


    return 0;



}
