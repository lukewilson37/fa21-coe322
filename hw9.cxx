#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include<memory>
using std::shared_ptr;
using std::make_shared;

class Node {
private:
  int datavalue{0};
  shared_ptr<Node> tail_ptr{nullptr};
public:
  Node() {};
  Node(int value): datavalue(value) {};
  void set_value(int value){ datavalue = value; };
  int value() { return datavalue; };
  bool has_next() { return tail_ptr != nullptr; }
  int list_length() {
    if (!has_next()) { return 1; }
    else return 1+tail_ptr->list_length();
  }
  void set_tail( shared_ptr<Node> tail ) { tail_ptr = tail; }
  void append( shared_ptr<Node> value ) {
    if( has_next() ) { tail_ptr->append(value); }
    else { set_tail( value ); }
  }

  void print() {
    cout << value();
    if ( has_next() ) { 
      cout << ", ";
      tail_ptr->print();
    }
    else { cout << endl; }
  }

  void insert(shared_ptr<Node> new_value) {
    if ( new_value->value() < value() ) {
      shared_ptr<Node> tail_tail = tail_ptr;
      set_tail(make_shared<Node>(value()));
      tail_ptr->set_tail(tail_tail);
      datavalue = new_value->value();
    } else { 
      if( !has_next() ) { set_tail( new_value ); }
      else { tail_ptr->insert(new_value); };
    };
  }
  void remove_tail() { tail_ptr = nullptr; };
};


int main() {

  int num;
  //cin >> num;
  Node list;
  while ( cin >> num ) {
    if (num == 0) {
      list.print();
      cin >> num;
      list.set_value(num);
      list.remove_tail();
    } else {
      list.insert(make_shared<Node>(num));
      list.print();
    }
  };
  return 0;
}
