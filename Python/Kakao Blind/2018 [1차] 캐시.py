def solution(cacheSize, cities):
    answer = 0
    
    cache = []
    
    new_cities = [i.lower() for i in cities]
    
    for c in new_cities:
        if c not in cache:
            cache.append(c)
            if len(cache) > cacheSize:
                del cache[0]
            answer+=5
        else:
            cache.remove(c)
            cache.append(c)
            answer+=1
    
    return answer