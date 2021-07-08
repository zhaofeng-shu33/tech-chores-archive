N = 1000
A = Vector{Int64}()
for i = 1:(N-1)
    if mod(i, 3) == 0 || mod(i, 5) == 0
        append!(A, i)
    end
end
println(sum(A))