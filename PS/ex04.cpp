//N(2 <= N <= 100)���� ���̰� �Էµ˴ϴ�.
//�� N���� ��� �� ���� �������̰� ���� ���� ���� ��� �ϱ��? �ִ� ���� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.
//ex 10
//ex 1 2 3 4 5 6 7 8 9 10
//ex 9

#include <iostream>

using namespace std;

int main() {
  freopen("ex04_input.txt", "rt", stdin);
  int n, a;
  int max = 0, min = INT_MAX;
  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>a;
    if(a > max) max = a;
    if(a < min) min = a;
  }

  cout<<max - min<<endl;
}