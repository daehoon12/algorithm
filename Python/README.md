# Python  

## Input 방법
- N = int(sys.stdin.readline()) # int형으로 자료를 받음. int(input)은 시간이 오래 걸린다!  
- a= [list(sys.stdin.readline()) for _ in range(n)] # list를 input으로 받아 a라는 리스트에 저장한다.
   -> M x N 맵을 만들 때 사용.  
- matrix = [[0]* n for _ in range(n)]  # N x N의 Matrix를 만듦 N이 5면 [0,0,0,0,0]이 5개가 있다.  
- 한번에 두개 받는 방법 : N, M = map(int, (sys.stdin.readline().strip().split()))  
- 3 2 7 8 1 4 5 6으로 나오면 리스트로 저장한다. list(map(int, sys.stdin.readline().strip().split()))  
- 이차원 배열 (0으로 초기화) : [[0 for _ in range(N+1)] for _ in range(N+1)]  
ex) list(map(int, sys.stdin.readline().strip()))

## Output  
- List 앞에 곱하기 기호를 붙이면 정수형으로 출력이 된다!  

## Graph  
v = [list([]) for _ in range(N+1)] # 연결 리스트 만드는 방법


## 문자열  
- 문자열에 접근할 때는 슬라이싱을 이용하자.
