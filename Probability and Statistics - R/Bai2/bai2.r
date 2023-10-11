tinhTheTich<-function(r){
    V<-r*3.14*r*r*r/3;
    return(V);
}

r<-c(1,2,3,4,5);
V<-c(tinhTheTich(1),tinhTheTich(2),tinhTheTich(3),tinhTheTich(4),tinhTheTich(5))

df<-data.frame(r,V);

