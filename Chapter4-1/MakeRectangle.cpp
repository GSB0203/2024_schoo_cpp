//Ŭ���� ���� ��Ģ
//1. private���� ��������� ���´�.(������ �� ���̵��� ����ȭ)
//2. public ������ �� ����Լ��� ���´�.
//3. �����ڴ� ��������� �ʱ�ȭ�ϴ� �������Ѵ�.
//4. ������ �� ����������� �Ű������� ���𰡸� ���� ������ �׻� �����ڷ� �޴´�.(���ʿ��� �޸𸮰��� ���縦 �����ϱ� ���ؼ�)
//5. �����ڷ� �ʱ�ȭ ��ų���� {} �ȿ��� ��Ű�� ���� ������ �̸� ���� :�� ���δ��� �� ������ �ʱ�ȭ ��Ų��.
//6. �Ű������� ���� ������ ���� ���� ���ٸ� const�� ���δ�.(�ڵ� ������ ������)
//7. ����Լ����� ��� ���� ������ ������ ���� ���ٸ�(�ܼ��� �ҷ����ų� ��¸� �� ���) const�� ���δ�.

#include <iostream>
using namespace std;

class Point {
private:
    //x��ǥ
    int x;
    //y��ǥ
    int y;
public:
    //������(����������� �ʱ�ȭ�����ִ� ����)
    Point(const int xPos, const int yPos):x{xPos}, y{yPos} {}

    //x, y �� �ҷ����� �Լ�(Get)
    int getX() const {
      return x;
    }

    int getY() const {
      return y;
    }

    ///x, y �� �ҷ����� �Լ�(Set)
    void setX(int &xPos) {
      x = xPos;
    }

    void setY(int &yPos) {
      y = yPos;
    }

};


class Rectangle {
private:
    //���簢�� �»�� ��ǥ
    Point upLeft;
    //���簢�� ���ϴ� ��ǥ
    Point lowRight;
public:
    //������(����������� �ʱ�ȭ�����ִ� ����)
    Rectangle(const Point &pos1, const Point &pos2): upLeft{pos1}, lowRight{pos2}{}
    //���簢�� �������
    void showRecInfo() const {
      cout<<"�� ���: "<<"["<<upLeft.getX()<<", ";
      cout<<upLeft.getY()<<"]"<<endl;
      cout<<"�� �ϴ�: "<<"["<<lowRight.getX()<<", ";
      cout<<lowRight.getY()<<"]"<<endl;
    }
};

int main() {
  int lx, ly, rx, ry;
  cout<<"�� ��� x, y ��ǥ�� �Է��ϼ��� : "; cin>>lx>>ly;
  cout<<"�� �ϴ� x, y ��ǥ�� �Է��ϼ��� : "; cin>>rx>>ry;
  Point pos1{lx, ly};
  Point pos2{rx, ry};
  Rectangle rec{pos1, pos2};
  rec.showRecInfo();

  return 0;
}
