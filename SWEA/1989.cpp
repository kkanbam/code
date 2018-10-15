/*
        20181011
        1989. 초심자의 회문 검사

        1. 각 글자를 거울상 대칭에 있는 문자와 비교하기 위한 점화식을 세움
        2. 비교 시 같지 않은 글자면 return
        3. 글자 인덱스가 halfpoint까지 증가하지 않았다면 중간에 상이한 글자가 있었던 것이므로 palindrome이 아님
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
