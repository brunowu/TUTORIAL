#include <iostream>
#include <map>

void printIt(std::map<int,int> m) {
    for(std::map<int,int>::iterator it=m.begin();it!=m.end();++it)
        std::cout << it->first<<":"<<it->second<<" ";
    std::cout << "\n";
}

int main() {
    std::map<int,int> foo,bar, sum;
    foo[1] = 11; foo[2] = 12; foo[3] = 13; foo[10] = 20;
    bar[2] = 20; bar[3] = 30; bar[4] = 40; bar[13] = 30;
    printIt(foo);
    printIt(bar);
    sum.insert(foo.begin(), foo.end());
    sum.insert(bar.begin(),bar.end());
    printIt(sum);
    return 0;
}
