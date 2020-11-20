# Sort
- 파이썬에 내장된 sort 함수는 O(NlogN)의 시간 복잡도를 가짐

## Sort와 sorted의 차이
- sorted()는 새로운 정렬된 목록을 반환하며, 원래 목록은 영향을 받지 않는다.
- .sort()는 목록을 반환하지 않으며, 원래 목록이 정렬이 된다.

## Lambda를 이용한 정렬  
- sort나 sorted 함수의 키 옵션에 lambda를 써서 정렬 할 수 있다. (Dictionary 자료형 정렬할 때 유용)  
ex) sorted(d.items(), key = lambda x: (-x[1], x[0]))는 Value의 내림차순으로 정렬하되, 같은 값이 나올 경우 key의 오름차순으로 정렬  
