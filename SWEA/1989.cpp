/*
	20181011
	1989. 초심자의 회문 검사
*/
#include <iostream>

using namespace std;
 
int main() 
{
    int tc;
    int halfpoint;
    string tgstring;
    int size;
    int j=0;
  
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> tgstring;
        
	halfpoint = tgstring.size()/2; // 문자열의 중간 지점을 지정
        size = tgstring.size();
        j = 0;

        while (j < halfpoint) {
            if (tgstring[size-1-j] == tgstring[j]) j++; // 중간 지점을 기준으로 대칭되는 위치에 있는 문자를 서로 비교하여 같으면 인덱스 증가
            else break; // 다르면 break
        }
        
	// print result
        if (j == halfpoint) cout << "#" << i+1 << " 1" << endl; // j가 중간 지점까지 증가했으면 회문임을 나타냄
        else cout << "#" << i+1 << " 0" << endl;
    }
}
