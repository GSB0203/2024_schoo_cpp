  //explicit : �������, implicit : ��������
  //ex) explicit conversion(����� ����ȯ) - �����Ϸ��� �򰥸��� �ʰ��ϱ� ���ؼ� �����ڰ� ���� ����ȯ ��Ű�� ���
  // int a = 3;, b = 4;
  // double c;
  // c = (double)a / b;
  //ex) implicit conversion(������ ����ȯ) - �����Ϸ��� �ڷ����� �� �´� ��Ȳ���� ���� �˾Ƽ� ����ȯ ��Ű�� ���
  // int a = 3;, b = 4;
  // double c;
  // c = a / b;

  //��� : ��������� ���α׷����� �ϴ°� ���� �ڵ��.

#include <iostream>
  using namespace std;

  class Cat {
  public:

      //�������� �Ű������� �ϳ��� ���� '=' �����ڰ� �����ϱ� ������ ������ǥ���� �������� ������ �տ� explicit�� �����־�� �Ѵ�.
      //�������� �Ű������� �ΰ� �̻��� ���� explicit�� �ٿ��� �ʿ䰡 ����.

    Cat(string name, int age):mName{std::move(name)}, mAge{age} {}
    void catInfo() {
      cout<<"������� �̸��� : "<<mName<<endl;
      cout<<"������� ���̴� : "<<mAge<<endl;
    };
  private:
    string mName;
    int mAge;
};

int main() {
  string str = "kitty";
  int num = 3;
  Cat kitty{str, num};
  kitty.catInfo();
  return 0;
}
