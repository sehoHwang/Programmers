# startswitch를 사용해 문자열을 포함하는지 찾는다.

# zip을 통해 여러 객체를 한번에 순회할 수 있다.

def solution(phone_book):
    
    phone_book.sort()
    
    for p2, p1 in zip(phone_book, phone_book[1:]):
        if p1.startswith(p2):
            return False
        
    return True