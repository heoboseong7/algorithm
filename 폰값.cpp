#include <bits/stdc++.h>

using namespace std;

int main()
{
    int gongsi;           // 공시지원금
    int phone;            // 할부원금(공시 미포함)
    int charge1, charge2; // 의무 요금제, 사용할 요금제
    int duty;             // 의무 요금제 유지기간
    int period;           // 총 이용 개월 수

    cout << "의무 요금제 :";
    cin >> charge1;
    cout << "변경할 요금제 :";
    cin >> charge2;
    cout << "할부원금 : ";
    cin >> phone;
    cout << "공시지원금 :";
    cin >> gongsi;
    cout << "요금제 유지 개월 수 :";
    cin >> duty;
    cout << "총 이용 개월 수 :";
    cin >> period;

    int total1 = charge1 * duty + charge2 * (period - duty) + phone - gongsi; // 공시
    int total2 = (charge1 * duty + charge2 * (period - duty)) * 0.75 + phone; // 선약
    cout << "공시 총 비용: " << total1 << '\n'
         << "선약 총 비용: " << total2;
    return 0;
}