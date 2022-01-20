T = int(input())
for t in range(0,T):
    a,b,c = map(int, input().split())
    
    lowerBound = a
    numOfDigit = len(str(lowerBound))
    upperBound = 10**numOfDigit - 1
    currentNumberCount = int((upperBound - lowerBound) / b) + 1;
    currentDigitCount = currentNumberCount * numOfDigit
    
    while currentDigitCount < c:
        c -= currentDigitCount
        lowerBound += b * currentNumberCount
        numOfDigit += 1
        upperBound = 10**numOfDigit - 1
        currentNumberCount = int((upperBound - lowerBound) / b) + 1;
        currentDigitCount = currentNumberCount * numOfDigit
    
    numPos = int(c / numOfDigit)
    if c % numOfDigit == 0:
        numPos -= 1
        
    numC = lowerBound + b * numPos
    
    c = c - numPos * numOfDigit - 1
    
    s = str(numC)
    digit = s[c]
    print(digit)