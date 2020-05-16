a=matrix(c(0,0,0,pi/2,pi/2,0,pi/2,pi/2),2,4)
for(i in 1:4){
theta=a[1,i]
u1=c(cos(theta),sin(theta))
phi=a[2,i]
u2=c(cos(phi),sin(phi))
lambda_1=14;
lambda_2=13.8;
lambda_3=3;
lambda_4=2.8;
Sigma_0=matrix(c(lambda_1,0,0,lambda_2),2,2)#lambda_1>lambda_2
Sigma_1=matrix(c(lambda_3,0,0,lambda_4),2,2)#lambda_3>lambda_4
epsilon=12.2

f4=matrix(,4,4)
f4[1:2,1:2]=Sigma_0+epsilon*matrix(kronecker(u1,u1),2,2)
f4[3:4,3:4]=Sigma_1+epsilon*matrix(kronecker(u2,u2),2,2)
f4[1:2,3:4]=-epsilon*matrix(kronecker(u2,u1),2,2)
f4[3:4,1:2]=-epsilon*matrix(kronecker(u1,u2),2,2)
print(c(theta,phi,sum(1/eigen(f4)$values)))
}
myc=c(lambda_1,lambda_2,lambda_3,lambda_4)
pro=exp(sum(log(myc)))
myc2=c(cos(theta),sin(theta),cos(phi),sin(phi))
denom=1+epsilon*sum(myc2^2*(1/myc))
numu=sum(1/myc)
numu=numu+epsilon*cos(theta)^2*(sum(1/myc)-1/lambda_1)/lambda_1
numu=numu+epsilon*sin(theta)^2*(sum(1/myc)-1/lambda_2)/lambda_2
numu=numu+epsilon*cos(phi)^2*(sum(1/myc)-1/lambda_3)/lambda_3
numu=numu+epsilon*sin(phi)^2*(sum(1/myc)-1/lambda_4)/lambda_4


 
result<-eigen(f4)
#f4=result$vectors%*%diag(result$values)%*%t(result$vectors)
f5=f4
#EFIM=f4[1:2,1:2]-f4[1:2,3:4]%*%solve(f4[3:4,3:4])%*%f4[1:2,3:4]
#EFIM=solve(f4[3:4,3:4]-f4[1:2,3:4]%*%solve(f4[1:2,1:2])%*%f4[1:2,3:4])
EFIM=matrix(c(1,0,0,1),2,2)
f5[1:2,1:2]=f4[1:2,1:2]-EFIM
f5[3:4,3:4]=f4[3:4,3:4]-EFIM
rankMatrix(f5)
#sum(result$values)/(result$values[1]*result$values[2])
#result<-solve(matrix(c(1,0,0,1),2,2)+matrix(kronecker(u1,u1),2,2))
#f4<-matrix(,4,4)
#s1=sin(pi/3)
f_tosolve<-function(x){
c(c1^4*(1-x[3])+2*c1^3*s1*x[2]+c1^2*s1^2*(1-x[1])-((1-x[1])*(1-x[3])-x[2]^2)*(2-x[1]),
c1^2*s1^2*(1-x[3])+2*c1*s1^2*x[2]+s1^4*(1-x[1])-((1-x[1])*(1-x[3])-x[2]^2)*(2-x[3]),
c1^3*s1*(1-x[3])+2*c1^2*s1^2*x[2]+c1*s1^3*(1-x[1])-((1-x[1])*(1-x[3])-x[2]^2)*(-x[2]))
}
