def solution(s):
    LENGTH = len(s)
    cand = [LENGTH]  
    for size in range(1, (LENGTH/2)+1):
        compressed = ""
        
        splited = [s[i:i+size] for i in range(0, LENGTH, size)]
        count = 1

        for j in range(1, len(splited)):
            prev, cur = splited[j-1], splited[j]
            if prev == cur: 
                count += 1
            else:  
                compressed += (str(count) + prev) if count > 1 else prev
                count = 1  
        compressed += (str(count) + splited[-1]) if count > 1 else splited[-1]
        
        cand.append(len(compressed))
    
    return min(cand)
