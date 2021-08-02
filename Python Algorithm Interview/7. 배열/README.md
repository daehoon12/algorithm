# 배열
- 크기를 지정하고 해당 크기만큼의 연속된 메모리 공간을 할당받는 작업을 수행하는 선형 자료구조  

## 시간 복잡도  

### 1. Search  
- Index를 통한 Search -> O(1)  

### 2. Insert  
- Best : 배열의 맨 뒤에 원소를 삽입하는 경우 -> O(1)  
- Worst : 배열의 맨 앞에 원소를 삽입하는 경우 -> 모든 원소를 한 칸씩 뒤로 밀어야 함 O(N)  

### 3. Delete
- Best : 배열의 맨 뒤에 원소를 삭제하는 경우 -> O(1)  
- Worst : 배열의 맨 앞에 원소를 삭제하는 경우 -> 모든 원소를 한 칸씩 로 밀어야 함 O(N)  

## 투 포인터 (Two Pointers) Algorithm  
- **시작점과 끝점 or 왼쪽 포인터와 오른쪽 포인터 두 지점을 기준**으로 하는 문제 풀이 전략  
- 선형 자료구조에서 풀이 시간을 줄여주는 알고리즘.  

## 문제  
[5. Longest Palindromic Substring]: https://leetcode.com/problems/longest-palindromic-substring/
