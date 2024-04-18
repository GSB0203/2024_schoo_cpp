#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //STL ���͸� ������� �ʴ� ���ð��� �迭����
    int num[5];
  for (int i = 0; i < 5; ++i) {
    num[i] = i;
    cout<<num[i]<<" ";
  }
  cout<<endl;
    //STL ���͸� ������� �ʴ� ������ �迭 ����
    //C��� ��Ÿ�� - malloc, free
//    int* numPtr = (int*)malloc(sizeof(int)*5);
//    free(numPtr);
  //c++��Ÿ�� - new, delete
  int *numPtr = new int[5];
  for (int i = 0; i < 5; ++i) {
    numPtr[i] = i;
    cout<<numPtr[i]<<" ";
  }
  cout<<endl;
  delete []numPtr;

  //STL ���͸� ����� ���(������)
  vector<int> nums(5);
  for (int i = 0; i < 5; ++i) {
    nums[i] = i;
    cout<<nums[i]<<" ";
  }
  cout<<endl;

    //���� �ʱ�ȭ 2
    //vector<int> num2 = {0, 1, 2, 3, 4};

    //���� ���� �Լ���
  cout<<"----��� ���� ��----"<<endl;
  cout<<"���� ����� ���� : "<<nums.size()<<endl;  //������ ��� ���� ��ȯ
  nums.emplace_back(5);  //������ ������ ������ ����
  cout<<"���� ��� ���� ��----"<<endl;
    //size_t = unsigned long
  for (size_t i = 0; i < nums.size(); ++i) {
    cout<<nums[i]<<" ";
  }
  cout<<endl;
  nums.pop_back();  //������ ������ ��� ����
  cout<<"----��� ���� ��----"<<endl;
  for (size_t i = 0; i < nums.size(); ++i) {
    cout<<nums[i]<<" ";
  }
  cout<<endl;

    //���� ��ȸ���1 - �ε����� ����
  for(size_t idx = 0;idx < nums.size(); ++idx) {
    cout<<nums[idx]<<" ";
  }
  cout<<endl;

    //���� ���ͷ�����
  vector<int>::iterator itr;  //���͸� ��ȸ�� �� ����ϴ� ������
    //nums.begin(); : ù��° ����� �ּҰ�
    //nums.end()  ������ ����� �ּҰ� + 1
  itr = nums.begin();
  cout<<"ù��° ����� ����? : "<<*itr<<endl;
  itr = nums.end();
  cout<<"������ ����� ����? : "<<*(--itr)<<endl;

    //���� ��ȸ ��� 2 - ���ͷ����� Ȱ��(���� Ȱ��)
//  vector<int>::iterator itr2;
  for (auto itr2 = nums.begin(); itr2 < nums.end() ; itr2++) {
    cout<<*itr2<<" ";
  }
  cout<<endl;

    //���� ��ȸ ��� 3 - range for(���� ª��)
  for (auto num : nums) {
    cout<<num<<" ";
  }
  cout<<endl;
  return 0;
}


