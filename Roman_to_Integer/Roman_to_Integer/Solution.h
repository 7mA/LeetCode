#include<iostream>
#include<string>
using namespace std;

class Solution {  //�Ž⣺���������ֵĹ���ԭ����ͦ��Ҫ�ģ����Դ�ͷ��β���������
	              //û��ע�⵽���Ӵ�ֻ�п�����һλ��һʮ�١��������ص�
public:
	int romanToInt(string s) {
		int res = addLR(s);
		return res;
	}

	int addLR(string s){
		if (s.length() == 0){
			return 0;
		}

		int pos = s.find("M");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 1000 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("D");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 500 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("C");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 100 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("L");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 50 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("X");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 10 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("V");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 5 - addLR(lsub) + addLR(rsub);
		}

		pos = s.find("I");
		if (pos != -1){
			string lsub = s.substr(0, pos);
			string rsub = s.substr(pos + 1);
			return 1 - addLR(lsub) + addLR(rsub);
		}
	}
};