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
    }
    bool _insert(int i)
    {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
