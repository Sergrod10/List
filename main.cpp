#include <bits/stdc++.h>

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long long

using namespace std;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;

using namespace std;

struct Node {
    int val = 0;
    Node *next = nullptr;
};

class List {
    Node *head = nullptr;
    int sz = 0;

public:

    List () {
        head = nullptr;
    }

    List(int val) {
        Node *x = new Node{val};
        head = x;
        sz = 1;
    }

    friend ostream& operator<<(ostream &fout, const List&);

    int empty() {
        return (sz == 0);
    }

    int check(Node x, Node y) {
        if (x.next == nullptr) {
            return 0;
        }
        return (x.val == y.val && x.next == y.next);
    }

    void push_front(int val) {
        Node *now = new Node{val};
        now -> next = head;
        head = now;
        sz++;
    }

    void push_back(int val) {
        Node *now = new Node{val};
        if (sz == 0) {
            sz++;
            head = now;
            return;
        }
        Node *nxt = head;
        while (nxt -> next) {
            nxt = nxt -> next;
        }
        nxt -> next = now;
        sz++;
    }

    void pop_front() {
        if (sz == 0) {
            return;
        }
        if (sz == 1) {
            sz = 0;
            delete head;
            head = nullptr;
            return;
        }
        Node *tmp = head;
        head = (*head).next;
        delete tmp;
        sz--;
    }

    void pop_back() {
        if (sz == 0) {
            return;
        }
        if (sz == 1) {
            sz = 0;
            Node *x = head;
            delete x;
            head = nullptr;
            return;
        }

        Node *nxt = head;

        while (nxt -> next -> next) {
            nxt = nxt -> next;
        }
        delete nxt -> next;
        nxt -> next = nullptr;
        sz--;
    }

    void insert(Node *x, int val) {
        if (check(*head, *x)) {
            push_front(val);
            return;
        }
        int ok = 0;
        Node *nxt = head;
        while (!check(*nxt, *x)) {
            if (nxt -> next == nullptr) {
                ok = 1;
                break;
            }
            nxt = nxt -> next;
        }
        if (!ok) {
            Node *nw = new Node{val};
            nw -> next = nxt -> next;
            sz++;
            nxt -> next = nw;
        }
        else {
            push_back(val);
        }
    }

    void erase(Node *x) {
        if (check(*head, *x)) {
            pop_back();
            return;
        }
        int ok = 0;
        Node *nxt = head;
        while (!check(*(nxt -> next), *x)) {
            if (nxt -> next == nullptr) {
                ok = 1;
                break;
            }
            nxt = nxt -> next;
        }
        if (!ok) {
            sz--;
            Node *del = nxt -> next;
            nxt -> next = nxt -> next -> next;
            delete del;
        }
    }

    int find(int val) {
        Node *now = head;
        int id = 0;
        while (now) {
            if (now -> val == val) {
                return id;
            }
            now = now -> next;
            id++;
        }
        return -1;
    }

    void eraseval(int val) {
        int ind = find(val);
        if (ind == -1) {
            return;
        }
        if (ind == 0) {
            pop_front();
        }
        int now = 0;
        Node *nxt = head;
        while (now != ind - 1) {
            now++;
            nxt = nxt -> next;
        }
        Node *del = nxt -> next;
        nxt -> next = nxt -> next -> next;
        delete del;
    }

    List copy();
    List operator+(List);
};

List List::copy() {
    List nw;
    //cout << 111 << endl;
    Node *nxt = head;
    while (nxt) {
        //cout << nxt -> val << endl;
        nw.push_back(nxt -> val);
        //cout << nw << endl;
        nxt = nxt -> next;
    }
    //cout << nw;
    return nw;
}

List List::operator+(List a) {
    List ans = copy();
    //cout << ans << endl;
    Node *nxt = a.head;
    while (nxt) {
        ans.push_back(nxt -> val);
        nxt = nxt -> next;
    }
    return ans;
}


ostream& operator<<(ostream &fout, const List &a) {
    Node *now = a.head;
    while (now != nullptr) {
        fout << now -> val << " ";
        //fout << now -> next << endl;
        now = now -> next;
    }
    return fout;
}

signed main() {
    system("chcp 65001");

    /*List test(2);
    cout << test.empty() << endl;
    test.pop_back();
    cout << test << endl;
    cout << test.empty() << endl;
    test.push_front(5);
    test.push_front(10);
    test.push_back(15);
    test.push_back(15);
    test.push_back(20);
    test.push_front(2);
    cout << test << endl;
    cout << test.find(2) << endl;
    cout << test.find(15) << endl;
    cout << test.find(0) << endl;
    cout << test.find(20) << endl;
    test.pop_front();
    test.pop_back();
    test.pop_front();
    cout << test << endl;
    test.eraseval(15);
    test.eraseval(15);
    cout << test << endl;
    List test2;
    test2.push_back(10);
    test2.push_front(-1);
    test2.push_front(10);
    test2.push_front(4);
    cout << test << endl << test2 << endl << test + test2 << endl;*/

    cout << "Введите ... если хотите:\n1 - узнать пустой ли список\n2 - добавить в начало элемент\n3 - добавить в конец списка\n4 - удалить первый элемент\n5 - удалить последний элемент\n6 - найти элемент по значению\n7 - удалить элемент по значению\n";
    cout << "Введите количество операций над первым односвязном списком\n";
    List lst1;
    int x; cin >> x;
    while (x--) {
        int t; cin >> t;
        if (t == 1) {
            cout << lst1.empty() << "\n";
        }
        if (t == 2) {
            int val; cin >> val;
            lst1.push_front(val);
        }
        if (t == 3) {
            int val; cin >> val;
            lst1.push_back(val);
        }
        if (t == 4) {
            lst1.pop_front();
        }
        if (t == 5) {
            lst1.pop_back();
        }
        if (t == 6) {
            int val; cin >> val;
            cout << lst1.find(val) + 1 << endl;
        }
        if (t == 7) {
            int val; cin >> val;
            lst1.eraseval(val);
        }
        cout << lst1 << endl;
    }

    cout << "Введите количество операций над вторым односвязном списком\n";
    List lst2;
    cin >> x;
    while (x--) {
        int t; cin >> t;
        if (t == 1) {
            cout << lst2.empty() << "\n";
        }
        if (t == 2) {
            int val; cin >> val;
            lst2.push_front(val);
        }
        if (t == 3) {
            int val; cin >> val;
            lst2.push_back(val);
        }
        if (t == 4) {
            lst2.pop_front();
        }
        if (t == 5) {
            lst2.pop_back();
        }
        if (t == 6) {
            int val; cin >> val;
            cout << lst2.find(val) + 1 << endl;
        }
        if (t == 7) {
            int val; cin >> val;
            lst2.eraseval(val);
        }
        cout << lst2 << endl;
    }

    cout << "Сложение этих списков\n";
    cout << lst1 + lst2 << endl;
}
