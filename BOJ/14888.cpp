/*
    20181020
    14888. 연산자 끼워넣기 #브루트포스 #순열

    풀이:
    +, -, *, /를 각각 0, 1, 2, 3으로 정의하고
    세 번째 줄에 입력받은 횟수 만큼 select_arr vector에 적는다.
    예) 입력이 2 1 1 2 이라고 하면, select_arr에 0 0 1 2 3 3이라고 적는다.
    select_arr를 정렬한 다음, 모든 순열을 검색한다.

    주의:
    sum 초기화가 do ... while permutation loop 안에 들어가야 한다.
    push_back을 잘못 사용하면 vector array size가 늘어나면서 이상한 값이 들어간다. 자신 없으면 그냥 index로 대입하자.
    맨 마지막에 vector.clear()를 넣어주는 것을 잊지 말자 (백준 특이성)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j, op;
    int arr_size;
    int sum = 0;
    int min = 1000000000;
    int max = -1000000000;
    
    cin >> n;
    
    vector<int> target_num(n);
    vector<int> select_arr(n-1);

    for (i = 0; i < n; i++) {
        cin >> target_num[i];
    }

    i = 0;
    
    cin >> op; // +
    if (op >= 1) {
        for (j = 0; j < op; j++)
            select_arr[i++] = 0; // + = 0
    }

    cin >> op; //  -
    if (op >= 1) {
        for (j = 0; j < op; j++)
            select_arr[i++] = 1; // - = 1
    }
    
    cin >> op; //  *
    if (op >= 1) {
        for (j = 0; j < op; j++)
            select_arr[i++] = 2; // * = 2
    }
    
    cin >> op; //  /
    if (op >= 1) {
        for (j = 0; j < op; j++)
            select_arr[i++] = 3; // / = 1
    }
    
    sort(select_arr.begin(), select_arr.end());
    
    do {        
        sum = target_num[0];
        
        //cout << j << '\n';
        //for (i = 0; i < n-1; i++)
            //cout << select_arr[i] << " ";
       // cout << '\n';
        
        for (i = 1; i < n; i++) {
            if (select_arr[i-1] == 0) sum += target_num[i];
            else if (select_arr[i-1] == 1) sum -= target_num[i];
            else if (select_arr[i-1] == 2) sum *= target_num[i];
            else if (select_arr[i-1] == 3) sum /= target_num[i];
        }

        if (sum < min) min = sum;
        if (sum > max) max = sum;
        
    } while (next_permutation(select_arr.begin(), select_arr.end()));
    
    cout << max << '\n';
    cout << min << '\n';
    
    target_num.clear();
    select_arr.clear();
}
