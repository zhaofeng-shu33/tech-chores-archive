function is_palindromic(x)
    x1 = string(x)
    reverse(x1) == x1
end
my_max = 0
for i=100:999
    for j=(i+1):999
        global my_max
        a = i * j
        if is_palindromic(a) && my_max < a
            my_max = a
        end
    end
end
println(my_max)
