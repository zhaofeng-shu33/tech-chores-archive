x_len=10
sim_time=150
lambda_vector=c(0.2,1,2,5)
a2=matrix(,2*length(lambda_vector),x_len-2)
for (r in 1:length(lambda_vector)){
a1_final=seq(0,0,length=x_len)
lambda=lambda_vector[r]
for (i in 1:sim_time){
a1=seq(0,0,length=x_len)
theta=runif(x_len-2)*2*pi
a1[1]=lambda;
a1[2]=lambda+lambda/(lambda+1);
matrix_left=matrix(c(lambda,1,1,0),2,2);
for(j in 3:x_len){
matrix_left=matrix_left%*%matrix(c(lambda+1,lambda,1+sin(theta[j-2])^2/lambda,1),2,2)
vector_tmp=matrix_left%*%matrix(c(1+1/lambda,1,1,0),2,2)%*%c(1,0)
a1[j]=vector_tmp[1]/vector_tmp[2]
}
a1_final=(a1_final*(i-1)+a1)/i
a2[2*r-1,]=diff(a1_final)[2:(x_len-1)]
a2[2*r,]=1/((1+lambda)^seq(from=0,to=2*(x_len-3),by=2))/(lambda^2+lambda*2)
}
}
write.csv(a2,'E:/paper/test1.csv')
#four columns
#each group: first column: Monte Carlo Sim result
#second column: Upper Bound