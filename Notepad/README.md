# 설명 
    간단한 노트패드
---------------------------------
### 동작
    일반적인 텍스트 입력기와 같음 저장은 구현하지 않음
### 동작사진
![Capture](https://user-images.githubusercontent.com/54137044/102683504-058ff900-4215-11eb-9ef0-f2526c1fe5f4.png)
### 사용코드
    word.AppendChar(nChar);     -> myView.cpp line 118 : 문자추가
	Invalidate();               -> myView.cpp line 119 : 화면출력 함수
    word.Delete(word.GetLength()-1,1);      -> myView.cpp line 137 : 문자삭제