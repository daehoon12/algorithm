# Euclidean Algorithm  

## GCD를 구하는 방법  
1. 2개의 자연수를 받아 GCD 받기위해 2부터 두 자연수 중 작은 자연수 까지 나누어보면서 가장 큰 공약수를 찾는 방법  
  - O(N)의 시간 복잡도  
2. 유클리드 호제법을 사용  
  - O(logN)
  
## Euclidean Algorithm  
- 2개의 자연수 a,b에 대해서 a를 b로 나눈 나머지를 r이라 하자 (단 a > b)  
-**a와 b의 GCD는 b와 r의 GCD와 같다.** 이 성질에 따라, b를 r로 나눈 나머지 r0를 구하고, 다시 r을 r0로 나눈 나머지를 구하는 과정을 반복해 나머지가 0이 되었을 때 나누는 수가 a와 b의 GCD이다.  

### 수도 코드  

![image](https://user-images.githubusercontent.com/32921115/104703165-56ced200-575a-11eb-8709-0466f37e3288.png)

## LCD를 구하는 법  
- LCD * GCD = a * b 공식을 이용  
- LCD = a * b / GCD  
