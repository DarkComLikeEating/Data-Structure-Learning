/*
顺序串
生成串 StrAssign(&s, cstr)
销毁串 DestroyStr(&s)
串的复制 StrCopy(&s, t)
判断串相等 StrEqual(s, t)
求串长 StrLength(s)
串的连接 Concat(s, t)
求子串 SubStr(s, i, j)
子串的插入 InsStr(s1, i, s2)
子串的删除 DelStr(s, i, j)
子串的替换 RepStr(s, i, j, t)
输出串 DispStr(s)
*/

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	char data[Maxsize];
	int length;
} SqString;

void StrAssign(SqString &s, char cstr[]) {
	int i;
	for (i = 0; cstr[i] != '\0'; i ++) {
		s.data[i] = cstr[i];
	}
	s.length = i;
}

void DestroyStr(SqString &s) {
	
}

void StrCopy(SqString &s, SqString t) {
	for (int i = 0; i < t.length; i ++) {
		s.data[i] = t.data[i];
	}
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t) {
	bool same = true;
	if (s.length != t.length) {
		same = false;
	} else {
		for (int i = 0; i < s.length; i ++) {
			if (s.data[i] != t.data[i]) {
				same = false;
				break;
			}
		}
	}
	return same;
}

int StrLength(SqString s) {
	return s.length;
}

SqString Concat(SqString s, SqString t) {
	SqString str;
	str.length = s.length + t.length;
	for (int i = 0; i < s.length; i ++) {
		str.data[i] = s.data[i];
	} 
	for (int i = 0; i < t.length; i ++) {
		str.data[s.length + i] = t.data[i];
	}
	
	return str;
}

SqString SubStr(SqString s, int i, int j) {
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
		return str;
	}
	for (int k = i - 1; k < i + j - 1; k ++) {
		str.data[k - i + 1] = s.data[k];
	}
	str.length = j;
	return str;
}

SqString InsStr(SqString s1, int i, SqString s2) {
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1) {
		return str;
	}
	for (int j = 0; j < i - 1; j ++) {
		str.data[j] = s1.data[j];
	}
	for (int j = 0; j < s2.length; j ++) {
		str.data[i + j - 1] = s2.data[j];
	}
	for (int j = i - 1; j < s1.length; j ++) {
		str.data[s2.length + j] = s1.data[j];
	}
	str.length = s1.length + s2.length;
	return str;
}

SqString DelStr(SqString s, int i, int j) {
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1) {
		return str;
	}
	for (int k = 0; k < i - 1; k ++) {
		str.data[k] = s.data[k];
	}
	for (int k = i + j - 1; k < s.length; k ++) {
		str.data[k - j] = s.data[k];
	}
	str.length = s.length - 1;
	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t) {
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j - 1 > s.length) {
		return str;
	}
	for (int k = 0; k < i - 1; k ++) {
		str.data[k] = s.data[k];
	}
	for (int k = 0; k < t.length; k ++) {
		str.data[i + k - 1] = t.data[k];
	}
	for (int k = i + j - 1; k < s.length; k ++) {
		str.data[t.length + k - j] = s.data[k];
	}
	str.length = s.length - j + t.length;
	return str;
}

void DispStr(SqString s) {
	if (s.length > 0) {
		for (int i = 0; i < s.length; i ++) {
			cout << s.data[i];
		}
		cout << endl;
	}
}
