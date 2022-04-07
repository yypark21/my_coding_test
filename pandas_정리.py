import pandas as pd

# PATH = 'addresses.csv'
# n = 1

# data = pd.read_csv(PATH)

# data.shape      # 몇 행 몇 열인지 (5, 6)
# data.head(n)    # 위에서부터 n개의 행 
# data.tail(n)    # 아래서부터 n개의 행

# data.info()
# #<class 'pandas.core.frame.DataFrame'>
# # RangeIndex: 5 entries, 0 to 4
# # Data columns (total 6 columns):
# #  #   Column             Non-Null Count  Dtype
# # ---  ------             --------------  -----
# #  0   John               4 non-null      object
# #  1   Doe                5 non-null      object
# #  2   120 jefferson st.  4 non-null      object
# #  3   Riverside          5 non-null      object
# #  4    NJ                5 non-null      object
# #  5    08075             5 non-null      int64
# # dtypes: int64(1), object(5)
# # memory usage: 368.0+ bytes
# # None

# data['John']
# data.John

# data = pd.DataFrame(columns=['도시','인구수'], index=range(10)) # 행렬 만들기

# # 1. 채워 넣기 list 사용
# city = ['서울', '부산', '인천', '대구', '대전', '광주', '수원', '울산',
#         '고양', '용인']
# population = [1111,2222,3333,44444,55555,66666,777,888,999,10000]

# data['도시']=city
# data['인구수']=population

# # 2. 채워 넣기 dictionary
# data_dict = {'도시': city, '인구수': population}
# data = pd.DataFrame(data_dict)

# # 데이터 저장
# data.to_csv('my_csv.csv', index=False, header=True) # index = True DataFrame의 인덱스가 하나의 컬럼으로 추가 
#                                                    # header = False  컬럼명을 제외하고 저장

# men = [1111,2222,3333,44444,55555,66666,777,888,999,10000]
# women = men 
# women = [x+y for x,y in zip(men, women)]
# data['남자'] = men
# data['여자'] = women
# data.loc[data.shape[0]] = data.sum()        # data.sum() 각 열의 합
# data.loc[data.shape[0]-1, '도시'] = '총합'
# ex) data[2:4] 2번 3번 읽어옴
# data.loc[[2,3], ['도시', '여자']] / data.loc[2:3 , '도시':'여자'] 
# data.iloc[[2,3],[2,3]] / data.iloc[2:8, 1:4]

