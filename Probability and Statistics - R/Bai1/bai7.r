x<-c(3,2);
y<-c(-1,1);
x=rbind(1,2);
m<-c(1,4,0);
n<-c(0,1,-1);
y=rbind(m,n);

A=matrix(
    c(3,2,-1,1),
    byrow=TRUE
)
rownames(A)=c("1","2");
colnames(A)=c("1","2");