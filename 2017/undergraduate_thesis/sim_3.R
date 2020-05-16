f<-c(function(t){c(t,t^2)},function(t){c(cos(pi*t),sin(pi*t))})
lambda=2
theoretical_value=(lambda+sqrt(4*lambda+lambda^2))/2
delta_t=c(0.1,0.01,0.001,0.0001)
a_final=matrix(,nrow=length(f),ncol=length(delta_t))
for(r in 1:length(f)){
for (j in 1:length(delta_t)){
a=lambda+1/(1+1/lambda)
time_discrete=seq(0,1,by=delta_t[j])
for(i in 2:(length(time_discrete)-1)){
pos_1=f[[r]](time_discrete[i])-f[[r]](time_discrete[i-1])
pos_2=f[[r]](time_discrete[i])-f[[r]](time_discrete[i+1])
angle_cos=sum(pos_1*pos_2)/(norm(pos_1,'2')*norm(pos_2,'2'))
a=lambda+1/(1+(1-angle_cos^2)/lambda+angle_cos^2/a)
}
a_final[r,j]=a
}
}
write.csv(a_final,'E:/paper/test3.csv')
