#include "LinkedList.h"

int main() {
	//SingleLinkedList<int> a;
	SingleLinkedList<int> a{ 1,2,3,4,5 };
	int a_get = a.getCurrentVal();
	std::cout << a_get << std::endl;		//���ԡ�ȡֵ�������Ƿ���ȷ���������ܵĿ��������(//����)��ÿ�����9��
	//SingleLinkedList<char> b;
	SingleLinkedList<char> b{ 'a','c','e' };
	b.setCurrentVal('g');
	b.printList();							//���ԡ�����ֵ�������Ƿ���ȷ���������ܵĿ��������(//����)��ÿ�����9��
	SingleLinkedList<char> e;
	std::cout << b.isEmpty() << " "
			  << e.isEmpty() << std::endl;  //���ԡ��������жϡ������Ƿ���ȷ��18��
	SingleLinkedList<double> c1;
	SingleLinkedList<double> c2{ 1.5,2.0,9.0,4.7 };
	SingleLinkedList<double> c3;
	c3 = c2;
	c1.insert(3.0);
	c2.insert(8.8);
	bool f_c3 = c3.find(2.0);
	c3.insert(8.8);
	c1.printList();
	c2.printList();
	c3.printList();							 //���ԡ����롿�����Ƿ���ȷ��ÿ�����6��
	e.remove();
	c1.remove();
	bool f = c2.find(9.0);
	c2.remove();
	e.printList();
	c1.printList();
	c2.printList();							//���ԡ�ɾ���������Ƿ���ȷ��ÿ�����6��
	return 0;
}