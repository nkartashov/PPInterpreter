# rec.pp
# пример взаимной рекурсии
def foo(n):
   if n > 0:
       return bar(n - 1)
end 
end
def bar(n):
   if n > 0:
       return foo(n - 1)
   end
end
print foo(10)  # напечататет 0, foo и bar определены, а порядок не важен