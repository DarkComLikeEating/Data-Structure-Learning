#include "sqlist.cpp"

int main() {
    Sqlist * L;
    ElemType e;
    cout << "Below are basic operations of a sequence list:" << endl;
    cout << "(1) Initialize sequence list L" << endl;
    initList(L);
    cout << "(2) Insert elements a, b, c, d, e successively" << endl;
    listInsert(L, 1, 'a');
    listInsert(L, 2, 'b');
    listInsert(L, 3, 'c');
    listInsert(L, 4, 'd');
    listInsert(L, 5, 'e');
    cout << "(3) Print sequence list L: "; dispList(L);
    cout << "(4) The length of sequence list: " << listLength(L) << endl;
    cout << "(5) Sequence list is" << (listEmpty(L) ? " EMPTY" : " NOT EMPTY") << endl;
    getElem(L, 3, e);
    cout << "(6) The 3nd element of L is " << e << endl;
    cout << "(7) Element a position is " << locateElem(L, 'a') << endl;
    cout << "(8) Insert element f at 4th position" << endl;
    listInsert(L, 4, 'f');
    cout << "(9) Print sequence list L: "; dispList(L);
    cout << "(10) Delete 3nd element of L" << endl;
    listDelete(L, 3, e);
    cout << "(11) Print sequence list: "; dispList(L);
    cout << "Free sequence list." << endl;
    destroyList(L);
    return 0;
}
