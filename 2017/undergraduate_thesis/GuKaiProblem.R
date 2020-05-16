L0=6
sigma=1;
N0=1000;
x1=rrayleigh(N0, scale = sigma)#length L, Rayleigh distribution
x2=runif(N0)
x2=x2*2*pi#theta,angle,uniform distribution
x3=sqrt(x1^2+L0^2-2*L0*x1*cos(x2))#L'
x4=pi-acos((L0^2+x3^2-x1^2)/(2*L0*x3))#theta'
f_trans<-function(L,theta){#new coordinate
t0=sqrt(L^2+L0^2+2*L*L0*cos(theta))
t1=exp(-t0^2/(2*sigma))*t0/(2*pi*sigma^2)
t2=-L0^2*L-L^3-2*L^2*L0*cos(theta)+L0^2*L*sin(theta)*cos(theta)+L0*L^2*sin(theta)
t3=(L^2+L0^2+2*L*L0*cos(theta))^1.5
abs(t1*t2/t3)
}
my_1=seq(0,3,0.1)
my_2=c()
for(i in 1:length(my_1)){
my_2=c(my_2,integrate(function(x){f_trans(my_1[i],x)},0,2)$value)
}