#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;

class Solution {  //�Ż���1.ֻ��һ���ַ�ʱ�����Բ���find()����forѭ�����У���Ϊfind()ƽ��ʱ�临�Ӷ���O(m+n)
	              //     2.����ʹ��stoi()��stringתint���������Բ���c_str()
	              //     3.intתstring������to_string()
public:
	string complexNumberMultiply(string a, string b) {
		string plus = "+";
		string ap1, ap2, bp1, bp2, rp1, rp2;
		stringstream stream;
		int an1, an2, bn1, bn2, rn1, rn2;
		int index;

		index = a.find(plus);
		ap1 = a.substr(0, index);
		ap2 = a.substr(index + 1, a.length() - 1); 
		index = b.find(plus);
		bp1 = b.substr(0, index);
		bp2 = b.substr(index + 1, b.length() - 1);
		cout << ap1 << " " << ap2 << endl;
		cout << bp1 << " " << bp2 << endl;

		an1 = atoi(ap1.c_str());
		an2 = atoi(ap2.c_str());
		bn1 = atoi(bp1.c_str());
		bn2 = atoi(bp2.c_str());
		rn1 = an1 * bn1 - an2 * bn2;
		rn2 = an1 * bn2 + an2 * bn1;
		cout << rn1 << " " << rn2 << endl;
		stream << rn1;
		stream >> rp1;
		stream.clear();
		stream << rn2;
		stream >> rp2; 
		cout << rp1 << " " << rp2 <<endl;

		return rp1 + "+" + rp2 + "i";
	}
};