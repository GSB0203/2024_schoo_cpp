//���̻� ������ ����������. �Լ��� ������ �� �����ڸ� �����ϼ���.

#include <iostream>
using namespace std;

void swapByPtr(int *ptr1, int *ptr2);
void swapByRef(int &ref1, int &ref2);

int main() {
  int val1 = 10;
  int val2 = 20;
  cout<<val1<<" "<<val2<<endl;
  swapByPtr(&val1, &val2);
  cout<<val1<<" "<<val2<<endl;
  swapByRef(val1, val2);
  cout<<val1<<" "<<val2<<endl;
  return 0;
}

void swapByPtr(int *ptr1, int *ptr2) {
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

void swapByRef(int &ref1, int &ref2) {
  int tmp = ref1;
  ref1 = ref2;
  ref2 = tmp;
}

//�����͸� �����Ҷ��� int *ptr�̶�� ������ ���� ������ �ּҸ��ޱ����� &�� ������ �ٿ����Ѵ�
//�����ڸ� �����Ҷ��� int &ref�̶�� ������ ���� �׳� ������ �̸��� ������ ���̴�.