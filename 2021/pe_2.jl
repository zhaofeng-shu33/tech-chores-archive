N = 4000000
A = [1, 2]
while last(A) <= N
    append!(A, last(A) + A[end-1])
end
my_sum = 0
for i=1:length(A)
    if mod(A[i], 2) == 0
        global my_sum
        my_sum = my_sum + A[i]
    end
end
println(my_sum)
