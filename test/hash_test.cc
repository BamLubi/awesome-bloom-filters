#include "hash.h"
#include <iostream>
using namespace std;

int main(){
    cout<<"hash test\n";
    cout<<"abcdefg: "<<Hash("abcdefg")<<endl;
    cout<<"123advasd: "<<Hash("123advasd")<<endl;
    cout<<"asd2gbs23: "<<Hash("asd2gbs23")<<endl;
    cout<<"savbjfgkjtiy: "<<Hash("savbjfgkjtiy")<<endl;
    return 0;
}