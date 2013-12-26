def divides(n, d):
    res = n / d
    if res * d == n:
        return 1
    end
    return 0
end

def pow(a, n):
if n == 0:
    return 1
end
if n == 1:
    return a
end

if divides(n, 2) == 1:
    return pow(a * a, n / 2)
end
return a * pow(a * a, (n - 1) / 2)
end

print pow(3, 13)