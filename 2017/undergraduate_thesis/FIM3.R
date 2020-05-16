J1Nb=matrix(c(1,0,0,1),2,2)
J2Nb=matrix(c(2,0,0,2),2,2)
J3Nb=matrix(c(3,0,0,3),2,2)

theta=0;
u1=c(cos(theta),sin(theta));
u2=c(cos(pi/3+theta),sin(pi/3+theta));
u3=c(cos(4*pi/3+theta),sin(4*pi/3+theta));
u12=(u1-u2)/norm(u1-u2,type='2')
u13=(u1-u3)/norm(u1-u3,type='2')
u23=(u2-u3)/norm(u2-u3,type='2')
C12=matrix(kronecker(u12,u12),2,2)
C13=matrix(kronecker(u13,u13),2,2)
C23=matrix(kronecker(u23,u23),2,2)
JC=matrix(,6,6)
JC[1:2,1:2]=J1Nb+C12+C13
JC[3:4,3:4]=J1Nb+C12+C23
JC[5:6,5:6]=J1Nb+C13+C23
JC[1:2,3:4]=-C12
JC[3:4,1:2]=-C12
JC[1:2,5:6]=-C13
JC[5:6,1:2]=-C13
JC[3:4,5:6]=-C23
JC[5:6,3:4]=-C23

%旋转不变的性质




n=4;
JC=matrix(0,2*n,2*n)
for(i in 1:(n-1)){
for(j in (i+1):n){
u1=c(cos(2*pi*i/n),sin(2*pi*i/n));
u2=c(cos(2*pi*j/n),sin(2*pi*j/n));
u12=(u1-u2)/norm(u1-u2,type='2')
C12=matrix(kronecker(u12,u12),2,2)
JC[(2*i-1):(2*i),(2*j-1):(2*j)]=-C12
JC[(2*j-1):(2*j),(2*i-1):(2*i)]=-C12
JC[(2*i-1):(2*i),(2*i-1):(2*i)]=JC[(2*i-1):(2*i),(2*i-1):(2*i)]+C12
JC[(2*j-1):(2*j),(2*j-1):(2*j)]=JC[(2*j-1):(2*j),(2*j-1):(2*j)]+C12
}
}

u13=(u1-u3)/norm(u1-u3,type='2')
u23=(u2-u3)/norm(u2-u3,type='2')
C12=matrix(kronecker(u12,u12),2,2)
C13=matrix(kronecker(u13,u13),2,2)
C23=matrix(kronecker(u23,u23),2,2)
JC=matrix(,6,6)
JC[1:2,1:2]=C12+C13
JC[3:4,3:4]=C12+C23
JC[5:6,5:6]=C13+C23
JC[1:2,3:4]=-C12
JC[3:4,1:2]=-C12
JC[1:2,5:6]=-C13
JC[5:6,1:2]=-C13
JC[3:4,5:6]=-C23
JC[5:6,3:4]=-C23


theta12=pi/3
u12=c(cos(theta12),sin(theta12))
C12=matrix(kronecker(u12,u12),2,2)

theta13=pi/4
u13=c(cos(theta13),sin(theta13))
C13=matrix(kronecker(u13,u13),2,2)

theta23=2*pi/3
u23=c(cos(theta23),sin(theta23))
C23=matrix(kronecker(u23,u23),2,2)

zeta12=1.5
zeta13=2
zeta23=3

JC=matrix(,6,6)
JC[1:2,1:2]=J1Nb+zeta12*C12+zeta13*C13
JC[3:4,3:4]=J2Nb+zeta12*C12+zeta23*C23
JC[5:6,5:6]=J3Nb+zeta13*C13+zeta23*C23
JC[1:2,3:4]=-zeta12*C12
JC[3:4,1:2]=-zeta12*C12
JC[1:2,5:6]=-zeta13*C13
JC[5:6,1:2]=-zeta13*C13
JC[3:4,5:6]=-zeta23*C23
JC[5:6,3:4]=-zeta23*C23


C1213=(matrix(kronecker(u12,u13),2,2)+matrix(kronecker(u13,u12),2,2))/2
C1323=(matrix(kronecker(u13,u23),2,2)+matrix(kronecker(u23,u13),2,2))/2
C1223=(matrix(kronecker(u12,u23),2,2)+matrix(kronecker(u23,u12),2,2))/2
Phi<-function(J,index_1,index_2){
if(index_1==1 && index_2==2){
 (1/(1+zeta12*(u12%*%solve(J)%*%u12)))[1,1]}
else if(index_1==1 && index_2==3){
 (1/(1+zeta13*(u13%*%solve(J)%*%u13)))[1,1]}
else{
 (1/(1+zeta23*(u23%*%solve(J)%*%u23)))[1,1]}
}

zeta_check12=zeta12*Phi(J2Nb+zeta23*Phi(J3Nb+zeta13*C13,2,3)*C23,1,2)
zeta_check13=zeta13*Phi(J3Nb+zeta23*Phi(J2Nb+zeta12*C12,2,3)*C23,1,3)
kappa23_numerator=2*zeta12*Phi(J2Nb,1,2)*zeta13*Phi(J3Nb,1,3)*sum(diag(solve(J2Nb)%*%C1223))*sum(diag(solve(J3Nb)%*%C1323))
kappa23_denomerator=1/zeta23-1/(zeta23*Phi(J2Nb+zeta12*C12,2,3))-1/(zeta23*Phi(J3Nb+zeta13*C13,2,3))
kappa23=kappa23_numerator/kappa23_denomerator
J1EFIM=J1Nb+zeta_check12*C12+zeta_check13*C13+kappa23*C1213
#solve(JC)[1:2,1:2]-solve(J1EFIM)

#tmp_matrix=solve(JC[3:4,3:4])%*%C23%*%solve(-JC[5:6,5:6]/zeta23^2+C23%*%solve(JC[3:4,3:4])%*%C23)%*%C23%*%solve(JC[3:4,3:4])
#tmp_matrix=solve(JC[3:4,3:4])-tmp_matrix
#my_zeta_check12=zeta12*(1-zeta12*(u12%*%tmp_matrix%*%u12)[1,1])

tmp_matrix=solve(J2Nb)%*%C23%*%solve(J3Nb)
tmp_coeff=Phi(J2Nb,1,2)*Phi(J3Nb,1,3)/(1-1/(Phi(J2Nb+zeta12*C12,2,3))-1/(Phi(J3Nb+zeta13*C13,2,3)))
tmp_1=tmp_coeff*(u12%*%tmp_matrix%*%u13)[1,1]


(J2Nb+zeta12*C12-zeta12*diag(2))%*%u12%*%u13%*%(J3Nb+zeta13*C13-zeta13*diag(2))*(u12%*%solve(J2Nb)%*%C23%*%solve(J3Nb)%*%u13)[1,1]/(1-1/(Phi(J2Nb+zeta12*C12,2,3))-1/(Phi(J3Nb+zeta13*C13,2,3)))




K2=J2Nb+zeta12*C12+zeta23*C23
tmp_matrix_2=solve(K2)%*%C23%*%solve(J3Nb+zeta13*C13+zeta23*C23-zeta23^2*C23%*%solve(K2)%*%C23)

t1=zeta23*diag(2)-1/(1+zeta23*(u23%*%(J2Nb+zeta12*C12)%*%u23)[1,1])*C23%*%solve(J2Nb+zeta12*C12)
t2=zeta23*diag(2)-1/(1+zeta23*(u23%*%(J3Nb+zeta13*C13)%*%u23)[1,1])*C23%*%solve(J3Nb+zeta13*C13)
t1%*%C23%*%solve(J3Nb+zeta13*C13+zeta23*C23-zeta23^2*C23%*%solve(K2)%*%C23)%*%t2





solve(K2)%*%C23%*%solve(J3Nb+zeta13*C13+zeta23*C23-zeta23^2*C23%*%solve(K2)%*%C23)


u12%*%tmp_matrix_2%*%u13+tmp_1

#x=solve(solve(JC)[1:2,1:2])
#y=solve(solve(JC)[3:4,3:4])
#z=solve(solve(JC)[5:6,5:6])
#v1=zeta12^2*(u12%*%solve(J1Nb+zeta12*C12)%*%u12)[1,1]
#K1=(u12%*%solve(y)%*%u12)[1,1]
#v2=zeta13^2*(u13%*%solve(J1Nb+zeta13*C13)%*%u13)[1,1]
#K2=(u13%*%solve(z)%*%u13)[1,1]
#J1Nb+zeta12*C12*(1-zeta12/(v1+1/K1))+zeta13*C13*(1-zeta13/(v2+1/K2))-x


theta=0;
JC<-matrix(0,8,8)
u1=c(cos(theta),sin(theta));
u2=c(cos(pi/3+theta),sin(pi/3+theta));
u3=c(cos(theta),sin(theta));
C1=matrix(kronecker(u1,u1),2,2)
C2=matrix(kronecker(u2,u2),2,2)
C3=matrix(kronecker(u3,u3),2,2)
JC[1:2,1:2]=C1
JC[3:4,3:4]=C1+C2
JC[5:6,5:6]=C2+C3
JC[7:8,7:8]=C3
JC[1:2,3:4]=-C1
JC[3:4,1:2]=-C1
JC[7:8,5:6]=-C3
JC[5:6,7:8]=-C3
JC[3:4,5:6]=-C2
JC[5:6,3:4]=-C2

theta=0;
u1=c(cos(theta),sin(theta));
u2=c(cos(pi/3+theta),sin(pi/3+theta));
u3=c(cos(4*pi/3+theta),sin(4*pi/3+theta));
u4=c(cos(pi/4+theta),sin(pi/4+theta));
u12=(u1-u2)/norm(u1-u2,type='2')
u13=(u1-u3)/norm(u1-u3,type='2')
u23=(u2-u3)/norm(u2-u3,type='2')
u14=(u1-u4)/norm(u1-u4,type='2')
u24=(u2-u4)/norm(u2-u4,type='2')
u34=(u3-u4)/norm(u3-u4,type='2')
C12=matrix(kronecker(u12,u12),2,2)
C13=matrix(kronecker(u13,u13),2,2)
C23=matrix(kronecker(u23,u23),2,2)
C14=matrix(kronecker(u14,u14),2,2)
C24=matrix(kronecker(u24,u24),2,2)
C34=matrix(kronecker(u34,u34),2,2)
JC=matrix(,8,8)
JC[1:2,1:2]=C12+C13+C14
JC[3:4,3:4]=C12+C23+C24
JC[5:6,5:6]=C13+C23+C34
JC[7:8,7:8]=C14+C24+C34
JC[1:2,3:4]=-C12
JC[3:4,1:2]=-C12
JC[1:2,5:6]=-C13
JC[5:6,1:2]=-C13
JC[3:4,5:6]=-C23
JC[5:6,3:4]=-C23
JC[1:2,7:8]=-C14
JC[7:8,1:2]=-C14
JC[3:4,7:8]=-C24
JC[7:8,3:4]=-C24
JC[7:8,5:6]=-C34
JC[5:6,7:8]=-C34




