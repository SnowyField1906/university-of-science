x <- sample(-5:5,size=6,replace=TRUE);

sumOfListToi <- function(x){
    sum=0;      
    for(i in x)  sum<-sum+i;
    return(sum);
}

sumOfListToi(x);