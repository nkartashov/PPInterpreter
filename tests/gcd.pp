def rem(n, divisor):
    while n > divisor:
        n = n - (n / divisor) * divisor
    end
    return n
end

def gcd(a, b):
    if b == 0:
        return a
    end
    
    return gcd(b, rem(a, b))
end

print gcd(2038033, 231234)