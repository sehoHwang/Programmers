app_list = [
['Facebook', '3.5', '3.5', '95.0', '4+', 'Social Networking', '37', '1', '29', '1'], 
['Instagram', '4.5', '4.0', '10.23', '12+', 'Photo & Video', '37', '0', '29', '1'], 
['Clash of Clans', '4.5', '4.5', '9.24.12', '9+', 'Games', '38', '5', '18', '1'], 
['Temple Run', '4.5', '4.0', '1.6.2', '9+', 'Games', '40', '5', '1', '1'], 
['Pandora - Music & Radio', '4.0', '4.5', '8.4.1', '12+', 'Music', '37', '4', '1', '1'], 
['Pinterest', '4.5', '4.0', '6.26', '12+', 'Social Networking', '37', '5', '27', '1'], 
['Bible', '4.5', '5.0', '7.5.1', '4+', 'Reference', '37', '5', '45', '1'], 
['Candy Crush Saga', '4.5', '4.5', '1.101.0', '4+', 'Games', '43', '5', '24', '1'], 
['Spotify Music', '4.5', '4.5', '8.4.3', '12+', 'Music', '37', '5', '18', '1'], 
['Angry Birds', '4.5', '3.0', '7.4.0', '4+', 'Games', '38', '0', '10', '1'], 
['Subway Surfers', '4.5', '4.0', '1.72.1', '9+', 'Games', '38', '5', '1', '1'], 
['Fruit Ninja Classic', '4.5', '4.0', '2.3.9', '4+', 'Games', '38', '5', '13', '1'], 
['Solitaire', '4.5', '4.5', '4.11.2', '4+', 'Games', '38', '4', '11', '1'], 
['CSR Racing', '4.5', '4.5', '4.0.1', '4+', 'Games', '37', '5', '10', '1'], 
['Crossy Road', '4.5', '4.5', '1.5.4', '9+', 'Games', '38', '5', '13', '1'], 
['Gods Among Us', '4.5', '4.5', '2.15.1', '12+', 'Games', '39', '5', '13', '1'], 
['Hay Day', '4.5', '4.5', '1.33.134', '4+', 'Games', '38', '5', '18', '1'], 
['Clear Vision (17+)', '4.5', '4.5', '1.1.3', '17+', 'Games', '43', '5', '1', '1'], 
['Minecraft', '4.5', '4.5', '1.1', '9+', 'Games', '37', '1', '11', '1']]

games_social_ratings = []

# Q4 - for문 안에 장르가 'Social Networking' 이거나 'Games'인 앱들의 평점만 추출하여 games_social_ratings 변수에 저장하세요
# app_list 중첩 리스트 변수 내의 각 세부 리스트 데이터에서 평점은 1번 인덱스, 장르는 5번 인덱스에 데이터가 저장 되어 있습니다.
# float()함수를 사용하여 문자형 데이터인 평점을 실수형 데이터로 형 변환 해야 합니다.
# for문이 종료된 후 games_social_ratings 리스트에는 총 15개의 평점이 저장되어 있어야 합니다.
for row in app_list:
  if row[5] == "Social Networking" or row[5] =="Games":
    games_social_ratings.append(row[1])
print(games_social_ratings)