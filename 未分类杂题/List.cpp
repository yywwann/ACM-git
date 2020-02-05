#include <iostream>
using namespace std;

struct node {
  int   val;
  node *pre, *next;
};

void look(node *t) {
  cout << "look" << endl;
  cout << "地址： " << &t << endl;
  cout << "地址里的值： " << t << endl;
}

void init(node *& t) {
  cout << "init" << endl;
  cout << "地址： " << &t << endl;
  cout << "地址里的值： " << t << endl;
  cout << "new 一下" << endl;
  t       = new node;
  t->val  = 0;
  t->next = NULL;
  t->pre  = NULL;
  cout << "地址： " << &t << endl;
  cout << "地址里的值： " << t << endl;
}

int main() {
  node *head = NULL;

  cout << "head的地址和值"  << endl;
  cout << "地址： " << &head << endl;
  cout << "地址里的值： " << head << endl;
  look(head);
  init(head);
  look(head);
}

void del(node *& t) {
  if (t != NULL) {
    del(t->next);
    delete t;
    t = NULL;
  }
}

void insert(node *t, int x) {
  node *p = new node;

  p->val  = x;
  t->next = p;
  p->pre  = t;
  p->next = NULL;
}

void add(node *t, int x) {
  t->val += x;
}

void print(node *head) {
  node *p = head;

  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
}

void init1(node *t) {
  cout << "init" << endl;
  cout << "地址： " << &t << endl;
  cout << "地址里的值： " << t << endl;
  cout << "new 一下" << endl;
  t       = new node;
  t->val  = 0;
  t->next = NULL;
  t->pre  = NULL;
  cout << "地址： " << &t << endl;
  cout << "地址里的值： " << t << endl;
}
