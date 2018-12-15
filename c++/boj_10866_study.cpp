//
// Created by SUN on 2018-12-15.
//

#include <iostream>

using namespace std;

struct List {
    int val;
    List *front = NULL; // front
    List *back = NULL; // back

    List(int val) : val(val) {};

};

struct Deque {
private:
    List *head = NULL;
    List *tail = NULL;

public:

    void push_front(int x) {
        if (head == NULL) {
            head = new List(x);
            tail = head;
            return;
        }
        List *tmp = head;
        head->front = new List(x);
        head = head->front;
        head->back = tmp;
    }

    void push_back(int x) {
        if (tail == NULL) {
            tail = new List(x);
            head = tail;
            return;
        }
        List *tmp = tail;
        tail->back = new List(x);
        tail = tail->back;
        tail->front = tmp;
    }

    void pop_front() {
        if (head == NULL) {
            cout << -1 << '\n';
            return;
        }
        cout << head->val << '\n';
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->back;
            if (head->front) {
                head->front = NULL;
            }
        }

    }

    void pop_back() {
        if (tail == NULL) {
            cout << -1 << '\n';
            return;
        }
        cout << tail->val << '\n';
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->front;
            if (tail->back) {
                tail->back = NULL;
            }
        }
    }

    void size() {
        int cnt = 0;
        List *tmp = head;
        if (head == NULL) {
            cout << cnt << '\n';
            return;
        }

        cnt++;
        while (tmp->back != NULL) {
            tmp = tmp->back;
            cnt++;
        }

        cout << cnt << '\n';

    }

    void empty() {
        int ret = 0;
        if (head == NULL) {
            ret = 1;
        }

        cout << ret << '\n';
    }

    void front() {
        if (head == NULL) {
            cout << -1 << '\n';
            return;
        }
        cout << head->val << '\n';
    }

    void back() {
        if (tail == NULL) {
            cout << -1 << '\n';
            return;
        }
        cout << tail->val << '\n';
    }
};


int main() {
    int n;
    cin >> n;

    Deque d;

    while (n--) {
        string input;
        cin >> input;

        if ("push_front" == input) {
            int val;
            cin >> val;
            d.push_front(val);
        } else if ("push_back" == input) {
            int val;
            cin >> val;
            d.push_back(val);
        } else if ("pop_front" == input) {
            d.pop_front();
        } else if ("pop_back" == input) {
            d.pop_back();
        } else if ("size" == input) {
            d.size();
        } else if ("empty" == input) {
            d.empty();
        } else if ("front" == input) {
            d.front();
        } else if ("back" == input) {
            d.back();
        }
    }


    return 0;
}