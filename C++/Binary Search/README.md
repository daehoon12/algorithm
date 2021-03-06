# Binary Search


## Binary Search

### 개념

 - 자료의 가운데에 있는 항목의 키 값과 비교하여 다음 검색의 위치를 결정하고  
   검색을 계속 진행하는 방법 (단 자료는 정렬된 상태)

- 목적 값을 찾을 때까지 반복 수행

- 검색 범위를 반으로 줄여가면서 보다 빠르게 검색 수행

### 과정

1. 자료의 중앙에 있는 원소 선택  
2. 선택한 값과 찾고자 하는 목표 값 비교
3-1. (목표 값 < 선택한 값)일 경우 자료 왼쪽 반에 대해 새로 검색 수행  
3-2. (목표 값 > 선택한 값)일 경우 자료 오른쪽 반에 대해 새로 검색 수행  
4. 찾고자 하는 값을 찾을 때까지 과정 반복


### 시간 복잡도 

- 탐색이 수행될 때 마다 탐색 범위가 반씩 줄어들어 **O(logN)** 의 시간 복잡도를 가진다.


## Parametric Search

 - 원하는 조건을 만족하는 값을 특정한 범위 내에서 알고싶은 경우에 사용
 
 - 임의의 값으로 계산 후 조건을 확인해가며 해를 구함 
 
 - 탐색은 Binary Search를 이용
