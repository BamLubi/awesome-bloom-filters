#include "hash.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "hash test\n";
    cout << "abcdefg: " << Hash("abcdefg", 0) << endl;
    cout << "123advasd: " << Hash("123advasd", 0) << endl;
    cout << "asd2gbs23: " << Hash("asd2gbs23", 0) << endl;
    cout << "savbjfgkjtiy: " << Hash("savbjfgkjtiy", 0) << endl;
    return 0;
}