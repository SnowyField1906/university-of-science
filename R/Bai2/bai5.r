phanvi<-function(vector X,integer P){
    t<-sort(X);
    print(t);
    integer i=(P/100)*length(X);
    if(!is.integer(i))
    {
        return(round(i));
    }
    else{
        return((X[i]+X[i+1])/2);
    }
    return(0);
}