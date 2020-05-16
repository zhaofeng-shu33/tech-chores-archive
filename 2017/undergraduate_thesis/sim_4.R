myfun<-function(){
lambda1=2
lambda2=2.3
lambda3=2.6
lambda4=2.9
p1=c(1,1)
p2=c(1,-1)
p3=c(-1,-1)
p4=c(1,-1)
sim_time=10000
result=matrix(,sim_time,2)
for (i in 1:sim_time){
p=2*runif(2)-1
u1=(p1-p)/norm(p1-p,'2')
u2=(p2-p)/norm(p2-p,'2')
u3=(p3-p)/norm(p3-p,'2')
u4=(p4-p)/norm(p4-p,'2')
I=lambda1*t(matrix(kronecker(u1,u1),2,2))
I=I+lambda2*t(matrix(kronecker(u2,u2),2,2))
I=I+lambda3*t(matrix(kronecker(u3,u3),2,2))
I=I+lambda4*t(matrix(kronecker(u4,u4),2,2))
tmp=eigen(I)$values
result[i,]=c(sqrt(1-tmp[2]/tmp[1]),sum(1/tmp))
}
result
}
system.time(myfun())
#plot(result[,1],result[,2])

#4/(lambda1+lambda2+lambda3+lambda4)




