# 각 리스트 안에는 아래 순서로 데이터가 저장
# 앱의 이름, 가격, 화폐단위, 다운로두 회수, 앱 평점
row_1 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
row_2 = ['Instagram', 0.0, 'USD', 2161558, 4.5]
row_3 = ['Clash of Clans', 0.0, 'USD', 2130805, 4.5]
row_4 = ['Temple Run', 0.0, 'USD', 1724546, 4.5]
row_5 = ['Pandora - Music & Radio', 0.0, 'USD', 1126879, 4.0]

rating_sum = 0
app_data_set = [row_1, row_2, row_3, row_4, row_5]

# Q1 - for문 안에 5개 앱의 평점의 합을 rating_sum 저장하는 코드를 작성하세요

for data in app_data_set:
    rating_sum += data[4]
print(rating_sum)