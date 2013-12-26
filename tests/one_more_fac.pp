# one_more_fib.pp
# вычисление n-того числа Фибоначчи на PP
def fac(n):
   if n <= 1:
      return 1
end
   return n * fac(n-1) # ok, рекурсивные функции допустимы
end

lol = 11
print fac(lol)