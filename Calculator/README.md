# 설명
    간단한 계산기 MFC 프로그램
-------------------------------------
### 기능
    1. +
    2. -
    3. *
    4. /
### 동작사진
![20201219_153830](https://user-images.githubusercontent.com/54137044/102683351-b6959400-4213-11eb-95b7-7112cee4e0da.png)

### 활용코드
    ON_BN_CLICKED(IDC_BUTTON1, &Cmy1Dlg::OnBnClickedButton1) :  버튼 클릭
    Do.AppendChar('1');     : 문자열 추가
    UpdateData(0);          : 최신화
    연산자 중복 판단 코드     <- my1Dlg.cpp line344
     