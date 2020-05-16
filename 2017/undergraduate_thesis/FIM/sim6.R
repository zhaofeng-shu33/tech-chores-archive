u=matrix(c(1,0,-1,1,0,-1),nrow=2)
div=3
u=matrix(0,ncol=div,nrow=2)
for(i in 1:div){
u[,i]=c(cos(2*pi*i/div)-cos(2*pi*(i-1)/div),sin(2*pi*i/div)-sin(2*pi*(i-1)/div))
}
node_num=dim(u)[2];
#normalization
for(i in 1:node_num){
u[,i]=u[,i]/sqrt(norm(u[,i],'2'))
}
lambda=0.2
#construct FIM
FIM=matrix(0,nrow=2*node_num,ncol=2*node_num)
for(i in 1:node_num){
FIM[(2*i-1):(2*i),(2*i-1):(2*i)]=lambda*diag(c(1,1))+
matrix(kronecker(u[,i],u[,i]),ncol=2)+
matrix(kronecker(u[,(1+i%%node_num)],u[,(1+i%%node_num)]),ncol=2)
FIM[(2*i-1):(2*i),((1+i%%node_num)*2-1):((1+i%%node_num)*2)]=-matrix(kronecker(u[,(1+i%%node_num)],u[,(1+i%%node_num)]),ncol=2)
FIM[((1+i%%node_num)*2-1):((1+i%%node_num)*2),(2*i-1):(2*i)]=-matrix(kronecker(u[,(1+i%%node_num)],u[,(1+i%%node_num)]),ncol=2)
}
f_FIM=solve(solve(FIM)[(node_num*2-1):(node_num*2),(node_num*2-1):(node_num*2)])

#LU decomposition
U=matrix(0,nrow=(2*node_num-2),ncol=(2*node_num-2))
L=diag(seq(1,1,length=(node_num*2-2)))
U[1:2,1:2]=FIM[1:2,1:2]
for(i in 1:(node_num-2)){
L[(2*i+1):(2*i+2),(2*i-1):(2*i)]=FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]%*%solve(U[(2*i-1):(2*i),(2*i-1):(2*i)])
U[(2*i+1):(2*i+2),(2*i+1):(2*i+2)]=FIM[(2*i+1):(2*i+2),(2*i+1):(2*i+2)]-L[(2*i+1):(2*i+2),(2*i-1):(2*i)]%*%FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]
U[(2*i-1):(2*i),(2*i+1):(2*i+2)]=FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]
}

#UL decomposition
#UPrime,LPrime
UPrime=matrix(0,nrow=(2*node_num-2),ncol=(2*node_num-2))
LPrime=diag(seq(1,1,length=(node_num*2-2)))
UPrime[(node_num*2-3):(node_num*2-2),(node_num*2-3):(node_num*2-2)]=FIM[(node_num*2-3):(node_num*2-2),(node_num*2-3):(node_num*2-2)]
for(i in (node_num-2):1){
LPrime[(2*i-1):(2*i),(2*i+1):(2*i+2)]=FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]%*%solve(UPrime[(2*i+1):(2*i+2),(2*i+1):(2*i+2)])
UPrime[(2*i-1):(2*i),(2*i-1):(2*i)]=FIM[(2*i-1):(2*i),(2*i-1):(2*i)]-LPrime[(2*i-1):(2*i),(2*i+1):(2*i+2)]%*%FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]
UPrime[(2*i+1):(2*i+2),(2*i-1):(2*i)]=FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]
}

first_term=FIM[(node_num*2-1):(node_num*2),(node_num*2-1):(node_num*2)]-
FIM[(node_num*2-1):(node_num*2),(node_num*2-3):(node_num*2-2)]%*%
solve(U[(node_num*2-3):(node_num*2-2),(node_num*2-3):(node_num*2-2)])%*%
FIM[(node_num*2-1):(node_num*2),(node_num*2-3):(node_num*2-2)]-
FIM[1:2,(node_num*2-1):(node_num*2)]%*%
solve(UPrime[1:2,1:2])%*%
FIM[1:2,(node_num*2-1):(node_num*2)]
second_term=FIM[1:2,(node_num*2-1):(node_num*2)]
third_term=FIM[1:2,(node_num*2-1):(node_num*2)]
for(i in 1:(node_num-1)){
second_term=FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]%*%solve(U[(2*i-1):(2*i),(2*i-1):(2*i)])%*%second_term
third_term=third_term%*%solve(U[(2*i-1):(2*i),(2*i-1):(2*i)])%*%FIM[(2*i-1):(2*i),(2*i+1):(2*i+2)]
}
my_f_FIM=first_term+((-1)^(node_num-1))*(second_term+third_term)
