def solution(s):
    words = s.split(' ')

    jaden_words = []
    for word in words:
        if word:
            jaden_words.append(word.capitalize())
        else:
            jaden_words.append('')
    
    return ' '.join(jaden_words)