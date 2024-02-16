clear;

d = 0.01;

xn = 0 : d : 1;
yn = 0 : d : 1;

tic

for i = 1:length(xn)-1
    for j = 1:length(yn)-1
        c(i,j) = ( 1 - xn(i)^2 - yn(i)^2 );
        if( c(i,j) < 0 )
            c(i,j) = 0;
        end
    end
end

toc

disp( "8 * s =" + 8 * sum(sum(c.^.5))*d^2 )
disp( "solution = " + 4/3 * pi )