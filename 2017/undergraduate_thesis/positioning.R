p=t(matrix(c(0,0,5,0,3,2),2,3))
#p[i,] i anchor point
#unknown position point:
q=c(0.1,0.1)
sigma=0.2
A=matrix(0,2,2)
A[1,]=2*c(p[2,]-p[1,])
A[2,]=2*c(p[3,]-p[1,])
b=c(0,0)
u=c(0,0,0)

At=solve(t(A)%*%A)%*%t(A)
#unbiasness
tmp=matrix(0,30000,2)
for(j in 1:30000){
for(i in 1:3){
u[i]=+rnorm(1,sd=sigma)
}
b[1]=u[1]^2-u[2]^2+p[2,1]^2-p[1,1]^2+p[2,2]^2-p[1,2]^2
b[2]=u[1]^2-u[3]^2+p[3,1]^2-p[1,1]^2+p[3,2]^2-p[1,2]^2
tmp[j,]=At%*%b
}
xi=c(0,0,0)
for(i in 1:3){
xi[i]=4*sigma^2*norm(p[i,]-q,type='2')^2+2*sigma^4
}
covb=xi[1]*matrix(1,2,2)+diag(c(xi[2],xi[3]))
At=solve(t(A)%*%A)%*%t(A)
At%*%covb%*%t(At)
#CRLB
FIM=matrix(0,2,2)
for(i in 1:3){
FIM=FIM+matrix(kronecker(p[i,]-q,p[i,]-q),2,2)/norm(p[i,]-q,type='2')^2
}
CRLB=sigma^2*solve(FIM)


 