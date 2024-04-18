#include <iostream>
using namespace std;

class FruitSeller {
private:
    //����� ����
    const int APPLE_PRICE = 1000;
    //����� ����
    int numOfApple;
    //���
    int myMoney;
public:
    //������
    FruitSeller(const int &num, const int &money)
    :numOfApple{num}, myMoney{money} {}
    //��� �Ǹ�(�Է�:��, ����:��/����ǰ��� = ����ǰ��� �������� ����������� ����, �������� ��꿡�� ����  ���� ���ϱ�, ��ȯ:����� ����)
    int saleApple(const int &money) {
      int num = money / APPLE_PRICE;
      numOfApple -= num;
      myMoney += money;
      return num;
    }
    //�Ǹ���Ȳ
    void showSaleResult() const{
      cout<<"���� ���: "<<numOfApple<<endl;
      cout<<"�Ǹ� ����: "<<myMoney<<endl;
    }
};

class FruitBuyer {
private:
    //���
    int myMoney;
    //����� ����
    int numOfApple = 0;
public:
    //������
    FruitBuyer(const int &money):myMoney{money} {}
    //�������(�Է�:�Ǹ��ڰ�ü, �󸶳�ġ��, ����:�Ǹ��ڰ�ü�� ����ǸŸ� ȣ�� ����� ��ȯ�ް� �׸�ŭ ��������� ���ϸ�ȴ�. ����� ����(�󸶳�ġ��), ��ȯ:����)
    void buyApples(FruitSeller &seller, const int &money) {
      int num = seller.saleApple(money);
      numOfApple += num;
      myMoney -= money;
    }
    //������Ȳ
    void showBuyResult() const {
      cout<<"��� ����: "<<numOfApple<<endl;
      cout<<"���� �ܾ�: "<<myMoney<<endl;
    }
};


int main() {
  FruitSeller seller1(20, 5000);
  FruitSeller seller2(20, 6000);
  FruitBuyer buyer1(5000);
  FruitBuyer buyer2(5000);
  buyer1.buyApples(seller1, 2000);
  cout<<"���� �Ǹ��ڵ��� ��Ȳ"<<endl;
  seller1.showSaleResult();
  seller2.showSaleResult();
  cout<<"���� �����ڵ��� ��Ȳ"<<endl;
  buyer1.showBuyResult();
  buyer2.showBuyResult();
  return 0;
}
